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

#ifndef OVR_REQUESTS_IAP_H
#define OVR_REQUESTS_IAP_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_ProductArray.h"
#include "OVR_PurchaseArray.h"

/// \file
/// # In-App Purchasing (IAP)
///
/// In-app purchasing allows a user to buy items without leaving VR, using
/// the credit card they have on file with Oculus.  There are two
/// different types of IAP: consumable and durable.
///
/// Durable:
/// This type is considered 'single use unlock'; once it has been
/// purchased, it cannot be purchased again. For example, you might
/// provide your app for free with a demo level and use an in-app purchase
/// to unlock the rest of the game.
///
/// Consumable:
/// This type can be purchased multiple times. Examples of consumable IAP include
/// 'character lives' or 'coins'. These items must be 'consumed' before they can be
/// purchased again. Consumable IAP items that have been purchased, but not consumed
/// will be returned as part of ovr_IAP_GetViewerPurchases().
///
/// ## Creating IAP
///
/// IAP items are defined in the developer dashboard, found at
/// https://dashboard.oculus.com/application/[YOUR_APP_ID]/iap.
///
/// Each IAP item is defined with a "SKU" (a unique identifier for
/// referring to the item), a description (shown in the checkout flow),
/// and a price.
///
/// To handle special behaviors like sales or special offers, we recommend
/// creating a new SKU (e.g "game-unlock-sale") with a custom price, and
/// use your game logic to display that to a specific set of people or for
/// a specific amount of time.
///
/// ## Main Flow
///
/// A typical use of IAP is structured like so:
///
///   1. On startup, fetch the user's current purchases with ovr_IAP_GetViewerPurchases().
///   If any of the results are consumable, consume them now.
///   2. Call ovr_IAP_GetProductsBySKU() to retrieve a list of products.
///   If you've hard-coded this list into your app and don't need to show
///   prices, this may be optional.
///   3. When the user chooses to purchase an item, call ovr_IAP_LaunchCheckoutFlow()
///   4. (for consumables): call ovr_IAP_ConsumePurchase() to consume the item, allowing later re-purchase.
///
/// ## Testing IAP
///
/// You can create a set of Test Users for your organization, which have
/// permission to purchase IAP items / applications without needing real money. These
/// users only work within applications in your organization. Test users can be created
/// at  https://dashboard.oculus.com/organizations/[YOUR_ORG_ID]/testusers. Once the
/// test user has been created, you can add special credit cards that have different
/// properties. NOTE: these cards only work with test users and they can only be used
/// within your organization. When using these cards, you can enter any
/// address and expiration date as long as it's valid.
///
/// Always succeeds:  4111 1177 1155 2927
/// Fails at auth:    4111 1180 9636 6644
/// Fails at sale:  	4111 1193 1540 5122
///
/// ## Server-to-server REST API
///
/// In some cases you would like to query for purchase information from
/// your game server rather than from the client. For example, to avoid
/// cheating you may want to maintain the user's balance of coins on the
/// server.  The available API calls are:
///
/// ### Verify the the user owns a specific IAP item
///
///     $ curl -d "access_token=$USER_ACCESSTOKEN" -d "sku=EXAMPLE1" https://graph.oculus.com/$APPID/verify_entitlement
///     {"success":true}
///
/// ### Consume an IAP item
///
///     $ curl  -d "access_token=$USER_ACCESSTOKEN" -d "sku=EXAMPLE1" https://graph.oculus.com/$APPID/consume_entitlement
///     {"success":true}
///
/// After consumption the use is no longer entitled to the item:
///
///     $ curl  -d "access_token=$USER_ACCESSTOKEN" -d "sku=EXAMPLE1" https://graph.oculus.com/$APPID/verify_entitlement
///     {"success":false}
///
/// ### Query all IAP entitlements
///
///     $ curl -G -d "access_token=$USER_ACCESSTOKEN"  -d "fields=id,item{sku}" https://graph.oculus.com/$APPID/viewer_purchases
///     {"data":[{"id":"963119010431337","item":{"sku":"EXAMPLE1"}}]}
///
/// ## Limitations
///
/// * At the moment there is no support for selling a single item with multiple currencies.
///
/// * All IAP operations require online access.  A future update will support offline caching of IAP purchases.


