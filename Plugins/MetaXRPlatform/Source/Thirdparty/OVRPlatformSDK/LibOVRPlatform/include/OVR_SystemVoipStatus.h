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

#ifndef OVR_SYSTEM_VOIP_STATUS_H
#define OVR_SYSTEM_VOIP_STATUS_H

#include "OVR_Platform_Defs.h"

/// \file
/// The system voip status is the priamary status in every
/// ::ovrSystemVoipStateHandle. The system voip state is used in parties and
/// horizon home to describe the current state of the input/output for voip in
/// an application. You can read more about system voip
/// [here](https://developer.oculus.com/documentation/native/ps-parties/#voip-
/// options).

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrSystemVoipStatus_ {
  ovrSystemVoipStatus_Unknown,
  ovrSystemVoipStatus_Unavailable,
  ovrSystemVoipStatus_Suppressed,
  ovrSystemVoipStatus_Active,
} ovrSystemVoipStatus;

/// Converts an ::ovrSystemVoipStatus enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrSystemVoipStatus_ToString(ovrSystemVoipStatus value);

/// Converts a string representing an ::ovrSystemVoipStatus to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrSystemVoipStatus) ovrSystemVoipStatus_FromString(const char* str);

#endif
