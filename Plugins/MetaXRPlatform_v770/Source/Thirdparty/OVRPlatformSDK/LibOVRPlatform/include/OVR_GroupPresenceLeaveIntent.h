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

#ifndef OVR_GROUPPRESENCELEAVEINTENT_H
#define OVR_GROUPPRESENCELEAVEINTENT_H

#include "OVR_Platform_Defs.h"

/// \file
/// An GroupPresenceLeaveIntent represents a user's intent to leave a group
/// presence which is user's presence to be at a ::ovrDestinationHandle and
/// session. People with same session id are considered to be co-present
/// together. Every combination of destination api name, lobby session id and
/// match session id can uniquely identify a destination.
typedef struct ovrGroupPresenceLeaveIntent *ovrGroupPresenceLeaveIntentHandle;

/// ovr_Destination_GetApiName() is the unique API Name that refers to an in-
/// app destination.
OVRP_PUBLIC_FUNCTION(const char *) ovr_GroupPresenceLeaveIntent_GetDestinationApiName(const ovrGroupPresenceLeaveIntentHandle obj);

/// This is the match session that the current user wants to leave. A lobby
/// session is a session ID that represents a closer group/squad/party of
/// users. It is expected that all users with the same lobby session id can see
/// or hear each other. Users with the same lobby session id in their group
/// presence will show up in the roster and will show up as "Recently Played
/// With" for future invites if they aren't already Oculus friends.
OVRP_PUBLIC_FUNCTION(const char *) ovr_GroupPresenceLeaveIntent_GetLobbySessionId(const ovrGroupPresenceLeaveIntentHandle obj);

/// This is the match session that the current user wants to leave. A match
/// session represents all the users that are playing a specific instance of a
/// map, game mode, round, etc. This can include users from multiple different
/// lobbies that joined together and the users may or may not remain together
/// after the match is over.
OVRP_PUBLIC_FUNCTION(const char *) ovr_GroupPresenceLeaveIntent_GetMatchSessionId(const ovrGroupPresenceLeaveIntentHandle obj);


#endif
