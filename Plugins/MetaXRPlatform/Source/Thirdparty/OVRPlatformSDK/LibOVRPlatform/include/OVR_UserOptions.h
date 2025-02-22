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

#ifndef OVR_USER_OPTIONS_H
#define OVR_USER_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_ServiceProvider.h"
#include "OVR_TimeWindow.h"

/// \file
/// The user_options configuration is used to specify additional settings for
/// the ::ovrUserHandle. It allows you to customize the response by specifying
/// the time window, maximum number of users, and service providers for which
/// linked accounts should be retrieved.
struct ovrUserOptions;

typedef struct ovrUserOptions* ovrUserOptionsHandle;
/// \brief Creates a new instance of ovrUserOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrUserOptionsHandle) ovr_UserOptions_Create();
/// \brief Destroys an existing instance of the ovrUserOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_UserOptions_Destroy(ovrUserOptionsHandle handle);
/// This field specifies the maximum number of ::ovrUserHandle that should be
/// returned in the response.
OVRP_PUBLIC_FUNCTION(void) ovr_UserOptions_SetMaxUsers(ovrUserOptionsHandle handle, unsigned int value);
/// It's an array of ovrServiceProvider() objects that specifies the service
/// providers for which linked accounts should be retrieved.
OVRP_PUBLIC_FUNCTION(void) ovr_UserOptions_AddServiceProvider(ovrUserOptionsHandle handle, ovrServiceProvider value);
OVRP_PUBLIC_FUNCTION(void) ovr_UserOptions_ClearServiceProviders(ovrUserOptionsHandle handle);
/// This field specifies the time window in seconds for which the linked
/// accounts should be retrieved.
OVRP_PUBLIC_FUNCTION(void) ovr_UserOptions_SetTimeWindow(ovrUserOptionsHandle handle, ovrTimeWindow value);

#endif
