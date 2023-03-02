/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/************************************************************************************
 * Filename    :   OVR_PlatformLoader.cpp
 * Content     :   Platform DLL user library
 * Created     :   February 18, 2016
 ***********************************************************************************/

// Drop-in shim to load LibOVRPlatform
// This shim will perform signature verification on the platform library.
// If the library is properly signed and loaded, it will pass through
// the initialization call, and also pass through attempts to call
// a few other critical functions.

// The majority of this is code derived from LibOVR/Src/OVR_CAPIShim.c

#ifndef OVRPL_DISABLED

#if defined(_MSC_VER)
#pragma warning(push, 0)
#endif
#include <Windows.h>
#if defined(_MSC_VER)
#pragma warning(pop)
#endif

#pragma comment(lib, "advapi32.lib")

#include <stdio.h>
#include <stdlib.h>
#include "OVR_Platform.h"
#include "OVR_PlatformVersion.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4996) // 'getenv': This function or variable may be unsafe.
#endif

//-----------------------------------------------------------------------------------
// ***** FilePathCharType, ModuleHandleType, ModuleFunctionType
//
// #define instead of typedef because debuggers (VC++, XCode) don't recognize typedef'd types as a
// string type.
#define FilePathCharType wchar_t
typedef HMODULE ModuleHandleType;
typedef FARPROC ModuleFunctionType;

#define ModuleHandleTypeNull ((ModuleHandleType)NULL)
#define ModuleFunctionTypeNull ((ModuleFunctionType)NULL)

//-----------------------------------------------------------------------------------
// ***** OVRPL_DECLARE_IMPORT
//
// Creates typedef and pointer declaration for a function of a given signature.
// The typedef is <FunctionName>Type, and the pointer is <FunctionName>Ptr.
//
// Example usage:
//     int MultiplyValues(float x, float y);  // Assume this function exists in an external shared
//     library. We don't actually need to redeclare it. OVRPL_DECLARE_IMPORT(int, MultiplyValues,
//     (float x, float y)) // This creates a local typedef and pointer for it.

#define OVRPL_DECLARE_IMPORT(ReturnValue, FunctionName, Arguments) \
  typedef ReturnValue(OVRP_CDECL* FunctionName##Type) Arguments;   \
  static FunctionName##Type FunctionName##PLPtr = NULL;

//-----------------------------------------------------------------------------------
// ***** OVRPL_GETFUNCTION
//
// Loads <FunctionName>Ptr from <library> if not already loaded.
// Assumes a variable named <FunctionName>Ptr of type <FunctionName>Type exists which is called
// <FunctionName> in LibOVRPlatform.
//
// Example usage:
//     OVRPL_GETFUNCTION(module, MultiplyValues)
//     int result = MultiplyValuesPtr(3.f, 4.f);

#define OVRPL_GETFUNCTION(l, f)   \
  if (!f##PLPtr) {                \
    union {                       \
      f##Type p1;                 \
      ModuleFunctionType p2;      \
    } u;                          \
    u.p2 = GetProcAddress(l, #f); \
    f##PLPtr = u.p1;              \
  }

//-----------------------------------------------------------------------------------
// ***** OVR_MAX_PATH
//
#if !defined(OVR_MAX_PATH)
#define OVR_MAX_PATH _MAX_PATH
#endif

static size_t OVR_wstrlcat(wchar_t* dest, const wchar_t* src, size_t destsize) {
  const size_t d = destsize ? wcslen(dest) : 0;
  const size_t s = wcslen(src);
  const size_t t = s + d;

  if (t < destsize)
    memcpy(dest + d, src, (s + 1) * sizeof(*src));
  else {
    if (destsize) {
      memcpy(dest + d, src, ((destsize - d) - 1) * sizeof(*src));
      dest[destsize - 1] = 0;
    }
  }

  return t;
}

static bool OVR_GetOculusBaseDirectory(
    FilePathCharType* directoryPath,
    size_t directoryPathCapacity) {
  DWORD length = directoryPathCapacity;
  HKEY key = 0;
  // Query the 32bit key even if 64bit build
  LONG result = RegOpenKeyExW(
      HKEY_LOCAL_MACHINE, L"Software\\Oculus VR, LLC\\Oculus", 0, KEY_READ | KEY_WOW64_32KEY, &key);
  if (result != ERROR_SUCCESS) {
    return false;
  }

  result = RegGetValueW(
      key, NULL, L"Base", RRF_RT_REG_SZ | RRF_ZEROONFAILURE, NULL, (LPBYTE)directoryPath, &length);
  RegCloseKey(key);

  return result == ERROR_SUCCESS;
}

static bool IsHighIntegrityLevel() {
  // Allocate a fixed size buffer for the maximum possible size:
  // SID_AND_ATTRIBUTES can be the size of a SID + size of DWORD (for attributes).
  uint8_t mandatoryLabelBuffer[SECURITY_MAX_SID_SIZE + sizeof(DWORD)];
  DWORD bufferSize;
  HANDLE processToken;
  DWORD integrityLevel = SECURITY_MANDATORY_HIGH_RID;

  if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY | TOKEN_QUERY_SOURCE, &processToken) == 0) {
    return false;
  }

  if (GetTokenInformation(
          processToken,
          TokenIntegrityLevel,
          mandatoryLabelBuffer,
          sizeof(mandatoryLabelBuffer),
          &bufferSize) != 0) {
    TOKEN_MANDATORY_LABEL* mandatoryLabel = (TOKEN_MANDATORY_LABEL*)mandatoryLabelBuffer;
    const DWORD subAuthorityCount = *GetSidSubAuthorityCount(mandatoryLabel->Label.Sid);
    integrityLevel = *GetSidSubAuthority(mandatoryLabel->Label.Sid, subAuthorityCount - 1);
  }

  CloseHandle(processToken);
  return integrityLevel > SECURITY_MANDATORY_MEDIUM_RID;
}

