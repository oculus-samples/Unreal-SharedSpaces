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

#ifndef OVR_MICROPHONE_H
#define OVR_MICROPHONE_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdint.h>

/// \file
/// This object provides a comprehensive way to access and manipulate audio
/// data from a microphone device. Its availability can be retrieving using
/// ovr_MicrophoneAvailabilityState_GetMicrophoneAvailable(). With Microphone
/// class, developers can build engaging and interactive applications that
/// leverage real-time audio input, such as voice chat, audio recording, or
/// speech recognition.
typedef struct ovrMicrophone *ovrMicrophoneHandle;

/// Returns the minimum number of samples available to be read. This function
/// is inherently racy, it is possible that more samples may be returned by the
/// next call to getPCM. This function is only implemented on Android. Windows
/// will always return 0.
OVRP_PUBLIC_FUNCTION(size_t) ovr_Microphone_GetNumSamplesAvailable(const ovrMicrophoneHandle obj);

/// Returns the size of the internal ringbuffer used by the microhone in
/// elements. This size is the maximum number of elements that can ever be
/// returned by ovr_Microphone_GetPCM()*.
///
/// This function can be safely called from any thread.
OVRP_PUBLIC_FUNCTION(size_t) ovr_Microphone_GetOutputBufferMaxSize(const ovrMicrophoneHandle obj);

/// Gets all available samples of microphone data and copies it into
/// outputBuffer. The microphone will generate data at roughly the rate of 480
/// samples per 10ms. The data format is 16 bit fixed point 48khz mono.
///
/// This function can be safely called from any thread.
OVRP_PUBLIC_FUNCTION(size_t) ovr_Microphone_GetPCM(const ovrMicrophoneHandle obj, int16_t *outputBuffer, size_t outputBufferNumElements);

/// Gets all available samples of microphone data and copies it into
/// outputBuffer. The microphone will generate data at roughly the rate of 480
/// samples per 10ms. The data format is 32 bit floating point 48khz mono.
///
/// This function can be safely called from any thread.
OVRP_PUBLIC_FUNCTION(size_t) ovr_Microphone_GetPCMFloat(const ovrMicrophoneHandle obj, float *outputBuffer, size_t outputBufferNumElements);

/// Gets all available samples of microphone data and copies it into
/// outputBuffer. The microphone will generate data at roughly the rate of 480
/// samples per 10ms. The data format is 32 bit floating point 48khz mono.
///
/// This function can be safely called from any thread.
/// \deprecated Use ovr_Microphone_GetPCMFloat() instead.
OVRP_PUBLIC_FUNCTION(size_t) ovr_Microphone_ReadData(const ovrMicrophoneHandle obj, float *outputBuffer, size_t outputBufferSize);

/// Indicates that the caller is fine with a certain delay in the delivery of
/// recorded audio frames. Setting this to a low value will reduce the latency
/// at the cost of efficiency. Note that this is only a hint; the actual
/// implementation may ignore it.
OVRP_PUBLIC_FUNCTION(void) ovr_Microphone_SetAcceptableRecordingDelayHint(const ovrMicrophoneHandle obj, size_t delayMs);

/// Register a callback that will be called whenever audio data is available
/// for the microphone.
OVRP_PUBLIC_FUNCTION(void) ovr_Microphone_SetAudioDataAvailableCallback(const ovrMicrophoneHandle obj, MicrophoneDataAvailableCallback cb, void *userData);

/// Starts microphone recording. The VoIP session can be established by
/// ovr_Voip_Start(). After this is called pcm data can be extracted using
/// ovr_Microphone_GetPCM().
///
/// This function can be safely called from any thread.
OVRP_PUBLIC_FUNCTION(void) ovr_Microphone_Start(const ovrMicrophoneHandle obj);

/// Stops microphone recording. The VoIP session can be terminated by
/// ovr_Voip_Stop().
///
/// This function can be safely called from any thread.
OVRP_PUBLIC_FUNCTION(void) ovr_Microphone_Stop(const ovrMicrophoneHandle obj);


#endif
