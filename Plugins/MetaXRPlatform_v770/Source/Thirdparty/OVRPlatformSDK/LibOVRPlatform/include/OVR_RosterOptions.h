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

#ifndef OVR_ROSTER_OPTIONS_H
#define OVR_ROSTER_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>


/// \file
/// The roster option, to be passed into ovr_GroupPresence_LaunchRosterPanel()
/// which is used to launch the panel displaying the current users in the
/// roster/party. You can read more about rosters in our
/// [docs](https://developer.oculus.com/documentation/native/ps-roster/).
struct ovrRosterOptions;

typedef struct ovrRosterOptions* ovrRosterOptionsHandle;
/// \brief Creates a new instance of ovrRosterOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrRosterOptionsHandle) ovr_RosterOptions_Create();
/// \brief Destroys an existing instance of the ovrRosterOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_RosterOptions_Destroy(ovrRosterOptionsHandle handle);
/// Passing in these users will add them to the invitable users list. From the
/// ovr_GroupPresence_LaunchRosterPanel(), the ::ovrUserHandle can open the
/// invite list, where the suggested users will be added.
OVRP_PUBLIC_FUNCTION(void) ovr_RosterOptions_AddSuggestedUser(ovrRosterOptionsHandle handle, ovrID value);
OVRP_PUBLIC_FUNCTION(void) ovr_RosterOptions_ClearSuggestedUsers(ovrRosterOptionsHandle handle);

#endif
