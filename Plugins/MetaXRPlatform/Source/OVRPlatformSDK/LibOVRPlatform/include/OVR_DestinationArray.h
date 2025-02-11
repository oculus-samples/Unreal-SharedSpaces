// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_DESTINATIONARRAY_H
#define OVR_DESTINATIONARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Destination.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrDestinationHandle elements
typedef struct ovrDestinationArray *ovrDestinationArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrDestinationHandle) ovr_DestinationArray_GetElement(const ovrDestinationArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_DestinationArray_GetNextUrl(const ovrDestinationArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_DestinationArray_GetSize(const ovrDestinationArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_DestinationArray_HasNextPage(const ovrDestinationArrayHandle obj);


#endif
