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

#ifndef OVR_OFFER_TERM_H
#define OVR_OFFER_TERM_H

#include "OVR_Platform_Defs.h"

/// \file
/// An enumeration that defines the type of the ::ovrTrialOfferHandle. This can
/// be utilized to determine the length of time for which the offer is valid.
/// By setting this field, you can easily manage the duration of your offers
/// and provide a better user experience for your customers.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrOfferTerm_ {
  ovrOfferTerm_Unknown,
  /// Represents that the offer term is weekly. This means that the offer will be
  /// valid for a period of one week from the date of purchase.
  ovrOfferTerm_WEEKLY,
  /// Represents that the offer term is biweekly. This means that the offer will
  /// be valid for a period of two weeks from the date of purchase.
  ovrOfferTerm_BIWEEKLY,
  /// Represents that the offer term is monthly. This means that the offer will
  /// be valid for a period of one month from the date of purchase.
  ovrOfferTerm_MONTHLY,
  /// Represents that the offer term is quarterly. This means that the offer will
  /// be valid for a period of three months from the date of purchase.
  ovrOfferTerm_QUARTERLY,
  /// Represents that the offer term is every 6 months. This means that the offer
  /// will be valid for a period of six months from the date of purchase.
  ovrOfferTerm_SEMIANNUAL,
  /// Represents that the offer term is annual. This means that the offer will be
  /// valid for a period of one year from the date of purchase.
  ovrOfferTerm_ANNUAL,
  /// Represents that the offer term is every 2 years. This means that the offer
  /// will be valid for a period of two years from the date of purchase.
  ovrOfferTerm_BIANNUAL,
} ovrOfferTerm;

/// Converts an ::ovrOfferTerm enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrOfferTerm_ToString(ovrOfferTerm value);

/// Converts a string representing an ::ovrOfferTerm to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrOfferTerm) ovrOfferTerm_FromString(const char* str);

#endif
