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

#ifndef OVR_MULTIPLAYER_ERROR_OPTIONS_H
#define OVR_MULTIPLAYER_ERROR_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_MultiplayerErrorErrorKey.h"

/// \file
/// The multiplayer error option is a feature that allows developers to display
/// general error messages to ::ovrUserHandle in invokable error dialogs. This
/// option is particularly useful in multiplayer games or applications where
/// errors can occur due to various reasons such as network connectivity
/// issues, server downtime, or other technical problems. Read more about error
/// dialogues in our
/// [docs](https://developer.oculus.com/documentation/native/ps-error-
/// dialogs/).
struct ovrMultiplayerErrorOptions;

typedef struct ovrMultiplayerErrorOptions* ovrMultiplayerErrorOptionsHandle;
/// \brief Creates a new instance of ovrMultiplayerErrorOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrMultiplayerErrorOptionsHandle) ovr_MultiplayerErrorOptions_Create();
/// \brief Destroys an existing instance of the ovrMultiplayerErrorOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_MultiplayerErrorOptions_Destroy(ovrMultiplayerErrorOptionsHandle handle);
/// Key associated with the predefined error message to be shown to users.
///
/// Key List:
///
/// - ovrMultiplayerErrorErrorKey_DestinationUnavailable()
///
/// - ovrMultiplayerErrorErrorKey_DlcRequired()
///
/// - ovrMultiplayerErrorErrorKey_General()
///
/// - ovrMultiplayerErrorErrorKey_GroupFull()
///
/// - ovrMultiplayerErrorErrorKey_InviterNotJoinable()
///
/// - ovrMultiplayerErrorErrorKey_LevelNotHighEnough()
///
/// - ovrMultiplayerErrorErrorKey_LevelNotUnlocked()
///
/// - ovrMultiplayerErrorErrorKey_NetworkTimeout()
///
/// - ovrMultiplayerErrorErrorKey_NoLongerAvailable()
///
/// - ovrMultiplayerErrorErrorKey_UpdateRequired()
///
/// - ovrMultiplayerErrorErrorKey_TutorialRequired()
OVRP_PUBLIC_FUNCTION(void) ovr_MultiplayerErrorOptions_SetErrorKey(ovrMultiplayerErrorOptionsHandle handle, ovrMultiplayerErrorErrorKey value);

#endif
