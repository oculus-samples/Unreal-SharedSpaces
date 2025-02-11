// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PARTYUPDATENOTIFICATION_H
#define OVR_PARTYUPDATENOTIFICATION_H

#include "OVR_Platform_Defs.h"
#include "OVR_PartyUpdateAction.h"
#include "OVR_Types.h"

/// The notification about updating a party status information to a
/// participating user. Party Notifications are intended to update the user on
/// various actions that are occurring in the user's party. This is primarily
/// used in {'party_update': 'ovrNotification_Party_PartyUpdate'}.
typedef struct ovrPartyUpdateNotification *ovrPartyUpdateNotificationHandle;

/// An enum that specifies the type of action related to the party and user
/// that this notification holds. It can be retrieved by using
/// ovr_PartyUpdateNotification_GetAction().
///
/// ovrPartyUpdateAction_Join: The user is going to join the party.
///
/// ovrPartyUpdateAction_Leave: The user is going to leave the party.
///
/// ovrPartyUpdateAction_Invite: The user is invited to the party.
///
/// ovrPartyUpdateAction_Uninvite: The user is uninvited from the party.
OVRP_PUBLIC_FUNCTION(ovrPartyUpdateAction) ovr_PartyUpdateNotification_GetAction(const ovrPartyUpdateNotificationHandle obj);

/// The ID of the party that will be updated. This can be retrieved with
/// ovrPartyIDHandle.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_PartyUpdateNotification_GetPartyId(const ovrPartyUpdateNotificationHandle obj);

/// The id of the ovrUserHandle who initiated the action that this party update
/// status notification is in reference to. This is equivalent to
/// ovr_User_GetID() for this user.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_PartyUpdateNotification_GetSenderId(const ovrPartyUpdateNotificationHandle obj);

/// A timestamp denoting when the party action occurred that this status update
/// notification refers to.
OVRP_PUBLIC_FUNCTION(const char *) ovr_PartyUpdateNotification_GetUpdateTimestamp(const ovrPartyUpdateNotificationHandle obj);

/// The alias of the ovrUserHandle whose party status has changed. This is an
/// alias that is set by the user.
OVRP_PUBLIC_FUNCTION(const char *) ovr_PartyUpdateNotification_GetUserAlias(const ovrPartyUpdateNotificationHandle obj);

/// The ID of the user, ovr_User_GetID(), whose party status has changed. This
/// is a unique value for every ovrUserHandle.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_PartyUpdateNotification_GetUserId(const ovrPartyUpdateNotificationHandle obj);

/// The displayable name of the ovrUserHandle whose party status has changed.
/// This is equivalent to ovr_User_GetDisplayName() for this user.
OVRP_PUBLIC_FUNCTION(const char *) ovr_PartyUpdateNotification_GetUserName(const ovrPartyUpdateNotificationHandle obj);


#endif
