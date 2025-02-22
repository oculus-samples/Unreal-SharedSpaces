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

#ifndef OVR_USERREPORTID_H
#define OVR_USERREPORTID_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stdbool.h>

/// \file
/// \deprecated Do not add new requests using this. Use launch_report_flow_result instead.
typedef struct ovrUserReportID *ovrUserReportIDHandle;

/// Whether the viewer chose to cancel the report flow.
OVRP_PUBLIC_FUNCTION(bool) ovr_UserReportID_GetDidCancel(const ovrUserReportIDHandle obj);

OVRP_PUBLIC_FUNCTION(ovrID) ovr_UserReportID_GetID(const ovrUserReportIDHandle obj);

#endif
