// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USERCAPABILITY_H
#define OVR_USERCAPABILITY_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

typedef struct ovrUserCapability *ovrUserCapabilityHandle;

/// Human readable description of the capability describing what possessing it
/// entails for a given user
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserCapability_GetDescription(const ovrUserCapabilityHandle obj);

/// Whether the capability is currently enabled for the user
OVRP_PUBLIC_FUNCTION(bool) ovr_UserCapability_GetIsEnabled(const ovrUserCapabilityHandle obj);

/// Unique identifer for the capability
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserCapability_GetName(const ovrUserCapabilityHandle obj);

/// If present, specifies the reason the capability was enabled or disabled
OVRP_PUBLIC_FUNCTION(const char *) ovr_UserCapability_GetReasonCode(const ovrUserCapabilityHandle obj);


#endif
