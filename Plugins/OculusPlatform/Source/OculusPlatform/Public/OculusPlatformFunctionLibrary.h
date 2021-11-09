// Copyright (c) Facebook, Inc. and its affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OculusPlatformTypes.h"
#include "OculusPlatformFunctionLibrary.generated.h"

UCLASS()
class OCULUSPLATFORM_API UOculusPlatformFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/**
	 * Builds a random id.
	 * @param Prefix - The prefix to use for the random symbol.
	 * @return The supplied prefix followed by a 9 digit random number.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Utils")
	static FString MakeRandomSessionId(const FString& Prefix);

	/**
	 * Function to auto-convert from FOculusId to FString.
	 */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "ToString (OculusId)", CompactNodeTitle = "->", BlueprintAutocast), Category="OculusPlatform|Utils")
	static FString Conv_OculusIdToString(FOculusId OculusId);

	/**
	 * Function to auto-convert from int64 to FString.
	 */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "ToOculusId (Int64)", CompactNodeTitle = "->", BlueprintAutocast), Category="OculusPlatform|Utils")
	static FOculusId Conv_Int64ToOculusId(int64 Id);

	/**
	 * Utility to compare two Oculus ids in blueprint.
	 */
	UFUNCTION(BlueprintPure, meta=(DisplayName = "Equal OculusId", CompactNodeTitle = "==", Keywords = "== equal"), Category="OculusPlatform|Utils")
	static bool EqualEqual_OculusIdOculusId(const FOculusId& A, const FOculusId& B);
};
