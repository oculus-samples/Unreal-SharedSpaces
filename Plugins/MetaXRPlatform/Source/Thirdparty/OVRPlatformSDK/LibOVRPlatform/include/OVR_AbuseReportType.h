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

#ifndef OVR_ABUSE_REPORT_TYPE_H
#define OVR_ABUSE_REPORT_TYPE_H

#include "OVR_Platform_Defs.h"

/// \file
/// Represents the type of abuse report, can be categorized as either
/// concerning a user, an object, or being unknown. It can be specified as a
/// field in the ovr_AbuseReportOptions_SetReportType() option.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrAbuseReportType_ {
  ovrAbuseReportType_Unknown,
  /// This refers to reports that are related to non-user entities, such as a
  /// virtual environment or an inanimate object within a platform. An example
  /// provided is a report concerning a "world," which could be a virtual space
  /// or environment.
  ovrAbuseReportType_Object,
  /// This category is used for reports that directly involve a user's actions or
  /// behavior. This could include reports on harassment, inappropriate behavior,
  /// or other violations that are directly linked to a user's conduct on a
  /// platform.
  ovrAbuseReportType_User,
} ovrAbuseReportType;

/// Converts an ::ovrAbuseReportType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAbuseReportType_ToString(ovrAbuseReportType value);

/// Converts a string representing an ::ovrAbuseReportType to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrAbuseReportType) ovrAbuseReportType_FromString(const char* str);

#endif
