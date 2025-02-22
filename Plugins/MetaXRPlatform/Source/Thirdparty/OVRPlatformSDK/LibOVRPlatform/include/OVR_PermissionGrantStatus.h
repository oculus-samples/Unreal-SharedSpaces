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

#ifndef OVR_PERMISSION_GRANT_STATUS_H
#define OVR_PERMISSION_GRANT_STATUS_H

#include "OVR_Platform_Defs.h"

/// \file
/// This `enum` represents the all possible statuses of a premission request.
/// For example, if an user wants to participate in a challenge, the user may
/// request the permission to join the ::ovrChallengeHandle first. If the
/// permission grant status is granted, the user can call ovr_Challenges_Join()
/// to join the challenge.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrPermissionGrantStatus_ {
  ovrPermissionGrantStatus_Unknown,
  /// This `enum` member indicates the status of the permission grant was
  /// approved.
  ovrPermissionGrantStatus_Granted,
  /// This `enum` member indicates the status of the permission grant was
  /// rejected.
  ovrPermissionGrantStatus_Denied,
  /// This `enum` member indicates the status of the permission grant was
  /// blocked.
  ovrPermissionGrantStatus_Blocked,
} ovrPermissionGrantStatus;

/// Converts an ::ovrPermissionGrantStatus enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrPermissionGrantStatus_ToString(ovrPermissionGrantStatus value);

/// Converts a string representing an ::ovrPermissionGrantStatus to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrPermissionGrantStatus) ovrPermissionGrantStatus_FromString(const char* str);

#endif
