// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_INVITE_OPTIONS_H
#define OVR_INVITE_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>


struct ovrInviteOptions;
typedef struct ovrInviteOptions* ovrInviteOptionsHandle;

OVRP_PUBLIC_FUNCTION(ovrInviteOptionsHandle) ovr_InviteOptions_Create();
OVRP_PUBLIC_FUNCTION(void) ovr_InviteOptions_Destroy(ovrInviteOptionsHandle handle);
/// Passing in these users will add them to the invitable users list
OVRP_PUBLIC_FUNCTION(void) ovr_InviteOptions_AddSuggestedUser(ovrInviteOptionsHandle handle, ovrID value);
OVRP_PUBLIC_FUNCTION(void) ovr_InviteOptions_ClearSuggestedUsers(ovrInviteOptionsHandle handle);

#endif
