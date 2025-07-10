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

#ifndef OVR_LAUNCHINVITEPANELFLOWRESULT_H
#define OVR_LAUNCHINVITEPANELFLOWRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_UserArray.h"

/// \file
/// Represents the result of a user's interaction with the invite panel, which
/// is used to send out invitations to other users. It provides a way for
/// developers to track the results of a user's interaction with the invite
/// panel, including the list of users who were invited to the session. It can
/// be retrieved using #ovrMessage_Notification_GroupPresence_InvitationsSent.
typedef struct ovrLaunchInvitePanelFlowResult *ovrLaunchInvitePanelFlowResultHandle;

/// A list of ::ovrUserHandle who were invited to the session by the user who
/// interacted with the invite panel.
OVRP_PUBLIC_FUNCTION(ovrUserArrayHandle) ovr_LaunchInvitePanelFlowResult_GetInvitedUsers(const ovrLaunchInvitePanelFlowResultHandle obj);


#endif
