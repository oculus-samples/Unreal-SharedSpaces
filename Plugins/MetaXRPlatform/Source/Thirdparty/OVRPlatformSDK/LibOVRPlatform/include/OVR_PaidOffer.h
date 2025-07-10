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

#ifndef OVR_PAIDOFFER_H
#define OVR_PAIDOFFER_H

#include "OVR_Platform_Defs.h"
#include "OVR_OfferTerm.h"
#include "OVR_Price.h"

/// \file
/// Contains the details about the paid offer associated with a
/// ::ovrBillingPlanHandle.
typedef struct ovrPaidOffer *ovrPaidOfferHandle;

/// The ::ovrPriceHandle of the paid offer contains the currency code, the
/// amount in hundredths, and the formatted string representation.
OVRP_PUBLIC_FUNCTION(ovrPriceHandle) ovr_PaidOffer_GetPrice(const ovrPaidOfferHandle obj);

/// An enum that specifies the term.
///
/// ovrOfferTerm_Unknown(): unknown
///
/// ovrOfferTerm_WEEKLY(): WEEKLY
///
/// ovrOfferTerm_BIWEEKLY(): BIWEEKLY
///
/// ovrOfferTerm_MONTHLY(): MONTHLY
///
/// ovrOfferTerm_QUARTERLY(): QUARTERLY
///
/// ovrOfferTerm_SEMIANNUAL(): SEMIANNUAL
///
/// ovrOfferTerm_ANNUAL(): ANNUAL
///
/// ovrOfferTerm_BIANNUAL(): BIANNUAL
OVRP_PUBLIC_FUNCTION(ovrOfferTerm) ovr_PaidOffer_GetSubscriptionTerm(const ovrPaidOfferHandle obj);


#endif
