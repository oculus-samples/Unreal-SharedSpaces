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

#ifndef OVR_VOIP_BITRATE_H
#define OVR_VOIP_BITRATE_H

#include "OVR_Platform_Defs.h"

/// \file
/// It's a set of predefined values that represent different levels of audio
/// quality for Voice over IP (VoIP) connections. It can be used in
/// ovr_VoipOptions_SetBitrateForNewConnections() to set the maximum average
/// bitrate the audio codec should use for new VoIP connections.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrVoipBitrate_ {
  ovrVoipBitrate_Unknown,
  /// Very low audio quality for minimal network usage. This may not give the
  /// full range of Hz for audio, but it will save on network usage.
  ovrVoipBitrate_B16000,
  /// Lower audio quality but also less network usage.
  ovrVoipBitrate_B24000,
  /// This is the default bitrate for voip connections. It should be the best
  /// tradeoff between audio quality and network usage.
  ovrVoipBitrate_B32000,
  /// Higher audio quality at the expense of network usage. Good if there's music
  /// being streamed over the connections
  ovrVoipBitrate_B64000,
  /// Even higher audio quality for music streaming or radio-like quality.
  ovrVoipBitrate_B96000,
  /// At this point the audio quality should be perceptually indistinguishable
  /// from the uncompressed input.
  ovrVoipBitrate_B128000,
} ovrVoipBitrate;

/// Converts an ::ovrVoipBitrate enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrVoipBitrate_ToString(ovrVoipBitrate value);

/// Converts a string representing an ::ovrVoipBitrate to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrVoipBitrate) ovrVoipBitrate_FromString(const char* str);

#endif
