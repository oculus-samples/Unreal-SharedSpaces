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

#ifndef OVR_LAUNCHUNBLOCKFLOWRESULT_H
#define OVR_LAUNCHUNBLOCKFLOWRESULT_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
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
