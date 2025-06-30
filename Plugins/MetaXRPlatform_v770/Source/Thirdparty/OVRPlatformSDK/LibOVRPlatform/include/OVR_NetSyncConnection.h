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

#ifndef OVR_NETSYNCCONNECTION_H
#define OVR_NETSYNCCONNECTION_H

#include "OVR_Platform_Defs.h"
#include "OVR_NetSyncConnectionStatus.h"
#include "OVR_NetSyncDisconnectReason.h"
#include "OVR_Types.h"

/// \file
/// It represents the connection of a network synchronization system that
/// allows multiple clients to connect and communicate with each other in real-
/// time. It provides a way to manage and facilitate real-time communication
/// and data synchronization between multiple clients in a networked
/// environment.
typedef struct ovrNetSyncConnection *ovrNetSyncConnectionHandle;

/// A 'long' integer ID which can be used to uniquely identify the network
/// synchronization connection.
OVRP_PUBLIC_FUNCTION(long long) ovr_NetSyncConnection_GetConnectionId(const ovrNetSyncConnectionHandle obj);

/// If the status is ovrNetSyncConnectionStatus_Disconnected(),
/// ovrNetSyncDisconnectReason() specifies the reason.
/// ovrNetSyncDisconnectReason_Unknown() - The disconnect reason was unknown.
/// ovrNetSyncDisconnectReason_LocalTerminated() - The disconnect was requested
/// by an user. ovrNetSyncDisconnectReason_ServerTerminated() - The server
/// closed the connection. ovrNetSyncDisconnectReason_Failed() - The initial
/// connection never succeeded. ovrNetSyncDisconnectReason_Lost() - The
/// disconnect was caused by network timeout.
OVRP_PUBLIC_FUNCTION(ovrNetSyncDisconnectReason) ovr_NetSyncConnection_GetDisconnectReason(const ovrNetSyncConnectionHandle obj);

/// The ID of the local session. Will be null if the connection is not active.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_NetSyncConnection_GetSessionId(const ovrNetSyncConnectionHandle obj);

/// A ovrNetSyncConnectionStatus() that defines the different status of the
/// network synchronization connection. ovrNetSyncConnectionStatus_Unknown() -
/// The current connection status is unknown.
/// ovrNetSyncConnectionStatus_Connecting() - The connection has been started
/// and the process is ongoing. ovrNetSyncConnectionStatus_Disconnected() - The
/// current connection status is disconnected.
/// ovrNetSyncConnectionStatus_Connected() - The connection has been
/// established.
OVRP_PUBLIC_FUNCTION(ovrNetSyncConnectionStatus) ovr_NetSyncConnection_GetStatus(const ovrNetSyncConnectionHandle obj);

/// A `string` represents the unique identifier within the current application
/// grouping.
OVRP_PUBLIC_FUNCTION(const char *) ovr_NetSyncConnection_GetZoneId(const ovrNetSyncConnectionHandle obj);


#endif
