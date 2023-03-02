// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LOG_EVENT_NAME_H
#define OVR_LOG_EVENT_NAME_H

#include "OVR_Platform_Defs.h"

typedef enum ovrLogEventName_ {
  ovrLogEventName_Unknown,
  ovrLogEventName_AdClick,
  ovrLogEventName_AdImpression,
  ovrLogEventName_VrCompleteRegistration,
  ovrLogEventName_VrTutorialCompletion,
  ovrLogEventName_Contact,
  ovrLogEventName_CustomizeProduct,
  ovrLogEventName_Donate,
  ovrLogEventName_FindLocation,
  ovrLogEventName_VrRate,
  ovrLogEventName_Schedule,
  ovrLogEventName_VrSearch,
  ovrLogEventName_SmartTrial,
  ovrLogEventName_SubmitApplication,
  ovrLogEventName_Subscribe,
  ovrLogEventName_VrContentView,
  ovrLogEventName_VrSdkInitialize,
  ovrLogEventName_VrSdkBackgroundStatusAvailable,
  ovrLogEventName_VrSdkBackgroundStatusDenied,
  ovrLogEventName_VrSdkBackgroundStatusRestricted,
  ovrLogEventName_VrAddPaymentInfo,
  ovrLogEventName_VrAddToCart,
  ovrLogEventName_VrAddToWishlist,
  ovrLogEventName_VrInitiatedCheckout,
  ovrLogEventName_VrPurchase,
  ovrLogEventName_VrCatalogUpdate,
  ovrLogEventName_VrPurchaseFailed,
  ovrLogEventName_VrPurchaseRestored,
  ovrLogEventName_SubscriptionInitiatedCheckout,
  ovrLogEventName_SubscriptionFailed,
  ovrLogEventName_SubscriptionRestore,
  ovrLogEventName_VrLevelAchieved,
  ovrLogEventName_VrAchievementUnlocked,
  ovrLogEventName_VrSpentCredits,
  ovrLogEventName_VrObtainPushToken,
  ovrLogEventName_VrPushOpened,
  ovrLogEventName_VrActivateApp,
  ovrLogEventName_VrDeactivateApp,
} ovrLogEventName;

/// Converts an ovrLogEventName enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLogEventName_ToString(ovrLogEventName value);

/// Converts a string representing an ovrLogEventName enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrLogEventName) ovrLogEventName_FromString(const char* str);

#endif
