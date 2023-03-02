// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MATCHMAKINGROOM_H
#define OVR_MATCHMAKINGROOM_H

#include "OVR_Platform_Defs.h"
#include "OVR_Room.h"
#include <stdbool.h>

typedef struct ovrMatchmakingRoom *ovrMatchmakingRoomHandle;

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_MatchmakingRoom_GetPingTime(const ovrMatchmakingRoomHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(ovrRoomHandle) ovr_MatchmakingRoom_GetRoom(const ovrMatchmakingRoomHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(bool) ovr_MatchmakingRoom_HasPingTime(const ovrMatchmakingRoomHandle obj);


#endif
