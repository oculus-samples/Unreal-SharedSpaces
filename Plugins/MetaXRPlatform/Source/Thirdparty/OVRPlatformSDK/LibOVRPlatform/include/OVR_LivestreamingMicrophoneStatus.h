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

#ifndef OVR_LIVESTREAMING_MICROPHONE_STATUS_H
#define OVR_LIVESTREAMING_MICROPHONE_STATUS_H

#include "OVR_Platform_Defs.h"

/// \file
/// It's an enum that represents the status of a microphone during a
/// livestream. It provides a simple and standardized way to represent the
/// status of a microphone during a livestream, which can be useful for various
/// applications and use cases. See
/// [livestreaming](https://developer.oculus.com/blog/sharing-via-
/// livestreaming-now-available-for-rift-applications/) documentation for more
/// details.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrLivestreamingMicrophoneStatus_ {
  ovrLivestreamingMicrophoneStatus_Unknown,
  /// It indicates that the microphone is currently on and transmitting audio.
  /// This value can be used to indicate that the microphone is functioning
  /// properly and that audio is being captured and transmitted during the
  /// livestream.
  ovrLivestreamingMicrophoneStatus_MicrophoneOn,
  /// It indicates that the microphone is currently off and not transmitting
  /// audio. This value can be used to indicate that the microphone has been
  /// turned off or muted, either intentionally or unintentionally, during the
  /// livestream.
  ovrLivestreamingMicrophoneStatus_MicrophoneOff,
} ovrLivestreamingMicrophoneStatus;

/// Converts an ::ovrLivestreamingMicrophoneStatus enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLivestreamingMicrophoneStatus_ToString(ovrLivestreamingMicrophoneStatus value);

/// Converts a string representing an ::ovrLivestreamingMicrophoneStatus to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrLivestreamingMicrophoneStatus) ovrLivestreamingMicrophoneStatus_FromString(const char* str);

#endif
