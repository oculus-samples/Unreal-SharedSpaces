// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_LIVESTREAMINGAPPLICATIONSTATUS_H
#define OVR_LIVESTREAMINGAPPLICATIONSTATUS_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// The livestreaming application status represents the status result of
/// whether the livestreaming is enabled for an app. If your app is enabled,
/// you will receive ovrNotification_Livestreaming_StatusChange when the
/// livestreaming session gets updated.
typedef struct ovrLivestreamingApplicationStatus *ovrLivestreamingApplicationStatusHandle;

/// This is a boolean field and represents whether the app is allowed to do the
/// livestreaming or not.
OVRP_PUBLIC_FUNCTION(bool) ovr_LivestreamingApplicationStatus_GetStreamingEnabled(const ovrLivestreamingApplicationStatusHandle obj);


#endif