static ModuleHandleType OVR_OpenLibrary(
    const FilePathCharType* libraryPath,
    ovrPlatformInitializeResult* outResult) {
  // In this case we thought we found a valid library at the location, so we'll load it, and if that
  // fails for some reason we'll mark it as an invalid file error.
  ModuleHandleType hModule = LoadLibraryW(libraryPath);

  if (hModule == ModuleHandleTypeNull) {
    *outResult = ovrPlatformInitialize_FileInvalid;
  } else {
    *outResult = ovrPlatformInitialize_Success;
  }
  return hModule;
}

void OVR_CloseLibrary(ModuleHandleType hLibrary) {
  if (hLibrary) {
    // We may need to consider what to do in the case that the library is in an exception state.
    // In a Windows C++ DLL, all global objects (including static members of classes) will be
    // constructed just before the calling of the DllMain with DLL_PROCESS_ATTACH and they will be
    // destroyed just after the call of the DllMain with DLL_PROCESS_DETACH. We may need to
    // intercept DLL_PROCESS_DETACH and have special handling for the case that the DLL is broken.
    FreeLibrary(hLibrary);
  }
}

// Returns a valid ModuleHandleType (e.g. Windows HMODULE) or returns ModuleHandleTypeNull (e.g.
// NULL). The caller is required to eventually call OVR_CloseLibrary on a valid return handle.
//
static ModuleHandleType OVR_FindLibraryPath(
    int requestedProductVersion,
    int requestedMajorVersion,
    ovrPlatformInitializeResult* outResult,
    FilePathCharType* libraryPath,
    size_t libraryPathCapacity) {
  ModuleHandleType moduleHandle;
  int printfResult;
  FilePathCharType developerDir[OVR_MAX_PATH] = {'\0'};
  FilePathCharType oculusInstallDir[OVR_MAX_PATH] = {'\0'};

#if defined(_WIN64)
  const char* pBitDepth = "64";
#else
  const char* pBitDepth = "32";
#endif

  (void)requestedProductVersion;

  moduleHandle = ModuleHandleTypeNull;
  if (libraryPathCapacity)
    libraryPath[0] = '\0';

#define OVR_FILE_PATH_SEPARATOR L"\\"

  if (!IsHighIntegrityLevel()) {
    size_t length;
    errno_t success = _wgetenv_s(&length, developerDir, _countof(developerDir), L"LIBOVR_DLL_DIR");
    if ((success == 0) && (length != 0) && (length < _countof(developerDir)) &&
        developerDir[length - 2] != OVR_FILE_PATH_SEPARATOR[0]) {
      OVR_wstrlcat(developerDir, OVR_FILE_PATH_SEPARATOR, _countof(developerDir));
    }
  }

  if (OVR_GetOculusBaseDirectory(oculusInstallDir, _countof(oculusInstallDir))) {
    size_t baseDirLength = wcslen(oculusInstallDir);

    // If missing a trailing path separator then append one.
    if ((baseDirLength > 0) && (baseDirLength < _countof(oculusInstallDir)) &&
        (oculusInstallDir[baseDirLength - 1] != OVR_FILE_PATH_SEPARATOR[0])) {
      baseDirLength =
          OVR_wstrlcat(oculusInstallDir, OVR_FILE_PATH_SEPARATOR, _countof(oculusInstallDir));
    }

#define OVR_RUNTIME_PATH L"Support\\oculus-runtime\\"

    if ((baseDirLength > 0) &&
        (baseDirLength + _countof(OVR_RUNTIME_PATH) < _countof(oculusInstallDir))) {
      baseDirLength = OVR_wstrlcat(oculusInstallDir, OVR_RUNTIME_PATH, _countof(oculusInstallDir));
    }
  }

  auto lastOpenResult = ovrPlatformInitialize_Uninitialized;

  {
    size_t i;

    // On Windows, only search the developer directory and the install path
    const FilePathCharType* directoryArray[2];
    directoryArray[0] = developerDir[0] != '\0' ? developerDir : NULL; // Developer directory
    directoryArray[1] = oculusInstallDir;

    for (i = 0; i < sizeof(directoryArray) / sizeof(directoryArray[0]); ++i) {
      if (directoryArray[i] != NULL) {
        printfResult = swprintf(
            libraryPath,
            libraryPathCapacity,
            L"%lsLibOVRPlatform%hs_%d.dll",
            directoryArray[i],
            pBitDepth,
            requestedMajorVersion);

        if ((printfResult >= 0) && (printfResult < (int)libraryPathCapacity)) {
          auto openResult = ovrPlatformInitialize_Uninitialized;
          moduleHandle = OVR_OpenLibrary(libraryPath, &openResult);
          if (moduleHandle != ModuleHandleTypeNull) {
            *outResult = openResult;
            return moduleHandle;
          } else {
            lastOpenResult = openResult;
          }
        }
      }
    }
  }

  *outResult = lastOpenResult != ovrPlatformInitialize_Uninitialized
      ? lastOpenResult
      : ovrPlatformInitialize_UnableToVerify;
  return moduleHandle;
}

