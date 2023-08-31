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

/// DEPRECATED. Use server-to-server API call instead.
///
/// A message with type ::ovrMessage_Challenges_Create will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_Create(const char *leaderboardName, ovrChallengeOptionsHandle challengeOptions);

/// If the current user has an invite to the challenge, decline the invite
///
/// A message with type ::ovrMessage_Challenges_DeclineInvite will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_DeclineInvite(ovrID challengeID);

/// DEPRECATED. Use server-to-server API call instead.
///
/// A message with type ::ovrMessage_Challenges_Delete will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_Delete(ovrID challengeID);

/// Gets the information for a single challenge
/// \param challengeID The id of the challenge whose entries to return.
///
/// A message with type ::ovrMessage_Challenges_Get will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_Get(ovrID challengeID);

/// Requests a block of challenge entries.
/// \param challengeID The id of the challenge whose entries to return.
/// \param limit Defines the maximum number of entries to return.
/// \param filter By using ovrLeaderboard_FilterFriends, this allows you to filter the returned values to bidirectional followers.
/// \param startAt Defines whether to center the query on the user or start at the top of the challenge.
///
/// A message with type ::ovrMessage_Challenges_GetEntries will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallengeEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_GetEntries(ovrID challengeID, int limit, ovrLeaderboardFilterType filter, ovrLeaderboardStartAt startAt);

/// Requests a block of challenge entries.
/// \param challengeID The id of the challenge whose entries to return.
/// \param limit The maximum number of entries to return.
/// \param afterRank The position after which to start.  For example, 10 returns challenge results starting with the 11th user.
///
/// A message with type ::ovrMessage_Challenges_GetEntriesAfterRank will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeEntryArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallengeEntryArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_GetEntriesAfterRank(ovrID challengeID, int limit, unsigned long long afterRank);

/// Requests a block of challenge entries. Will return only entries matching
/// the user IDs passed in.
/// \param challengeID The id of the challenge whose entries to return.
/// \param limit Defines the maximum number of entries to return.
/// \param startAt Defines whether to center the query on the user or start at the top of the challenge. If this is ovrLeaderboard_StartAtCenteredOnViewer or ovrLeaderboard_StartAtCenteredOnViewerOrTop, then the current user's ID will be automatically added to the query.
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

/// Requests for a list of challenge
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

/// If the current user has permission, join the challenge
///
/// A message with type ::ovrMessage_Challenges_Join will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_Join(ovrID challengeID);

/// If the current user has permission, leave the challenge
///
/// A message with type ::ovrMessage_Challenges_Leave will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_Leave(ovrID challengeID);

/// DEPRECATED. Use server-to-server API call instead.
///
/// A message with type ::ovrMessage_Challenges_UpdateInfo will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrChallengeHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetChallenge().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Challenges_UpdateInfo(ovrID challengeID, ovrChallengeOptionsHandle challengeOptions);

#endif
