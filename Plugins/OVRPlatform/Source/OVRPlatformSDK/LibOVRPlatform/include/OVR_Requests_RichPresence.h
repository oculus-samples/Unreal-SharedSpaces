// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_RICHPRESENCE_H
#define OVR_REQUESTS_RICHPRESENCE_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_DestinationArray.h"
#include "OVR_RichPresenceOptions.h"

/// DEPRECATED. Use the clear method in group presence
///
/// A message with type ::ovrMessage_RichPresence_Clear will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_RichPresence_Clear();

/// Gets all the destinations that the presence can be set to
///
/// A message with type ::ovrMessage_RichPresence_GetDestinations will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrDestinationArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetDestinationArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_RichPresence_GetDestinations();

/// Get the next page of entries
///
/// A message with type ::ovrMessage_RichPresence_GetNextDestinationArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrDestinationArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetDestinationArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_RichPresence_GetNextDestinationArrayPage(ovrDestinationArrayHandle handle);

/// DEPRECATED. Use ovr_GroupPresence_Set().
///
/// A message with type ::ovrMessage_RichPresence_Set will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_RichPresence_Set(ovrRichPresenceOptionsHandle richPresenceOptions);

#endif
