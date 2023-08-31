// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APPLICATIONLIFECYCLE_H
#define OVR_APPLICATIONLIFECYCLE_H

#include "OVR_LaunchDetails.h"
#include "OVR_LaunchResult.h"

/// Returns information about how the application was started.
OVRP_PUBLIC_FUNCTION(ovrLaunchDetailsHandle) ovr_ApplicationLifecycle_GetLaunchDetails();

/// Logs if the user successfully deeplinked to a destination.
OVRP_PUBLIC_FUNCTION(void) ovr_ApplicationLifecycle_LogDeeplinkResult(const char *trackingID, ovrLaunchResult result);


#endif
