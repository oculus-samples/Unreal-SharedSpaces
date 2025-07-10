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

#ifndef OVR_CHALLENGE_CREATION_TYPE_H
#define OVR_CHALLENGE_CREATION_TYPE_H

#include "OVR_Platform_Defs.h"

/// \file
/// Describes the creator of the associated challenge. This field indicates who
/// created the challenge, whether it was
/// ovrChallengeCreationType_UserCreated() or
/// ovrChallengeCreationType_DeveloperCreated(). Understanding the creator of
/// the associated challenge can provide valuable context and help participants
/// better understand the nature and purpose of the challenge.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrChallengeCreationType_ {
  ovrChallengeCreationType_Unknown,
  /// The challenge was created by a User. This means that a regular user of the
  /// app created the challenge, and it may be a community-driven challenge or a
  /// personal challenge created by the user for themselves or others.
  ovrChallengeCreationType_UserCreated,
  /// The challenge was created by the app developer. This means that the
  /// challenge was created by the team behind the app, and it may be an official
  /// challenge or a special event created by the developers to engage with the
  /// community or promote specific features of the app.
  ovrChallengeCreationType_DeveloperCreated,
} ovrChallengeCreationType;

/// Converts an ::ovrChallengeCreationType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrChallengeCreationType_ToString(ovrChallengeCreationType value);

/// Converts a string representing an ::ovrChallengeCreationType to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrChallengeCreationType) ovrChallengeCreationType_FromString(const char* str);

#endif
