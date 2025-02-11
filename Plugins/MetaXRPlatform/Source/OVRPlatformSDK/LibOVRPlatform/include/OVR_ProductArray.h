// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PRODUCTARRAY_H
#define OVR_PRODUCTARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Product.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrProductHandle elements
typedef struct ovrProductArray *ovrProductArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrProductHandle) ovr_ProductArray_GetElement(const ovrProductArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ProductArray_GetNextUrl(const ovrProductArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_ProductArray_GetSize(const ovrProductArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_ProductArray_HasNextPage(const ovrProductArrayHandle obj);


#endif
