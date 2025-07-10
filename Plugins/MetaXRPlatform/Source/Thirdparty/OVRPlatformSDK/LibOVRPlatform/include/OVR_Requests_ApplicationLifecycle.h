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

#ifndef OVR_REQUESTS_APPLICATIONLIFECYCLE_H
#define OVR_REQUESTS_APPLICATIONLIFECYCLE_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// \file
/// # Application Lifecycle
///
/// The Application Lifecycle APIs are designed to help you manage application state
/// within the Oculus Runtime (PC only right now). As of writing this, the only
/// interesting cases here revolve around Universal Windows Platform (UWP) Applications.
///
/// ## Why it's needed:
/// UWP applications ship in two parts: launcher and implementation. However,
/// the Oculus runtime only knows about the application it launched. We now provide
/// a way to register the second application with our runtime.
///
/// ## How it works:
/// The launcher will need to request a SessionKey from the Runtime using
///   ovr_ApplicationLifecycle_GetSessionKey();
///
/// The launcher will then need to that session key to the second application.
/// The second application will then need to register itself using the session key using:
///   ovr_ApplicationLifecycle_RegisterSessionKey(char * sessionKey)
///
/// The second application will now be able to communicate with the runtime.


/// \file
/// This ApplicationLifecycle API provides methods for managing the lifecycle
/// of an application, including retrieving information about how the
/// application was started, such as the type of intent
/// ovr_LaunchDetails_GetLaunchType(), logging the results of deeplinking
/// attempts, whether it was ovrLaunchResult_Success() or not, and handling
/// changes to the launch intent.

/// Return a list of all the pids that we know are registered to your
/// application. This method is useful for tracking and managing the registered
/// PIDs associated with your application.
///
/// A message with type ::ovrMessage_ApplicationLifecycle_GetRegisteredPIDs will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrPidArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetPidArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_ApplicationLifecycle_GetRegisteredPIDs();

/// The launcher, which we know and trust can use this to create a key, pass it
/// to the UWP app, which will be able to register using it as the original
/// application.
///
/// A message with type ::ovrMessage_ApplicationLifecycle_GetSessionKey will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ovr_Message_GetString().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_ApplicationLifecycle_GetSessionKey();

/// The actual UWP app will be able to register as the original application
/// using the GUID from ovr_ApplicationLifecycle_GetSessionKey().
/// \param sessionKey The GUID obtained by calling ovr_ApplicationLifecycle_GetSessionKey().
///
/// A message with type ::ovrMessage_ApplicationLifecycle_RegisterSessionKey will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_ApplicationLifecycle_RegisterSessionKey(const char *sessionKey);

#endif
