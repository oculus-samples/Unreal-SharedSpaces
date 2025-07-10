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

#ifndef OVR_APPLICATIONLIFECYCLE_H
#define OVR_APPLICATIONLIFECYCLE_H

#include "OVR_LaunchDetails.h"
#include "OVR_LaunchResult.h"

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

/// Returns information about how the application was started. This function
/// provides details about the launch intent, such as the type of intent
/// ovr_LaunchDetails_GetLaunchType() and any additional data that was passed
/// along with it. By calling this function, you can gain insight into how your
/// application was launched and take appropriate action based on that
/// information.
OVRP_PUBLIC_FUNCTION(ovrLaunchDetailsHandle) ovr_ApplicationLifecycle_GetLaunchDetails();

/// Logs if the user successfully deeplinked to a destination. This function
/// takes two parameters: a string tracking ID and a launch result. The
/// tracking ID is used to identify the specific deeplink attempt, while the
/// launch result indicates whether the deeplink was ovrLaunchResult_Success()
/// or not. By logging this information, you can track the effectiveness of
/// your deeplinking efforts and make adjustments as needed.
/// \param trackingID The Tracking ID is a unique identifier assigned to each deeplink attempt. It allows developers to track the success or failure of individual deeplink attempts and gain insights into the effectiveness of their deeplinking efforts.
/// \param result An enum that indicates the outcome of an attempt to launch this application through a deeplink, including whether the attempt was ovrLaunchResult_Success() or not, and if not, the specific reasons for the failure.
OVRP_PUBLIC_FUNCTION(void) ovr_ApplicationLifecycle_LogDeeplinkResult(const char *trackingID, ovrLaunchResult result);


#endif
