// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LEADERBOARDUPDATESTATUS_H
#define OVR_LEADERBOARDUPDATESTATUS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stdbool.h>

/// This object contains information about the status of the request to update
/// the leaderboard.
typedef struct ovrLeaderboardUpdateStatus *ovrLeaderboardUpdateStatusHandle;

/// Whether the leaderboard was updated.
OVRP_PUBLIC_FUNCTION(bool) ovr_LeaderboardUpdateStatus_GetDidUpdate(const ovrLeaderboardUpdateStatusHandle obj);

/// If the leaderboard is updated, this represents the updated challenge IDs.
/// The updated challenge IDs can be used by ovr_Challenges_GetEntries(),
/// ovr_Challenges_GetEntriesAfterRank(), or ovr_Challenges_GetEntriesByIds()
/// APIs.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_LeaderboardUpdateStatus_GetUpdatedChallengeId(const ovrLeaderboardUpdateStatusHandle obj, unsigned int index);

OVRP_PUBLIC_FUNCTION(unsigned int) ovr_LeaderboardUpdateStatus_GetUpdatedChallengeIdsSize(const ovrLeaderboardUpdateStatusHandle obj);

#endif
