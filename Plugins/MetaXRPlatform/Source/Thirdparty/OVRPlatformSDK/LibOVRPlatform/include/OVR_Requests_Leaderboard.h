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

#ifndef OVR_REQUESTS_LEADERBOARD_H
#define OVR_REQUESTS_LEADERBOARD_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_LeaderboardArray.h"
#include "OVR_LeaderboardArray.h"
#include "OVR_LeaderboardEntryArray.h"
#include "OVR_LeaderboardFilterType.h"
#include "OVR_LeaderboardStartAt.h"
#include <stdbool.h>

/// \file
/// # Leaderboard Overview
///
/// Leaderboards are a way for a game to keep track of all the players and their scores in relation to other.
///
/// For example, in a racing game, for a specific track you might have a leaderboard for the fastest lap time
/// (where the lowest time is on top), and a leaderboard for the most number of wins (where the largest value
/// is on top).  A game may have many different leaderboards.
///
/// Leaderboards are requested by name and will return an array of the entries
/// in a leaderboard up to a specified limit.  Leaderboards can be set to consider if
/// a better score is one that is higher or lower.  When updating an entry on a
/// leaderboard with a new score, the previous entry will not be updated unless the
/// score is considered better than the old score.  This can be overridden by forcing
/// the score to update regardless if the new score is better than the old score or not.
///
/// ## Creating New Leaderboards
///
/// Leaderboards can be created through https://dashboard.oculus.com/application/[YOUR_APP_ID]/leaderboards
/// The API Name is how a leaderboard is requested through the client. A leaderboard can be set to consider
/// if a better score is one that is higher or lower.
///
/// ## Leaderboard Objects
///
/// The API exposes Leaderboards as an array of Leaderboard Entries.
///
/// ### Leaderboard Entry
///
/// A Leaderboard Entry represents a player's score and rank in a particular
/// leaderboard.  They comprise of a User object who the entry belongs to, the score,
/// their absolute rank in the leaderboard, the last time the entry was update, as well
/// as optional extra data that can be used to store extra data about the entry.
///
/// ### Leaderboard Filter Types
///
/// Leaderboards can be filtered to return a subset of players:
///
/// `ovrLeaderboard_FilterNone`
/// This will return all players in a leaderboard
///
/// `ovrLeaderboard_FilterFriends`
/// This will return only players who are bidirectional followers of the current player in a leaderboard.
/// The rank of the bidirectional followers returned will still show their absolute rank.
/// Example: If I have 1 bidirectional follower and he's rank 8th overall, his rank will still come back as
/// 8 with the Friends filter on and not 1.
///
/// ### Leaderboard Start At Types
///
/// When you first request for a Leaderboard, you have the option of specifying where
/// to start from.
///
/// `ovrLeaderboard_StartAtTop`
/// This is the default behavior and will return results starting from the player that is ranked
/// 1st on the leaderboard.  This can be combined with the filter types to get a more specific set
/// of entries.
///
/// `ovrLeaderboard_StartAtCenteredOnViewer`
/// This filter will try to start from the viewer's rank on the leaderboard and center the
/// leaderboard entries around that.  Example:  If the viewer is rank 9th and the request is to
/// fetch 3 entries centered on the viewer, it'll return the entries ranked 8th, 9th, and 10th.
/// If the viewer is not ranked on the requested leaderboard, this will return an error.  This can
/// be combined with the filter types to get a more specific set of entries.
///
/// `ovr_Leaderboard_GetEntriesAfterRank()`
/// Alternatively a leaderboard can be request to fetch results after a specific rank.  Example: If
/// a leaderboard is requested to get 3 entries after the 5th rank, it'll return entries ranked 6th,
/// 7th, and 8th.  No filters can be applied when requesting entries after a specific rank.
///
/// ### Leaderboard Paging
///
/// Unless there are very few players in a leaderboard, the requests will only return a subset of
/// entries.  If there are more entries after the returning array of entries, additional entries
/// can be requested through paging.  Leaderboard entries can be paged backwards and forwards.  The
/// initial filter and limits will still apply when paging through the entries.
///
/// Example: if a leaderboard was requested with the ovrLeaderboard_FilterFriends filter and a limit of 5, paging to the next entries
/// will return the next 5 bidirectional followers
///
///   // Initally request to grab the top 5 bidirectional followers from "MyLeaderboard"
///   ovr_Leaderboard_GetEntries("MyLeaderboard", 5, ovrLeaderboard_FilterFriends, ovrLeaderboard_StartAtTop);
///
///   ...
///
///   // Keep getting 5 bidirectional followers at a time in a loop
///   ovrMessage* message = nullptr;
///   while ((message = ovr_PopMessage() != nullptr) {
///     if (ovr_Message_GetType(message) == ovrMessageLeaderboard_GetEntries) {
///       // Get the leaderboards
///       ovrLeaderboardEntryArrayHandle leaderboard = ovr_Message_GetLeaderboardEntryArray(message);
///
///       // Do Stuff with the leaderboard
///
///       // If there's more, keep fetching
///       if (ovr_LeaderboardEntry_Array_HasNextPage(leaderboard) {
///         // Grabs the next 5 bidirectional followers
///         ovr_Leaderboard_GetNextEntries(leaderboard);
///       }
///     }
///   }


