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

#ifndef OVR_ABUSE_REPORT_OPTIONS_H
#define OVR_ABUSE_REPORT_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_AbuseReportType.h"

/// \file
/// The Abuse Report Options provide a way for developers to customize the
/// reporting flow and specify the type of content being reported, which can be
/// either a ovrAbuseReportType_User() or an ovrAbuseReportType_Object(),
/// helping to maintain a safe and respectful community within their
/// application.
struct ovrAbuseReportOptions;

typedef struct ovrAbuseReportOptions* ovrAbuseReportOptionsHandle;
/// \brief Creates a new instance of ovrAbuseReportOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrAbuseReportOptionsHandle) ovr_AbuseReportOptions_Create();
/// \brief Destroys an existing instance of the ovrAbuseReportOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_AbuseReportOptions_Destroy(ovrAbuseReportOptionsHandle handle);
/// Set whether or not to show the user selection step. If the reported object
/// is a user, they can choose to block the reported user from further
/// interactions within the platform.
OVRP_PUBLIC_FUNCTION(void) ovr_AbuseReportOptions_SetPreventPeopleChooser(ovrAbuseReportOptionsHandle handle, bool value);
/// The intended entity type ovrAbuseReportType() being reported, it can be
/// either a user ovrAbuseReportType_User() or an object/content
/// ovrAbuseReportType_Object().
OVRP_PUBLIC_FUNCTION(void) ovr_AbuseReportOptions_SetReportType(ovrAbuseReportOptionsHandle handle, ovrAbuseReportType value);

#endif
