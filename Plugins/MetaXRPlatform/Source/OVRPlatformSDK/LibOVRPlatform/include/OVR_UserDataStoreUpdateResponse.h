// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_USERDATASTOREUPDATERESPONSE_H
#define OVR_USERDATASTOREUPDATERESPONSE_H

#include "OVR_Platform_Defs.h"
#include <stdbool.h>

/// This payload contains information about the result of an update request to
/// the user data store. It includes a success field
/// ovr_UserDataStoreUpdateResponse_GetSuccess() that indicates whether the
/// update was successful or not.
typedef struct ovrUserDataStoreUpdateResponse *ovrUserDataStoreUpdateResponseHandle;

/// Indicates whether the update request was successful or not. A value of true
/// indicates that the update was successful, while a value of false indicates
/// that the update failed.
OVRP_PUBLIC_FUNCTION(bool) ovr_UserDataStoreUpdateResponse_GetSuccess(const ovrUserDataStoreUpdateResponseHandle obj);


#endif
