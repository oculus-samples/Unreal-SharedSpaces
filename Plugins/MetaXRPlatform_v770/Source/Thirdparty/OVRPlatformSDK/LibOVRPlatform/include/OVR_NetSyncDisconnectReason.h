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

#ifndef OVR_NET_SYNC_DISCONNECT_REASON_H
#define OVR_NET_SYNC_DISCONNECT_REASON_H

#include "OVR_Platform_Defs.h"

/// \file
/// It represents the possible reasons why the status of a
/// ::ovrNetSyncConnectionHandle, which allows multiple clients to connect and
/// communicate with each other in real-time, is disconnected. The connection
/// provides a way to manage and facilitate real-time communication and data
/// synchronization between multiple clients in a networked environment.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrNetSyncDisconnectReason_ {
  ovrNetSyncDisconnectReason_Unknown,
  /// This member indicates that the disconnect of the
  /// ::ovrNetSyncConnectionHandle was initialized from the a user request.
  ovrNetSyncDisconnectReason_LocalTerminated,
  /// This member indicates that the connection of the
  /// ::ovrNetSyncConnectionHandle was shutdown by the server intentionally.
  ovrNetSyncDisconnectReason_ServerTerminated,
  /// This member indicates that the initial connection request never succeeded.
  ovrNetSyncDisconnectReason_Failed,
  /// This member indicates that the ::ovrNetSyncConnectionHandle was shutdown
  /// because of the network timeout.
  ovrNetSyncDisconnectReason_Lost,
} ovrNetSyncDisconnectReason;

/// Converts an ::ovrNetSyncDisconnectReason enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrNetSyncDisconnectReason_ToString(ovrNetSyncDisconnectReason value);

/// Converts a string representing an ::ovrNetSyncDisconnectReason to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrNetSyncDisconnectReason) ovrNetSyncDisconnectReason_FromString(const char* str);

#endif
