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

#ifndef OVR_PID_H
#define OVR_PID_H

#include "OVR_Platform_Defs.h"

/// \file
/// The pid refers to "Process ID," which is a unique identifier assigned to
/// each process running in a system. This identifier plays a crucial role in
/// managing and tracking processes. See more info about Platform Solutions
/// [here](https://developer.oculus.com/documentation/native/ps-platform-
/// intro/).
typedef struct ovrPid *ovrPidHandle;

/// Unique identifier assigned to each process running in a system, used for
/// tracking and managing purposes.
OVRP_PUBLIC_FUNCTION(const char *) ovr_Pid_GetId(const ovrPidHandle obj);


#endif
