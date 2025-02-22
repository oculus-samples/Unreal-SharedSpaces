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

#ifndef OVR_INVITE_OPTIONS_H
#define OVR_INVITE_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>


/// \file
/// The Invite Option, to be passed in to ovr_GroupPresence_GetInvitableUsers()
/// and ovr_GroupPresence_LaunchInvitePanel(), is a field that allows
/// developers to specify a list of suggested users to be added to the
/// invitable users list, making it easier for users to connect with others and
/// create a more social experience.
struct ovrInviteOptions;

typedef struct ovrInviteOptions* ovrInviteOptionsHandle;
/// \brief Creates a new instance of ovrInviteOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrInviteOptionsHandle) ovr_InviteOptions_Create();
/// \brief Destroys an existing instance of the ovrInviteOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_InviteOptions_Destroy(ovrInviteOptionsHandle handle);
/// Passing in these users will add them to the invitable users list. From the
/// ovr_GroupPresence_LaunchInvitePanel(), the user can open the invite list,
/// where the suggested users will be added.
OVRP_PUBLIC_FUNCTION(void) ovr_InviteOptions_AddSuggestedUser(ovrInviteOptionsHandle handle, ovrID value);
OVRP_PUBLIC_FUNCTION(void) ovr_InviteOptions_ClearSuggestedUsers(ovrInviteOptionsHandle handle);

#endif
