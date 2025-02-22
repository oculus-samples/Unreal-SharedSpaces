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

#ifndef OVR_SUPPLEMENTARYMETRIC_H
#define OVR_SUPPLEMENTARYMETRIC_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

/// \file
/// This is a supplemental piece of data that is used for a single write to
/// leaderboard entries. This metric is used for tiebreaker scenarios. You can
/// make such an entry by using
/// ovr_Leaderboard_WriteEntryWithSupplementaryMetric()
typedef struct ovrSupplementaryMetric *ovrSupplementaryMetricHandle;

/// The ID of the leaderboard that this supplementary metric belongs to. This
/// is the unique value for every ::ovrLeaderboardHandle.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_SupplementaryMetric_GetID(const ovrSupplementaryMetricHandle obj);

/// This is the metric that is used to determine tiebreaks.
OVRP_PUBLIC_FUNCTION(long long) ovr_SupplementaryMetric_GetMetric(const ovrSupplementaryMetricHandle obj);


#endif
