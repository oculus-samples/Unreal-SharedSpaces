// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_COWATCHVIEWERARRAY_H
#define OVR_COWATCHVIEWERARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_CowatchViewer.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrCowatchViewerHandle elements
typedef struct ovrCowatchViewerArray *ovrCowatchViewerArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrCowatchViewerHandle) ovr_CowatchViewerArray_GetElement(const ovrCowatchViewerArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_CowatchViewerArray_GetNextUrl(const ovrCowatchViewerArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_CowatchViewerArray_GetSize(const ovrCowatchViewerArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_CowatchViewerArray_HasNextPage(const ovrCowatchViewerArrayHandle obj);


#endif
