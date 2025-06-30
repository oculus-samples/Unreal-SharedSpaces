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

#ifndef OVR_REQUESTS_VOIP_H
#define OVR_REQUESTS_VOIP_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"



/// \file
/// The voip API provides platform methods to interact with the voip
/// connections, inputs, syncing, and systems. You can also retrieve different
/// statuses for the current voip state. These methods exist to help integrate
/// a platform solution for voip in your app. Read more about voip in our
/// [docs](https://developer.oculus.com/documentation/native/ps-parties/)

/// Gets whether the microphone is currently available to the app. This can be
/// used to show if the user's voice is able to be heard by other users.
/// Returns a microphone availability state flag which determines whether it is
/// available or not - ::ovrMicrophoneAvailabilityStateHandle.
///
/// A message with type ::ovrMessage_Voip_GetMicrophoneAvailability will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrMicrophoneAvailabilityStateHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetMicrophoneAvailabilityState().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Voip_GetMicrophoneAvailability();

/// Sets whether SystemVoip should be suppressed so that this app's Voip can
/// use the microphone and play incoming Voip audio. Once microphone switching
/// functionality for the user is released, this function will no longer work.
/// You can use ovr_Voip_GetMicrophoneAvailability() to see if the user has
/// allowed the app access to the microphone. This returns a
/// ::ovrSystemVoipStateHandle object which contains statuses about whether the
/// microphone is muted or whether passthrough is enabled.
/// \param suppressed A boolean indicates if the voip is supressed or not.
///
/// A message with type ::ovrMessage_Voip_SetSystemVoipSuppressed will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrSystemVoipStateHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetSystemVoipState().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Voip_SetSystemVoipSuppressed(bool suppressed);

#endif
