// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_NETSYNCSESSIONARRAY_H
#define OVR_NETSYNCSESSIONARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_NetSyncSession.h"
#include <stddef.h>

/// Represents a paginated list of ovrNetSyncSessionHandle elements
typedef struct ovrNetSyncSessionArray *ovrNetSyncSessionArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrNetSyncSessionHandle) ovr_NetSyncSessionArray_GetElement(const ovrNetSyncSessionArrayHandle obj, size_t index);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_NetSyncSessionArray_GetSize(const ovrNetSyncSessionArrayHandle obj);


#endif
