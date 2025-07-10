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

#ifndef OVR_VOIPDECODER_H
#define OVR_VOIPDECODER_H

#include "OVR_Platform_Defs.h"
#include <stddef.h>

/// \file
/// It's a custom decoder for voice over internet protocol (VoIP) data. A VoIP
/// session can be established by ovr_Voip_Start() It provides a way to decode
/// compressed VoIP data into PCM format, which can then be played back or
/// further processed.
typedef struct ovrVoipDecoder *ovrVoipDecoderHandle;

/// This method is responsible for decoding the compressed VoIP data into a
/// format that can be played back or further processed. The compressed VoIP
/// data can be retrieved using ovr_Voip_GetPCM()
OVRP_PUBLIC_FUNCTION(void) ovr_VoipDecoder_Decode(const ovrVoipDecoderHandle obj, const unsigned char *compressedData, size_t compressedSize);

/// It's responsible for retrieving the decoded PCM data from the decoder. This
/// method returns the number of samples written to the output buffer
OVRP_PUBLIC_FUNCTION(size_t) ovr_VoipDecoder_GetDecodedPCM(const ovrVoipDecoderHandle obj, float *outputBuffer, size_t outputBufferSize);


#endif
