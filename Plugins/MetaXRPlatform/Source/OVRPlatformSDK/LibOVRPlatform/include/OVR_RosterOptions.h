// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ROSTER_OPTIONS_H
#define OVR_ROSTER_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>


struct ovrRosterOptions;
typedef struct ovrRosterOptions* ovrRosterOptionsHandle;

OVRP_PUBLIC_FUNCTION(ovrRosterOptionsHandle) ovr_RosterOptions_Create();
OVRP_PUBLIC_FUNCTION(void) ovr_RosterOptions_Destroy(ovrRosterOptionsHandle handle);
/// Passing in these users will add them to the invitable users list. From the
/// roster panel, the user can open the invite list, where the suggested users
/// will be added.
OVRP_PUBLIC_FUNCTION(void) ovr_RosterOptions_AddSuggestedUser(ovrRosterOptionsHandle handle, ovrID value);
OVRP_PUBLIC_FUNCTION(void) ovr_RosterOptions_ClearSuggestedUsers(ovrRosterOptionsHandle handle);

#endif
