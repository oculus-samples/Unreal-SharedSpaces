// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USERCAPABILITYARRAY_H
#define OVR_USERCAPABILITYARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_UserCapability.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ovrUserCapabilityArray *ovrUserCapabilityArrayHandle;

OVRP_PUBLIC_FUNCTION(ovrUserCapabilityHandle) ovr_UserCapabilityArray_GetElement(const ovrUserCapabilityArrayHandle obj, size_t index);
OVRP_PUBLIC_FUNCTION(const char *)            ovr_UserCapabilityArray_GetNextUrl(const ovrUserCapabilityArrayHandle obj);
OVRP_PUBLIC_FUNCTION(size_t)                  ovr_UserCapabilityArray_GetSize(const ovrUserCapabilityArrayHandle obj);
OVRP_PUBLIC_FUNCTION(bool)                    ovr_UserCapabilityArray_HasNextPage(const ovrUserCapabilityArrayHandle obj);

#endif
