// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LAUNCHUNBLOCKFLOWRESULT_H
#define OVR_LAUNCHUNBLOCKFLOWRESULT_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// It's used to unblock a user. Results of the launched unblock dialog
/// including whether the user was successfully unblocked and whether the
/// viewer canceled the unblock flow. It can be retrieved using
/// ovr_User_LaunchUnblockFlow().
typedef struct ovrLaunchUnblockFlowResult *ovrLaunchUnblockFlowResultHandle;

/// A `boolean` indicates whether the viewer chose to cancel the unblock flow.
/// It will be 'true' if the viewer canceled 'Unblock' from the modal.
OVRP_PUBLIC_FUNCTION(bool) ovr_LaunchUnblockFlowResult_GetDidCancel(const ovrLaunchUnblockFlowResultHandle obj);

/// A `boolean` indicates whether the viewer successfully unblocked the user.
/// Learn more about [unblocking
/// users](https://developer.oculus.com/documentation/native/ps-blockingsdk/)
/// from our website.
OVRP_PUBLIC_FUNCTION(bool) ovr_LaunchUnblockFlowResult_GetDidUnblock(const ovrLaunchUnblockFlowResultHandle obj);


#endif
