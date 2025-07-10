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

#ifndef OVR_LAUNCHBLOCKFLOWRESULT_H
#define OVR_LAUNCHBLOCKFLOWRESULT_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
/// It's used to block a user. Results of the launched block dialog including
/// whether the user was successfully blocked and whether the viewer canceled
/// the block flow. It can be retrieved using ovr_User_LaunchBlockFlow()
typedef struct ovrLaunchBlockFlowResult *ovrLaunchBlockFlowResultHandle;

/// A `boolean` indicates whether the viewer successfully blocked the user.
/// Learn more about [blocking
/// users](https://developer.oculus.com/documentation/native/ps-blockingsdk/)
/// from our website.
OVRP_PUBLIC_FUNCTION(bool) ovr_LaunchBlockFlowResult_GetDidBlock(const ovrLaunchBlockFlowResultHandle obj);

/// A `boolean` indicates whether the viewer chose to cancel the block flow. It
/// will be 'true' if the viewer canceled 'Block' from the modal.
OVRP_PUBLIC_FUNCTION(bool) ovr_LaunchBlockFlowResult_GetDidCancel(const ovrLaunchBlockFlowResultHandle obj);


#endif
