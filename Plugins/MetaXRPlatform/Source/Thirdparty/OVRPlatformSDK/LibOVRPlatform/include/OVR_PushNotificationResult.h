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

#ifndef OVR_PUSHNOTIFICATIONRESULT_H
#define OVR_PUSHNOTIFICATIONRESULT_H

#include "OVR_Platform_Defs.h"

/// \file
/// A PushNotificationResult represents the outcome of a user registering for
/// third-party (3P) notifications. This object contains essential information
/// about the registered notification, which can be used to send push
/// notifications to the user. It can be retrieved using
/// ovr_PushNotification_Register()
typedef struct ovrPushNotificationResult *ovrPushNotificationResultHandle;

/// The registered notification id is a type of string which you can push
/// notification to.
OVRP_PUBLIC_FUNCTION(const char *) ovr_PushNotificationResult_GetId(const ovrPushNotificationResultHandle obj);


#endif
