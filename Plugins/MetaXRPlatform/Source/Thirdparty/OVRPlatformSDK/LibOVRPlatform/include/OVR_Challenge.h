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

#ifndef OVR_CHALLENGE_H
#define OVR_CHALLENGE_H

#include "OVR_Platform_Defs.h"
#include "OVR_ChallengeCreationType.h"
#include "OVR_ChallengeVisibility.h"
#include "OVR_Leaderboard.h"
#include "OVR_Types.h"
#include "OVR_UserArray.h"

/// \file
/// Challenges leverage ::ovrDestinationHandle and Group Presence to create
/// shareable links that allow players to compete directly based on score.
///
/// Challenges can be ranked by highest or lowest scores within a time period.
/// Any application that uses Leaderboards gets Challenges for free. It appears
/// in the Scoreboards UI. Players can create Challenges and send invites
/// through the Challenges app.
typedef struct ovrChallenge *ovrChallengeHandle;

/// An enum that specifies if this challenge was created by a user
/// (ovrChallengeCreationType_UserCreated()) or the app developer
/// (ovrChallengeCreationType_DeveloperCreated()).
OVRP_PUBLIC_FUNCTION(ovrChallengeCreationType) ovr_Challenge_GetCreationType(const ovrChallengeHandle obj);

/// A displayable string of the challenge's description.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Challenge_GetDescription(const ovrChallengeHandle obj);

/// The timestamp when this challenge ends. You can retrieve this field from
/// the response of the challenge creation request.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_Challenge_GetEndDate(const ovrChallengeHandle obj);

/// The ID of the challenge. This is an unique string that the application will
/// refer to this challenge in your app.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_Challenge_GetID(const ovrChallengeHandle obj);

/// Users that are invited to this challenge.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_Challenge_GetInvitedUsers(const ovrChallengeHandle obj);

/// The ::ovrLeaderboardHandle associated with this challenge. You can retrieve
/// the leaderboard ID from the response of the challenge creation request.
OVRP_PUBLIC_FUNCTION(ovrLeaderboardHandle) ovr_Challenge_GetLeaderboard(const ovrChallengeHandle obj);

/// Users that have participated in this challenge.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_Challenge_GetParticipants(const ovrChallengeHandle obj);

/// The timestamp when this challenge begins. You can retrieve this field from
/// the response of the challenge creation request.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_Challenge_GetStartDate(const ovrChallengeHandle obj);

/// A displayable string of the challenge's title.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Challenge_GetTitle(const ovrChallengeHandle obj);

/// An enum that specifies who can see and participate in this challenge.
///
/// ovrChallengeVisibility_InviteOnly() - Only those invited can participate in
/// it. Everyone can see it.
///
/// ovrChallengeVisibility_Public() - Everyone can participate and see this
/// challenge.
///
/// ovrChallengeVisibility_Private() - Only those invited can participate and
/// see this challenge.
OVRP_PUBLIC_FUNCTION(ovrChallengeVisibility) ovr_Challenge_GetVisibility(const ovrChallengeHandle obj);


#endif
