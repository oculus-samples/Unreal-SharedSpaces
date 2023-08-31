// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_ABUSEREPORT_H
#define OVR_REQUESTS_ABUSEREPORT_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_AdvancedAbuseReportOptions.h"
#include "OVR_ReportRequestResponse.h"

/// The currently running application has indicated they want to show their in-
/// app reporting flow or that they choose to ignore the request.
///
/// A message with type ::ovrMessage_AbuseReport_ReportRequestHandled will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_AbuseReport_ReportRequestHandled(ovrReportRequestResponse response);

#endif
