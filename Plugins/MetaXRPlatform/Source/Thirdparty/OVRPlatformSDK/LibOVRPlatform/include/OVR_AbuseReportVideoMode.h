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

#ifndef OVR_ABUSE_REPORT_VIDEO_MODE_H
#define OVR_ABUSE_REPORT_VIDEO_MODE_H

#include "OVR_Platform_Defs.h"

/// \file
/// Determines under what circumstances the frontend UI will attempt to gather
/// video evidence to support a report, and the object_type is defined in
/// ovr_AdvancedAbuseReportOptions_SetObjectType(). This setting is crucial in
/// ensuring that the reporting process is thorough and accurate, as video
/// evidence can provide valuable context and proof of misconduct.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrAbuseReportVideoMode_ {
  ovrAbuseReportVideoMode_Unknown,
  /// The UI will collect video evidence if the object_type supports it, the
  /// object_type is defined in ovr_AdvancedAbuseReportOptions_SetObjectType().
  ovrAbuseReportVideoMode_Collect,
  /// The UI will try to collect video evidence if the object_type supports it,
  /// but will allow the user to skip that step if they wish.
  ovrAbuseReportVideoMode_Optional,
  /// The UI will not collect video evidence.
  ovrAbuseReportVideoMode_Skip,
} ovrAbuseReportVideoMode;

/// Converts an ::ovrAbuseReportVideoMode enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAbuseReportVideoMode_ToString(ovrAbuseReportVideoMode value);

/// Converts a string representing an ::ovrAbuseReportVideoMode to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrAbuseReportVideoMode) ovrAbuseReportVideoMode_FromString(const char* str);

#endif
