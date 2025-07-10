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

#ifndef OVR_NETSYNCSESSION_H
#define OVR_NETSYNCSESSION_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stdbool.h>

/// \file
/// It represents the session of ::ovrNetSyncConnectionHandle that allows
/// multiple clients to connect and communicate with each other in real-time.
/// It provides a way to manage and facilitate real-time communication and data
/// synchronization between multiple clients in a networked environment.
typedef struct ovrNetSyncSession *ovrNetSyncSessionHandle;

/// A `long` integer represents the unique ID of the
/// ::ovrNetSyncConnectionHandle within which this session exists.
OVRP_PUBLIC_FUNCTION(long long) ovr_NetSyncSession_GetConnectionId(const ovrNetSyncSessionHandle obj);

/// `True` if the local session has muted this session.
OVRP_PUBLIC_FUNCTION(bool) ovr_NetSyncSession_GetMuted(const ovrNetSyncSessionHandle obj);

/// The cloud networking internal session ID that can uniquely represent this
/// session within the connection.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_NetSyncSession_GetSessionId(const ovrNetSyncSessionHandle obj);

/// The ovrID of the user behind this session.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_NetSyncSession_GetUserId(const ovrNetSyncSessionHandle obj);

/// A `string` represents the name of the voip group that this session is
/// subscribed to.
OVRP_PUBLIC_FUNCTION(const char *) ovr_NetSyncSession_GetVoipGroup(const ovrNetSyncSessionHandle obj);


#endif
