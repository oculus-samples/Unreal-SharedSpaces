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

#ifndef OVR_MICROPHONEAVAILABILITYSTATE_H
#define OVR_MICROPHONEAVAILABILITYSTATE_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// \file
/// It represents the availability of a microphone device. It can be retrieved
/// using ovr_Voip_GetMicrophoneAvailability(). It has only one field,
/// microphone_available, which is a boolean value that indicates whether a
/// microphone is available or not. This data structure can be used by
/// applications to determine whether they can use the microphone for audio
/// input or not.
typedef struct ovrMicrophoneAvailabilityState *ovrMicrophoneAvailabilityStateHandle;

/// A `boolean` indicates whether the microphone is currently available or not.
/// If there is any update on the microphone availability, it will be retrieved
/// as a notification using
/// #ovrMessage_Notification_Voip_MicrophoneAvailabilityStateUpdate.
OVRP_PUBLIC_FUNCTION(bool) ovr_MicrophoneAvailabilityState_GetMicrophoneAvailable(const ovrMicrophoneAvailabilityStateHandle obj);


#endif
