// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ABUSEREPORTRECORDING_H
#define OVR_ABUSEREPORTRECORDING_H

#include "OVR_Platform_Defs.h"

/// A video recording evidence that can be used to collect video evidence when
/// reporting abusive behavior or content within a platform. More details are
/// available in our [User Reporting Service Virtual Reality Check
/// guideline](https://developer.oculus.com/resources/reporting-service/)
typedef struct ovrAbuseReportRecording *ovrAbuseReportRecordingHandle;

/// A unique UUID associated with the Abuse Report recording. It can be
/// retrieved using ovr_LaunchReportFlowResult_GetUserReportId()
OVRP_PUBLIC_FUNCTION(const char *) ovr_AbuseReportRecording_GetRecordingUuid(const ovrAbuseReportRecordingHandle obj);


#endif
