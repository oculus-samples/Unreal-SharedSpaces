// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGEARRAY_H
#define OVR_CHALLENGEARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Challenge.h"
#include <stdbool.h>
#include <stddef.h>

/// A paginated array of ovrChallengeHandles that can be retrieved by
/// ovr_Challenges_GetList().
typedef struct ovrChallengeArray *ovrChallengeArrayHandle;

/// The element of this challenge array. The element type is
/// ovrChallengeHandle.
OVRP_PUBLIC_FUNCTION(ovrChallengeHandle) ovr_ChallengeArray_GetElement(const ovrChallengeArrayHandle obj, size_t index);

/// The url of the next page of challenges.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ChallengeArray_GetNextUrl(const ovrChallengeArrayHandle obj);

/// The url of the previous page of challenges.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ChallengeArray_GetPreviousUrl(const ovrChallengeArrayHandle obj);

/// The size of this challenge array in bytes.
OVRP_PUBLIC_FUNCTION(size_t) ovr_ChallengeArray_GetSize(const ovrChallengeArrayHandle obj);

/// The total count of challenges contained in array, across all pages.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_ChallengeArray_GetTotalCount(const ovrChallengeArrayHandle obj);

/// Whether this challenge array has a next page.
OVRP_PUBLIC_FUNCTION(bool) ovr_ChallengeArray_HasNextPage(const ovrChallengeArrayHandle obj);

/// Whether this challenge array has a previous page.
OVRP_PUBLIC_FUNCTION(bool) ovr_ChallengeArray_HasPreviousPage(const ovrChallengeArrayHandle obj);


#endif
