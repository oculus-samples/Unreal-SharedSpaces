// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MATCHMAKINGENQUEUERESULTANDROOM_H
#define OVR_MATCHMAKINGENQUEUERESULTANDROOM_H

#include "OVR_Platform_Defs.h"
#include "OVR_MatchmakingEnqueueResult.h"
#include "OVR_Room.h"

typedef struct ovrMatchmakingEnqueueResultAndRoom *ovrMatchmakingEnqueueResultAndRoomHandle;

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(ovrMatchmakingEnqueueResultHandle) ovr_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult(const ovrMatchmakingEnqueueResultAndRoomHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(ovrRoomHandle) ovr_MatchmakingEnqueueResultAndRoom_GetRoom(const ovrMatchmakingEnqueueResultAndRoomHandle obj);


#endif
