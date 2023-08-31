// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGE_H
#define OVR_CHALLENGE_H

#include "OVR_Platform_Defs.h"
#include "OVR_ChallengeCreationType.h"
#include "OVR_ChallengeVisibility.h"
#include "OVR_Leaderboard.h"
#include "OVR_Types.h"
#include "OVR_UserArray.h"

typedef struct ovrChallenge *ovrChallengeHandle;

/// Was this challenge created by a user or the app developer
OVRP_PUBLIC_FUNCTION(ovrChallengeCreationType) ovr_Challenge_GetCreationType(const ovrChallengeHandle obj);

/// A displayable string of the challenge's description
OVRP_PUBLIC_FUNCTION(const char *) ovr_Challenge_GetDescription(const ovrChallengeHandle obj);

/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_Challenge_GetInvitedUsers(const ovrChallengeHandle obj);

/// The leaderboard associated with this challenge
OVRP_PUBLIC_FUNCTION(ovrLeaderboardHandle) ovr_Challenge_GetLeaderboard(const ovrChallengeHandle obj);

/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_Challenge_GetParticipants(const ovrChallengeHandle obj);

/// A displayable string of the challenge's title
OVRP_PUBLIC_FUNCTION(const char *) ovr_Challenge_GetTitle(const ovrChallengeHandle obj);

/// A enum that specify who can see this challenge
OVRP_PUBLIC_FUNCTION(ovrChallengeVisibility) ovr_Challenge_GetVisibility(const ovrChallengeHandle obj);

OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_Challenge_GetEndDate(const ovrChallengeHandle obj);
OVRP_PUBLIC_FUNCTION(ovrID)              ovr_Challenge_GetID(const ovrChallengeHandle obj);
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_Challenge_GetStartDate(const ovrChallengeHandle obj);

#endif
