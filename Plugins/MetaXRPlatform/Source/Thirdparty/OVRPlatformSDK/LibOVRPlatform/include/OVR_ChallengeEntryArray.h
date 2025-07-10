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

#ifndef OVR_CHALLENGEENTRYARRAY_H
#define OVR_CHALLENGEENTRYARRAY_H

#include "OVR_Platform_Defs.h"
#include "OVR_ChallengeEntry.h"
#include <stdbool.h>
#include <stddef.h>

/// \file
/// A paginated array of ::ovrChallengeEntryHandle that can be retrieved by
/// ovr_Challenges_GetEntries(). It provides information about the size of the
/// array, whether there are more pages available, and the URLs for navigating
/// to the next or previous pages.
typedef struct ovrChallengeEntryArray *ovrChallengeEntryArrayHandle;

/// The element of this array and the element type is
/// ::ovrChallengeEntryHandle. It contains information about a specific
/// challenge entry, such as its unique identifier, the user who created it,
/// the date and time of creation, and any additional metadata.
OVRP_PUBLIC_FUNCTION(ovrChallengeEntryHandle) ovr_ChallengeEntryArray_GetElement(const ovrChallengeEntryArrayHandle obj, size_t index);

/// It's a type of `string` contains the information about the url of the next
/// page of challenge entries.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ChallengeEntryArray_GetNextUrl(const ovrChallengeEntryArrayHandle obj);

/// It's a type of `string` contains the information about the url of the
/// previous page of challenge entries.
OVRP_PUBLIC_FUNCTION(const char *) ovr_ChallengeEntryArray_GetPreviousUrl(const ovrChallengeEntryArrayHandle obj);

/// The size of this challenge entry array in bytes. It provides information
/// about the amount of data that is stored in the array.
OVRP_PUBLIC_FUNCTION(size_t) ovr_ChallengeEntryArray_GetSize(const ovrChallengeEntryArrayHandle obj);

/// The total count of ::ovrChallengeEntryHandle in this array, across all
/// pages.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_ChallengeEntryArray_GetTotalCount(const ovrChallengeEntryArrayHandle obj);

/// A `boolean` indicates whether this challenge entry array has a next page.
OVRP_PUBLIC_FUNCTION(bool) ovr_ChallengeEntryArray_HasNextPage(const ovrChallengeEntryArrayHandle obj);

/// A `boolean` indicates whether this challenge entry array has a previous
/// page.
OVRP_PUBLIC_FUNCTION(bool) ovr_ChallengeEntryArray_HasPreviousPage(const ovrChallengeEntryArrayHandle obj);


#endif
