// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LEADERBOARDARRAY_H
#define OVR_LEADERBOARDARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Leaderboard.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ovrLeaderboardArray *ovrLeaderboardArrayHandle;

OVRP_PUBLIC_FUNCTION(ovrLeaderboardHandle) ovr_LeaderboardArray_GetElement(const ovrLeaderboardArrayHandle obj, size_t index);
OVRP_PUBLIC_FUNCTION(const char *)         ovr_LeaderboardArray_GetNextUrl(const ovrLeaderboardArrayHandle obj);
OVRP_PUBLIC_FUNCTION(size_t)               ovr_LeaderboardArray_GetSize(const ovrLeaderboardArrayHandle obj);
OVRP_PUBLIC_FUNCTION(bool)                 ovr_LeaderboardArray_HasNextPage(const ovrLeaderboardArrayHandle obj);

#endif
