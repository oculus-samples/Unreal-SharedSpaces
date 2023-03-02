// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_BLOCKEDUSER_H
#define OVR_BLOCKEDUSER_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

typedef struct ovrBlockedUser *ovrBlockedUserHandle;

/// user ID that has been blocked by the logged in user
OVRP_PUBLIC_FUNCTION(ovrID) ovr_BlockedUser_GetId(const ovrBlockedUserHandle obj);


#endif
