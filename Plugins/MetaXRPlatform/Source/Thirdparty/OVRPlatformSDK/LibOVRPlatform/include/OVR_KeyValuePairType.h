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

#ifndef OVR_KEY_VALUE_PAIR_TYPE_H
#define OVR_KEY_VALUE_PAIR_TYPE_H

#include "OVR_Platform_Defs.h"

/// \file
/// It's a data structure that represents a pair of values, where one value
/// serves as the key and the other value serves as the corresponding value. It
/// can be used to store a different type of data, allowing for flexibility in
/// how data is stored and retrieved.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrKeyValuePairType_ {
  /// This member represents the key value as a string. It is used to store text-
  /// based data, such as names.
  ovrKeyValuePairType_String,
  /// This member represents the key value as an integer. It is used to store
  /// numerical data, such as ages
  ovrKeyValuePairType_Int,
  /// This member represents the key value as a double-precision floating-point
  /// number. It is used to store numerical data with decimal points, such as
  /// prices.
  ovrKeyValuePairType_Double,
  ovrKeyValuePairType_Unknown,
} ovrKeyValuePairType;

/// Converts an ::ovrKeyValuePairType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrKeyValuePairType_ToString(ovrKeyValuePairType value);

/// Converts a string representing an ::ovrKeyValuePairType to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrKeyValuePairType) ovrKeyValuePairType_FromString(const char* str);

#endif
