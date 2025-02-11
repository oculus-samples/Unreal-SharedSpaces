// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_BLOCKEDUSERARRAY_H
#define OVR_BLOCKEDUSERARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_BlockedUser.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrBlockedUserHandle elements
typedef struct ovrBlockedUserArray *ovrBlockedUserArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrBlockedUserHandle) ovr_BlockedUserArray_GetElement(const ovrBlockedUserArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_BlockedUserArray_GetNextUrl(const ovrBlockedUserArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_BlockedUserArray_GetSize(const ovrBlockedUserArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_BlockedUserArray_HasNextPage(const ovrBlockedUserArrayHandle obj);


#endif
