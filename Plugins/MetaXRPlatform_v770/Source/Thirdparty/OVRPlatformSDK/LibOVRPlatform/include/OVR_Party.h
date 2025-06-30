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

#ifndef OVR_PARTY_H
#define OVR_PARTY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include "OVR_User.h"
#include "OVR_UserArray.h"

/// \file
/// Parties allow users to start a voice chat with other members of the party.
/// Party voice chats persist across apps in VR and users can continue to
/// interact while navigating between apps. You can use ovr_Party_GetCurrent()
/// to load the party the current user is in.
typedef struct ovrParty *ovrPartyHandle;

/// A unique identifier of this party.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_Party_GetID(const ovrPartyHandle obj);

/// An array of users who are invited to this party. These users are not a part
/// of the party yet but have been invited.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_Party_GetInvitedUsers(const ovrPartyHandle obj);

/// The user who initialized this party. It's also the first user who joined
/// the party. The leader can invite and kick other users.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserHandle) ovr_Party_GetLeader(const ovrPartyHandle obj);

/// An array that contains the users who are currently in this party. These
/// users will remain in the party while navigating between apps. Each user in
/// the party will get the update by #ovrMessage_Notification_Party_PartyUpdate
/// which is intended to update the user on various actions that are occurring
/// in the party.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_Party_GetUsers(const ovrPartyHandle obj);


#endif
