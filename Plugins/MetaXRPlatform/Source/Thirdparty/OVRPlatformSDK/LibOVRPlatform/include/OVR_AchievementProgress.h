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

#ifndef OVR_ACHIEVEMENTPROGRESS_H
#define OVR_ACHIEVEMENTPROGRESS_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
/// The unlock progress of a particular achievement can be retrieved using
/// ovr_Achievements_GetAllProgress(). It can be used to display the progress
/// of each achievement in your game. See the following
/// [link](https://developer.oculus.com/documentation/native/ps-achievements/)
/// for more information.
typedef struct ovrAchievementProgress *ovrAchievementProgressHandle;

/// If the type of the achievement is ovrAchievement_TypeBitfield() it
/// represents the current bitfield state that the achievement has reached.
OVRP_PUBLIC_FUNCTION(const char *) ovr_AchievementProgress_GetBitfield(const ovrAchievementProgressHandle obj);

/// If the type of the achievement is ovrAchievement_TypeCount(), it represents
/// the current counter state that the achievement has reached.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_AchievementProgress_GetCount(const ovrAchievementProgressHandle obj);

/// If the user has already unlocked this achievement.
OVRP_PUBLIC_FUNCTION(bool) ovr_AchievementProgress_GetIsUnlocked(const ovrAchievementProgressHandle obj);

/// The unique string that you use to reference the achievement in your app, as
/// specified in the developer dashboard. It can be retrieved using
/// ovr_AchievementDefinition_GetName().
OVRP_PUBLIC_FUNCTION(const char *) ovr_AchievementProgress_GetName(const ovrAchievementProgressHandle obj);

/// If the achievement is unlocked, the time when it was unlocked.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_AchievementProgress_GetUnlockTime(const ovrAchievementProgressHandle obj);


#endif