OVRPL_DECLARE_IMPORT(
    ovrPlatformInitializeResult,
    ovr_PlatformInitializeWindows,
    (const char* appId));
OVRPL_DECLARE_IMPORT(ovrRequest, ovr_PlatformInitializeWindowsAsynchronous, (const char* appId));
OVRPL_DECLARE_IMPORT(
    ovrRequest,
    ovr_PlatformInitializeWithAccessToken,
    (ovrID appId, const char* accessToken));
OVRPL_DECLARE_IMPORT(
    ovrRequest,
    ovr_PlatformInitializeWithAccessTokenAndOptions,
    (ovrID appId,
     const char* accessToken,
     ovrKeyValuePair* configOptions,
     size_t numConfigOptions));
OVRPL_DECLARE_IMPORT(ovrMessage*, ovr_PopMessage, ());
OVRPL_DECLARE_IMPORT(void, ovr_PlatformInitializeStandaloneAccessToken, (const char* accessToken));
OVRPL_DECLARE_IMPORT(
    ovrRequest,
    ovr_Platform_InitializeStandaloneOculus,
    (const ovrOculusInitParams* params));

static void LoadFunctions(ModuleHandleType hModule) {
  OVRPL_GETFUNCTION(hModule, ovr_PlatformInitializeWindows);
  OVRPL_GETFUNCTION(hModule, ovr_PlatformInitializeWindowsAsynchronous);
  OVRPL_GETFUNCTION(hModule, ovr_PlatformInitializeWithAccessToken);
  OVRPL_GETFUNCTION(hModule, ovr_PlatformInitializeWithAccessTokenAndOptions);
  OVRPL_GETFUNCTION(hModule, ovr_PopMessage);
  OVRPL_GETFUNCTION(hModule, ovr_PlatformInitializeStandaloneAccessToken);
  OVRPL_GETFUNCTION(hModule, ovr_Platform_InitializeStandaloneOculus);
}

static ovrPlatformInitializeResult InitializeResult = ovrPlatformInitialize_Uninitialized;

ovrPlatformInitializeResult loaderInitHelper(int productVersion, int majorVersion) {
  if (InitializeResult != ovrPlatformInitialize_Uninitialized) {
    return InitializeResult;
  }

  // Check to make sure the headers they're using (which automatically pass the version to this
  // function) match the version that this loader library was compiled under.
  if (productVersion != PLATFORM_PRODUCT_VERSION || majorVersion != PLATFORM_MAJOR_VERSION) {
    InitializeResult = ovrPlatformInitialize_VersionMismatch;
    return InitializeResult;
  }

  // See if the one we want has already been loaded by mirroring the OVR_FindLibraryPath name
  // generation but without the path
  FilePathCharType preLoadLibName[OVR_MAX_PATH];
  FilePathCharType preLoadFilePath[OVR_MAX_PATH];

#if defined(_WIN64)
  const char* pBitDepth = "64";
#else
  const char* pBitDepth = "32";
#endif

  swprintf(
      preLoadLibName,
      sizeof(preLoadLibName) / sizeof(preLoadLibName[0]),
      L"LibOVRPlatform%hs_%d.dll",
      pBitDepth,
      PLATFORM_MAJOR_VERSION);
  auto hLibPreLoad = GetModuleHandleW(preLoadLibName);
  if (hLibPreLoad != NULL) {
    // Someone already loaded the module. Might be fine, just copy the path out so we can check it
    // later.
    GetModuleFileNameW(
        hLibPreLoad, preLoadFilePath, sizeof(preLoadFilePath) / sizeof(preLoadFilePath[0]));
  }

  FilePathCharType filePath[OVR_MAX_PATH];

  auto hLib = OVR_FindLibraryPath(
      PLATFORM_PRODUCT_VERSION,
      PLATFORM_MAJOR_VERSION,
      &InitializeResult,
      filePath,
      sizeof(filePath) / sizeof(filePath[0]));

  if (InitializeResult == ovrPlatformInitialize_Success) {
    if (hLibPreLoad != NULL && wcsicmp(filePath, preLoadFilePath) != 0) {
      // The pre-loaded module was on a different path than the validated library. Not a
      // particularly likely case, but if it happens we should fail, since the non-shimmed functions
      // could call into the wrong library.
      InitializeResult = ovrPlatformInitialize_PreLoaded;
      return InitializeResult;
    }

    LoadFunctions(hLib);
  }

  return InitializeResult;
}

