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

#ifndef OVR_LAUNCH_TYPE_H
#define OVR_LAUNCH_TYPE_H

#include "OVR_Platform_Defs.h"

/// \file
/// It's an enum that defines several different types of launches for an
/// application. It provides a way to differentiate between different types of
/// launches and to access additional information about the launch details. It
/// can be retrieved using ovr_LaunchDetails_GetLaunchType() to get the launch
/// type information of an application.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrLaunchType_ {
  ovrLaunchType_Unknown,
  /// Normal launch from the user's library
  ovrLaunchType_Normal,
  /// Launch from the user accepting an invite. Check
  /// ovr_LaunchDetails_GetLobbySessionID(),
  /// ovr_LaunchDetails_GetMatchSessionID(),
  /// ovr_LaunchDetails_GetDestinationApiName() and
  /// ovr_LaunchDetails_GetDeeplinkMessage().
  ovrLaunchType_Invite,
  /// DEPRECATED
  ovrLaunchType_Coordinated,
  /// Launched from ovr_Application_LaunchOtherApp(). Check
  /// ovr_LaunchDetails_GetLaunchSource() and
  /// ovr_LaunchDetails_GetDeeplinkMessage().
  ovrLaunchType_Deeplink,
} ovrLaunchType;

/// Converts an ::ovrLaunchType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLaunchType_ToString(ovrLaunchType value);

/// Converts a string representing an ::ovrLaunchType to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrLaunchType) ovrLaunchType_FromString(const char* str);

#endif
