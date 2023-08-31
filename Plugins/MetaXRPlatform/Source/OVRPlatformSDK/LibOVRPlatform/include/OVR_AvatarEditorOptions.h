// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_AVATAR_EDITOR_OPTIONS_H
#define OVR_AVATAR_EDITOR_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>


struct ovrAvatarEditorOptions;
typedef struct ovrAvatarEditorOptions* ovrAvatarEditorOptionsHandle;

OVRP_PUBLIC_FUNCTION(ovrAvatarEditorOptionsHandle) ovr_AvatarEditorOptions_Create();
OVRP_PUBLIC_FUNCTION(void) ovr_AvatarEditorOptions_Destroy(ovrAvatarEditorOptionsHandle handle);
/// Optional: Override for where the request is coming from.
OVRP_PUBLIC_FUNCTION(void) ovr_AvatarEditorOptions_SetSourceOverride(ovrAvatarEditorOptionsHandle handle, const char * value);

#endif
