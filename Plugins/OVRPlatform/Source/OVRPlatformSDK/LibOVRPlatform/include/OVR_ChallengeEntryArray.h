// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGEENTRYARRAY_H
#define OVR_CHALLENGEENTRYARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_ChallengeEntry.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ovrChallengeEntryArray *ovrChallengeEntryArrayHandle;

OVRP_PUBLIC_FUNCTION(ovrChallengeEntryHandle) ovr_ChallengeEntryArray_GetElement(const ovrChallengeEntryArrayHandle obj, size_t index);
OVRP_PUBLIC_FUNCTION(const char *)            ovr_ChallengeEntryArray_GetNextUrl(const ovrChallengeEntryArrayHandle obj);
OVRP_PUBLIC_FUNCTION(const char *)            ovr_ChallengeEntryArray_GetPreviousUrl(const ovrChallengeEntryArrayHandle obj);
OVRP_PUBLIC_FUNCTION(size_t)                  ovr_ChallengeEntryArray_GetSize(const ovrChallengeEntryArrayHandle obj);
OVRP_PUBLIC_FUNCTION(unsigned long long)      ovr_ChallengeEntryArray_GetTotalCount(const ovrChallengeEntryArrayHandle obj);
OVRP_PUBLIC_FUNCTION(bool)                    ovr_ChallengeEntryArray_HasNextPage(const ovrChallengeEntryArrayHandle obj);
OVRP_PUBLIC_FUNCTION(bool)                    ovr_ChallengeEntryArray_HasPreviousPage(const ovrChallengeEntryArrayHandle obj);

#endif
