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

#ifndef OVR_APP_AGE_CATEGORY_H
#define OVR_APP_AGE_CATEGORY_H

#include "OVR_Platform_Defs.h"

/// \file
/// The age category in a Meta account is used to determine eligibility for
/// certain features and services. This information is important for ensuring
/// that users are able to access the appropriate content and functionality
/// based on their age. The values are used in
/// ::ovrUserAccountAgeCategoryHandle API. See more details
/// [here](https://developer.oculus.com/documentation/native/ps-get-age-
/// category-api).

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrAppAgeCategory_ {
  ovrAppAgeCategory_Unknown,
  /// Child age group for users between the ages of 10-12 (or applicable age in
  /// user's region).
  ovrAppAgeCategory_Ch,
  /// Non-child age group for users ages 13 and up (or applicable age in user's
  /// region).
  ovrAppAgeCategory_Nch,
} ovrAppAgeCategory;

/// Converts an ::ovrAppAgeCategory enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrAppAgeCategory_ToString(ovrAppAgeCategory value);

/// Converts a string representing an ::ovrAppAgeCategory to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrAppAgeCategory) ovrAppAgeCategory_FromString(const char* str);

#endif
