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

#ifndef OVR_REQUESTS_PARTY_H
#define OVR_REQUESTS_PARTY_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// \file
/// # Overview
///
/// Parties are groups that can communicate and easily move across different
/// app experiences together. Users in parties will have a System VoIP connection
/// allowing them to talk to everyone in their party. Users can only be in
/// a single party at a time, but they are not necessarily always in a party.
/// Parties are primarily intended to be a system that allows users to more easily
/// communicate and organize meetings with their friends in VR.
///
/// # Fields
///
/// ## Users
///
/// It's possible to fetch the list of users in a room with `ovr_Party_GetUsers`.
///
/// ## Invited Users
///
/// It's possible to fetch a list of all currently invited users with
/// `ovr_Party_GetInvitedUsers`.


/// \file
/// The party API allows you to retrieve information about parties and manage
/// various interactions between users and their respective ::ovrPartyHandle.
/// Calling ovr_Party_GetCurrent() with a party ID will grab the Party object
/// and the associated metadata.

/// Load the current party the current ::ovrUserHandle is in. The returned
/// ::ovrPartyHandle will then contain information about other users in the
/// party and invited users.
///
/// A message with type ::ovrMessage_Party_GetCurrent will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrPartyHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetParty().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Party_GetCurrent();

#endif
