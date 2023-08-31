// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_DEVICEAPPLICATIONINTEGRITY_H
#define OVR_REQUESTS_DEVICEAPPLICATIONINTEGRITY_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"


/// Returns Device and Application Integrity Attestation JSON Web Token. The
/// token has format of header.claims.signature encoded in base64. Header
/// contains algorithm type (PS256) and token type (JWT).
///
/// A message with type ::ovrMessage_DeviceApplicationIntegrity_GetIntegrityToken will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ovr_Message_GetString().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_DeviceApplicationIntegrity_GetIntegrityToken(const char *challenge_nonce);

#endif