/// \file
/// The Leaderboards API provides a way to manage and interact with
/// leaderboards in your application. The API allows you to retrieve
/// information about a single leaderboard, write entries to a leaderboard, and
/// retrieve blocks of leaderboard entries based on different criterias.
/// Leaderboard-integrated apps get Challenges for free, accessible through the
/// Scoreboards UI. Visit our
/// [website](https://developer.oculus.com/documentation/native/ps-
/// leaderboards/) for more information about leaderboards.

/// Retrieves detailed information for a single leaderboard with a specified
/// name, returning an array of ::ovrLeaderboardHandle.
/// \param leaderboardName The name of the leaderboard to retrieve.
///
/// A message with type ::ovrMessage_Leaderboard_Get will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLeaderboardArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLeaderboardArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Leaderboard_Get(const char *leaderboardName);

/// Retrieves a list of leaderboard entries for a specified leaderboardName,
/// with options to filter and limit the number of results returned.
/// \param leaderboardName The name of the leaderboard from which to retrieve entries.
/// \param limit Specifies the maximum number of entries to be returned.
/// \param filter By using ovrLeaderboard_FilterFriends, this allows you to filter the returned values to bidirectional followers.
/// \param startAt Defines whether to center the query on the user or start at the top of the leaderboard.
///
/// <b>Error codes</b>
/// - \b 100: Parameter {parameter}: invalid user id: {user_id}
/// - \b 100: Something went wrong.
/// - \b 12074: You're not yet ranked on this leaderboard.
///
/// A message with type ::ovrMessage_Leaderboard_GetEntries will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLeaderboardEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLeaderboardEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Leaderboard_GetEntries(const char *leaderboardName, int limit, ovrLeaderboardFilterType filter, ovrLeaderboardStartAt startAt);

/// Retrieves a block of leaderboard entries starting from a specific rank.
/// \param leaderboardName The name of the leaderboard from which to retrieve entries.
/// \param limit The maximum number of entries to return.
/// \param afterRank The position after which to start.  For example, 10 returns leaderboard results starting with the 11th user.
///
/// A message with type ::ovrMessage_Leaderboard_GetEntriesAfterRank will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLeaderboardEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLeaderboardEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Leaderboard_GetEntriesAfterRank(const char *leaderboardName, int limit, unsigned long long afterRank);

