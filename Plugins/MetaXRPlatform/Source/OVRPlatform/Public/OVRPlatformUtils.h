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

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OVRPlatformTypes.h"
#include "OVRPlatformUtils.generated.h"

UCLASS()
class OVRPLATFORM_API UOvrPlatformUtilsLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /**
     * Function to auto-convert from FOculusId to FString.
     */
    UFUNCTION(BlueprintPure, meta=(DisplayName = "ToString (OvrId)", CompactNodeTitle = "->", BlueprintAutocast), Category="OculusPlatform|Utils")
    static FString Conv_OvrIdToString(FOvrId Id);

    /**
     * Function to auto-convert from int64 to FString.
     */
    UFUNCTION(BlueprintPure, meta=(DisplayName = "ToOvrId (Int64)", CompactNodeTitle = "->", BlueprintAutocast), Category="OculusPlatform|Utils")
    static FOvrId Conv_Int64ToOvrId(int64 Id);

    /**
     * Utility to compare two Oculus ids in blueprint.
     */
    UFUNCTION(BlueprintPure, meta=(DisplayName = "Equal OvrId", CompactNodeTitle = "==", Keywords = "== equal"), Category="OculusPlatform|Utils")
    static bool EqualEqual_OvrIdOvrId(const FOvrId& A, const FOvrId& B);

    /**
     * Builds a random id.
     * @param Prefix - The prefix to use for the random symbol.
     * @return The supplied prefix followed by a 9 digit random number.
     */
    UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Utils")
    static FString MakeRandomSessionId(const FString& Prefix);
};
