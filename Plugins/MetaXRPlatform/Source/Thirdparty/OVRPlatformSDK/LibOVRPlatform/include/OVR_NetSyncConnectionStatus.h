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

#ifndef OVR_NET_SYNC_CONNECTION_STATUS_H
#define OVR_NET_SYNC_CONNECTION_STATUS_H

#include "OVR_Platform_Defs.h"

/// \file
/// It represents the possible status of a ::ovrNetSyncConnectionHandle which
/// allows multiple clients to connect and communicate with each other in real-
/// time. The connection provides a way to manage and facilitate real-time
/// communication and data synchronization between multiple clients in a
/// networked environment.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrNetSyncConnectionStatus_ {
  ovrNetSyncConnectionStatus_Unknown,
  /// This member indicates that the connection of the network sync has been
  /// started and the process is ongoing.
  ovrNetSyncConnectionStatus_Connecting,
  /// This member indicates that the current status of the network sync
  /// connection is not connected.
  ovrNetSyncConnectionStatus_Disconnected,
  /// This member indicates that the current status of the network sync
  /// connection is connected.
  ovrNetSyncConnectionStatus_Connected,
} ovrNetSyncConnectionStatus;

/// Converts an ::ovrNetSyncConnectionStatus enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrNetSyncConnectionStatus_ToString(ovrNetSyncConnectionStatus value);

/// Converts a string representing an ::ovrNetSyncConnectionStatus to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrNetSyncConnectionStatus) ovrNetSyncConnectionStatus_FromString(const char* str);

#endif
