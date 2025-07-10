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

#ifndef OVR_MULTIPLAYER_ERROR_ERROR_KEY_H
#define OVR_MULTIPLAYER_ERROR_ERROR_KEY_H

#include "OVR_Platform_Defs.h"

/// \file
/// Possible keys of the errors which could occurred when using the
/// [multiplayer
/// features](https://developer.oculus.com/documentation/native/ps-multiplayer-
/// overview/). e.g., you may need to use `destination_unavailable` for
/// destinations feature and use `inviter_not_joinable` for invite feature and
/// so on.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrMultiplayerErrorErrorKey_ {
  ovrMultiplayerErrorErrorKey_Unknown,
  /// This error key will be used to tell the user that the travel destination is
  /// not available any more.
  ovrMultiplayerErrorErrorKey_DestinationUnavailable,
  /// This error will tell the user that the downloadable content will be needed.
  ovrMultiplayerErrorErrorKey_DlcRequired,
  /// This error key will be used in a broad range of general errors which are
  /// not be covered by the members of the enum.
  ovrMultiplayerErrorErrorKey_General,
  /// This error key may be used to explain to the user the reason why she/he
  /// failed in joining a group.
  ovrMultiplayerErrorErrorKey_GroupFull,
  /// This error key will be used in explaining why an inviter cannot invite a
  /// recepient successfully. The group presence can be set to joinable by using
  /// ovr_GroupPresence_SetIsJoinable().
  ovrMultiplayerErrorErrorKey_InviterNotJoinable,
  /// Certain features will not be available to the user in the app because the
  /// user's level does not reach to certain level.
  ovrMultiplayerErrorErrorKey_LevelNotHighEnough,
  /// This error key may be used to explain to the user the failure was occurred
  /// becasue some level has not been reached.
  ovrMultiplayerErrorErrorKey_LevelNotUnlocked,
  /// When the predefined network timeout has reached, the ongoing activity would
  /// be stopped. The dialog will use this error key to give the user the
  /// information.
  ovrMultiplayerErrorErrorKey_NetworkTimeout,
  ovrMultiplayerErrorErrorKey_NoLongerAvailable,
  ovrMultiplayerErrorErrorKey_UpdateRequired,
  ovrMultiplayerErrorErrorKey_TutorialRequired,
} ovrMultiplayerErrorErrorKey;

/// Converts an ::ovrMultiplayerErrorErrorKey enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrMultiplayerErrorErrorKey_ToString(ovrMultiplayerErrorErrorKey value);

/// Converts a string representing an ::ovrMultiplayerErrorErrorKey to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrMultiplayerErrorErrorKey) ovrMultiplayerErrorErrorKey_FromString(const char* str);

#endif
