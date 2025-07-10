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

#ifndef OVR_INVITEPANELRESULTINFO_H
#define OVR_INVITEPANELRESULTINFO_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
/// It contains information about the user's invitation to others to join their
/// current session. It is used to provide feedback to the user about whether
/// their invitations have been successfully sent. It can be retrieved using
/// ovr_GroupPresence_LaunchInvitePanel().
typedef struct ovrInvitePanelResultInfo *ovrInvitePanelResultInfoHandle;

/// This field indicates whether any invitations have been sent successfully.
/// It is a boolean value where true means that one or more invites have been
/// successfully sent, and false indicates that no invites were sent or the
/// sending process failed.
OVRP_PUBLIC_FUNCTION(bool) ovr_InvitePanelResultInfo_GetInvitesSent(const ovrInvitePanelResultInfoHandle obj);


#endif
