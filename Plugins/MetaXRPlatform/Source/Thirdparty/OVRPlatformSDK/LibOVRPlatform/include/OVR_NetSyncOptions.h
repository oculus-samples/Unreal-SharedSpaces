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

#ifndef OVR_NET_SYNC_OPTIONS_H
#define OVR_NET_SYNC_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_NetSyncVoipStreamMode.h"

/// \file
/// The NetSyncOption configures network connections, focusing on VoIP data
/// streams. It includes 'zone_id' for unique identifiers within the
/// application, 'voip_stream_default' to set default VoIP stream modes , and
/// 'voip_group' to assign a VoIP group upon connection. It can be set when
/// create a new connection and retrieved using ::ovrNetSyncConnectionHandle.
struct ovrNetSyncOptions;

typedef struct ovrNetSyncOptions* ovrNetSyncOptionsHandle;
/// \brief Creates a new instance of ovrNetSyncOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrNetSyncOptionsHandle) ovr_NetSyncOptions_Create();
/// \brief Destroys an existing instance of the ovrNetSyncOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_NetSyncOptions_Destroy(ovrNetSyncOptionsHandle handle);
/// If provided, immediately set the voip_group to this value upon connection
/// and can be retrieved using ovr_NetSyncSession_GetVoipGroup()
OVRP_PUBLIC_FUNCTION(void) ovr_NetSyncOptions_SetVoipGroup(ovrNetSyncOptionsHandle handle, const char * value);
/// When a new remote voip user connects, default that connection to this
/// stream type by default. There are three modes:
/// ovrNetSyncVoipStreamMode_Unknown(), ovrNetSyncVoipStreamMode_Ambisonic(),
/// ovrNetSyncVoipStreamMode_Mono().
OVRP_PUBLIC_FUNCTION(void) ovr_NetSyncOptions_SetVoipStreamDefault(ovrNetSyncOptionsHandle handle, ovrNetSyncVoipStreamMode value);
/// A `string` represents the unique identifier within the current application
/// grouping.
OVRP_PUBLIC_FUNCTION(void) ovr_NetSyncOptions_SetZoneId(ovrNetSyncOptionsHandle handle, const char * value);

#endif
