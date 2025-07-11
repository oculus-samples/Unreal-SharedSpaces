/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PARTYUPDATENOTIFICATION_H
#define OVR_PARTYUPDATENOTIFICATION_H

#include "OVR_Platform_Defs.h"
#include "OVR_PartyUpdateAction.h"
#include "OVR_Types.h"

/// \file
/// The notification about updating a party status information to a
/// participating user. Party Notifications are intended to update the user on
/// various actions that are occurring in the user's party. It can be retrieved
/// using #ovrMessage_Notification_Party_PartyUpdate.
typedef struct ovrPartyUpdateNotification *ovrPartyUpdateNotificationHandle;

/// An enum that specifies the type of action related to the party and user
/// that this notification holds.
///
/// ovrPartyUpdateAction_Join(): The user joined the party.
///
/// ovrPartyUpdateAction_Leave(): The user left the party.
///
/// ovrPartyUpdateAction_Invite(): The user was invited to the party.
///
/// ovrPartyUpdateAction_Uninvite(): The user was uninvited to the party.
OVRP_PUBLIC_FUNCTION(ovrPartyUpdateAction) ovr_PartyUpdateNotification_GetAction(const ovrPartyUpdateNotificationHandle obj);

/// The ID of the party that will be updated. This can be retrieved with
/// ::ovrPartyIDHandle.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_PartyUpdateNotification_GetPartyId(const ovrPartyUpdateNotificationHandle obj);

/// The id of the ::ovrUserHandle who initiated the action that this party
/// update status notification is in reference to. This is equivalent to
/// ovr_User_GetID() for this user.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_PartyUpdateNotification_GetSenderId(const ovrPartyUpdateNotificationHandle obj);

/// A timestamp denoting when the party action occurred that this status update
/// notification refers to.
OVRP_PUBLIC_FUNCTION(const char *) ovr_PartyUpdateNotification_GetUpdateTimestamp(const ovrPartyUpdateNotificationHandle obj);

/// The alias of the ::ovrUserHandle whose party status has changed. This is an
/// alias that is set by the user.
OVRP_PUBLIC_FUNCTION(const char *) ovr_PartyUpdateNotification_GetUserAlias(const ovrPartyUpdateNotificationHandle obj);

/// The ID of the user, ovr_User_GetID(), whose party status has changed. This
/// is a unique value for every ::ovrUserHandle.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_PartyUpdateNotification_GetUserId(const ovrPartyUpdateNotificationHandle obj);

/// The displayable name of the ::ovrUserHandle whose party status has changed.
/// This is equivalent to ovr_User_GetDisplayName() for this user.
OVRP_PUBLIC_FUNCTION(const char *) ovr_PartyUpdateNotification_GetUserName(const ovrPartyUpdateNotificationHandle obj);


#endif
