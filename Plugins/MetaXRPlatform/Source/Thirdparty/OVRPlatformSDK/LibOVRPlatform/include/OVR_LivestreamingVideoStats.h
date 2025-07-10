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

#ifndef OVR_LIVESTREAMINGVIDEOSTATS_H
#define OVR_LIVESTREAMINGVIDEOSTATS_H

#include "OVR_Platform_Defs.h"

/// \file
/// The livestreaming video statistics represents the statistics info about a
/// livestreaming video in your app. The statistics include the total number of
/// views, the number of reactions and the number of comments. You can retrieve
/// the information about whether your comments are visible from
/// ovr_LivestreamingStatus_GetCommentsVisible().
typedef struct ovrLivestreamingVideoStats *ovrLivestreamingVideoStatsHandle;

/// An 'integer' represents the information about the total number of comments
/// left for your livestream video.
OVRP_PUBLIC_FUNCTION(int) ovr_LivestreamingVideoStats_GetCommentCount(const ovrLivestreamingVideoStatsHandle obj);

/// An 'integer' represents the information about the total number of reactions
/// your livestream video received.
OVRP_PUBLIC_FUNCTION(int) ovr_LivestreamingVideoStats_GetReactionCount(const ovrLivestreamingVideoStatsHandle obj);

/// This field gives the information about the total number of views of your
/// livestream video.
OVRP_PUBLIC_FUNCTION(const char *) ovr_LivestreamingVideoStats_GetTotalViews(const ovrLivestreamingVideoStatsHandle obj);


#endif
