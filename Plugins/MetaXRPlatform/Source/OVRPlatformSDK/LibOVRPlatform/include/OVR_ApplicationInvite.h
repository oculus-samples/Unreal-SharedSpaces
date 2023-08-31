// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APPLICATIONINVITE_H
#define OVR_APPLICATIONINVITE_H

#include "OVR_Platform_Defs.h"
#include "OVR_Destination.h"
#include "OVR_Types.h"
#include "OVR_User.h"
#include <stdbool.h>

typedef struct ovrApplicationInvite *ovrApplicationInviteHandle;

/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrDestinationHandle) ovr_ApplicationInvite_GetDestination(const ovrApplicationInviteHandle obj);

/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserHandle) ovr_ApplicationInvite_GetRecipient(const ovrApplicationInviteHandle obj);

OVRP_PUBLIC_FUNCTION(ovrID)        ovr_ApplicationInvite_GetID(const ovrApplicationInviteHandle obj);
OVRP_PUBLIC_FUNCTION(bool)         ovr_ApplicationInvite_GetIsActive(const ovrApplicationInviteHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationInvite_GetLobbySessionId(const ovrApplicationInviteHandle obj);
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationInvite_GetMatchSessionId(const ovrApplicationInviteHandle obj);

#endif
