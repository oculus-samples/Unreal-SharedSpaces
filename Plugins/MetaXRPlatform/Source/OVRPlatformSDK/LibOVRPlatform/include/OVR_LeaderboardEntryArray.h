// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LEADERBOARDENTRYARRAY_H
#define OVR_LEADERBOARDENTRYARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_LeaderboardEntry.h"
#include <stdbool.h>
#include <stddef.h>

/// An array of paginated leaderboard entries.
typedef struct ovrLeaderboardEntryArray *ovrLeaderboardEntryArrayHandle;

/// The url of the next page of leaderboard entries
OVRP_PUBLIC_FUNCTION(const char *) ovr_LeaderboardEntryArray_GetNextUrl(const ovrLeaderboardEntryArrayHandle obj);

/// The url of the previous leaderboard entries
OVRP_PUBLIC_FUNCTION(const char *) ovr_LeaderboardEntryArray_GetPreviousUrl(const ovrLeaderboardEntryArrayHandle obj);

/// The size of this leaderboard entry array in bytes
OVRP_PUBLIC_FUNCTION(size_t) ovr_LeaderboardEntryArray_GetSize(const ovrLeaderboardEntryArrayHandle obj);

/// The total count of this leaderboard entry array, ignoring the pagination.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_LeaderboardEntryArray_GetTotalCount(const ovrLeaderboardEntryArrayHandle obj);

/// Whether this leaderboard entry array has next page
OVRP_PUBLIC_FUNCTION(bool) ovr_LeaderboardEntryArray_HasNextPage(const ovrLeaderboardEntryArrayHandle obj);

/// Whether this leaderboard entry array has previous page
OVRP_PUBLIC_FUNCTION(bool) ovr_LeaderboardEntryArray_HasPreviousPage(const ovrLeaderboardEntryArrayHandle obj);

OVRP_PUBLIC_FUNCTION(ovrLeaderboardEntryHandle) ovr_LeaderboardEntryArray_GetElement(const ovrLeaderboardEntryArrayHandle obj, size_t index);

#endif
