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

#ifndef OVR_PLATFORM_INITIALIZE_RESULT_H
#define OVR_PLATFORM_INITIALIZE_RESULT_H

#include "OVR_Platform_Defs.h"

/// \file
/// Describes the various results possible when attempting to initialize the
/// platform. Anything other than ::ovrPlatformInitialize_Success should be
/// considered a fatal error with respect to using the platform, as the
/// platform is not guaranteed to be legitimate or work correctly.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrPlatformInitializeResult_ {
  /// Oculus Platform SDK initialization succeeded.
  ovrPlatformInitialize_Success = 0,
  /// Oculus Platform SDK was not initialized.
  ovrPlatformInitialize_Uninitialized = -1,
  /// Oculus Platform SDK failed to initialize because the pre-loaded module was
  /// on a different path than the validated library.
  ovrPlatformInitialize_PreLoaded = -2,
  /// Oculus Platform SDK files failed to load.
  ovrPlatformInitialize_FileInvalid = -3,
  /// Oculus Platform SDK failed to initialize due to an invalid signature in the
  /// signed certificate.
  ovrPlatformInitialize_SignatureInvalid = -4,
  /// Oculus Platform SDK failed to initialize due to unable to verify the
  /// application's signature during initialization.
  ovrPlatformInitialize_UnableToVerify = -5,
  /// There was a mismatch between the version of Oculus Platform SDK used by the
  /// application and the version installed on the Oculus user's device.
  ovrPlatformInitialize_VersionMismatch = -6,
  ovrPlatformInitialize_Unknown = -7,
  /// Oculus Platform SDK failed to initialize because the Oculus user had an
  /// invalid account access token.
  ovrPlatformInitialize_InvalidCredentials = -8,
  /// Oculus Platform SDK failed to initialize because the Oculus user does not
  /// have the application entitlement.
  ovrPlatformInitialize_NotEntitled = -9,
} ovrPlatformInitializeResult;

/// Converts an ::ovrPlatformInitializeResult enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrPlatformInitializeResult_ToString(ovrPlatformInitializeResult value);

/// Converts a string representing an ::ovrPlatformInitializeResult to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrPlatformInitializeResult) ovrPlatformInitializeResult_FromString(const char* str);

#endif
