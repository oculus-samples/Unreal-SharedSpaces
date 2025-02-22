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

#ifndef OVR_COWATCHVIEWER_H
#define OVR_COWATCHVIEWER_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

/// \file
/// Cowatch viewer represents a viewer in a cowatching session, including their
/// user ID and any data that they have set. The cowatch viewer data can be
/// retrieved using ovr_Cowatching_GetViewersData(). It can be useful for
/// tracking the participants in a cowatching session and managing their data.
typedef struct ovrCowatchViewer *ovrCowatchViewerHandle;

/// Represents the viewer data set by this cowatching viewer. It's an optional
/// `string` and can be set by ovr_Cowatching_SetViewerData().
OVRP_PUBLIC_FUNCTION(const char *) ovr_CowatchViewer_GetData(const ovrCowatchViewerHandle obj);

/// A unique user ID of the viewer.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_CowatchViewer_GetId(const ovrCowatchViewerHandle obj);


#endif
