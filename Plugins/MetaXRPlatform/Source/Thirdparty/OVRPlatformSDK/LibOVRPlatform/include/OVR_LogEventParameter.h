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

#ifndef OVR_LOG_EVENT_PARAMETER_H
#define OVR_LOG_EVENT_PARAMETER_H

#include "OVR_Platform_Defs.h"

/// \file
/// It's an enum about a list of possible parameters that can be logged for an
/// event. See more information about log event in ovrLogEventName(). Each
/// member of the enum represents a specific parameter that can be logged.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrLogEventParameter_ {
  ovrLogEventParameter_Unknown,
  /// This parameter represents the currency used in a virtual reality (VR)
  /// transaction and it's important for tracking and analyzing VR transactions
  /// across different regions and currencies.
  ovrLogEventParameter_VrCurrency,
  /// This parameter represents the method used to register for a VR service or
  /// application. It helps to understand how users are accessing VR services and
  /// applications.
  ovrLogEventParameter_VrRegistrationMethod,
  /// This parameter represents the type of content being accessed or interacted
  /// with in a VR environment. It helps to understand what types of content are
  /// most popular among VR users.
  ovrLogEventParameter_VrContentType,
  /// This parameter represents the specific content being accessed or interacted
  /// with in a VR environment.
  ovrLogEventParameter_VrContent,
  /// This parameter represents the unique identifier for the content being
  /// accessed or interacted with in a VR environment.
  ovrLogEventParameter_VrContentId,
  /// This parameter represents the search query entered by the user in a VR
  /// environment. It helps to understand what users are searching for and how
  /// they are interacting with VR search functionality.
  ovrLogEventParameter_VrSearchString,
  /// This parameter represents whether an action was successful or not in a VR
  /// environment.
  ovrLogEventParameter_VrSuccess,
  /// This parameter represents the maximum rating value allowed for a particular
  /// VR content or service.
  ovrLogEventParameter_VrMaxRatingValue,
  /// This parameter represents whether payment information is available for a VR
  /// transaction. It helps to understand whether users have the necessary
  /// payment information to complete a VR transaction.
  ovrLogEventParameter_VrPaymentInfoAvailable,
  /// This parameter represents the number of items involved.
  ovrLogEventParameter_VrNumItems,
  /// This parameter represents the level or stage reached by the user in a VR
  /// game or application.
  ovrLogEventParameter_VrLevel,
  /// This parameter represents a brief description of the VR content or service
  /// being accessed or interacted with.
  ovrLogEventParameter_VrDescription,
  /// This parameter represents the type of advertisement displayed to the user
  /// in a VR environment.
  ovrLogEventParameter_AdType,
  /// This parameter represents the unique identifier for a VR order or
  /// transaction. It helps to track and analyze individual VR transactions and
  /// orders.
  ovrLogEventParameter_VrOrderId,
  /// This parameter represents the name of the event being logged.
  ovrLogEventParameter_EventName,
  /// This parameter represents the timestamp when the event was logged. It helps
  /// to understand when specific events occurred and how they relate to other
  /// events in the VR environment.
  ovrLogEventParameter_LogTime,
  /// This parameter represents whether the event was implicitly logged or
  /// explicitly logged by the user.
  ovrLogEventParameter_ImplicitlyLogged,
  /// This parameter represents whether the event occurred while the application
  /// was running in the background or foreground.
  ovrLogEventParameter_InBackground,
  /// This parameter represents the campaign or promotion associated with a VR
  /// push notification. It helps to understand the context and purpose of VR
  /// push notifications.
  ovrLogEventParameter_VrPushCampaign,
  /// This parameter represents the action taken by the user on a VR push
  /// notification, such as clicking or dismissing.
  ovrLogEventParameter_VrPushAction,
  /// This parameter represents the type of in-app purchase (IAP) product being
  /// purchased or interacted with in a VR environment.
  ovrLogEventParameter_VrIapProductType,
  /// This parameter represents the title of the VR content being accessed or
  /// interacted with. It helps to provide context and understanding of what the
  /// VR experience entails.
  ovrLogEventParameter_VrContentTitle,
  /// This parameter represents the unique identifier for a VR transaction. It
  /// helps to track and analyze individual VR transactions and orders.
  ovrLogEventParameter_VrTransactionId,
  /// This parameter represents the date and time of a VR transaction. It helps
  /// to understand when specific transactions occurred.
  ovrLogEventParameter_VrTransactionDate,
  /// This parameter represents the subscription period for an in-app purchase
  /// (IAP) product in a VR environment, such as monthly or annually.
  ovrLogEventParameter_VrIapSubsPeriod,
  /// This parameter represents whether the user is starting a free trial for an
  /// IAP product in a VR environment.
  ovrLogEventParameter_VrIapIsStartTrial,
  /// This parameter represents whether an IAP product has a free trial available
  /// in a VR environment.
  ovrLogEventParameter_VrIapHasFreeTrial,
  /// This parameter represents the length of the free trial period for an IAP
  /// product in a VR environment.
  ovrLogEventParameter_VrIapTrialPeriod,
  /// This parameter represents the price of the IAP product during the free
  /// trial period in a VR environment.
  ovrLogEventParameter_VrIapTrialPrice,
  /// This parameter represents the unique identifier for a user session in a VR
  /// environment. It helps to track and analyze individual user sessions and
  /// understand how users are interacting with VR applications and services over
  /// time.
  ovrLogEventParameter_SessionId,
} ovrLogEventParameter;

/// Converts an ::ovrLogEventParameter enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLogEventParameter_ToString(ovrLogEventParameter value);

/// Converts a string representing an ::ovrLogEventParameter to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrLogEventParameter) ovrLogEventParameter_FromString(const char* str);

#endif
