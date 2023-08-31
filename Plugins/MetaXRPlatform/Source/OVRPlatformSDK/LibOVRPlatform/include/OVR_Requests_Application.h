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

/// Track download progress for an app
///
/// A message with type ::ovrMessage_Application_CheckAppDownloadProgress will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAppDownloadProgressResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAppDownloadProgressResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Application_CheckAppDownloadProgress();

/// Requests version information, including the version code and version name
/// of the currently installed app and version code, version name, size and
/// release date of the latest app update
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
/// process is complete, the app will be relaunched based on the options
/// passed.
/// \param deeplink_options Additional configuration for this relaunch. Optional.
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
/// \param appID The ID of the app to launch
/// \param deeplink_options Additional configuration for this requests. Optional.
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
/// check_app_download_progress API.
///
/// A message with type ::ovrMessage_Application_StartAppDownload will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrAppDownloadResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetAppDownloadResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Application_StartAppDownload();

#endif
