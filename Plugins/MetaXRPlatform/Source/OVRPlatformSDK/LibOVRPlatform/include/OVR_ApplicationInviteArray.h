// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APPLICATIONINVITEARRAY_H
#define OVR_APPLICATIONINVITEARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_ApplicationInvite.h"
#include <stdbool.h>
#include <stddef.h>

/// Represents a paginated list of ovrApplicationInviteHandle elements
typedef struct ovrApplicationInviteArray *ovrApplicationInviteArrayHandle;

/// Access the indexed element in this list.
OVRP_PUBLIC_FUNCTION(ovrApplicationInviteHandle) ovr_ApplicationInviteArray_GetElement(const ovrApplicationInviteArrayHandle obj, size_t index);

/// The URL to request the next paginated list of elements.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationInviteArray_GetNextUrl(const ovrApplicationInviteArrayHandle obj);

/// The number of elements contained within this list. This is not equal to the
/// total number of elements across multiple pages.
OVRP_PUBLIC_FUNCTION(size_t) ovr_ApplicationInviteArray_GetSize(const ovrApplicationInviteArrayHandle obj);

/// Whether there is a next page of elements that can be retrieved.
OVRP_PUBLIC_FUNCTION(bool) ovr_ApplicationInviteArray_HasNextPage(const ovrApplicationInviteArrayHandle obj);


#endif
