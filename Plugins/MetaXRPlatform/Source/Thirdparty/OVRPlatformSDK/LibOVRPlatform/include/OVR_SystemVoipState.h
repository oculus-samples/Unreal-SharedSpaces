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

#ifndef OVR_SYSTEMVOIPSTATE_H
#define OVR_SYSTEMVOIPSTATE_H

#include "OVR_Platform_Defs.h"
#include "OVR_SystemVoipStatus.h"
#include "OVR_VoipMuteState.h"

/// \file
/// The state of the voip that is used in parties and horizon home. This class
/// contains different statuses that is used to control the microphone and
/// input/output for commands or chat in your application. You can read more
/// about system voip
/// [here](https://developer.oculus.com/documentation/native/ps-parties/#voip-
/// options).
typedef struct ovrSystemVoipState *ovrSystemVoipStateHandle;

/// A flag that is used to indicate the current state of the microphone. The
/// status can be of the following types:
///
/// - Unknown: ovrVoipMuteState_Unknown()
///
/// - Muted: ovrVoipMuteState_Muted()
///
/// - Unmuted: ovrVoipMuteState_Unmuted()
OVRP_PUBLIC_FUNCTION(ovrVoipMuteState) ovr_SystemVoipState_GetMicrophoneMuted(const ovrSystemVoipStateHandle obj);

/// The status enum that indicates the current state of the system voip. The
/// status can be of the following types:
///
/// - Unknown: ovrSystemVoipStatus_Unknown()
///
/// - Unavailable: ovrSystemVoipStatus_Unavailable()
///
/// - Suppressed: ovrSystemVoipStatus_Suppressed()
///
/// - Active: ovrSystemVoipStatus_Active()
OVRP_PUBLIC_FUNCTION(ovrSystemVoipStatus) ovr_SystemVoipState_GetStatus(const ovrSystemVoipStateHandle obj);


#endif
