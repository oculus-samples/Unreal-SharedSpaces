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

#include "OVRPlatformUtils.h"
#include "Misc/DefaultValueHelper.h"
#include "Misc/DateTime.h"

FString UOvrPlatformUtilsLibrary::Conv_OvrIdToString(FOvrId Id)
{
    return FString::Printf(TEXT("%llu"), static_cast<ovrID>(Id));
}

FOvrId UOvrPlatformUtilsLibrary::Conv_Int64ToOvrId(int64 Id)
{
    return FOvrId(ovrID(Id));
}

bool UOvrPlatformUtilsLibrary::EqualEqual_OvrIdOvrId(const FOvrId& A, const FOvrId& B)
{
    return ovrID(A) == ovrID(B);
}

FString UOvrPlatformUtilsLibrary::MakeRandomSessionId(const FString& Prefix)
{
    return FString::Printf(TEXT("%s%d"), *Prefix, FMath::RandRange(100000000, 999999999));
}
