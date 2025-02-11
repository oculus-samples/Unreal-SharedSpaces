// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_ASSETFILEDELETERESULT_H
#define OVR_ASSETFILEDELETERESULT_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stdbool.h>

/// An AssetFileDeleteResult contains the result of a deleted asset file. You
/// can delete an asset file by using ovr_AssetFile_DeleteById() or
/// ovr_AssetFile_DeleteByName(). The delete result contains the
/// ovr_AssetFileDeleteResult_GetAssetId(), the file path, and the success
/// status of the deleted asset.
typedef struct ovrAssetFileDeleteResult *ovrAssetFileDeleteResultHandle;

/// \deprecated You can use ovr_AssetFileDeleteResult_GetAssetId() to retrieve the ID of the asset file.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_AssetFileDeleteResult_GetAssetFileId(const ovrAssetFileDeleteResultHandle obj);

/// This represents the ID of the asset file. When you want to use
/// ovr_AssetFileDeleteResult_GetAssetFileId(), you need to use
/// ovr_AssetFileDeleteResult_GetAssetId() instead.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_AssetFileDeleteResult_GetAssetId(const ovrAssetFileDeleteResultHandle obj);

/// File path of the asset file.
OVRP_PUBLIC_FUNCTION(const char *) ovr_AssetFileDeleteResult_GetFilepath(const ovrAssetFileDeleteResultHandle obj);

/// You can use this to determine whether deleting an asset file was successful
/// or not.
OVRP_PUBLIC_FUNCTION(bool) ovr_AssetFileDeleteResult_GetSuccess(const ovrAssetFileDeleteResultHandle obj);


#endif
