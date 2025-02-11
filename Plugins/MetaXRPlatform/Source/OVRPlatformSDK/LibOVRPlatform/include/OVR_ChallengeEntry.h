// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGEENTRY_H
#define OVR_CHALLENGEENTRY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include "OVR_User.h"

/// A challenge entry object contains information about an individual entry
/// within a challenge such as the user who made the entry, the score achieved,
/// and other relevant details. It's the array element type of
/// ovrChallengeEntryArrayHandle and can be retrieved using
/// ovr_Challenges_GetEntries().
typedef struct ovrChallengeEntry *ovrChallengeEntryHandle;

/// A displayable score for this challenge entry. The score is formatted with
/// thousands separators and the relevant units are appended based on the
/// associated leaderboard's score type.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ChallengeEntry_GetDisplayScore(const ovrChallengeEntryHandle obj);

/// A 2KB custom data field that is associated with the challenge entry.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ChallengeEntry_GetExtraData(const ovrChallengeEntryHandle obj);

/// The unique identifier of this challenge entry which can be used by
/// ovr_Challenges_GetEntriesByIds() and ovr_Challenges_GetEntries().
OVRP_PUBLIC_FUNCTION(ovrID) ovr_ChallengeEntry_GetID(const ovrChallengeEntryHandle obj);

/// Challenges can be ranked by highest or lowest scores within a time period.
/// This indicates the position of this challenge entry.
OVRP_PUBLIC_FUNCTION(int) ovr_ChallengeEntry_GetRank(const ovrChallengeEntryHandle obj);

/// The raw underlying value of the challenge entry score. It is a type of
/// string that is returned by a long integer.
OVRP_PUBLIC_FUNCTION(long long) ovr_ChallengeEntry_GetScore(const ovrChallengeEntryHandle obj);

/// The timestamp of the creation of this entry in the challenge.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_ChallengeEntry_GetTimestamp(const ovrChallengeEntryHandle obj);

/// The user corresponding to this entry within the challenge.
OVRP_PUBLIC_FUNCTION(ovrUserHandle) ovr_ChallengeEntry_GetUser(const ovrChallengeEntryHandle obj);

OVRP_PUBLIC_FUNCTION(unsigned int) ovr_ChallengeEntry_GetExtraDataLength(const ovrChallengeEntryHandle obj);

#endif
