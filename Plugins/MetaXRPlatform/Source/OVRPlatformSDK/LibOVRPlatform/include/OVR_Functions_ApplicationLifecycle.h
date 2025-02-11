// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_APPLICATIONLIFECYCLE_H
#define OVR_APPLICATIONLIFECYCLE_H

#include "OVR_LaunchDetails.h"
#include "OVR_LaunchResult.h"

/// Returns information about how the application was started. This function
/// provides details about the launch intent, such as the type of intent
/// ovr_LaunchDetails_GetLaunchType() and any additional data that was passed
/// along with it. By calling this function, you can gain insight into how your
/// application was launched and take appropriate action based on that
/// information.
OVRP_PUBLIC_FUNCTION(ovrLaunchDetailsHandle) ovr_ApplicationLifecycle_GetLaunchDetails();

/// Logs if the user successfully deeplinked to a destination. This function
/// takes two parameters: a string tracking ID and a launch result. The
/// tracking ID is used to identify the specific deeplink attempt, while the
/// launch result indicates whether the deeplink was ovrLaunchResult_Success or
/// not. By logging this information, you can track the effectiveness of your
/// deeplinking efforts and make adjustments as needed.
/// \param trackingID The Tracking ID is a unique identifier assigned to each deeplink attempt. It allows developers to track the success or failure of individual deeplink attempts and gain insights into the effectiveness of their deeplinking efforts.
/// \param result An enum that indicates the outcome of an attempt to launch this application through a deeplink, including whether the attempt was ovrLaunchResult_Success or not, and if not, the specific reasons for the failure.
OVRP_PUBLIC_FUNCTION(void) ovr_ApplicationLifecycle_LogDeeplinkResult(const char *trackingID, ovrLaunchResult result);


#endif
