// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MATCHMAKINGROOMARRAY_H
#define OVR_MATCHMAKINGROOMARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_MatchmakingRoom.h"
#include <stddef.h>

typedef struct ovrMatchmakingRoomArray *ovrMatchmakingRoomArrayHandle;

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(ovrMatchmakingRoomHandle) ovr_MatchmakingRoomArray_GetElement(const ovrMatchmakingRoomArrayHandle obj, size_t index);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(size_t) ovr_MatchmakingRoomArray_GetSize(const ovrMatchmakingRoomArrayHandle obj);


#endif
