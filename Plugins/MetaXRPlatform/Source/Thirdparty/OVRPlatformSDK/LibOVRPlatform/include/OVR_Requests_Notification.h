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

#ifndef OVR_REQUESTS_NOTIFICATION_H
#define OVR_REQUESTS_NOTIFICATION_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// \file
/// *** Notifications Overview:
/// Notifications are a way for the Oculus platform to push timely updates to your
/// application. These are typically time-sensitive items and try to be prolific.
/// In addition to your application, they usually present themselves in the 2D/3D
/// Stores as well as Universal Menu.
///
/// *** Read Status:
/// Notifications will currently show up in these areas until they either expire or
/// they're marked as read. If you mark a notification as read, it'll be removed
/// from all surfaces.


/// \file
/// The Notifications class provides a way to manage and display notifications
/// to the user. Notifications can be used to inform the user of important
/// events, such as new messages, friend requests, or updates to installed
/// apps. See more info about Platform Solutions
/// [here](https://developer.oculus.com/documentation/native/ps-platform-
/// intro/).

/// Marks a notification as read, causing it to disappear from various surfaces
/// such as the Universal Menu and in-app retrieval. This action is useful for
/// indicating that the user has acknowledged or acted upon the notification.
/// \param notificationID The unique identifier (UUID) of the notification to be marked as read.
///
/// A message with type ::ovrMessage_Notification_MarkAsRead will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Notification_MarkAsRead(ovrID notificationID);

#endif
