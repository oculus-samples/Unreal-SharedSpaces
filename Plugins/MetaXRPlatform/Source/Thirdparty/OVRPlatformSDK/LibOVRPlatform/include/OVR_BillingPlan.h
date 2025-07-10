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

#ifndef OVR_BILLINGPLAN_H
#define OVR_BILLINGPLAN_H

#include "OVR_Platform_Defs.h"
#include "OVR_PaidOffer.h"
#include "OVR_TrialOfferArray.h"

/// \file
/// Contains the detailed billing plan information for a
/// ovrProductType_SUBSCRIPTION(). A BillingPlan can have a
/// ::ovrPaidOfferHandle and an array of ::ovrTrialOfferHandle. The
/// ::ovrTrialOfferArrayHandle can contain a FREE_TRIAL and an INTRO_OFFER.
typedef struct ovrBillingPlan *ovrBillingPlanHandle;

/// Represents the ::ovrPaidOfferHandle associated with the billing_plan.
OVRP_PUBLIC_FUNCTION(ovrPaidOfferHandle) ovr_BillingPlan_GetPaidOffer(const ovrBillingPlanHandle obj);

/// A list of ::ovrTrialOfferHandle associated with the billing_plan.
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
OVRP_PUBLIC_FUNCTION(ovrTrialOfferArrayHandle) ovr_BillingPlan_GetTrialOffers(const ovrBillingPlanHandle obj);


#endif
