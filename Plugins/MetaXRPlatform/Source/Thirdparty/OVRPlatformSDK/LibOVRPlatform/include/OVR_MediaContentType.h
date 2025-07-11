/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_MEDIA_CONTENT_TYPE_H
#define OVR_MEDIA_CONTENT_TYPE_H

#include "OVR_Platform_Defs.h"

/// \file
/// An enum that represents the type of media content being shared, which can
/// be useful for various purposes such as displaying the media content in a
/// specific way or applying certain filters or effects to it. It can be used
/// as a type of parameter in ovr_Media_ShareToFacebook().

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrMediaContentType_ {
  ovrMediaContentType_Unknown,
  /// Indicates that the media content is a photo. This value can be used to
  /// specify that the media content being shared is a photo.
  ovrMediaContentType_Photo,
} ovrMediaContentType;

/// Converts an ::ovrMediaContentType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrMediaContentType_ToString(ovrMediaContentType value);

/// Converts a string representing an ::ovrMediaContentType to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrMediaContentType) ovrMediaContentType_FromString(const char* str);

#endif
