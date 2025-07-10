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

#ifndef OVR_REQUESTS_CHALLENGES_H
#define OVR_REQUESTS_CHALLENGES_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_ChallengeArray.h"
#include "OVR_ChallengeEntryArray.h"
#include "OVR_ChallengeOptions.h"
#include "OVR_LeaderboardFilterType.h"
#include "OVR_LeaderboardStartAt.h"
#include <stdbool.h>


/// \file
/// The Challenges API enhances social interactions in your app, which use
/// ovr_GroupPresence_SetDestination() to create shareable links for score-
/// based competition. Players can repeatedly challenge others, get to know
/// them, and compete asynchronously. Challenges can be ranked by
/// highest/lowest scores within a time period. Leaderboard-integrated apps get
/// Challenges for free, accessible through the Scoreboards UI. Players can
/// create and invite others to Challenges via the Challenges app.

/// \param leaderboardName A string represents the name of the leaderboard.
/// \param challengeOptions This indicates the options of the challenge and it can be retrieved by ovr_ChallengeOptions_Create().
/// \deprecated Use server-to-server API call instead.
///
/// A message with type ::ovrMessage_Challenges_Create will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_Create(const char *leaderboardName, ovrChallengeOptionsHandle challengeOptions);

/// If the current user has the necessary permissions, they can decline a
/// challenge by providing the challenge ID, which can be obtained using
/// ovr_Challenge_GetID().
/// \param challengeID The ID of challenge that the user is going to decline. It can be retrieved by ovr_Challenge_GetID().
///
/// A message with type ::ovrMessage_Challenges_DeclineInvite will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_DeclineInvite(ovrID challengeID);

/// \param challengeID The uuid of the challenge.
/// \deprecated Use server-to-server API call instead.
///
/// A message with type ::ovrMessage_Challenges_Delete will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_Delete(ovrID challengeID);

/// Gets detailed information for a single challenge by providing the challenge
/// ID, which can be retrieved by calling ovr_Challenge_GetID().
/// \param challengeID The id of the challenge whose entries to return, which can be retrieved by calling ovr_Challenge_GetID().
///
/// A message with type ::ovrMessage_Challenges_Get will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_Get(ovrID challengeID);

/// Retrieves a list of entries for a specific challenge, with options to
/// filter and limit the results. By providing the challengeID, you can specify
/// which challenge's entries you want to retrieve. The limit parameter allows
/// you to control the number of entries returned. The filter parameter enables
/// you to refine the results to only include entries from users who are
/// bidirectional followers. The startAt parameter allows you to define whether
/// to center the query on the user or start at the top of the challenge.
/// \param challengeID The id of the challenge whose entries to return, which can be retrieved by calling ovr_Challenge_GetID().
/// \param limit Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
/// \param filter By using the ovrLeaderboardFilterType(), you can refine the results to only include entries from users who are bidirectional followers.
/// \param startAt Defines whether to center the query on the user or start at the top of the challenge. If this is ovrLeaderboard_StartAtCenteredOnViewer() or ovrLeaderboard_StartAtCenteredOnViewerOrTop(), then the current user's ID will be automatically added to the query.
///
/// A message with type ::ovrMessage_Challenges_GetEntries will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallengeEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_GetEntries(ovrID challengeID, int limit, ovrLeaderboardFilterType filter, ovrLeaderboardStartAt startAt);

/// Returns a list of entries for a specific challenge, starting from a
/// specified rank. By providing the challengeID and rank, you can specify
/// which challenge's entries you want to retrieve and where to start the
/// query. The limit parameter allows you to control the number of entries
/// returned.
/// \param challengeID The id of the challenge whose entries to return, which can be retrieved by calling ovr_Challenge_GetID().
/// \param limit Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
/// \param afterRank The position after which to start. For example, 10 returns challenge results starting with the 11th user.
///
/// A message with type ::ovrMessage_Challenges_GetEntriesAfterRank will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallengeEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_GetEntriesAfterRank(ovrID challengeID, int limit, unsigned long long afterRank);

