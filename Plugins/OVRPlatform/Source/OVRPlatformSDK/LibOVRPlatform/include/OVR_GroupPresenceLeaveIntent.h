// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_GROUPPRESENCELEAVEINTENT_H
#define OVR_GROUPPRESENCELEAVEINTENT_H

#include "OVR_Platform_Defs.h"

typedef struct ovrGroupPresenceLeaveIntent *ovrGroupPresenceLeaveIntentHandle;

/// If populated, the destination the current user wants to leave
OVRP_PUBLIC_FUNCTION(const char *) ovr_GroupPresenceLeaveIntent_GetDestinationApiName(const ovrGroupPresenceLeaveIntentHandle obj);

/// If populated, the lobby session the current user wants to leave
OVRP_PUBLIC_FUNCTION(const char *) ovr_GroupPresenceLeaveIntent_GetLobbySessionId(const ovrGroupPresenceLeaveIntentHandle obj);

/// If populated, the match session the current user wants to leave
OVRP_PUBLIC_FUNCTION(const char *) ovr_GroupPresenceLeaveIntent_GetMatchSessionId(const ovrGroupPresenceLeaveIntentHandle obj);


#endif
