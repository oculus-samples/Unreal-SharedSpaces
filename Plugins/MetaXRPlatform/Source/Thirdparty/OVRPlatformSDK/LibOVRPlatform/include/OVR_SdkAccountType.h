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

#ifndef OVR_SDK_ACCOUNT_TYPE_H
#define OVR_SDK_ACCOUNT_TYPE_H

#include "OVR_Platform_Defs.h"

/// \file
/// A user can have multiple sdk accounts associated with it. An
/// ::ovrSdkAccountHandle represents the oculus user and the particular
/// x-account that is linked to the user. SDK accounts can be retrived for a
/// particular user by calling ovr_User_GetSdkAccounts(). This enumeration
/// represents the specific type of SDK account that is associated.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrSdkAccountType_ {
  ovrSdkAccountType_Unknown,
  ovrSdkAccountType_Oculus,
  ovrSdkAccountType_FacebookGameroom,
} ovrSdkAccountType;

/// Converts an ::ovrSdkAccountType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrSdkAccountType_ToString(ovrSdkAccountType value);

/// Converts a string representing an ::ovrSdkAccountType to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrSdkAccountType) ovrSdkAccountType_FromString(const char* str);

#endif
