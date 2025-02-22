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

#ifndef OVR_PLATFORMINITIALIZE_H
#define OVR_PLATFORMINITIALIZE_H

#include "OVR_Platform_Defs.h"
#include "OVR_PlatformInitializeResult.h"

/// \file
/// A PlatformInitialize object defines an attempt at initializing the Platform
/// SDK. It contains the result of attempting to initialize the platform. The
/// different types of initialization results are
/// ovrPlatformInitializeResult().
typedef struct ovrPlatformInitialize *ovrPlatformInitializeHandle;

/// The result of attempting to initialize the platform:
///
/// ovrPlatformInitialize_Success() - Platform SDK initialization succeeded.
///
/// ovrPlatformInitialize_Uninitialized() - Platform SDK was not initialized.
///
/// ovrPlatformInitialize_PreLoaded() - Platform SDK failed to initialize
/// because the pre-loaded module was on a different path than the validated
/// library.
///
/// ovrPlatformInitialize_FileInvalid() - Platform SDK files failed to load.
///
/// ovrPlatformInitialize_SignatureInvalid() - Platform SDK failed to
/// initialize due to an invalid signature in the signed certificate.
///
/// ovrPlatformInitialize_UnableToVerify() - Platform SDK failed to verify the
/// application's signature during initialization.
///
/// ovrPlatformInitialize_VersionMismatch() - There was a mismatch between the
/// version of Platform SDK used by the application and the version installed
/// on the user's device.
///
/// ovrPlatformInitialize_InvalidCredentials() - Platform SDK failed to
/// initialize because the user had an invalid account access token.
///
/// ovrPlatformInitialize_NotEntitled() - Platform SDK failed to initialize
/// because the user does not have the application entitlement.
OVRP_PUBLIC_FUNCTION(ovrPlatformInitializeResult) ovr_PlatformInitialize_GetResult(const ovrPlatformInitializeHandle obj);


#endif
