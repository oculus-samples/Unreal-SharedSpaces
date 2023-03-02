// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MATCHMAKING_OPTIONS_H
#define OVR_MATCHMAKING_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_RoomJoinPolicy.h"

struct ovrMatchmakingOptions;
typedef struct ovrMatchmakingOptions* ovrMatchmakingOptionsHandle;

OVRP_PUBLIC_FUNCTION(ovrMatchmakingOptionsHandle) ovr_MatchmakingOptions_Create();
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_Destroy(ovrMatchmakingOptionsHandle handle);
/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_SetCreateRoomDataStoreString(ovrMatchmakingOptionsHandle handle, const char* key, const char* value);
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_ClearCreateRoomDataStore(ovrMatchmakingOptionsHandle handle);
/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_SetCreateRoomJoinPolicy(ovrMatchmakingOptionsHandle handle, ovrRoomJoinPolicy value);
/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_SetCreateRoomMaxUsers(ovrMatchmakingOptionsHandle handle, unsigned int value);
/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_AddEnqueueAdditionalUser(ovrMatchmakingOptionsHandle handle, ovrID value);
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_ClearEnqueueAdditionalUsers(ovrMatchmakingOptionsHandle handle);
/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_SetEnqueueDataSettingsInt(ovrMatchmakingOptionsHandle handle, const char* key, int value);
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_SetEnqueueDataSettingsDouble(ovrMatchmakingOptionsHandle handle, const char* key, double value);
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_SetEnqueueDataSettingsString(ovrMatchmakingOptionsHandle handle, const char* key, const char* value);
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_ClearEnqueueDataSettings(ovrMatchmakingOptionsHandle handle);
/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_SetEnqueueIsDebug(ovrMatchmakingOptionsHandle handle, bool value);
/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_MatchmakingOptions_SetEnqueueQueryKey(ovrMatchmakingOptionsHandle handle, const char * value);

#endif
