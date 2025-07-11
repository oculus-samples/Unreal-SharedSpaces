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

#ifndef OVR_LEADERBOARDENTRYARRAY_H
#define OVR_LEADERBOARDENTRYARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_LeaderboardEntry.h"
#include <stdbool.h>
#include <stddef.h>

/// \file
/// An array of paginated leaderboard entries. It can be retrieved using
/// ovr_Leaderboard_GetEntries(). It provides information about the leaderboard
/// entries, such as their size, whether there are next or previous pages, the
/// URLs for those pages, and the total count of entries in the leaderboard.
typedef struct ovrLeaderboardEntryArray *ovrLeaderboardEntryArrayHandle;

/// This field represents an individual ::ovrLeaderboardEntryHandle within the
/// array. It contains information about the leaderboard entry, such as its
/// rank, score, and player name.
OVRP_PUBLIC_FUNCTION(ovrLeaderboardEntryHandle) ovr_LeaderboardEntryArray_GetElement(const ovrLeaderboardEntryArrayHandle obj, size_t index);

/// The url of the next page of leaderboard entries. It provides a link to the
/// next set of entries in the leaderboard.
OVRP_PUBLIC_FUNCTION(const char *) ovr_LeaderboardEntryArray_GetNextUrl(const ovrLeaderboardEntryArrayHandle obj);

/// The url of the previous leaderboard entries. It provides a link to the
/// previous set of entries in the leaderboard.
OVRP_PUBLIC_FUNCTION(const char *) ovr_LeaderboardEntryArray_GetPreviousUrl(const ovrLeaderboardEntryArrayHandle obj);

/// The size of this leaderboard entry array in bytes. It provides information
/// about the amount of data stored in the array.
OVRP_PUBLIC_FUNCTION(size_t) ovr_LeaderboardEntryArray_GetSize(const ovrLeaderboardEntryArrayHandle obj);

/// The total count of this leaderboard entry array, ignoring the pagination.
/// It provides information about the total number of entries in the
/// leaderboard.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_LeaderboardEntryArray_GetTotalCount(const ovrLeaderboardEntryArrayHandle obj);

/// A `boolean` indicates whether this leaderboard entry array has next page.
OVRP_PUBLIC_FUNCTION(bool) ovr_LeaderboardEntryArray_HasNextPage(const ovrLeaderboardEntryArrayHandle obj);

/// A `boolean` indicates whether this leaderboard entry array has previous
/// page.
OVRP_PUBLIC_FUNCTION(bool) ovr_LeaderboardEntryArray_HasPreviousPage(const ovrLeaderboardEntryArrayHandle obj);


#endif
