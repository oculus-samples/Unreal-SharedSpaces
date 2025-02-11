// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REJOINDIALOGRESULT_H
#define OVR_REJOINDIALOGRESULT_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// A boolean that indicates the result of
/// ovr_GroupPresence_LaunchRejoinDialog(). 'True' indicates that the
/// application will rejoin the dialog, otherwise the application will not
/// rejoin the dialog. Read more about the [rejoin
/// dialog](https://developer.oculus.com/documentation/native/ps-
/// rejoin/#rejoin-apis).
typedef struct ovrRejoinDialogResult *ovrRejoinDialogResultHandle;

/// A boolean for if the user has decided to rejoin. This is used in
/// ovr_GroupPresence_LaunchRejoinDialog().
OVRP_PUBLIC_FUNCTION(bool) ovr_RejoinDialogResult_GetRejoinSelected(const ovrRejoinDialogResultHandle obj);


#endif
