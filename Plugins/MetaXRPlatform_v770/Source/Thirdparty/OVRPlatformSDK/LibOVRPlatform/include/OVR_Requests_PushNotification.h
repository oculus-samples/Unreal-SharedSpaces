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

#ifndef OVR_REQUESTS_PUSHNOTIFICATION_H
#define OVR_REQUESTS_PUSHNOTIFICATION_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"



/// \file
/// Push notification ::ovrPushNotificationResultHandle provides a simple and
/// efficient way for devices to register for and receive push notifications,
/// enabling developers to build engaging and interactive applications that
/// deliver timely updates and alerts to users.

/// Register the device to receive push notification. The registered
/// notification id can be fetched by ovr_PushNotificationResult_GetId().
///
/// A message with type ::ovrMessage_PushNotification_Register will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrPushNotificationResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetPushNotificationResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_PushNotification_Register();

#endif
