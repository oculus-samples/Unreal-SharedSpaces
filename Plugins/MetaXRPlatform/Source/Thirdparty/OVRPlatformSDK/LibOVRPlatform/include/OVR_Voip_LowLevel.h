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

#ifndef OVR_VOIP_LOWLEVEL_H
#define OVR_VOIP_LOWLEVEL_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

#include "OVR_VoipEncoder.h"
#include "OVR_VoipDecoder.h"
#include "OVR_Microphone.h"

#ifdef __cplusplus
extern "C" {
#endif

OVRP_PUBLIC_FUNCTION(ovrVoipEncoderHandle) ovr_Voip_CreateEncoder();
OVRP_PUBLIC_FUNCTION(void) ovr_Voip_DestroyEncoder(ovrVoipEncoderHandle encoder);

OVRP_PUBLIC_FUNCTION(ovrVoipDecoderHandle) ovr_Voip_CreateDecoder();
OVRP_PUBLIC_FUNCTION(void) ovr_Voip_DestroyDecoder(ovrVoipDecoderHandle decoder);

OVRP_PUBLIC_FUNCTION(ovrMicrophoneHandle) ovr_Microphone_Create();
OVRP_PUBLIC_FUNCTION(void) ovr_Microphone_Destroy(ovrMicrophoneHandle obj);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // OVR_VOIP_LOWLEVEL_H
