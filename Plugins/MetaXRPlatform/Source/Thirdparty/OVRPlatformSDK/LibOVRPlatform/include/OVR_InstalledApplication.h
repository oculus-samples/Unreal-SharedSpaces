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

#ifndef OVR_INSTALLEDAPPLICATION_H
#define OVR_INSTALLEDAPPLICATION_H

#include "OVR_Platform_Defs.h"

/// \file
/// InstalledApplication provides a way to retrieve information about installed
/// application on a device, including their package name, application ID,
/// version name, version code, and status. This information can be useful for
/// tracking the status of applications on a device and identifying any issues
/// that may need to be addressed.
typedef struct ovrInstalledApplication *ovrInstalledApplicationHandle;

/// It's a type of `string` represents the ID of the application, which is a
/// unique identifier for the app.
OVRP_PUBLIC_FUNCTION(const char *) ovr_InstalledApplication_GetApplicationId(const ovrInstalledApplicationHandle obj);

/// The package name of the installed application.
OVRP_PUBLIC_FUNCTION(const char *) ovr_InstalledApplication_GetPackageName(const ovrInstalledApplicationHandle obj);

/// A `string` represents the status of the installed application.
OVRP_PUBLIC_FUNCTION(const char *) ovr_InstalledApplication_GetStatus(const ovrInstalledApplicationHandle obj);

/// It's a type of `int` represents the current version code of the installed
/// application. It can be retreiving using
/// ovr_ApplicationVersion_GetCurrentCode()
OVRP_PUBLIC_FUNCTION(int) ovr_InstalledApplication_GetVersionCode(const ovrInstalledApplicationHandle obj);

/// It's a type of `string` represents the current version name of the
/// installed application. It can be retreiving using
/// ovr_ApplicationVersion_GetCurrentName()
OVRP_PUBLIC_FUNCTION(const char *) ovr_InstalledApplication_GetVersionName(const ovrInstalledApplicationHandle obj);


#endif
