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

#ifndef OVR_APP_STATUS_H
#define OVR_APP_STATUS_H

#include "OVR_Platform_Defs.h"

/// \file
/// This property indicates the current status of the app on the device. It is
/// important to note that an app can only query its own status, not the status
/// of other apps installed on the device. It can be retrieved by
/// ovr_AppDownloadProgressResult_GetStatusCode().

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrAppStatus_ {
  ovrAppStatus_Unknown,
  /// The user possesses a valid entitlement for the app, indicating they have
  /// the right to install it, although it is not currently installed on the
  /// device.
  ovrAppStatus_Entitled,
  /// The app is scheduled for download. The download will start as soon as prior
  /// queued downloads are completed.
  ovrAppStatus_DownloadQueued,
  /// The app is currently being downloaded to the device. This status is active
  /// during the download process until it is complete.
  ovrAppStatus_Downloading,
  /// The app is currently being installed on the device. This status remains
  /// until the installation is fully completed.
  ovrAppStatus_Installing,
  /// The app is successfully installed on the device and is ready to be used.
  ovrAppStatus_Installed,
  /// The app is currently being uninstalled from the device. This status remains
  /// until the uninstallation process is complete.
  ovrAppStatus_Uninstalling,
  /// The installation of the app is scheduled and will commence once any prior
  /// installations are completed.
  ovrAppStatus_InstallQueued,
} ovrAppStatus;

/// Converts an ::ovrAppStatus enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAppStatus_ToString(ovrAppStatus value);

/// Converts a string representing an ::ovrAppStatus to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrAppStatus) ovrAppStatus_FromString(const char* str);

#endif
