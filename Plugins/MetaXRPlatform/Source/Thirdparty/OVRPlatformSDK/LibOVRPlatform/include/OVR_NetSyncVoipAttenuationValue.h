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

#ifndef OVR_NETSYNCVOIPATTENUATIONVALUE_H
#define OVR_NETSYNCVOIPATTENUATIONVALUE_H

#include "OVR_Platform_Defs.h"

/// \file
/// The value is used in the [VoIP
/// system](https://developer.oculus.com/documentation/native/ps-parties/#voip-
/// options). The value determines how much the audio volume is reduced as the
/// distance between players increases. This helps to create a more immersive
/// experience by making distant players' voices sound fainter.
typedef struct ovrNetSyncVoipAttenuationValue *ovrNetSyncVoipAttenuationValueHandle;

/// fall-off value in decibel
OVRP_PUBLIC_FUNCTION(float) ovr_NetSyncVoipAttenuationValue_GetDecibels(const ovrNetSyncVoipAttenuationValueHandle obj);

/// The starting distance of the attenuation value. As the distance between
/// players increases, the audio volumn is reduced.
OVRP_PUBLIC_FUNCTION(float) ovr_NetSyncVoipAttenuationValue_GetDistance(const ovrNetSyncVoipAttenuationValueHandle obj);


#endif
