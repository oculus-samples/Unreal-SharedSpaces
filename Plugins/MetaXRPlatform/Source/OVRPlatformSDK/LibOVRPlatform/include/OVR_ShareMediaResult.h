// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_SHAREMEDIARESULT_H
#define OVR_SHAREMEDIARESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_ShareMediaStatus.h"

/// The result from users launching the Share to Facebook modal which enables
/// them to share local media files through ovr_Media_ShareToFacebook(). The
/// result will contain a status field, ovrShareMediaStatus_ShareMediaStatus.
typedef struct ovrShareMediaResult *ovrShareMediaResultHandle;

/// The status of the share media result. The status can be of the following
/// types:
///
/// ovrShareMediaStatus_Unknown
///
/// ovrShareMediaStatus_Shared
///
/// ovrShareMediaStatus_Canceled
OVRP_PUBLIC_FUNCTION(ovrShareMediaStatus) ovr_ShareMediaResult_GetStatus(const ovrShareMediaResultHandle obj);


#endif
