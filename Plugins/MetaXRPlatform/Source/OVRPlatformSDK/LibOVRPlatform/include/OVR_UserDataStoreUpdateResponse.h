// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USERDATASTOREUPDATERESPONSE_H
#define OVR_USERDATASTOREUPDATERESPONSE_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

typedef struct ovrUserDataStoreUpdateResponse *ovrUserDataStoreUpdateResponseHandle;

/// Whether the update request is succeeded.
OVRP_PUBLIC_FUNCTION(bool) ovr_UserDataStoreUpdateResponse_GetSuccess(const ovrUserDataStoreUpdateResponseHandle obj);


#endif
