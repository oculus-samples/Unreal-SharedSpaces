// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_NOTIFICATION_H
#define OVR_REQUESTS_NOTIFICATION_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// \file
/// *** Notifications Overview:
/// Notifications are a way for the Oculus platform to push timely updates to your
/// application. These are typically time-sensitive items and try to be prolific.
/// In addition to your application, they usually present themselves in the 2D/3D
/// Stores as well as Universal Menu.
///
/// *** Read Status:
/// Notifications will currently show up in these areas until they either expire or
/// they're marked as read. If you mark a notification as read, it'll be removed
/// from all surfaces.

/// Mark a notification as read. This causes it to disappear from the Universal
/// Menu, the Oculus App, Oculus Home, and in-app retrieval.
///
/// A message with type ::ovrMessage_Notification_MarkAsRead will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Notification_MarkAsRead(ovrID notificationID);

#endif
