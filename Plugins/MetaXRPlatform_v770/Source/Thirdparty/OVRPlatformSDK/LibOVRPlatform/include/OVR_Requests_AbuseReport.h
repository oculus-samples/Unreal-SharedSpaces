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

#ifndef OVR_REQUESTS_ABUSEREPORT_H
#define OVR_REQUESTS_ABUSEREPORT_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_AdvancedAbuseReportOptions.h"
#include "OVR_ReportRequestResponse.h"


/// \file
/// The Abuse Report API provides a way for users to report abusive behavior or
/// content within the platform. It allows developers to submit reports for
/// various types of content, including users ovrAbuseReportType_User(), or an
/// object/content ovrAbuseReportType_Object().

/// The currently running application has indicated they want to show their in-
/// app reporting flow or that they choose to ignore the request.
/// \param response Possible states that an app can respond to the platform notification that the in-app reporting flow has been requested by the user.
///
/// A message with type ::ovrMessage_AbuseReport_ReportRequestHandled will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_AbuseReport_ReportRequestHandled(ovrReportRequestResponse response);

#endif
