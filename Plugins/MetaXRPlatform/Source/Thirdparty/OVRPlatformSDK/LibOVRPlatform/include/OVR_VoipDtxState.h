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

#ifndef OVR_VOIP_DTX_STATE_H
#define OVR_VOIP_DTX_STATE_H

#include "OVR_Platform_Defs.h"

/// \file
/// This is an enum that defines the possible states for the Opus codec's
/// discontinuous transmission (DTX) feature. It allows you to control whether
/// the Opus codec uses DTX to conserve battery power and reduce transmission
/// rate during pauses in the voice chat. It can be used as the type for the
/// ovr_VoipOptions_SetCreateNewConnectionUseDtx()

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrVoipDtxState_ {
  ovrVoipDtxState_Unknown,
  /// This state indicates that the DTX feature is enabled. When enabled, the
  /// Opus codec will only transmit data when a person is speaking, which can
  /// conserve battery power and reduce transmission rate during pauses in the
  /// voice chat.
  ovrVoipDtxState_Enabled,
  /// This state indicates that the DTX feature is disabled. When disabled, the
  /// Opus codec will continuously transmit data, even during pauses in the voice
  /// chat.
  ovrVoipDtxState_Disabled,
} ovrVoipDtxState;

/// Converts an ::ovrVoipDtxState enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrVoipDtxState_ToString(ovrVoipDtxState value);

/// Converts a string representing an ::ovrVoipDtxState to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrVoipDtxState) ovrVoipDtxState_FromString(const char* str);

#endif
