// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_BLOCKEDUSER_H
#define OVR_BLOCKEDUSER_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

/// It contains an array of users who have been blocked by the logged in user.
/// You can't follow, be followed, invited, or searched by a blocked user. It
/// can be retrieved using ovr_User_GetBlockedUsers().
typedef struct ovrBlockedUser *ovrBlockedUserHandle;

/// It represents the user ID that has been blocked by the logged in user. It
/// is a type of ID and can be retrieved using ovr_User_GetID().
OVRP_PUBLIC_FUNCTION(ovrID) ovr_BlockedUser_GetId(const ovrBlockedUserHandle obj);


#endif
