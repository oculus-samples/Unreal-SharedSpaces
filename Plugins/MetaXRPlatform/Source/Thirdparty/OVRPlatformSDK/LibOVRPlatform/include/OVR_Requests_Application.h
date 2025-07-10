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

#ifndef OVR_REQUESTS_APPLICATION_H
#define OVR_REQUESTS_APPLICATION_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_AppDownloadResult.h"
#include "OVR_ApplicationOptions.h"
#include "OVR_ApplicationVersion.h"

/// \file
/// *** Application Overview:
/// An application is what you're writing! These requests/methods will allow you to
/// pull basic metadata about your application.


/// \file
/// The Application API provides ways to manage and interact with applications
/// on the platform, including retrieving information about installed apps, for
/// example: getting ovr_ApplicationVersion_GetCurrentCode(), launching other
/// apps and managing app downloads and updates.

/// Cancel an app download that is in progress. It will return a result when
/// the download is cancelled.
///
/// A message with type ::ovrMessage_Application_CancelAppDownload will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAppDownloadResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAppDownloadResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Application_CancelAppDownload();

/// Track download progress for an app.
///
/// A message with type ::ovrMessage_Application_CheckAppDownloadProgress will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAppDownloadProgressResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAppDownloadProgressResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Application_CheckAppDownloadProgress();

/// Requests version information, including the
/// ovr_ApplicationVersion_GetCurrentCode() and
/// ovr_ApplicationVersion_GetCurrentName() of the currently installed app and
/// ovr_ApplicationVersion_GetLatestCode(),
/// ovr_ApplicationVersion_GetLatestName(), ovr_ApplicationVersion_GetSize()
/// and ovr_ApplicationVersion_GetReleaseDate() of the latest app update.
///
/// A message with type ::ovrMessage_Application_GetVersion will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrApplicationVersionHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetApplicationVersion().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Application_GetVersion();

/// Installs the app update that was previously downloaded. Once the install
/// begins the application will exit automatically. After the installation
/// process is complete, the app will be relaunched based on the options passed
/// in.
/// \param deeplink_options Additional configuration for this relaunch, which is optional. It contains 5 fields ovr_ApplicationOptions_SetDeeplinkMessage(), ovr_ApplicationOptions_SetDestinationApiName(), ovr_ApplicationOptions_SetLobbySessionId(), ovr_ApplicationOptions_SetMatchSessionId() and ovr_ApplicationOptions_SetRoomId().
///
/// A message with type ::ovrMessage_Application_InstallAppUpdateAndRelaunch will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAppDownloadResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAppDownloadResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Application_InstallAppUpdateAndRelaunch(ovrApplicationOptionsHandle deeplink_options);

/// Launches a different application in the user's library. If the user does
/// not have that application installed, they will be taken to that app's page
/// in the Oculus Store
/// \param appID The unique ID of the app to be launched.
/// \param deeplink_options Additional configuration for this request, which is optional. It contains 5 fields ovr_ApplicationOptions_SetDeeplinkMessage(), ovr_ApplicationOptions_SetDestinationApiName(), ovr_ApplicationOptions_SetLobbySessionId(), ovr_ApplicationOptions_SetMatchSessionId() and ovr_ApplicationOptions_SetRoomId().
///
/// A message with type ::ovrMessage_Application_LaunchOtherApp will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ovr_Message_GetString().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Application_LaunchOtherApp(ovrID appID, ovrApplicationOptionsHandle deeplink_options);

/// Starts an app download. It will return a result when the download is
/// finished. Download progress can be monitored using the
/// ovr_Application_CheckAppDownloadProgress().
///
/// A message with type ::ovrMessage_Application_StartAppDownload will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAppDownloadResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAppDownloadResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Application_StartAppDownload();

#endif
