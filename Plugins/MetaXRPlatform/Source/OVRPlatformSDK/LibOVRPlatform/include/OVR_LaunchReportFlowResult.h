// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LAUNCHREPORTFLOWRESULT_H
#define OVR_LAUNCHREPORTFLOWRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stdbool.h>

/// Results of the launched report dialog including resulting report ID and
/// user action. It can be retrieved using
/// ovr_AbuseReport_ReportRequestHandled() to handle the result of a report
/// request. Learn more about our [User Reporting
/// Service](https://developer.oculus.com/resources/reporting-
/// service#faq_856753478660534).
typedef struct ovrLaunchReportFlowResult *ovrLaunchReportFlowResultHandle;

/// A `boolean` which indicates whether the viewer chose to cancel the report
/// flow before completing it.
OVRP_PUBLIC_FUNCTION(bool) ovr_LaunchReportFlowResult_GetDidCancel(const ovrLaunchReportFlowResultHandle obj);

/// ID of the report created by the user. It's optional and may not be present
/// if the user cancelled the report flow. Learn more about the [user reporting
/// plugin](https://developer.oculus.com/resources/reporting-plugin) in our
/// website.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_LaunchReportFlowResult_GetUserReportId(const ovrLaunchReportFlowResultHandle obj);


#endif
