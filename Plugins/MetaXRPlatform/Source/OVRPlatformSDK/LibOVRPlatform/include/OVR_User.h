// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USER_H
#define OVR_USER_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include "OVR_UserPresenceStatus.h"

typedef struct ovrUser *ovrUserHandle;

/// A potentially non unique displayable name chosen by the user. Could also be
/// the same as the oculus_ID
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetDisplayName(const ovrUserHandle obj);

/// Human readable string of what the user is currently doing. Not intended to
/// be parsed as it might change at anytime or be translated
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresence(const ovrUserHandle obj);

/// Intended to be parsed and used to deeplink to parts of the app
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresenceDeeplinkMessage(const ovrUserHandle obj);

/// If provided, the destination this user is currently at in the app
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresenceDestinationApiName(const ovrUserHandle obj);

/// If provided, the lobby session this user is currently at in the app
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresenceLobbySessionId(const ovrUserHandle obj);

/// If provided, the match session this user is currently at in the app
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetPresenceMatchSessionId(const ovrUserHandle obj);

/// Enum value of what the user is currently doing.
OVRP_PUBLIC_FUNCTION(ovrUserPresenceStatus) ovr_User_GetPresenceStatus(const ovrUserHandle obj);

OVRP_PUBLIC_FUNCTION(ovrID)        ovr_User_GetID(const ovrUserHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetImageUrl(const ovrUserHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetOculusID(const ovrUserHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_User_GetSmallImageUrl(const ovrUserHandle obj);

#endif
