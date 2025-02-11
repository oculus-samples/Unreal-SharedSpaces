// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_AVATAREDITORRESULT_H
#define OVR_AVATAREDITORRESULT_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// This is the result that can be extracted from message payload when the
/// avatar editor is launched. It can be retrieved using
/// ovr_Avatar_LaunchAvatarEditor().
typedef struct ovrAvatarEditorResult *ovrAvatarEditorResultHandle;

/// Whether the request has sent.
OVRP_PUBLIC_FUNCTION(bool) ovr_AvatarEditorResult_GetRequestSent(const ovrAvatarEditorResultHandle obj);


#endif
