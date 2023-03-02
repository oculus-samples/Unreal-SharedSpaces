// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ROOMINVITENOTIFICATION_H
#define OVR_ROOMINVITENOTIFICATION_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

typedef struct ovrRoomInviteNotification *ovrRoomInviteNotificationHandle;

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_RoomInviteNotification_GetID(const ovrRoomInviteNotificationHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_RoomInviteNotification_GetRoomID(const ovrRoomInviteNotificationHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_RoomInviteNotification_GetSenderID(const ovrRoomInviteNotificationHandle obj);

/// DEPRECATED. Will be removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_RoomInviteNotification_GetSentTime(const ovrRoomInviteNotificationHandle obj);


#endif
