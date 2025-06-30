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

#ifndef OVR_TYPES_H
#define OVR_TYPES_H

#include "OVR_KeyValuePairType.h"
#include "OVR_VoipSampleRate.h"
#include "OVR_MediaContentType.h"

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/// Represents a single state change in the platform such as the
/// response to a request, or some new information from the backend.
typedef uint64_t ovrRequest;

// Represents an RequestID that can used as a default.
// We guarantee that no valid Request ID will equal invalidRequestID
const uint64_t invalidRequestID = 0;

// Represents an invalid MessageID that can used as a default.
// We guarantee that no valid Message ID will equal invalidMessageID
const uint64_t invalidMessageID = 0;

/// The ovrKeyValuePair struct represents a key-value pair, where the key is a string and the value can be either an integer,
/// a double, or a string. This struct is used to represent data in the Oculus Platform API.
/// See more details [here](https://developer.oculus.com/reference/platform/latest/).
typedef struct {
  /// The key component of the ovrKeyValuePair struct. It is a string value representing the key.
  const char* key;
  /// The type of value stored in the ovrKeyValuePair struct. Can be one of ovrKeyValuePairType: ovrKeyValuePairType_Integer,
  /// ovrKeyValuePairType_Double, ovrKeyValuePairType_String or ovrKeyValuePairType_Unknown.
  ovrKeyValuePairType valueType;
  
  /// The string value associated with the key, if the valueType is ovrKeyValuePairType_String.
  /// If the valueType is not ovrKeyValuePairType_String, this field is ignored.
  const char* stringValue;
  /// The integer value associated with the key, if the valueType is ovrKeyValuePairType_Integer.
  /// If the valueType is not ovrKeyValuePairType_Integer, this field is ignored.
  int intValue;
  /// The double value associated with the key, if the valueType is ovrKeyValuePairType_Double.
  /// If the valueType is not ovrKeyValuePairType_Double, this field is ignored.
  double doubleValue;

} ovrKeyValuePair;

/// Helper function for making an int ovrKeyValuePair.
///
/// For example, ovrKeyValuePair_makeInt("key", 1);
ovrKeyValuePair ovrKeyValuePair_makeInt(const char* key, int value);

/// Helper function for making a double ovrKeyValuePair.
///
/// For example, ovrKeyValuePair_makeDouble("key", 1.1);
ovrKeyValuePair ovrKeyValuePair_makeDouble(const char* key, double value);

/// Helper function for making a string ovrKeyValuePair.
///
/// For example, ovrKeyValuePair_makeString("key", "value");
ovrKeyValuePair ovrKeyValuePair_makeString(const char* key, const char* value);

/// A unique identifier for some entity in the system (user, room, etc).
///
typedef uint64_t ovrID;

/// Convert a string into an ovrID.  Returns false if the input is
/// malformed (either out of range, or not an integer).
bool ovrID_FromString(ovrID* outId, const char* inId);

/// Convert an ID back into a string.  This function round trips with
/// ovrID_FromString().  Note: the id format may change in the future.
/// Developers should not rely on the string representation being an
/// integer.
///
/// Length of outParam should be > 20.
bool ovrID_ToString(char* outParam, size_t bufferLength, ovrID id);

typedef void (*LogFunctionPtr)(const char*, const char*);
extern LogFunctionPtr DoLogging;

/// Callback used by the Voip subsystem for audio filtering
///
typedef void (
    *VoipFilterCallback)(int16_t pcmData[], size_t pcmDataLength, int frequency, int numChannels);

/// Callback used by the ovrMicrophone class to signal that data is available
///
typedef void (*MicrophoneDataAvailableCallback)(void*);

/// The ovrNetSyncVec3 struct represents a 3D vector with float components. It is used to represent net sync data in the Oculus Platform API.
/// The struct consists of 3 float values: x, y, and z each representing an axis.
/// See more details [here](https://developer.oculus.com/reference/platform/latest/).
typedef struct {
  /// The x component of the ovrNetSyncVec3 struct. It is a float value representing the x-axis.    
  float x;
  /// The y component of the ovrNetSyncVec3 struct. It is a float value representing the y-axis.
  float y;
  /// The z component of the ovrNetSyncVec3 struct. It is a float value representing the z-axis.
  float z;
} ovrNetSyncVec3;

#ifdef __cplusplus
}
#endif

#endif
