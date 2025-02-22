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

#ifndef OVR_APPLICATIONVERSION_H
#define OVR_APPLICATIONVERSION_H

#include "OVR_Platform_Defs.h"

/// \file
/// Represents the version information for an application. The information
/// includes the date of latest release, the size of the latest release and the
/// application name and version code of currently installed version and the
/// latest release. You can retrieve it with ovr_Application_GetVersion().
typedef struct ovrApplicationVersion *ovrApplicationVersionHandle;

/// The version code number for the version of the application that is
/// currently installed on the device.
OVRP_PUBLIC_FUNCTION(int) ovr_ApplicationVersion_GetCurrentCode(const ovrApplicationVersionHandle obj);

/// The version name string for the version of the application that is
/// currently installed on the device.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationVersion_GetCurrentName(const ovrApplicationVersionHandle obj);

/// Version code number of the latest update of the application. This may or
/// may not be currently installed on the device.
OVRP_PUBLIC_FUNCTION(int) ovr_ApplicationVersion_GetLatestCode(const ovrApplicationVersionHandle obj);

/// Version name string of the latest update of the application. This may or
/// may not be currently installed on the device.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationVersion_GetLatestName(const ovrApplicationVersionHandle obj);

/// Seconds since epoch when the latest application update was released. You
/// need to convert this date to a human readable format before displaying it
/// to the application users.
OVRP_PUBLIC_FUNCTION(long long) ovr_ApplicationVersion_GetReleaseDate(const ovrApplicationVersionHandle obj);

/// Size of the latest application update in bytes.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ApplicationVersion_GetSize(const ovrApplicationVersionHandle obj);


#endif
