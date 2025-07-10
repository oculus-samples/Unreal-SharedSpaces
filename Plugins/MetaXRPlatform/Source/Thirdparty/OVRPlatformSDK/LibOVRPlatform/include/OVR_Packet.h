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

#ifndef OVR_PACKET_H
#define OVR_PACKET_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>

/// \file
/// A packet owned by an ::ovrInstalledApplicationHandle is a basic unit of
/// data transmission over a network, allowing devices to communicate with each
/// other efficiently and reliably. UDP and TCP are two protocols that govern
/// how those packets are transmitted over a network. UDP is suitable for
/// applications that require fast transmission and can tolerate some packet
/// loss, while TCP is better suited for applications that require reliable
/// data transfer.
typedef struct ovrPacket *ovrPacketHandle;

/// This method is used to release the memory of a packet which is owned by an
/// ::ovrInstalledApplicationHandle and contains data transmitted over the
/// network.
OVRP_PUBLIC_FUNCTION(void) ovr_Packet_Free(const ovrPacketHandle obj);

/// This size field represents the size of the packet in bytes. Ideally, it is
/// recommended to keep a message under 1200 bytes so that data can fit into a
/// single packet.
OVRP_PUBLIC_FUNCTION(const void *) ovr_Packet_GetBytes(const ovrPacketHandle obj);

/// This `id` field represents the id of the sender of the packet.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_Packet_GetSenderID(const ovrPacketHandle obj);

OVRP_PUBLIC_FUNCTION(size_t)        ovr_Packet_GetSize(const ovrPacketHandle obj);

#endif
