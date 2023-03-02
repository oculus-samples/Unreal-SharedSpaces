// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MATCHMAKINGSTATS_H
#define OVR_MATCHMAKINGSTATS_H

#include "OVR_Platform_Defs.h"

typedef struct ovrMatchmakingStats *ovrMatchmakingStatsHandle;

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_MatchmakingStats_GetDrawCount(const ovrMatchmakingStatsHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_MatchmakingStats_GetLossCount(const ovrMatchmakingStatsHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_MatchmakingStats_GetSkillLevel(const ovrMatchmakingStatsHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(double) ovr_MatchmakingStats_GetSkillMean(const ovrMatchmakingStatsHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(double) ovr_MatchmakingStats_GetSkillStandardDeviation(const ovrMatchmakingStatsHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_MatchmakingStats_GetWinCount(const ovrMatchmakingStatsHandle obj);


#endif
