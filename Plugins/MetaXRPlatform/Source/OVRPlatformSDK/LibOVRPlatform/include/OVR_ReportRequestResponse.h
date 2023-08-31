// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REPORT_REQUEST_RESPONSE_H
#define OVR_REPORT_REQUEST_RESPONSE_H

#include "OVR_Platform_Defs.h"

typedef enum ovrReportRequestResponse_ {
  ovrReportRequestResponse_Unknown,
  ovrReportRequestResponse_Handled,
  ovrReportRequestResponse_Unhandled,
  ovrReportRequestResponse_Unavailable,
} ovrReportRequestResponse;

/// Converts an ovrReportRequestResponse enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrReportRequestResponse_ToString(ovrReportRequestResponse value);

/// Converts a string representing an ovrReportRequestResponse enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(ovrReportRequestResponse) ovrReportRequestResponse_FromString(const char* str);

#endif
