// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MULTIPLAYER_ERROR_OPTIONS_H
#define OVR_MULTIPLAYER_ERROR_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_MultiplayerErrorErrorKey.h"

struct ovrMultiplayerErrorOptions;
typedef struct ovrMultiplayerErrorOptions* ovrMultiplayerErrorOptionsHandle;

OVRP_PUBLIC_FUNCTION(ovrMultiplayerErrorOptionsHandle) ovr_MultiplayerErrorOptions_Create();
OVRP_PUBLIC_FUNCTION(void) ovr_MultiplayerErrorOptions_Destroy(ovrMultiplayerErrorOptionsHandle handle);
/// Key associated with the predefined error message to be shown to users.
OVRP_PUBLIC_FUNCTION(void) ovr_MultiplayerErrorOptions_SetErrorKey(ovrMultiplayerErrorOptionsHandle handle, ovrMultiplayerErrorErrorKey value);

#endif
