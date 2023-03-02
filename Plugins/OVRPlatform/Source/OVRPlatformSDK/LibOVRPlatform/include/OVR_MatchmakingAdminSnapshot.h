// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MATCHMAKINGADMINSNAPSHOT_H
#define OVR_MATCHMAKINGADMINSNAPSHOT_H

#include "OVR_Platform_Defs.h"
#include "OVR_MatchmakingAdminSnapshotCandidateArray.h"

typedef struct ovrMatchmakingAdminSnapshot *ovrMatchmakingAdminSnapshotHandle;

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(ovrMatchmakingAdminSnapshotCandidateArrayHandle) ovr_MatchmakingAdminSnapshot_GetCandidates(const ovrMatchmakingAdminSnapshotHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(double) ovr_MatchmakingAdminSnapshot_GetMyCurrentThreshold(const ovrMatchmakingAdminSnapshotHandle obj);


#endif
