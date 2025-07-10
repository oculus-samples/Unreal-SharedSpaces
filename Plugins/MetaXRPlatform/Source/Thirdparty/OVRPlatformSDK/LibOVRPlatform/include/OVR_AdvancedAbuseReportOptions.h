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

#ifndef OVR_ADVANCED_ABUSE_REPORT_OPTIONS_H
#define OVR_ADVANCED_ABUSE_REPORT_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_AbuseReportType.h"
#include "OVR_AbuseReportVideoMode.h"

/// \file
/// The Advanced Abuse Report Options provides a way for developers to
/// customize the reporting flow and specify the type of content being
/// reported, which can be either a ovrAbuseReportType_User() or an
/// ovrAbuseReportType_Object(), helping to maintain a safe and respectful
/// community within their application.
struct ovrAdvancedAbuseReportOptions;

typedef struct ovrAdvancedAbuseReportOptions* ovrAdvancedAbuseReportOptionsHandle;
/// \brief Creates a new instance of ovrAdvancedAbuseReportOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrAdvancedAbuseReportOptionsHandle) ovr_AdvancedAbuseReportOptions_Create();
/// \brief Destroys an existing instance of the ovrAdvancedAbuseReportOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_AdvancedAbuseReportOptions_Destroy(ovrAdvancedAbuseReportOptionsHandle handle);
/// This field is intended to allow developers to pass custom metadata through
/// the report flow. The metadata passed through is included with the report
/// received by the developer.
OVRP_PUBLIC_FUNCTION(void) ovr_AdvancedAbuseReportOptions_SetDeveloperDefinedContextString(ovrAdvancedAbuseReportOptionsHandle handle, const char* key, const char* value);
OVRP_PUBLIC_FUNCTION(void) ovr_AdvancedAbuseReportOptions_ClearDeveloperDefinedContext(ovrAdvancedAbuseReportOptionsHandle handle);
/// If ovrAbuseReportType() is ovrAbuseReportType_Object(), a string
/// representing the type of content being reported. This should correspond to
/// the object_type string used in the UI.
OVRP_PUBLIC_FUNCTION(void) ovr_AdvancedAbuseReportOptions_SetObjectType(ovrAdvancedAbuseReportOptionsHandle handle, const char * value);
/// The intended entity type ovrAbuseReportType() being reported, it can be
/// either a user ovrAbuseReportType_User() or an object/content
/// ovrAbuseReportType_Object().
OVRP_PUBLIC_FUNCTION(void) ovr_AdvancedAbuseReportOptions_SetReportType(ovrAdvancedAbuseReportOptionsHandle handle, ovrAbuseReportType value);
/// Provide a list of users to suggest for reporting. This list should include
/// users that the reporter has recently interacted with to aid them in
/// selecting the right user to report.
OVRP_PUBLIC_FUNCTION(void) ovr_AdvancedAbuseReportOptions_AddSuggestedUser(ovrAdvancedAbuseReportOptionsHandle handle, ovrID value);
OVRP_PUBLIC_FUNCTION(void) ovr_AdvancedAbuseReportOptions_ClearSuggestedUsers(ovrAdvancedAbuseReportOptionsHandle handle);
/// The video mode ovrAbuseReportVideoMode() controls whether or not the abuse
/// report flow should collect evidence and whether it is optional or not.
/// ovrAbuseReportVideoMode_Collect() requires video evidence to be provided by
/// the user. ovrAbuseReportVideoMode_Optional() presents the user with the
/// option to provide video evidence. ovrAbuseReportVideoMode_Skip() bypasses
/// the video evidence collection step altogether.
OVRP_PUBLIC_FUNCTION(void) ovr_AdvancedAbuseReportOptions_SetVideoMode(ovrAdvancedAbuseReportOptionsHandle handle, ovrAbuseReportVideoMode value);

#endif
