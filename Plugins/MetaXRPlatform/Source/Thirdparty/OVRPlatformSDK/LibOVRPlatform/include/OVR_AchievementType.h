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

#ifndef OVR_ACHIEVEMENT_TYPE_H
#define OVR_ACHIEVEMENT_TYPE_H

#include "OVR_Platform_Defs.h"

/// \file
/// Determines the type of the achievement. This enum defines the different
/// types of achievements that can be used in the game. Each type has its own
/// unique characteristics and requirements for unlocking. See more details
/// about achievement
/// [here](https://developer.oculus.com/documentation/native/ps-achievements/).

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrAchievementType_ {
  ovrAchievement_TypeUnknown,
  /// Simple achievements are unlocked by a single event or objective completion.
  /// They are often used to reward players for completing specific tasks or
  /// milestones within the game.
  ovrAchievement_TypeSimple,
  /// Bitfield achievements are unlocked when a target number of bits are set
  /// within a bitfield.
  ovrAchievement_TypeBitfield,
  /// Count achievements are unlocked when a counter reaches a defined target.
  /// The counter is incremented each time the player completes the required
  /// action, and when it reaches the target value, the achievement is unlocked.
  ovrAchievement_TypeCount,
} ovrAchievementType;

/// Converts an ::ovrAchievementType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAchievementType_ToString(ovrAchievementType value);

/// Converts a string representing an ::ovrAchievementType to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrAchievementType) ovrAchievementType_FromString(const char* str);

#endif