/// Retrieves a block of leaderboard entries that match the specified user IDs.
/// Only entries corresponding to the provided user IDs will be returned.
/// \param leaderboardName The name of the leaderboard from which to retrieve entries.
/// \param limit The maximum number of entries to return.
/// \param startAt Defines whether to center the query on the user or start at the top of the leaderboard. If this is ovrLeaderboard_StartAtCenteredOnViewer() or ovrLeaderboard_StartAtCenteredOnViewerOrTop(), then the current user's ID will be automatically added to the query.
/// \param userIDs Defines a list of user ids to get entries for.
/// \param userIDLength The number of user IDs provided.
///
/// A message with type ::ovrMessage_Leaderboard_GetEntriesByIds will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLeaderboardEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLeaderboardEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Leaderboard_GetEntriesByIds(const char *leaderboardName, int limit, ovrLeaderboardStartAt startAt, ovrID *userIDs, unsigned int userIDLength);

/// Requests the next block of leaderboard entries.
/// \param handle The return value from ovr_Message_GetLeaderboardEntryArray().
///
/// A message with type ::ovrMessage_Leaderboard_GetNextEntries will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLeaderboardEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLeaderboardEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Leaderboard_GetNextEntries(const ovrLeaderboardEntryArrayHandle handle);

/// Get the next page of entries
/// \param handle The handle to the array to get the next page of entries.
///
/// A message with type ::ovrMessage_Leaderboard_GetNextLeaderboardArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLeaderboardArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLeaderboardArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Leaderboard_GetNextLeaderboardArrayPage(ovrLeaderboardArrayHandle handle);

/// Requests the previous block of leaderboard entries.
/// \param handle The return value from ovr_Message_GetLeaderboardEntryArray().
///
/// A message with type ::ovrMessage_Leaderboard_GetPreviousEntries will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLeaderboardEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLeaderboardEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Leaderboard_GetPreviousEntries(const ovrLeaderboardEntryArrayHandle handle);

/// Writes a single entry to the leaderboard, returning
/// ::ovrLeaderboardUpdateStatusHandle indicating whether the update was
/// successful and providing the updated challenge IDs.
/// \param leaderboardName The name of the leaderboard to which the entry should be written.
/// \param score The score to be written in the leaderboard.
/// \param extraData A 2KB custom data field that is associated with the leaderboard entry. This can be a game replay or any additional information that provides more context about the entry for the viewer.
/// \param extraDataLength The length of the extra data.
/// \param forceUpdate If true, the score always updates.  This happens even if it is not the user's best score.
///
/// <b>Error codes</b>
/// - \b 100: Parameter {parameter}: invalid user id: {user_id}
/// - \b 100: Something went wrong.
/// - \b 100: This leaderboard entry is too late for the leaderboard's allowed time window.
///
/// A message with type ::ovrMessage_Leaderboard_WriteEntry will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLeaderboardUpdateStatusHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLeaderboardUpdateStatus().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Leaderboard_WriteEntry(const char *leaderboardName, long long score, const void *extraData, unsigned int extraDataLength, bool forceUpdate);

/// Writes a single entry to a leaderboard which can include supplementary
/// metrics, returning ::ovrLeaderboardUpdateStatusHandle indicating whether
/// the update was successful and providing the updated challenge IDs.
/// \param leaderboardName The name of the leaderboard to which the entry should be written.
/// \param score The score to be written in the leaderboard.
/// \param supplementaryMetric Supplemental piece of data that can be used for tiebreakers.
/// \param extraData A 2KB custom data field that is associated with the leaderboard entry. This can be a game replay or any additional information that provides more context about the entry for the viewer.
/// \param extraDataLength The length of the extra data.
/// \param forceUpdate If true, the score always updates. This happens even if it is not the user's best score.
///
/// <b>Error codes</b>
/// - \b 100: Parameter {parameter}: invalid user id: {user_id}
/// - \b 100: Something went wrong.
/// - \b 100: This leaderboard entry is too late for the leaderboard's allowed time window.
///
/// A message with type ::ovrMessage_Leaderboard_WriteEntryWithSupplementaryMetric will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLeaderboardUpdateStatusHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLeaderboardUpdateStatus().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Leaderboard_WriteEntryWithSupplementaryMetric(const char *leaderboardName, long long score, long long supplementaryMetric, const void *extraData, unsigned int extraDataLength, bool forceUpdate);

#endif
