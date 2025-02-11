// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_PURCHASEARRAY_H
#define OVR_PURCHASEARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Purchase.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrPurchaseHandle elements
typedef struct ovrPurchaseArray *ovrPurchaseArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrPurchaseHandle) ovr_PurchaseArray_GetElement(const ovrPurchaseArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_PurchaseArray_GetNextUrl(const ovrPurchaseArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_PurchaseArray_GetSize(const ovrPurchaseArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_PurchaseArray_HasNextPage(const ovrPurchaseArrayHandle obj);


#endif