OVRPL_PUBLIC_FUNCTION(ovrRequest)
ovr_PlatformInitializeWindowsAsynchronousEx(
    const char* appId,
    ovrPlatformInitializeResult* outResult,
    int productVersion,
    int majorVersion) {
  ovrPlatformInitializeResult result = loaderInitHelper(productVersion, majorVersion);
  *outResult = result;

  if (result == ovrPlatformInitialize_Success) {
    return ovr_PlatformInitializeWindowsAsynchronousPLPtr(appId);
  }

  return 0;
}

OVRPL_PUBLIC_FUNCTION(ovrPlatformInitializeResult)
ovr_PlatformInitializeWindowsEx(const char* appId, int productVersion, int majorVersion) {
  ovrPlatformInitializeResult result = loaderInitHelper(productVersion, majorVersion);
  if (result == ovrPlatformInitialize_Success) {
    ovr_PlatformInitializeWindowsPLPtr(appId);
  }
  return result;
}

OVRPL_PUBLIC_FUNCTION(ovrMessage*) ovr_PopMessage() {
  if (InitializeResult == ovrPlatformInitialize_Success) {
    return ovr_PopMessagePLPtr();
  }
  return nullptr;
}

// We also shim the standalone initializer just for consistency in debugging, basically a shorter
// version of the windows init since we don't care about safety
OVRPL_PUBLIC_FUNCTION(void) ovr_PlatformInitializeStandaloneAccessToken(const char* accessToken) {
  if (InitializeResult != ovrPlatformInitialize_Uninitialized) {
    return;
  }

  InitializeResult = ovrPlatformInitialize_Success;

  FilePathCharType preLoadLibName[OVR_MAX_PATH];

#if defined(_WIN64)
  const char* pBitDepth = "64";
#else
  const char* pBitDepth = "32";
#endif

  swprintf(
      preLoadLibName,
      sizeof(preLoadLibName) / sizeof(preLoadLibName[0]),
      L"LibOVRPlatform%hs_%d.dll",
      pBitDepth,
      PLATFORM_MAJOR_VERSION);
  auto hLibPreLoad = GetModuleHandleW(preLoadLibName);

  LoadFunctions(hLibPreLoad);
  ovr_PlatformInitializeStandaloneAccessTokenPLPtr(accessToken);
}

OVRPL_PUBLIC_FUNCTION(ovrRequest)
ovr_Platform_InitializeStandaloneOculusEx(
    const ovrOculusInitParams* params,
    ovrPlatformInitializeResult* outResult,
    int productVersion,
    int majorVersion) {
  if (params != nullptr && outResult != nullptr) {
    ovrPlatformInitializeResult result = loaderInitHelper(productVersion, majorVersion);
    *outResult = result;
    if (result == ovrPlatformInitialize_Success) {
      return ovr_Platform_InitializeStandaloneOculusPLPtr(params);
    }
  } else if (outResult != nullptr) {
    *outResult = ovrPlatformInitialize_Uninitialized;
  }
  return 0;
}

OVRPL_PUBLIC_FUNCTION(ovrRequest)
ovr_PlatformInitializeWithAccessTokenEx(
    ovrID appId,
    const char* serviceAccessToken,
    ovrPlatformInitializeResult* outResult,
    int productVersion,
    int majorVersion) {
  if (outResult != nullptr) {
    ovrPlatformInitializeResult result = loaderInitHelper(productVersion, majorVersion);
    *outResult = result;
    if (result == ovrPlatformInitialize_Success) {
      return ovr_PlatformInitializeWithAccessTokenPLPtr(appId, serviceAccessToken);
    }
  }
  return 0;
}

#endif
