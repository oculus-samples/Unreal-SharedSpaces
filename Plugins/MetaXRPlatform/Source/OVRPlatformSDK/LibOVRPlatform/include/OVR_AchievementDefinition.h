// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ACHIEVEMENTDEFINITION_H
#define OVR_ACHIEVEMENTDEFINITION_H

#include "OVR_Platform_Defs.h"
#include "OVR_AchievementType.h"

/// An AchievementDefinition defines an achievement; this includes its name and
/// how it is unlocked. For an individual user's progress in unlocking an
/// achievement, see AchievementProgress. It can be retrieved using
/// ovr_Achievements_GetAllDefinitions().
typedef struct ovrAchievementDefinition *ovrAchievementDefinitionHandle;

/// It is required for bitfield achievements(ovrAchievement_TypeBitfield). This
/// represents the size of the bitfield for this achievement.
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_AchievementDefinition_GetBitfieldLength(const ovrAchievementDefinitionHandle obj);

/// A string of the api name of the achievement. It can be used to get the
/// achievement progress by name by the function
/// ovr_Achievements_GetProgressByName().
OVRP_PUBLIC_FUNCTION(const char *) ovr_AchievementDefinition_GetName(const ovrAchievementDefinitionHandle obj);

/// This is the type of achievement. There are three types of achievement:
/// ovrAchievement_TypeSimple - unlocked by completion of a single event or
/// objective, ovrAchievement_TypeBitfield - unlocked when a number of bits in
/// a bitfield are set, and ovrAchievement_TypeCount - unlocked when a counter
/// reaches a defined target.
OVRP_PUBLIC_FUNCTION(ovrAchievementType) ovr_AchievementDefinition_GetType(const ovrAchievementDefinitionHandle obj);

OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_AchievementDefinition_GetTarget(const ovrAchievementDefinitionHandle obj);

#endif
