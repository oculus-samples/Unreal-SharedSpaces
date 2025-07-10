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

#ifndef OVR_NETSYNCSESSIONSCHANGEDNOTIFICATION_H
#define OVR_NETSYNCSESSIONSCHANGEDNOTIFICATION_H

#include "OVR_Platform_Defs.h"
#include "OVR_NetSyncSessionArray.h"

/// \file
/// When a new list of sessions was added or the list of known connected
/// sessions has changed, this #ovrMessage_Notification_NetSync_SessionsChanged
/// will be sent. When the status of a connection has changed, the
/// #ovrMessage_Notification_NetSync_ConnectionStatusChanged will be sent.
typedef struct ovrNetSyncSessionsChangedNotification *ovrNetSyncSessionsChangedNotificationHandle;

/// A `long` integer ID which can be used to uniquely identify the network
/// synchronization connection.
OVRP_PUBLIC_FUNCTION(long long) ovr_NetSyncSessionsChangedNotification_GetConnectionId(const ovrNetSyncSessionsChangedNotificationHandle obj);

/// An `array` which contains the new list of ::ovrNetSyncSessionHandle.
OVRP_PUBLIC_FUNCTION(ovrNetSyncSessionArrayHandle) ovr_NetSyncSessionsChangedNotification_GetSessions(const ovrNetSyncSessionsChangedNotificationHandle obj);


#endif
