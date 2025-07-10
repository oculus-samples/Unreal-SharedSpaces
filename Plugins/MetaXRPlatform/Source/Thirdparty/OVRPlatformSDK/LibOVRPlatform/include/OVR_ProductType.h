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

#ifndef OVR_PRODUCT_TYPE_H
#define OVR_PRODUCT_TYPE_H

#include "OVR_Platform_Defs.h"

/// \file
/// This `enum` value represents the possible types of a ::ovrProductHandle,
/// which is an item purchased in the application. An In-app purchase (IAP)
/// add-on can be durable, consuable, or a subscription.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrProductType_ {
  ovrProductType_Unknown,
  /// This product is a durable IAP item that can be consumed multiple times. It
  /// can be purchased only once.
  ovrProductType_DURABLE,
  /// This product is an IAP item that can be consumed only once. It can only be
  /// purchased again after it is consumed.
  ovrProductType_CONSUMABLE,
  /// This product represents a subscription. Subscriptions provide a way for
  /// users to purchase your app or its premium content by way of a recurring
  /// payment model.
  ovrProductType_SUBSCRIPTION,
} ovrProductType;

/// Converts an ::ovrProductType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrProductType_ToString(ovrProductType value);

/// Converts a string representing an ::ovrProductType to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrProductType) ovrProductType_FromString(const char* str);

#endif
