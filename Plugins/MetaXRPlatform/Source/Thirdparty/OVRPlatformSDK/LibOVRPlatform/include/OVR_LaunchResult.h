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

#ifndef OVR_LAUNCH_RESULT_H
#define OVR_LAUNCH_RESULT_H

#include "OVR_Platform_Defs.h"

/// \file
/// An enum that specifies the whether the attempt to launch this application
/// via a deeplink was successful. The value is meant to be reported after a
/// deeplink by calling ovr_ApplicationLifecycle_LogDeeplinkResult()

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrLaunchResult_ {
  ovrLaunchResult_Unknown,
  /// The application launched successfully.
  ovrLaunchResult_Success,
  /// The application launch failed because the room was full.
  ovrLaunchResult_FailedRoomFull,
  /// The application launch failed because the game has already started.
  ovrLaunchResult_FailedGameAlreadyStarted,
  /// The appplicatin launch failed because the room couldn't be found.
  ovrLaunchResult_FailedRoomNotFound,
  /// The application launch failed because the user declined the invitation.
  ovrLaunchResult_FailedUserDeclined,
  /// The application launch failed due to some other reason.
  ovrLaunchResult_FailedOtherReason,
} ovrLaunchResult;

/// Converts an ::ovrLaunchResult enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLaunchResult_ToString(ovrLaunchResult value);

/// Converts a string representing an ::ovrLaunchResult to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrLaunchResult) ovrLaunchResult_FromString(const char* str);

#endif
