// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LEADERBOARDARRAY_H
#define OVR_LEADERBOARDARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Leaderboard.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrLeaderboardHandle elements
typedef struct ovrLeaderboardArray *ovrLeaderboardArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrLeaderboardHandle) ovr_LeaderboardArray_GetElement(const ovrLeaderboardArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_LeaderboardArray_GetNextUrl(const ovrLeaderboardArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_LeaderboardArray_GetSize(const ovrLeaderboardArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_LeaderboardArray_HasNextPage(const ovrLeaderboardArrayHandle obj);


#endif
