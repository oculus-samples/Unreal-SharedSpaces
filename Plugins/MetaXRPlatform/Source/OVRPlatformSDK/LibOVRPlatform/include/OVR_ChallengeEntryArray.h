// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGEENTRYARRAY_H
#define OVR_CHALLENGEENTRYARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_ChallengeEntry.h"
#include <stdbool.h>
#include <stddef.h>

/// A paginated array of ovrChallengeEntryHandle which can be retrieved by
/// ovr_Challenges_GetEntries().
typedef struct ovrChallengeEntryArray *ovrChallengeEntryArrayHandle;

/// The element of this array and the element type is ovrChallengeEntryHandle.
OVRP_PUBLIC_FUNCTION(ovrChallengeEntryHandle) ovr_ChallengeEntryArray_GetElement(const ovrChallengeEntryArrayHandle obj, size_t index);

/// The url of the next page of challenge entries.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ChallengeEntryArray_GetNextUrl(const ovrChallengeEntryArrayHandle obj);

/// The url of the previous page of challenge entries.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ChallengeEntryArray_GetPreviousUrl(const ovrChallengeEntryArrayHandle obj);

/// The size of this challenge entry array in bytes.
OVRP_PUBLIC_FUNCTION(size_t) ovr_ChallengeEntryArray_GetSize(const ovrChallengeEntryArrayHandle obj);

/// The total count of ovrChallengeEntryHandle in this array, across all pages.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_ChallengeEntryArray_GetTotalCount(const ovrChallengeEntryArrayHandle obj);

/// Whether this challenge entry array has a next page.
OVRP_PUBLIC_FUNCTION(bool) ovr_ChallengeEntryArray_HasNextPage(const ovrChallengeEntryArrayHandle obj);

/// Whether this challenge entry array has a previous page.
OVRP_PUBLIC_FUNCTION(bool) ovr_ChallengeEntryArray_HasPreviousPage(const ovrChallengeEntryArrayHandle obj);


#endif
