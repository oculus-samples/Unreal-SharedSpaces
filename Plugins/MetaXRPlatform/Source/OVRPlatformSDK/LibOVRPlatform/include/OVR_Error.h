// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ERROR_H
#define OVR_ERROR_H

#include "OVR_Platform_Defs.h"

/// It represents an error response from the server. It contains error
/// information such as the error code, http status code, technical message,
/// and displayable message. It's used whenever the server needs to communicate
/// an error or failure to the client.
typedef struct ovrError *ovrErrorHandle;

/// It's a type of `integer` that represents the error code:
///
/// UNKNOWN_ERROR:1
///
/// AUTHENTICATION_ERROR:2
///
/// NETWORK_ERROR:3
///
/// STORE_INSTALLATION_ERROR:4
///
/// CALLER_NOT_SIGNED:5
///
/// UNKNOWN_SERVER_ERROR:6
///
/// PERMISSIONS_FAILURE:7
OVRP_PUBLIC_FUNCTION(int) ovr_Error_GetCode(const ovrErrorHandle obj);

/// Human readable description of the error that can be displayed to the user.
/// Might be the empty string if there is no user-appropriate description
/// available. Not intended to be parsed as it might change at any time or be
/// translated.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Error_GetDisplayableMessage(const ovrErrorHandle obj);

/// It contains the HTTP status code for the error. More information about the
/// http code can be found
/// [here](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes).
OVRP_PUBLIC_FUNCTION(int) ovr_Error_GetHttpCode(const ovrErrorHandle obj);

/// Technical description of what went wrong intended for developers. For use
/// in logs or developer consoles.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Error_GetMessage(const ovrErrorHandle obj);


#endif
