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

#ifndef OVR_CHALLENGEARRAY_H
#define OVR_CHALLENGEARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_Challenge.h"
#include <stdbool.h>
#include <stddef.h>

/// \file
/// This is a paginated array of ::ovrChallengeHandles that can be retrieved
/// using the ovr_Challenges_GetList() request. The array contains elements of
/// type ::ovrChallengeHandle, which represent individual challenges. See more
/// details of Challenges in
/// [here](https://developer.oculus.com/documentation/native/ps-challenges/).
typedef struct ovrChallengeArray *ovrChallengeArrayHandle;

/// This field represents an individual element within the challenge array.
/// Each element is of type ::ovrChallengeHandle, which contains detailed
/// information about a specific challenge.
OVRP_PUBLIC_FUNCTION(ovrChallengeHandle) ovr_ChallengeArray_GetElement(const ovrChallengeArrayHandle obj, size_t index);

/// This field contains the URL of the next page of challenges. If there is no
/// next page, this field will be empty.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ChallengeArray_GetNextUrl(const ovrChallengeArrayHandle obj);

/// The URL of the previous page of challenges. If has_previous_page is true,
/// this field provides the URL that the client can use to request the previous
/// page of results.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ChallengeArray_GetPreviousUrl(const ovrChallengeArrayHandle obj);

/// This field indicates the total size of the challenge array in bytes.
OVRP_PUBLIC_FUNCTION(size_t) ovr_ChallengeArray_GetSize(const ovrChallengeArrayHandle obj);

/// The total count of challenges contained in the array, across all pages.
/// This field provides the total number of challenges that match the search
/// criteria, regardless of the current page or pagination settings.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_ChallengeArray_GetTotalCount(const ovrChallengeArrayHandle obj);

/// This field indicates whether there is a next page of challenges available
/// in the array. If this value is true, it means that there are more
/// challenges to retrieve beyond the current page.
OVRP_PUBLIC_FUNCTION(bool) ovr_ChallengeArray_HasNextPage(const ovrChallengeArrayHandle obj);

/// This field indicates whether there is a previous page of challenges
/// available in the array. If this value is true, it means that there are more
/// challenges to retrieve before the current page.
OVRP_PUBLIC_FUNCTION(bool) ovr_ChallengeArray_HasPreviousPage(const ovrChallengeArrayHandle obj);


#endif
