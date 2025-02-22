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

#ifndef OVR_LEADERBOARDUPDATESTATUS_H
#define OVR_LEADERBOARDUPDATESTATUS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stdbool.h>

/// \file
/// This object is a response from the server that contains information about
/// the status of the request to update the leaderboard. It can be retrieved
/// using two different API requests: ovr_Leaderboard_WriteEntry() and
/// ovr_Leaderboard_WriteEntryWithSupplementaryMetric().
typedef struct ovrLeaderboardUpdateStatus *ovrLeaderboardUpdateStatusHandle;

/// A `boolean` indicates whether the leaderboard was updated.
OVRP_PUBLIC_FUNCTION(bool) ovr_LeaderboardUpdateStatus_GetDidUpdate(const ovrLeaderboardUpdateStatusHandle obj);

/// If the leaderboard is updated, this represents the updated challenge IDs.
/// The updated challenge IDs can be used by ovr_Challenges_GetEntries(),
/// ovr_Challenges_GetEntriesAfterRank(), or ovr_Challenges_GetEntriesByIds()
/// APIs.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_LeaderboardUpdateStatus_GetUpdatedChallengeId(const ovrLeaderboardUpdateStatusHandle obj, unsigned int index);

OVRP_PUBLIC_FUNCTION(unsigned int) ovr_LeaderboardUpdateStatus_GetUpdatedChallengeIdsSize(const ovrLeaderboardUpdateStatusHandle obj);

#endif
