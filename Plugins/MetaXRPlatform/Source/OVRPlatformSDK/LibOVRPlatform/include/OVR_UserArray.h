// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USERARRAY_H
#define OVR_USERARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_User.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrUserHandle elements
typedef struct ovrUserArray *ovrUserArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrUserHandle) ovr_UserArray_GetElement(const ovrUserArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserArray_GetNextUrl(const ovrUserArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_UserArray_GetSize(const ovrUserArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_UserArray_HasNextPage(const ovrUserArrayHandle obj);


#endif
