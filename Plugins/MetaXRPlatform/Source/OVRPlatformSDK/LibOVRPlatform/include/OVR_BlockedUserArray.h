// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_BLOCKEDUSERARRAY_H
#define OVR_BLOCKEDUSERARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_BlockedUser.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ovrBlockedUserArray *ovrBlockedUserArrayHandle;

OVRP_PUBLIC_FUNCTION(ovrBlockedUserHandle) ovr_BlockedUserArray_GetElement(const ovrBlockedUserArrayHandle obj, size_t index);
OVRP_PUBLIC_FUNCTION(const char *)         ovr_BlockedUserArray_GetNextUrl(const ovrBlockedUserArrayHandle obj);
OVRP_PUBLIC_FUNCTION(size_t)               ovr_BlockedUserArray_GetSize(const ovrBlockedUserArrayHandle obj);
OVRP_PUBLIC_FUNCTION(bool)                 ovr_BlockedUserArray_HasNextPage(const ovrBlockedUserArrayHandle obj);

#endif
