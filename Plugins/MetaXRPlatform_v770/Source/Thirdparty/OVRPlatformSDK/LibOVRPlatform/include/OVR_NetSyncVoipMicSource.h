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

#ifndef OVR_NET_SYNC_VOIP_MIC_SOURCE_H
#define OVR_NET_SYNC_VOIP_MIC_SOURCE_H

#include "OVR_Platform_Defs.h"

/// \file
/// A network synchronization system allows multiple clients to connect and
/// communicate with each other in real-time. Once a
/// ::ovrNetSyncConnectionHandle is established, it uses Voice over Internet
/// Protocol to allow users to make voice calls using the internet. The mic
/// source will represent the current source of the mic in the call.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrNetSyncVoipMicSource_ {
  ovrNetSyncVoipMicSource_Unknown,
  /// This `enum` member represents no net sync connection has been identified as
  /// the source from which the data was sent to the server
  ovrNetSyncVoipMicSource_None,
  /// This `enum` member represents an internal net sync connection has been
  /// identified as the source from which the data was sent to the server
  ovrNetSyncVoipMicSource_Internal,
} ovrNetSyncVoipMicSource;

/// Converts an ::ovrNetSyncVoipMicSource enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrNetSyncVoipMicSource_ToString(ovrNetSyncVoipMicSource value);

/// Converts a string representing an ::ovrNetSyncVoipMicSource to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrNetSyncVoipMicSource) ovrNetSyncVoipMicSource_FromString(const char* str);

#endif
