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
 
// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APP_INSTALL_RESULT_H
#define OVR_APP_INSTALL_RESULT_H

#include "OVR_Platform_Defs.h"

/// \file
/// Result of installing an app. In case of an error during install process,
/// the error message contains the string representation of this result. This
/// is returned from ovr_Application_StartAppDownload(),
/// ovr_Application_CancelAppDownload() and
/// ovr_Application_InstallAppUpdateAndRelaunch() APIs.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrAppInstallResult_ {
  ovrAppInstallResult_Unknown,
  /// Install of the app failed due to low storage on the device
  ovrAppInstallResult_LowStorage,
  /// Install of the app failed due to a network error
  ovrAppInstallResult_NetworkError,
  /// Install of the app failed as another install request for this application
  /// is already being processed by the installer
  ovrAppInstallResult_DuplicateRequest,
  /// Install of the app failed due to an internal installer error
  ovrAppInstallResult_InstallerError,
  /// Install of the app failed because the user canceled the install operation
  ovrAppInstallResult_UserCancelled,
  /// Install of the app failed due to a user authorization error
  ovrAppInstallResult_AuthorizationError,
  /// Install of the app succeeded
  ovrAppInstallResult_Success,
} ovrAppInstallResult;

/// Converts an ::ovrAppInstallResult enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAppInstallResult_ToString(ovrAppInstallResult value);

/// Converts a string representing an ::ovrAppInstallResult to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrAppInstallResult) ovrAppInstallResult_FromString(const char* str);

#endif
