// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APPLICATIONINVITEARRAY_H
#define OVR_APPLICATIONINVITEARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_ApplicationInvite.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ovrApplicationInviteArray *ovrApplicationInviteArrayHandle;

OVRP_PUBLIC_FUNCTION(ovrApplicationInviteHandle) ovr_ApplicationInviteArray_GetElement(const ovrApplicationInviteArrayHandle obj, size_t index);
OVRP_PUBLIC_FUNCTION(const char *)               ovr_ApplicationInviteArray_GetNextUrl(const ovrApplicationInviteArrayHandle obj);
OVRP_PUBLIC_FUNCTION(size_t)                     ovr_ApplicationInviteArray_GetSize(const ovrApplicationInviteArrayHandle obj);
OVRP_PUBLIC_FUNCTION(bool)                       ovr_ApplicationInviteArray_HasNextPage(const ovrApplicationInviteArrayHandle obj);

#endif
