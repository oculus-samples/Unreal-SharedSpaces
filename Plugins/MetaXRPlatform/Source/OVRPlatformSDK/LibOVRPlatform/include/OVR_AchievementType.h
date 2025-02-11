// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ACHIEVEMENT_TYPE_H
#define OVR_ACHIEVEMENT_TYPE_H

#include "OVR_Platform_Defs.h"

/// Determines the type of the achievement.
typedef enum ovrAchievementType_ {
  ovrAchievement_TypeUnknown,
  /// Simple achievements are unlocked by a single event or objective completion.
  ovrAchievement_TypeSimple,
  /// Bitfield achievements are unlocked when a target number of bits are set
  /// within a bitfield.
  ovrAchievement_TypeBitfield,
  /// Count achievements are unlocked when a counter reaches a defined target.
  ovrAchievement_TypeCount,
} ovrAchievementType;

/// Converts an ovrAchievementType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAchievementType_ToString(ovrAchievementType value);

/// Converts a string representing an ovrAchievementType enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrAchievementType) ovrAchievementType_FromString(const char* str);

#endif
