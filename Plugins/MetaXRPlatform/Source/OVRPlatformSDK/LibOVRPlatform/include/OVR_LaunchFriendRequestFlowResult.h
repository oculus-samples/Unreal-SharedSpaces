// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LAUNCHFRIENDREQUESTFLOWRESULT_H
#define OVR_LAUNCHFRIENDREQUESTFLOWRESULT_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// Users can initiate follow requests to other users encountered in the app by
/// launching the process from within the app. After the follow request has
/// been sent via a deeplinked modal, the viewer is returned to the app. Users
/// may find this process more convenient than using the Meta Quest mobile app
/// or returning to Meta Horizon Home to send follow requests since it is less
/// disruptive to the app experience they are currently focused on. You can
/// retrieve it using ovr_User_LaunchFriendRequestFlow().
typedef struct ovrLaunchFriendRequestFlowResult *ovrLaunchFriendRequestFlowResultHandle;

/// User can choose to cancel the friend request flow after sending it. You can
/// use this to check whether the viewer chose to cancel the friend request
/// flow.
OVRP_PUBLIC_FUNCTION(bool) ovr_LaunchFriendRequestFlowResult_GetDidCancel(const ovrLaunchFriendRequestFlowResultHandle obj);

/// Whether the viewer successfully sent the friend request.
OVRP_PUBLIC_FUNCTION(bool) ovr_LaunchFriendRequestFlowResult_GetDidSendRequest(const ovrLaunchFriendRequestFlowResultHandle obj);


#endif
