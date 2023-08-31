// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LOG_EVENT_PARAMETER_H
#define OVR_LOG_EVENT_PARAMETER_H

#include "OVR_Platform_Defs.h"

typedef enum ovrLogEventParameter_ {
  ovrLogEventParameter_Unknown,
  ovrLogEventParameter_VrCurrency,
  ovrLogEventParameter_VrRegistrationMethod,
  ovrLogEventParameter_VrContentType,
  ovrLogEventParameter_VrContent,
  ovrLogEventParameter_VrContentId,
  ovrLogEventParameter_VrSearchString,
  ovrLogEventParameter_VrSuccess,
  ovrLogEventParameter_VrMaxRatingValue,
  ovrLogEventParameter_VrPaymentInfoAvailable,
  ovrLogEventParameter_VrNumItems,
  ovrLogEventParameter_VrLevel,
  ovrLogEventParameter_VrDescription,
  ovrLogEventParameter_AdType,
  ovrLogEventParameter_VrOrderId,
  ovrLogEventParameter_EventName,
  ovrLogEventParameter_LogTime,
  ovrLogEventParameter_ImplicitlyLogged,
  ovrLogEventParameter_InBackground,
  ovrLogEventParameter_VrPushCampaign,
  ovrLogEventParameter_VrPushAction,
  ovrLogEventParameter_VrIapProductType,
  ovrLogEventParameter_VrContentTitle,
  ovrLogEventParameter_VrTransactionId,
  ovrLogEventParameter_VrTransactionDate,
  ovrLogEventParameter_VrIapSubsPeriod,
  ovrLogEventParameter_VrIapIsStartTrial,
  ovrLogEventParameter_VrIapHasFreeTrial,
  ovrLogEventParameter_VrIapTrialPeriod,
  ovrLogEventParameter_VrIapTrialPrice,
  ovrLogEventParameter_SessionId,
} ovrLogEventParameter;

/// Converts an ovrLogEventParameter enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLogEventParameter_ToString(ovrLogEventParameter value);

/// Converts a string representing an ovrLogEventParameter enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrLogEventParameter) ovrLogEventParameter_FromString(const char* str);

#endif
