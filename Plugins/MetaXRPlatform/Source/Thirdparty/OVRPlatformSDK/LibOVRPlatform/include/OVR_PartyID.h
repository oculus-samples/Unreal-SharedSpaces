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

#ifndef OVR_PARTYID_H
#define OVR_PARTYID_H

#include "OVR_Platform_Defs.h"
#include "OVR_Types.h"

/// \file
/// The party ID is a unique identifier of the party that will be generated for
/// every distinct party. This ID can be used to make requests such as
/// ovr_Party_GetCurrent() to get the current party by its id. Read more about
/// [parties](https://developer.oculus.com/documentation/native/ps-parties/).
typedef struct ovrPartyID *ovrPartyIDHandle;

/// The party ID can be used to retrieve ::ovrPartyHandle. Every party will
/// have a unique ID that is associated with it.
OVRP_PUBLIC_FUNCTION(ovrID) ovr_PartyID_GetID(const ovrPartyIDHandle obj);


#endif
