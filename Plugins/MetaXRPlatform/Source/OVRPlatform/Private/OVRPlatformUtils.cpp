// Copyright (c) Meta Platforms, Inc. and affiliates.

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
