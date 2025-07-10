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

#ifndef OVR_SENDINVITESRESULT_H
#define OVR_SENDINVITESRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_ApplicationInviteArray.h"

/// \file
/// The result of sending an invite to a user or list of users shows invites
/// were sent successfully through the resulting array. This is the model
/// returned in a successful response to the ovr_GroupPresence_SendInvites()
/// api.
typedef struct ovrSendInvitesResult *ovrSendInvitesResultHandle;

/// The list of invites that was sent through ovr_GroupPresence_SendInvites().
/// This invite list can comprise of friends and recently met users.
OVRP_PUBLIC_FUNCTION(ovrApplicationInviteArrayHandle) ovr_SendInvitesResult_GetInvites(const ovrSendInvitesResultHandle obj);


#endif
