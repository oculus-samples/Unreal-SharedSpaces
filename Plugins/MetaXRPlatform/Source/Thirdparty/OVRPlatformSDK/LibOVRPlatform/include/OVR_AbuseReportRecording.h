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

#ifndef OVR_ABUSEREPORTRECORDING_H
#define OVR_ABUSEREPORTRECORDING_H

#include "OVR_Platform_Defs.h"

/// \file
/// A video recording evidence that can be used to collect video evidence when
/// reporting abusive behavior or content within a platform. More details are
/// available in our [User Reporting Service Virtual Reality Check
/// guideline](https://developer.oculus.com/resources/reporting-service/)
typedef struct ovrAbuseReportRecording *ovrAbuseReportRecordingHandle;

/// A unique UUID associated with the Abuse Report recording. It can be
/// retrieved using ovr_LaunchReportFlowResult_GetUserReportId()
OVRP_PUBLIC_FUNCTION(const char *) ovr_AbuseReportRecording_GetRecordingUuid(const ovrAbuseReportRecordingHandle obj);


#endif
