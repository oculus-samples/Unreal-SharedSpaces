// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_SDKACCOUNTARRAY_H
#define OVR_SDKACCOUNTARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_SdkAccount.h"
#include <stddef.h>

/// Represents a paginated list of ovrSdkAccountHandle elements
typedef struct ovrSdkAccountArray *ovrSdkAccountArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrSdkAccountHandle) ovr_SdkAccountArray_GetElement(const ovrSdkAccountArrayHandle obj, size_t index);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_SdkAccountArray_GetSize(const ovrSdkAccountArrayHandle obj);


#endif
