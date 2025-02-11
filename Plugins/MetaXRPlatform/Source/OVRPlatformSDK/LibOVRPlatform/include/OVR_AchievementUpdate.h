// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ACHIEVEMENTUPDATE_H
#define OVR_ACHIEVEMENTUPDATE_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// Represents an update to an existing achievement. It will be the payload if
/// there is any updates on achievements, as unlocking an achievement by
/// ovr_Achievements_Unlock(), adding 'count' to the achievement by
/// ovr_Achievements_AddCount(), and unlocking fields of a BITFIELD achievement
/// by ovr_Achievements_AddFields().
typedef struct ovrAchievementUpdate *ovrAchievementUpdateHandle;

/// This indicates if this update caused the achievement to unlock.
OVRP_PUBLIC_FUNCTION(bool) ovr_AchievementUpdate_GetJustUnlocked(const ovrAchievementUpdateHandle obj);

/// The unique ovr_AchievementDefinition_GetName() used to reference the
/// updated achievement, as specified in the developer dashboard.
OVRP_PUBLIC_FUNCTION(const char *) ovr_AchievementUpdate_GetName(const ovrAchievementUpdateHandle obj);


#endif
