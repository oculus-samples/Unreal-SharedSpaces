// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REPORT_REQUEST_RESPONSE_H
#define OVR_REPORT_REQUEST_RESPONSE_H

#include "OVR_Platform_Defs.h"

/// Possible states that an app can respond to the platform notification that
/// the in-app reporting flow has been requested by the user.
typedef enum ovrReportRequestResponse_ {
  ovrReportRequestResponse_Unknown,
  /// Response to the platform notification that the in-app reporting flow
  /// request is handled.
  ovrReportRequestResponse_Handled,
  /// Response to the platform notification that the in-app reporting flow
  /// request is not handled.
  ovrReportRequestResponse_Unhandled,
  /// Response to the platform notification that the in-app reporting flow is
  /// unavailable or non-existent.
  ovrReportRequestResponse_Unavailable,
} ovrReportRequestResponse;

/// Converts an ovrReportRequestResponse enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrReportRequestResponse_ToString(ovrReportRequestResponse value);

/// Converts a string representing an ovrReportRequestResponse enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrReportRequestResponse) ovrReportRequestResponse_FromString(const char* str);

#endif
