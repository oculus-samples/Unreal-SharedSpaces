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

#ifndef OVR_CHALLENGE_VISIBILITY_H
#define OVR_CHALLENGE_VISIBILITY_H

#include "OVR_Platform_Defs.h"

/// \file
/// The visibility of the challenge. A challenge may be invite-only, public, or
/// private. The visibility setting determines who can see and participate in
/// the challenge. See more details of Challenges in
/// [here](https://developer.oculus.com/documentation/native/ps-challenges/).

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrChallengeVisibility_ {
  ovrChallengeVisibility_Unknown,
  /// Only those invited can participate in it. Everyone can see it, but only
  /// those with an invitation can joinand participate in the challenge. This
  /// setting is useful for challenges that are meant to be exclusive or for a
  /// specific group of people.
  ovrChallengeVisibility_InviteOnly,
  /// Everyone can participate and see this challenge. This setting makes the
  /// challenge open to anyone who wants to join, and everyone can see the
  /// challenge details and progress. This setting is useful for challenges that
  /// are meant to be open and inclusive.
  ovrChallengeVisibility_Public,
  /// Only those invited can participate and see this challenge. This setting
  /// makes the challenge invisible to everyone except those who have been
  /// explicitly invited. Only those with an invitation can see the challenge
  /// details and progress, and only they can participate. This setting is useful
  /// for challenges that are meant to be highly exclusive or confidential.
  ovrChallengeVisibility_Private,
} ovrChallengeVisibility;

/// Converts an ::ovrChallengeVisibility enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrChallengeVisibility_ToString(ovrChallengeVisibility value);

/// Converts a string representing an ::ovrChallengeVisibility to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrChallengeVisibility) ovrChallengeVisibility_FromString(const char* str);

#endif
