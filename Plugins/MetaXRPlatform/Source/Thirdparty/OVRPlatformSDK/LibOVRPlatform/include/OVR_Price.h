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

#ifndef OVR_PRICE_H
#define OVR_PRICE_H

#include "OVR_Platform_Defs.h"

/// \file
/// The price of a ::ovrProductHandle. A price contains a currency code, an
/// amount in hundredths, and its formatted string representation. For example,
/// a price with a currency code of "USD" and an amount in hundredths of 99 has
/// a formatted string of "$0.99".
typedef struct ovrPrice *ovrPriceHandle;

/// The price of the product in hundredths of currency units.
OVRP_PUBLIC_FUNCTION(unsigned int) ovr_Price_GetAmountInHundredths(const ovrPriceHandle obj);

/// The ISO 4217 currency code for the price of the product. For example,
/// "USD", "GBP", "JPY".
OVRP_PUBLIC_FUNCTION(const char *) ovr_Price_GetCurrency(const ovrPriceHandle obj);

/// The formatted string representation of the price, e.g., "$0.78". The value
/// depends on the ovr_Price_GetCurrency() and
/// ovr_Price_GetAmountInHundredths().
OVRP_PUBLIC_FUNCTION(const char *) ovr_Price_GetFormatted(const ovrPriceHandle obj);


#endif
