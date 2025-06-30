/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LAUNCHFRIENDREQUESTFLOWRESULT_H
#define OVR_LAUNCHFRIENDREQUESTFLOWRESULT_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
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
