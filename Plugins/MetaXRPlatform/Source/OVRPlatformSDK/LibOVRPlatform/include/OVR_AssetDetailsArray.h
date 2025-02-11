// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ASSETDETAILSARRAY_H
#define OVR_ASSETDETAILSARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_AssetDetails.h"
#include <stddef.h>

/// Represents a paginated list of ovrAssetDetailsHandle elements
typedef struct ovrAssetDetailsArray *ovrAssetDetailsArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrAssetDetailsHandle) ovr_AssetDetailsArray_GetElement(const ovrAssetDetailsArrayHandle obj, size_t index);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_AssetDetailsArray_GetSize(const ovrAssetDetailsArrayHandle obj);


#endif
