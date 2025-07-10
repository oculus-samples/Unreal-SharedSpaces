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

#ifndef OVR_LEADERBOARDENTRY_H
#define OVR_LEADERBOARDENTRY_H

#include "OVR_Platform_Defs.h"
#include "OVR_SupplementaryMetric.h"
#include "OVR_Types.h"
#include "OVR_User.h"

/// \file
/// A leaderboard entry object contains information about the ::ovrUserHandle
/// who made the entry, their score, and other relevant details in the
/// leaderboard. It provides a way for a game to keep track of players and
/// their scores in relation to other. A single leaderboard entry can be
/// written by ovr_Leaderboard_WriteEntry(). A block of leaderboard entries can
/// be retrieved using ovr_Leaderboard_GetEntries(). Visit our
/// [website](https://developer.oculus.com/documentation/native/ps-
/// leaderboards/) for more information about the leaderboard entry.
typedef struct ovrLeaderboardEntry *ovrLeaderboardEntryHandle;

/// The formatted score that will be displayed in the leaderboard of this
/// entry. You can select a score type to determine how scores are displayed on
/// Leaderboard. See
/// [here](https://developer.oculus.com/documentation/native/ps-
/// leaderboards/#create) for examples of different score type.
OVRP_PUBLIC_FUNCTION(const char *) ovr_LeaderboardEntry_GetDisplayScore(const ovrLeaderboardEntryHandle obj);

/// A 2KB custom data field that is associated with the leaderboard entry. This
/// can be a game replay or anything that provides more detail about the entry
/// to the viewer. It will be used by two entry methods:
/// ovr_Leaderboard_WriteEntry() and
/// ovr_Leaderboard_WriteEntryWithSupplementaryMetric()
OVRP_PUBLIC_FUNCTION(const char *) ovr_LeaderboardEntry_GetExtraData(const ovrLeaderboardEntryHandle obj);

/// This is a unique identifier for the leaderboard entry. It is of type `id`
/// and is optional.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_LeaderboardEntry_GetID(const ovrLeaderboardEntryHandle obj);

/// The rank of this leaderboard entry in the leaderboard. It is of type `int`.
/// It can be used in ovr_Leaderboard_GetEntriesAfterRank() to retrieve
/// leaderboard entries starting from a specified rank.
OVRP_PUBLIC_FUNCTION(int) ovr_LeaderboardEntry_GetRank(const ovrLeaderboardEntryHandle obj);

/// The raw underlying value of the score achieved by the user in the
/// leaderboard. It's of type `long_as_string` and it's used to determine the
/// user's rank in the leaderboard.
OVRP_PUBLIC_FUNCTION(long long) ovr_LeaderboardEntry_GetScore(const ovrLeaderboardEntryHandle obj);

/// ::ovrSupplementaryMetricHandle is a supplemental piece of data that can be
/// used for tiebreakers by
/// ovr_Leaderboard_WriteEntryWithSupplementaryMetric().
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrSupplementaryMetricHandle) ovr_LeaderboardEntry_GetSupplementaryMetric(const ovrLeaderboardEntryHandle obj);

/// The timestamp of this entry being created in the leaderboard.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_LeaderboardEntry_GetTimestamp(const ovrLeaderboardEntryHandle obj);

/// User of this leaderboard entry. It is of type ::ovrUserHandle. You can
/// request a block of leaderboard entries for the specified user ID(s) by
/// ovr_Leaderboard_GetEntriesByIds().
OVRP_PUBLIC_FUNCTION(ovrUserHandle) ovr_LeaderboardEntry_GetUser(const ovrLeaderboardEntryHandle obj);

OVRP_PUBLIC_FUNCTION(unsigned int) ovr_LeaderboardEntry_GetExtraDataLength(const ovrLeaderboardEntryHandle obj);

#endif
