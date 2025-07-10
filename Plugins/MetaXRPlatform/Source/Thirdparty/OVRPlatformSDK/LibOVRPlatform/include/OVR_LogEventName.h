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

#ifndef OVR_LOG_EVENT_NAME_H
#define OVR_LOG_EVENT_NAME_H

#include "OVR_Platform_Defs.h"

/// \file
/// It's an enum that represents a list of possible event names that can be
/// used to track user interactions and other important occurrences within an
/// application. These events can be used to track user engagement, conversion
/// rates, and other important metrics within an app. By logging these events,
/// developers can gain valuable insights into how users interact with their
/// app and make data-driven decisions to improve the user experience. The log
/// event parameters can be found in ovrLogEventParameter().

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrLogEventName_ {
  ovrLogEventName_Unknown,
  /// This event is triggered when a user clicks on an advertisement within the
  /// app.
  ovrLogEventName_AdClick,
  /// This event is triggered when an advertisement is displayed to the user
  /// within the app.
  ovrLogEventName_AdImpression,
  /// This event is triggered when a user completes the registration process
  /// within the app. This could include creating an account, verifying email
  /// address, or completing a profile.
  ovrLogEventName_VrCompleteRegistration,
  /// This event is triggered when a user completes a tutorial or guided
  /// experience within the app.
  ovrLogEventName_VrTutorialCompletion,
  /// This event is triggered when a user interacts with a contact form or other
  /// contact-related feature within the app.
  ovrLogEventName_Contact,
  /// This event is triggered when a user customizes a product or item within the
  /// app. This could include selecting options, choosing colors, or adding
  /// features.
  ovrLogEventName_CustomizeProduct,
  /// This event is triggered when a user makes a donation within the app.
  ovrLogEventName_Donate,
  /// This event is triggered when a user interacts with a feature that helps
  /// them find a physical location, such as a store or event.
  ovrLogEventName_FindLocation,
  /// This event is triggered when a user rates an item or experience within the
  /// app. This could include rating a product, service, or experience on a
  /// scale.
  ovrLogEventName_VrRate,
  /// This event is triggered when a user schedules an appointment or event
  /// within the app.
  ovrLogEventName_Schedule,
  /// This event is triggered when a user performs a search within the app. This
  /// could include searching for a product, service, or information.
  ovrLogEventName_VrSearch,
  /// This event is triggered when a user starts a free trial or demo of an app
  /// or game.
  ovrLogEventName_SmartTrial,
  /// This event is triggered when a user submits an application or form within
  /// the app.
  ovrLogEventName_SubmitApplication,
  /// This event is triggered when a user subscribes to a service or newsletter
  /// within the app.
  ovrLogEventName_Subscribe,
  /// This event is triggered when a user views content within the app, such as a
  /// video or article.
  ovrLogEventName_VrContentView,
  /// This event is triggered when the Oculus Platform SDK is initialized within
  /// the app. This could include setting up the SDK, loading assets, or
  /// initializing game engines.
  ovrLogEventName_VrSdkInitialize,
  /// This event is triggered when the app is granted background status by the
  /// Oculus Platform SDK.
  ovrLogEventName_VrSdkBackgroundStatusAvailable,
  /// This event is triggered when the app is denied background status by the
  /// Oculus Platform SDK.
  ovrLogEventName_VrSdkBackgroundStatusDenied,
  /// This event is triggered when the app is granted restricted background
  /// status by the Oculus Platform SDK.
  ovrLogEventName_VrSdkBackgroundStatusRestricted,
  /// This event is triggered when a user adds payment information within the
  /// app. This could include entering credit card details, linking a PayPal
  /// account, or setting up recurring payments.
  ovrLogEventName_VrAddPaymentInfo,
  /// This event is triggered when a user adds an item to their cart within the
  /// app. This could include selecting products and choosing quantities.
  ovrLogEventName_VrAddToCart,
  /// This event is triggered when a user adds an item to their wishlist within
  /// the app.
  ovrLogEventName_VrAddToWishlist,
  /// This event is triggered when a user begins the checkout process within the
  /// app. This could include reviewing orders, entering shipping information, or
  /// selecting payment methods.
  ovrLogEventName_VrInitiatedCheckout,
  /// This event is triggered when a user completes a purchase within the app.
  /// This could include finalizing an order, confirming payment, or receiving a
  /// confirmation message.
  ovrLogEventName_VrPurchase,
  /// This event is triggered when a user updates their catalog or inventory
  /// within the app.
  ovrLogEventName_VrCatalogUpdate,
  /// This event is triggered when a purchase fails within the app. This could
  /// include an error message, a failed payment, or a cancelled order.
  ovrLogEventName_VrPurchaseFailed,
  /// This event is triggered when a purchase is restored within the app. This
  /// could include reactivating a subscription, reinstating a service, or
  /// restoring access to a product.
  ovrLogEventName_VrPurchaseRestored,
  /// This event is triggered when a user begins the checkout process for a
  /// subscription within the app.
  ovrLogEventName_SubscriptionInitiatedCheckout,
  /// This event is triggered when a subscription fails within the app. This
  /// could include an error message, a failed payment, or a cancelled
  /// subscription.
  ovrLogEventName_SubscriptionFailed,
  /// This event is triggered when a subscription is restored within the app.
  /// This could include reactivating a subscription, reinstating a service, or
  /// restoring access to a product.
  ovrLogEventName_SubscriptionRestore,
  /// This event is triggered when a user achieves a level or milestone within
  /// the app.
  ovrLogEventName_VrLevelAchieved,
  /// This event is triggered when a user achieves a level or milestone within
  /// the app.
  ovrLogEventName_VrAchievementUnlocked,
  /// This event is triggered when a user spends credits or virtual currency
  /// within the app.
  ovrLogEventName_VrSpentCredits,
  /// This event is triggered when a user obtains a push token within the app.
  ovrLogEventName_VrObtainPushToken,
  /// This event is triggered when a user opens a push notification within the
  /// app.
  ovrLogEventName_VrPushOpened,
  /// This event is triggered when a user activates the app. This could include
  /// launching the app, logging in, or starting a new session.
  ovrLogEventName_VrActivateApp,
  /// This event is triggered when a user deactivates the app. This could include
  /// closing the app, logging out, or ending a session.
  ovrLogEventName_VrDeactivateApp,
} ovrLogEventName;

/// Converts an ::ovrLogEventName enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLogEventName_ToString(ovrLogEventName value);

/// Converts a string representing an ::ovrLogEventName to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrLogEventName) ovrLogEventName_FromString(const char* str);

#endif
