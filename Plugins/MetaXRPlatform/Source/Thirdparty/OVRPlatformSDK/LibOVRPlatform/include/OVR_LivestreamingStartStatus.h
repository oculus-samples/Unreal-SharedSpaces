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

#ifndef OVR_LIVESTREAMING_START_STATUS_H
#define OVR_LIVESTREAMING_START_STATUS_H

#include "OVR_Platform_Defs.h"

/// \file
/// It's an enum that represents the possible outcomes of starting a
/// livestreaming session. This allows the API to return a standardized and
/// well-defined set of values to indicate the outcome of starting a
/// livestreaming session. It can be used in
/// ovr_LivestreamingStartResult_GetStreamingResult() as type information.

/// A custom data structure that defines a set of enumerated values, where each value represents a specific type or category for that enumeration. See our [index](https://developer.oculus.com/reference/platform/latest/all_files_outline) for a full list of our enums and APIs. 
typedef enum ovrLivestreamingStartStatus_ {
  /// This member represents a successful start of the livestreaming session.
  ovrLivestreamingStartStatus_Success = 1,
  ovrLivestreamingStartStatus_Unknown = 0,
  /// This member represents an error where the package was not set during the
  /// livestreaming start process.
  ovrLivestreamingStartStatus_NoPackageSet = -1,
  /// This member represents an error where Facebook Connect was not enabled
  /// during the livestreaming start process.
  ovrLivestreamingStartStatus_NoFbConnect = -2,
  /// This member represents an error where a session ID was not provided during
  /// the livestreaming start process.
  ovrLivestreamingStartStatus_NoSessionId = -3,
  /// This member represents an error where required parameters were missing
  /// during the livestreaming start process.
  ovrLivestreamingStartStatus_MissingParameters = -4,
} ovrLivestreamingStartStatus;

/// Converts an ::ovrLivestreamingStartStatus enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) ovrLivestreamingStartStatus_ToString(ovrLivestreamingStartStatus value);

/// Converts a string representing an ::ovrLivestreamingStartStatus to the actual enum value and returns the value
OVRPL_PUBLIC_FUNCTION(ovrLivestreamingStartStatus) ovrLivestreamingStartStatus_FromString(const char* str);

#endif
