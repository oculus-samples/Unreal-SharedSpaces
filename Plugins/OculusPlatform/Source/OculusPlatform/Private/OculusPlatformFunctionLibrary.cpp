// Copyright (c) Facebook, Inc. and its affiliates.

#include "OculusPlatformFunctionLibrary.h"
#include "Misc/DefaultValueHelper.h"
#include "Misc/DateTime.h"
#include "OculusPlatformTypes.h"
#include "OculusPlatform.h"

FString UOculusPlatformFunctionLibrary::Conv_OculusIdToString(FOculusId OculusId)
{
	return FString::Printf(TEXT("%llu"), static_cast<ovrID>(OculusId));
}

FOculusId UOculusPlatformFunctionLibrary::Conv_Int64ToOculusId(int64 Id)
{
	return FOculusId(ovrID(Id));
}

FString UOculusPlatformFunctionLibrary::MakeRandomSessionId(const FString& Prefix)
{
	return FString::Printf(TEXT("%s%d"), *Prefix, FMath::RandRange(100000000, 999999999));
}

bool UOculusPlatformFunctionLibrary::EqualEqual_OculusIdOculusId(const FOculusId& A, const FOculusId& B)
{
	return ovrID(A) == ovrID(B);
}