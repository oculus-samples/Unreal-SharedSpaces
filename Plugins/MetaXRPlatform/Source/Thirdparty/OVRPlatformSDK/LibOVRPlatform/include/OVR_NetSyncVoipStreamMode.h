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

#ifndef OVR_NET_SYNC_VOIP_STREAM_MODE_H
#define OVR_NET_SYNC_VOIP_STREAM_MODE_H

#include "OVR_Platform_Defs.h"

/// \file
/// A network synchronization system allows multiple clients to connect and
/// communicate with each other in real-time. Once a
/// ::ovrNetSyncConnectionHandle is established, user can choose the stream
/// mode for the connection. The ovr_NetSyncOptions_SetVoipStreamDefault() will
/// be used when a new VoIP(Voice over Internet Protocol) user connects.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrNetSyncVoipStreamMode_ {
  ovrNetSyncVoipStreamMode_Unknown,
  /// This `enum` member represents the ambisonic steam mode the VoIP stream
  /// uses. It is the default value of ovr_NetSyncOptions_SetVoipStreamDefault().
  /// Since it allows for the creation of immersive, surround sound experiences
  /// that simulate real-world audio environments, it typically used in virtual
  /// reality (VR) and augmented reality (AR) applications.
  ovrNetSyncVoipStreamMode_Ambisonic,
  /// This `enum` member represents the mono steam mode the VoIP stream uses. The
  /// advantages mono stream mode has over ambisonic steam mode is the audio
  /// encoding and decoding require less computational resources and thus audio
  /// streams require less bandwidth. So it is typically used in applications
  /// with limited network resources.
  ovrNetSyncVoipStreamMode_Mono,
} ovrNetSyncVoipStreamMode;

/// Converts an ::ovrNetSyncVoipStreamMode enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrNetSyncVoipStreamMode_ToString(ovrNetSyncVoipStreamMode value);

/// Converts a string representing an ::ovrNetSyncVoipStreamMode to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrNetSyncVoipStreamMode) ovrNetSyncVoipStreamMode_FromString(const char* str);

#endif
