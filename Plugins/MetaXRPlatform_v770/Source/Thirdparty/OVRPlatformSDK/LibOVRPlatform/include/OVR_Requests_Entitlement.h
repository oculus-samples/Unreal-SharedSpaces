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

#ifndef OVR_REQUESTS_ENTITLEMENT_H
#define OVR_REQUESTS_ENTITLEMENT_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// \file
/// # Entitlements
///
/// When a user has an entitlement to an application, it means they have purchased
/// and downloaded the application via the Oculus store, or are otherwise entitled
/// to run the application. The Platform SDK entitlement check system allows you to
/// verify at run-time that the currently user attempting to run your application
/// is in fact entitled. This check works even if the user is offline.
///
/// It's critical to note that this entitlement check does not happen automatically,
/// and if it fails it does not automatically exit the application or have any other
/// side effect. It's up to you to call the entitlement check and handle failure
/// however you see fit.
///
/// To make an entitlement check use ovr_Entitlement_GetIsViewerEntitled(). This is
/// an asynchronous call, so you may wish to avoid making other platform calls until
/// you handle the response, but this is not strictly required.
///
/// ## Development:
///
/// During development the entitlement check can return false unless a number of
/// additional steps are taken. Most of these steps will require you to set things
/// up using the developer website at https://dashboard.oculus.com.
///
/// Each application must be set up:
///
///  1. You must create an application at https://dashboard.oculus.com and obtain
///       the application ID, which you provide to the Platform SDK.
///  2. You must upload a binary package for your application on the developer
///       website at https://dashboard.oculus.com/application/[YOUR_APP_ID]/build.
///       During development this package does not need to function in any way, but
///       it does need to exist.
///
/// Each developer that needs to pass the application's entitlement check must:
///
///  1. Have an entitlement to the application by being added as a developer for the
///       application, which can be set up on the developer website at
///       https://dashboard.oculus.com/application/[YOUR_APP_ID]/developers.
///  2. Be able to see a binary package for the application by being in a release
///       channel that has a binary package, which can be set up on the developer
///       website at https://dashboard.oculus.com/application/[YOUR_APP_ID]/build.
///
/// NOTE: If some of your developers are not part of the application's organization,
/// and they need to run your application outside the normal install directory, that
/// can be enabled by adding a special registry key "AllowDevSideloaded" as DWORD(1)
/// to the registry folder at  HKLM\\SOFTWARE\\Wow6432Node\\Oculus VR, LLC\\Oculus.
/// This does not bypass having a valid entitlement, it just bypasses the directory
/// check.
///
///
/// Once the above steps are completed, the entitlement check should succeed even if
/// running a local build of your application.


/// \file
/// The Entitlement API is a crucial component of the Meta Quest Store's app
/// verification process. It allows developers to check whether a user has
/// purchased or obtained their app legitimately, ensuring that only authorized
/// users can access the app. The API must be called within 10 seconds of the
/// user launching the app and does not require internet connectivity. In the
/// event of a failed entitlement check, developers are responsible for
/// handling the error in their app code, such as by displaying an error
/// message and quitting the app. This API plays a vital role in maintaining
/// the security and integrity of the Meta Quest Store ecosystem. See more
/// details [here](https://developer.oculus.com/documentation/native/ps-
/// entitlement-check/).

/// Returns whether the current user is entitled to the current app. The
/// primary purpose of this function is to verify user access rights to the
/// application, ensuring that the user is authorized to use it. See example
/// usage [here](https://developer.oculus.com/documentation/native/ps-
/// entitlement-check/#entitlement).
///
/// A message with type ::ovrMessage_Entitlement_GetIsViewerEntitled will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Entitlement_GetIsViewerEntitled();

#endif