/// \file
/// The IAP (In-App Purchases) API provides methods for managing in-app
/// purchases, including retrieving purchase history, getting detailed product
/// information by ovr_Purchase_GetSKU(), and consuming purchases as needed.
/// For more information, see
/// [here](https://developer.oculus.com/documentation/native/ps-iap/).

/// Allow the consumable IAP product to be purchased again. Conceptually, this
/// indicates that the item was used or consumed. Important: Make sure to pass
/// the correct SKU of the purchase that will be consumed. This value is case-
/// sensitive and should match exactly with the product SKU set in the
/// Developer Dashboard.
/// \param sku The SKU of the product of the purchase that will be consumed. This value is case-sensitive and should match exactly with the product SKU set in the Developer Dashboard.
///
/// A message with type ::ovrMessage_IAP_ConsumePurchase will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_IAP_ConsumePurchase(const char *sku);

/// Get the next page of entries
/// \param handle The handle to the array to get the next page of entries.
///
/// A message with type ::ovrMessage_IAP_GetNextProductArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrProductArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetProductArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_IAP_GetNextProductArrayPage(ovrProductArrayHandle handle);

/// Get the next page of entries
/// \param handle The handle to the array to get the next page of entries.
///
/// A message with type ::ovrMessage_IAP_GetNextPurchaseArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrPurchaseArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetPurchaseArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_IAP_GetNextPurchaseArrayPage(ovrPurchaseArrayHandle handle);

/// Retrieve a list of IAP products that can be purchased. Note: You must
/// provide a list of SKUs (Stock Keeping Units) to retrieve the corresponding
/// product information. The SKUs are used to identify the products in the
/// Oculus store, which can be retrieved by accessing the Developer Dashboard
/// or by ovr_Purchase_GetSKU().
/// \param skus An array of SKUs of the products to retrieve. Each SKU should be a string value that matches exactly with the product SKU set in the Oculus Developer Dashboard.
/// \param count The number of items you provided in the SKUs array. This parameter is used to validate the input and ensure that the correct number of products is returned.
///
/// A message with type ::ovrMessage_IAP_GetProductsBySKU will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrProductArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetProductArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_IAP_GetProductsBySKU(const char **skus, int count);

/// Retrieve a list of Purchase that the Logged-In-User has made. This list
/// will also contain consumable purchases that have not been consumed. Note:
/// This method returns all purchases, including consumable and non-consumable
/// ones. If you only want to retrieve durable purchases, use
/// get_viewer_purchases_durable_cache instead.
///
/// A message with type ::ovrMessage_IAP_GetViewerPurchases will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrPurchaseArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetPurchaseArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_IAP_GetViewerPurchases();

/// Retrieve a list of Purchase that the Logged-In-User has made. This list
/// will only contain durable purchase (non-consumable) and is populated from a
/// device cache. Important: It is recommended to use
/// ovr_IAP_GetViewerPurchases() first and only check the cache if that fails.
/// This method is intended as a fallback mechanism and may not always return
/// up-to-date results.
///
/// A message with type ::ovrMessage_IAP_GetViewerPurchasesDurableCache will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrPurchaseArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetPurchaseArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_IAP_GetViewerPurchasesDurableCache();

/// Launch the checkout flow to purchase the existing product. Oculus Home
/// tries handle and fix as many errors as possible. Home returns the
/// appropriate error message and how to resolve it, if possible. Returns a
/// purchase on success, and an error on user cancellation or other errors.
///
/// In the case of a user cancelation, the ovr_Error_GetMessage() value will
/// contain a JSON object with a `"category"` property containing a value of
/// `"user_canceled"`.
/// \param sku IAP sku for the item the user wishes to purchase.
///
/// A message with type ::ovrMessage_IAP_LaunchCheckoutFlow will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrPurchaseHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetPurchase().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_IAP_LaunchCheckoutFlow(const char *sku);

#endif
