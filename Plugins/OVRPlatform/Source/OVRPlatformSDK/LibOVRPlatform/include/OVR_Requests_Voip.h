// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_VOIP_H
#define OVR_REQUESTS_VOIP_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// Gets whether the microphone is currently available to the app. This can be
/// used to show if the user's voice is able to be heard by other users.
///
/// A message with type ::ovrMessage_Voip_GetMicrophoneAvailability will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrMicrophoneAvailabilityStateHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetMicrophoneAvailabilityState().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Voip_GetMicrophoneAvailability();

/// Sets whether SystemVoip should be suppressed so that this app's Voip can
/// use the mic and play incoming Voip audio. Once microphone switching
/// functionality for the user is released, this function will no longer work.
/// You can use get_microphone_availability to see if the user has allowed the
/// app access to the microphone.
///
/// A message with type ::ovrMessage_Voip_SetSystemVoipSuppressed will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrSystemVoipStateHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetSystemVoipState().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Voip_SetSystemVoipSuppressed(bool suppressed);

#endif
