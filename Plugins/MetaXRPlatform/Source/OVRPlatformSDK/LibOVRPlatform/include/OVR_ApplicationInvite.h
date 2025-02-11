// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APPLICATIONINVITE_H
#define OVR_APPLICATIONINVITE_H

#include "OVR_Platform_Defs.h"
#include "OVR_Destination.h"
#include "OVR_Types.h"
#include "OVR_User.h"
#include <stdbool.h>

/// An Application Invite contains information about the invite, including the
/// application ID, destination, activity status, the lobby session id, the
/// match session id, and recipient's user id or user alias. If the invite is
/// generated from rich presence, the lobby/match session id will be auto
/// populated by calling ovr_User_GetPresenceLobbySessionId() and
/// ovr_User_GetPresenceMatchSessionId() from the inviter's viewer context.
typedef struct ovrApplicationInvite *ovrApplicationInviteHandle;

/// The destination to which the recipient is invited.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrDestinationHandle) ovr_ApplicationInvite_GetDestination(const ovrApplicationInviteHandle obj);

/// The ID of the application invite.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_ApplicationInvite_GetID(const ovrApplicationInviteHandle obj);

/// A boolean value indicating whether the invite is still active or not.
OVRP_PUBLIC_FUNCTION(bool) ovr_ApplicationInvite_GetIsActive(const ovrApplicationInviteHandle obj);

/// The lobby session id to which the recipient is invited. You can retrieve
/// this by calling ovr_User_GetPresenceLobbySessionId() from the inviter's
/// viewer context.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationInvite_GetLobbySessionId(const ovrApplicationInviteHandle obj);

/// The match session id to which the recipient is invited. You can retrieve
/// this by calling ovr_User_GetPresenceMatchSessionId() from the inviter's
/// viewer context.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationInvite_GetMatchSessionId(const ovrApplicationInviteHandle obj);

/// The recipient's user information, such as their ID and alias. You can get
/// the ID of an user by calling ovr_User_GetID().
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserHandle) ovr_ApplicationInvite_GetRecipient(const ovrApplicationInviteHandle obj);


#endif
