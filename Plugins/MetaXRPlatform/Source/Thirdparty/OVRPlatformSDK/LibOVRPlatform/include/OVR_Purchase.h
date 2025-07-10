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

#ifndef OVR_PURCHASE_H
#define OVR_PURCHASE_H

#include "OVR_Platform_Defs.h"
#include "OVR_ProductType.h"
#include "OVR_Types.h"

/// \file
/// A purchase is made when a user buys a ::ovrProductHandle. The IAP product,
/// which can represent a consumable item, a durable item, or a subscription,
/// must be defined for purchase through the developer dashboard.
typedef struct ovrPurchase *ovrPurchaseHandle;

/// The developer payload feature is unimplemented.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Purchase_GetDeveloperPayload(const ovrPurchaseHandle obj);

/// The time when the purchased ::ovrProductHandle expires. This value only
/// applies to subscriptions, and will be null for durable and consumable IAP
/// items.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_Purchase_GetExpirationTime(const ovrPurchaseHandle obj);

/// The timestamp that represents when the user was granted entitlement to the
/// ::ovrProductHandle that was purchased.
OVRP_PUBLIC_FUNCTION(unsigned long long) ovr_Purchase_GetGrantTime(const ovrPurchaseHandle obj);

/// The unique identifier of a ::ovrPurchaseHandle represents a user's unique
/// entitlement to a ::ovrProductHandle. This value is 0 for shared IAP
/// entitlements.
/// \deprecated  Use ovr_Purchase_GetPurchaseStrID() instead.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_Purchase_GetPurchaseID(const ovrPurchaseHandle obj);

/// The Reporting ID feature is not implemented.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Purchase_GetReportingId(const ovrPurchaseHandle obj);

/// The SKU of the IAP ::ovrProductHandle that was purchased. This value is
/// case-sensitive. To retrieve the product information, you can use this value
/// when calling ovr_IAP_GetProductsBySKU().
OVRP_PUBLIC_FUNCTION(const char *) ovr_Purchase_GetSKU(const ovrPurchaseHandle obj);

/// The Type of the IAP ::ovrProductHandle that was purchased. The values can
/// be ovrProductType_DURABLE(), ovrProductType_CONSUMABLE(), or a
/// ovrProductType_SUBSCRIPTION().
OVRP_PUBLIC_FUNCTION(ovrProductType) ovr_Purchase_GetType(const ovrPurchaseHandle obj);

OVRP_PUBLIC_FUNCTION(const char *) ovr_Purchase_GetPurchaseStrID(const ovrPurchaseHandle obj);

#endif
