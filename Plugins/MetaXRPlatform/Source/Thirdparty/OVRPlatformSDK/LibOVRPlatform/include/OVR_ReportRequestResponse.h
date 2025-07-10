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

#ifndef OVR_REPORT_REQUEST_RESPONSE_H
#define OVR_REPORT_REQUEST_RESPONSE_H

#include "OVR_Platform_Defs.h"

/// \file
/// An application user can report abusive behavior or content following the
/// in-app reporting flow. This report request response represents the possible
/// states that the app can respond to the platform notification, i.e., the
/// running application indicates whether they want to show their in-app
/// reporting flow or that they choose to ignore the request via
/// ovr_AbuseReport_ReportRequestHandled().

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrReportRequestResponse_ {
  ovrReportRequestResponse_Unknown,
  /// This 'enum' member represents the response to the platform notification
  /// that the in-app reporting flow request is handled.
  ovrReportRequestResponse_Handled,
  /// This 'enum' member represents the response to the platform notification
  /// that the in-app reporting flow request is not handled.
  ovrReportRequestResponse_Unhandled,
  /// This 'enum' member represents the response to the platform notification
  /// that the in-app reporting flow is unavailable or non-existent.
  ovrReportRequestResponse_Unavailable,
} ovrReportRequestResponse;

/// Converts an ::ovrReportRequestResponse enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrReportRequestResponse_ToString(ovrReportRequestResponse value);

/// Converts a string representing an ::ovrReportRequestResponse to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrReportRequestResponse) ovrReportRequestResponse_FromString(const char* str);

#endif
