// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_GROUPPRESENCEJOININTENT_H
#define OVR_GROUPPRESENCEJOININTENT_H

#include "OVR_Platform_Defs.h"

typedef struct ovrGroupPresenceJoinIntent *ovrGroupPresenceJoinIntentHandle;

/// An opaque string provided by the developer to help them deeplink to
/// content.
OVRP_PUBLIC_FUNCTION(const char *) ovr_GroupPresenceJoinIntent_GetDeeplinkMessage(const ovrGroupPresenceJoinIntentHandle obj);

/// If populated, the destination the current user wants to go to
OVRP_PUBLIC_FUNCTION(const char *) ovr_GroupPresenceJoinIntent_GetDestinationApiName(const ovrGroupPresenceJoinIntentHandle obj);

/// If populated, the lobby session the current user wants to go to
OVRP_PUBLIC_FUNCTION(const char *) ovr_GroupPresenceJoinIntent_GetLobbySessionId(const ovrGroupPresenceJoinIntentHandle obj);

/// If populated, the match session the current user wants to go to
OVRP_PUBLIC_FUNCTION(const char *) ovr_GroupPresenceJoinIntent_GetMatchSessionId(const ovrGroupPresenceJoinIntentHandle obj);


#endif
