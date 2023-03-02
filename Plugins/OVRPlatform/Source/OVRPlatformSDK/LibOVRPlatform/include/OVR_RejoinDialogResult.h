// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REJOINDIALOGRESULT_H
#define OVR_REJOINDIALOGRESULT_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

typedef struct ovrRejoinDialogResult *ovrRejoinDialogResultHandle;

/// A boolean for if the user decided to rejoin.
OVRP_PUBLIC_FUNCTION(bool) ovr_RejoinDialogResult_GetRejoinSelected(const ovrRejoinDialogResultHandle obj);


#endif
