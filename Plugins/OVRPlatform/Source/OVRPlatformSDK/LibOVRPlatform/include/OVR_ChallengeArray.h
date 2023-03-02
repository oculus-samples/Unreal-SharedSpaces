// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_CHALLENGEARRAY_H
#define OVR_CHALLENGEARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Challenge.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ovrChallengeArray *ovrChallengeArrayHandle;

OVRP_PUBLIC_FUNCTION(ovrChallengeHandle) ovr_ChallengeArray_GetElement(const ovrChallengeArrayHandle obj, size_t index);
OVRP_PUBLIC_FUNCTION(const char *)       ovr_ChallengeArray_GetNextUrl(const ovrChallengeArrayHandle obj);
OVRP_PUBLIC_FUNCTION(const char *)       ovr_ChallengeArray_GetPreviousUrl(const ovrChallengeArrayHandle obj);
OVRP_PUBLIC_FUNCTION(size_t)             ovr_ChallengeArray_GetSize(const ovrChallengeArrayHandle obj);
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_ChallengeArray_GetTotalCount(const ovrChallengeArrayHandle obj);
OVRP_PUBLIC_FUNCTION(bool)               ovr_ChallengeArray_HasNextPage(const ovrChallengeArrayHandle obj);
OVRP_PUBLIC_FUNCTION(bool)               ovr_ChallengeArray_HasPreviousPage(const ovrChallengeArrayHandle obj);

#endif
