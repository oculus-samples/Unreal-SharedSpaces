// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LIVESTREAMINGSTARTRESULT_H
#define OVR_LIVESTREAMINGSTARTRESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_LivestreamingStartStatus.h"

/// You will receive this livestreaming start result once you start a
/// livestream to Facebook or to a party in your app. This result will show if
/// the start status is a success or unknown or a failure because of various
/// reasons including no Facebook connection or missing parameters.
typedef struct ovrLivestreamingStartResult *ovrLivestreamingStartResultHandle;

/// This livestreaming result represents the start status of your livestream.
/// You can refer to ovrLivestreamingStartStatus_LivestreamingStartStatus for
/// possible status info.
OVRP_PUBLIC_FUNCTION(ovrLivestreamingStartStatus) ovr_LivestreamingStartResult_GetStreamingResult(const ovrLivestreamingStartResultHandle obj);


#endif
