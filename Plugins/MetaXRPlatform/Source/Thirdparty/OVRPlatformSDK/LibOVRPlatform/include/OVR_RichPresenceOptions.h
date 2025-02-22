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

#ifndef OVR_RICH_PRESENCE_OPTIONS_H
#define OVR_RICH_PRESENCE_OPTIONS_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "OVR_RichPresenceExtraContext.h"

struct ovrRichPresenceOptions;

typedef struct ovrRichPresenceOptions* ovrRichPresenceOptionsHandle;
/// \brief Creates a new instance of ovrRichPresenceOptionsHandle() which is used to customize the option flow. It returns a handle to the newly created options object, which can be used to set various properties for the options.
OVRP_PUBLIC_FUNCTION(ovrRichPresenceOptionsHandle) ovr_RichPresenceOptions_Create();
/// \brief Destroys an existing instance of the ovrRichPresenceOptionsHandle() and frees up memory when you're done using it.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_Destroy(ovrRichPresenceOptionsHandle handle);
/// \deprecated Use ovr_GroupPresenceOptions_SetDestinationApiName()
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetApiName(ovrRichPresenceOptionsHandle handle, const char * value);
/// \deprecated Unused.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetArgsString(ovrRichPresenceOptionsHandle handle, const char* key, const char* value);
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_ClearArgs(ovrRichPresenceOptionsHandle handle);
/// \deprecated Unused. Removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetCurrentCapacity(ovrRichPresenceOptionsHandle handle, unsigned int value);
/// \deprecated Use ovr_GroupPresenceOptions_SetDeeplinkMessageOverride()
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetDeeplinkMessageOverride(ovrRichPresenceOptionsHandle handle, const char * value);
/// \deprecated Unused. Removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetEndTime(ovrRichPresenceOptionsHandle handle, unsigned long long value);
/// \deprecated Unused. Removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetExtraContext(ovrRichPresenceOptionsHandle handle, ovrRichPresenceExtraContext value);
/// \deprecated Use ovr_GroupPresenceOptions_SetMatchSessionId() Removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetInstanceId(ovrRichPresenceOptionsHandle handle, const char * value);
/// \deprecated Unused. Removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetIsIdle(ovrRichPresenceOptionsHandle handle, bool value);
/// \deprecated Use ovr_GroupPresenceOptions_SetIsJoinable()
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetIsJoinable(ovrRichPresenceOptionsHandle handle, bool value);
/// \deprecated Unused.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetJoinableId(ovrRichPresenceOptionsHandle handle, const char * value);
/// \deprecated Use ovr_GroupPresenceOptions_SetLobbySessionId() Removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetLobbySessionId(ovrRichPresenceOptionsHandle handle, const char * value);
/// \deprecated Use ovr_GroupPresenceOptions_SetMatchSessionId() Removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetMatchSessionId(ovrRichPresenceOptionsHandle handle, const char * value);
/// \deprecated Unused. Removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetMaxCapacity(ovrRichPresenceOptionsHandle handle, unsigned int value);
/// \deprecated Unused. Removed from headers at version v51.
OVRP_PUBLIC_FUNCTION(void) ovr_RichPresenceOptions_SetStartTime(ovrRichPresenceOptionsHandle handle, unsigned long long value);

#endif
