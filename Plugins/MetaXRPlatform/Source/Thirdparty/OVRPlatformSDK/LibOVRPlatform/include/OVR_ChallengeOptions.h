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

#ifndef OVR_CHALLENGE_OPTIONS_H
#define OVR_CHALLENGE_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_ChallengeViewerFilter.h"
#include "OVR_ChallengeVisibility.h"

/// \file
/// The Challenge Option is a parameter that can be passed in the
/// ovr_Challenges_GetList() method to retrieve a list of challenges that match
/// the specified options. The ovr_ChallengeOptions_Create() parameter allows
/// you to specify the criteria for the challenges you want to retrieve, such
/// as the viewer filter, the visibility, or the date range.
struct ovrChallengeOptions;

typedef struct ovrChallengeOptions* ovrChallengeOptionsHandle;
/// \brief Creates a new instance of ovrChallengeOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrChallengeOptionsHandle) ovr_ChallengeOptions_Create();
/// \brief Destroys an existing instance of the ovrChallengeOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_Destroy(ovrChallengeOptionsHandle handle);
/// The description of the challenge is a detailed and informative text that
/// provides a comprehensive overview of the challenge's objectives, rules, and
/// requirements, which can be retrieved with ovr_Challenge_GetDescription().
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetDescription(ovrChallengeOptionsHandle handle, const char * value);
/// The challenge end date is the timestamp when this challenge ends, which can
/// be retrieved using ovr_Challenge_GetEndDate().
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetEndDate(ovrChallengeOptionsHandle handle, unsigned long long value);
/// This option indicates whether to include challenges that are currently
/// active in the search results. By default, this is set to true, meaning that
/// only active challenges will be returned.
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetIncludeActiveChallenges(ovrChallengeOptionsHandle handle, bool value);
/// This option indicates whether to include challenges that have not yet
/// started in the search results. By default, this is set to false, meaning
/// that only active will be returned.
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetIncludeFutureChallenges(ovrChallengeOptionsHandle handle, bool value);
/// This option indicates whether to include challenges that have already ended
/// in the search results. By default, this is set to false, meaning that only
/// active will be returned.
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetIncludePastChallenges(ovrChallengeOptionsHandle handle, bool value);
/// Optional: Only find challenges belonging to this leaderboard. This filter
/// allows you to narrow down the search results to only include challenges
/// that are associated with a specific leaderboard.
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetLeaderboardName(ovrChallengeOptionsHandle handle, const char * value);
/// The challenge start date is the timestamp when this challenge begins, which
/// can be retrieved using ovr_Challenge_GetStartDate().
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetStartDate(ovrChallengeOptionsHandle handle, unsigned long long value);
/// The title of the challenge is a descriptive label that provides a concise
/// summary of the challenge's purpose and objectives, which can be retrieved
/// with ovr_Challenge_GetTitle().
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetTitle(ovrChallengeOptionsHandle handle, const char * value);
/// An enum that specifies what filter to apply to the list of returned
/// challenges.
///
/// Returns all public (ovrChallengeVisibility_Public()) and invite-only
/// (ovrChallengeVisibility_InviteOnly()) ::ovrChallengeHandle in which the
/// user is a participant or invitee. Excludes private
/// (ovrChallengeVisibility_Private()) challenges.
///
/// ovrChallengeViewerFilter_Participating() - Returns challenges the user is
/// participating in.
///
/// ovrChallengeViewerFilter_Invited() - Returns challenges the user is invited
/// to.
///
/// ovrChallengeViewerFilter_ParticipatingOrInvited() - Returns challenges the
/// user is either participating in or invited to.
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetViewerFilter(ovrChallengeOptionsHandle handle, ovrChallengeViewerFilter value);
/// The challenge visibility setting specifies who can see and participate in
/// this challenge, which be retrieved with ovr_Challenge_GetVisibility().
/// There are three visibility levels: ovrChallengeVisibility_Public(),
/// ovrChallengeVisibility_InviteOnly() and ovrChallengeVisibility_Private().
OVRP_PUBLIC_FUNCTION(void) ovr_ChallengeOptions_SetVisibility(ovrChallengeOptionsHandle handle, ovrChallengeVisibility value);

#endif
