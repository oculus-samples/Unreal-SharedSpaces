// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LEADERBOARDUPDATESTATUS_H
#define OVR_LEADERBOARDUPDATESTATUS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stdbool.h>

typedef struct ovrLeaderboardUpdateStatus *ovrLeaderboardUpdateStatusHandle;

OVRP_PUBLIC_FUNCTION(bool)         ovr_LeaderboardUpdateStatus_GetDidUpdate(const ovrLeaderboardUpdateStatusHandle obj);
OVRP_PUBLIC_FUNCTION(ovrID)        ovr_LeaderboardUpdateStatus_GetUpdatedChallengeId(const ovrLeaderboardUpdateStatusHandle obj, unsigned int index);
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_LeaderboardUpdateStatus_GetUpdatedChallengeIdsSize(const ovrLeaderboardUpdateStatusHandle obj);

#endif
