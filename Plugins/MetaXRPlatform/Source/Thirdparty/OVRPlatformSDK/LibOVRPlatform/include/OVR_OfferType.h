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

#ifndef OVR_OFFER_TYPE_H
#define OVR_OFFER_TYPE_H

#include "OVR_Platform_Defs.h"

/// \file
/// An enumeration that defines the type of the ::ovrTrialOfferHandle. This can
/// be utilized to identify the specific type of offer, such as a free trial or
/// an intro offer. By setting this field, you can easily differentiate between
/// different types of offers and provide a better user experience for your
/// customers.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrOfferType_ {
  ovrOfferType_Unknown,
  /// This value indicates that the offer is an intro offer, which is typically a
  /// special promotion or discount offered to new customers.
  ovrOfferType_INTROOFFER,
  /// This value indicates that the offer is a free trial, which allows customers
  /// to try out a product or service without paying for it.
  ovrOfferType_FREETRIAL,
} ovrOfferType;

/// Converts an ::ovrOfferType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrOfferType_ToString(ovrOfferType value);

/// Converts a string representing an ::ovrOfferType to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrOfferType) ovrOfferType_FromString(const char* str);

#endif
