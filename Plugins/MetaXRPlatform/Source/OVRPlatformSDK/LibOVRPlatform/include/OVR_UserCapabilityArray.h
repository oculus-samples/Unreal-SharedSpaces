// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USERCAPABILITYARRAY_H
#define OVR_USERCAPABILITYARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_UserCapability.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrUserCapabilityHandle elements
typedef struct ovrUserCapabilityArray *ovrUserCapabilityArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrUserCapabilityHandle) ovr_UserCapabilityArray_GetElement(const ovrUserCapabilityArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserCapabilityArray_GetNextUrl(const ovrUserCapabilityArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_UserCapabilityArray_GetSize(const ovrUserCapabilityArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_UserCapabilityArray_HasNextPage(const ovrUserCapabilityArrayHandle obj);


#endif