/// Retrieves a list of challenge entries for a specific set of user IDs, with
/// options to filter and limit the results. This method is useful for
/// retrieving a list of challenge entries for a specific set of users,
/// allowing you to display their progress and rankings within the challenge.
/// \param challengeID The id of the challenge whose entries to return, which can be retrieved by calling ovr_Challenge_GetID().
/// \param limit Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
/// \param startAt Defines whether to center the query on the user or start at the top of the challenge. If this is ovrLeaderboard_StartAtCenteredOnViewer() or ovrLeaderboard_StartAtCenteredOnViewerOrTop(), then the current user's ID will be automatically added to the query.
/// \param userIDs Defines a list of user ids to get entries for.
/// \param userIDLength The number of user IDs provided.
///
/// A message with type ::ovrMessage_Challenges_GetEntriesByIds will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallengeEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_GetEntriesByIds(ovrID challengeID, int limit, ovrLeaderboardStartAt startAt, ovrID *userIDs, unsigned int userIDLength);

/// Returns a list of challenges that match the specified options. The
/// ovr_ChallengeOptions_Create() parameter allows you to specify the criteria
/// for the challenges you want to retrieve. The limit parameter allows you to
/// control the number of challenges returned.
/// \param challengeOptions This indicates the options of the challenge and it can be retrieved by ovr_ChallengeOptions_Create().
/// \param limit Sets a limit on the maximum number of challenges to be fetched, which can be useful for pagination or performance reasons.
///
/// A message with type ::ovrMessage_Challenges_GetList will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallengeArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_GetList(ovrChallengeOptionsHandle challengeOptions, int limit);

/// Requests the next block of challenges.
/// \param handle The return value from ovr_Message_GetChallengeArray().
///
/// A message with type ::ovrMessage_Challenges_GetNextChallenges will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallengeArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_GetNextChallenges(const ovrChallengeArrayHandle handle);

/// Requests the next block of challenge entries.
/// \param handle The return value from ovr_Message_GetChallengeEntryArray().
///
/// A message with type ::ovrMessage_Challenges_GetNextEntries will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallengeEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_GetNextEntries(const ovrChallengeEntryArrayHandle handle);

/// Requests the previous block of challenges.
/// \param handle The return value from ovr_Message_GetChallengeArray().
///
/// A message with type ::ovrMessage_Challenges_GetPreviousChallenges will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallengeArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_GetPreviousChallenges(const ovrChallengeArrayHandle handle);

/// Requests the previous block of challenge entries.
/// \param handle The return value from ovr_Message_GetChallengeEntryArray().
///
/// A message with type ::ovrMessage_Challenges_GetPreviousEntries will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallengeEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_GetPreviousEntries(const ovrChallengeEntryArrayHandle handle);

/// If the current user has the necessary permissions to join, participate in a
/// challenge by providing the challenge ID, which can be retrieved using
/// ovr_Challenge_GetID().
/// \param challengeID The ID of challenge that the user is going to join. It can be retrieved by ovr_Challenge_GetID().
///
/// A message with type ::ovrMessage_Challenges_Join will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_Join(ovrID challengeID);

/// If the current user has the necessary permissions, they can leave a
/// challenge by providing the challenge ID, which can be obtained using
/// ovr_Challenge_GetID().
/// \param challengeID The ID of challenge that the user is going to leave. It can be retrieved by ovr_Challenge_GetID().
///
/// A message with type ::ovrMessage_Challenges_Leave will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_Leave(ovrID challengeID);

/// \param challengeID The uuid of the challenge.
/// \param challengeOptions This indicates the options of the challenge and it can be retrieved by ovr_ChallengeOptions_Create().
/// \deprecated Use server-to-server API call instead.
///
/// A message with type ::ovrMessage_Challenges_UpdateInfo will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_UpdateInfo(ovrID challengeID, ovrChallengeOptionsHandle challengeOptions);

#endif
