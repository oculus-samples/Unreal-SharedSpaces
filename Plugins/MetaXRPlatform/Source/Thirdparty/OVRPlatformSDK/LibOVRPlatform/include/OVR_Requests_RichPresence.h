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

#ifndef OVR_REQUESTS_RICHPRESENCE_H
#define OVR_REQUESTS_RICHPRESENCE_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_DestinationArray.h"
#include "OVR_RichPresenceOptions.h"


/// \file
/// Rich Presence has been deprecated in favor of [Group
/// Presence](https://developers.meta.com/horizon/documentation/native/ps-
/// group-presence-overview).

/// \deprecated Use ovr_GroupPresence_Clear()
///
/// A message with type ::ovrMessage_RichPresence_Clear will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_RichPresence_Clear();

/// Gets all the ::ovrDestinationHandle that the presence can be set to
///
/// A message with type ::ovrMessage_RichPresence_GetDestinations will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrDestinationArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetDestinationArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_RichPresence_GetDestinations();

/// Get the next page of entries
/// \param handle The handle to the array to get the next page of entries.
///
/// A message with type ::ovrMessage_RichPresence_GetNextDestinationArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrDestinationArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetDestinationArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_RichPresence_GetNextDestinationArrayPage(ovrDestinationArrayHandle handle);

/// \param richPresenceOptions The options of the rich presence.
/// \deprecated Use ovr_GroupPresence_Set().
///
/// A message with type ::ovrMessage_RichPresence_Set will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_RichPresence_Set(ovrRichPresenceOptionsHandle richPresenceOptions);

#endif
