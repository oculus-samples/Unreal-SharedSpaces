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

// UE to C array converters.

class UOPSS_String
{
public:

    UOPSS_String(const FString& InString)
    {
        size_t OutStringLength = FTCHARToUTF8_Convert::ConvertedLength(*InString, InString.Len());
        OutString = (const char*) FMemory::Malloc(sizeof(const char) * (OutStringLength+1));
        FTCHARToUTF8_Convert::Convert(
            OutString,
            (int32)(OutStringLength),
            *InString,
            InString.Len());
        OutString[OutStringLength] = '\0';
    }

    ~UOPSS_String()
    {
        FMemory::Free((void*) OutString);
    }

    operator const char* ()
    {
        return OutString;
    }

private:

    const char* OutString;
};

class UOPSS_StringArray
{
public:

    UOPSS_StringArray(const TArray<FString>& InStrings)
    {
        size_t Bytes = sizeof(const char*) * InStrings.Num();
        size_t Offset = Bytes;

        for (size_t Index = 0; Index < InStrings.Num(); ++Index)
        {
            int32 StringLen =
            FTCHARToUTF8_Convert::ConvertedLength(*InStrings[Index], InStrings[Index].Len());
            Bytes += StringLen + 1;
        }

        StringArray = FMemory::Malloc(Bytes);
        const char** Strings = (const char**)StringArray;
        char* String = ((char*)StringArray) + Offset;
        char* StringLim = ((char*)StringArray) + Bytes;

        for (size_t Index = 0; Index < InStrings.Num(); ++Index)
        {
            Strings[Index] = String;
            int32 StringLen = FTCHARToUTF8_Convert::Convert(
                String,
                (int32)(StringLim - String),
                *InStrings[Index],
                InStrings[Index].Len());
            String[StringLen] = '\0';
            String += StringLen + 1;
        }
    }

    ~UOPSS_StringArray()
    {
        FMemory::Free(StringArray);
    }

    operator const char**() const
    {
        return (const char**)StringArray;
    }

private:

    void* StringArray;
};

class UOPSS_ByteArray
{
public:

    UOPSS_ByteArray(const TArray<Byte>& InBytes)
    {
        NumOutBytes = InBytes.Num();
        OutBytes = FMemory::Malloc(sizeof(char) * NumOutBytes);

        for (size_t Index = 0; Index < NumOutBytes; ++Index)
        {
            OutBytes[Index] = InBytes[Index];
        }
    }

    ~UOPSS_ByteArray()
    {
        FMemory::Free(OutBytes);
    }

    operator const void* ()
    {
        return OutBytes;
    }

private:

    void* OutBytes;
    size_t NumOutBytes;
};

class UOPSS_IdArray
{
public:

    UOPSS_IdArray(const TArray<FOculusId>& InIds)
    {
        NumOutIds = InIds.Num();
        OutIds = FMemory::Malloc(sizeof(ovrID) * NumOutIds);

        for (size_t Index = 0; Index < InIds; ++Index)
        {
            OutIds[Index] = InIds[Index];
        }
    }

    ~UOPSS_ByteArray()
    {
        FMemory::Free(OutBytes);
    }

    operator const ovrID* ()
    {
        return OutIds;
    }

private:

    ovrID* OutIds;
    size_t NumOutIds;
};

class UOPSS_KeyValuePairArray
{
public:

    UOPSS_KeyValuePairArray(const TMap<FString, FOculusVariant>& KeyValuePairMap)
    {
        size_t NumOutKeyValuePairs = KeyValuePairMap.Num();
        OutKeyValuePairs = FMemory::Malloc(sizeof(ovrKeyValuePair) * NumOutKeyValuePairs);

        size_t Index = 0;
        for (auto& KeyValuePair : KeyValuePairMap)
        {
            OutKeyValuePairs[Index].key = Store(KeyValuePair.Key);
            OutKeyValuePairsr[Index].valueType = ConvertKeyValuePairType(KeyValuePair.Value.Type);
            switch (KeyValuePair.Value.Type)
            {
                case EOculusKeyValuePairType::String:
                    OutKeyValuePairs[Index].stringValue = Store(KeyValuePair.Value.StringValue);
                    break;
                case EOculusKeyValuePairType::Int:
                    OutKeyValuePairs[Index].intValue = KeyValuePair.Value.IntValue;
                    break;
                case EOculusKeyValuePairType::Double:
                    OutKeyValuePairs[Index].doubleValue = KeyValuePair.Value.FloatValue;
                    break;
                default:
                    break;
            }

            Index++;
        }
    }

    ~UOPSS_KeyValuePairArray()
    {
        FMemory::Free(OutKeyValuePairs);
    }

    operator const ovrKeyValuePair* ()
    {
        return OutKeyValuePairs;
    }

private:

    ovrKeyValuePair* OutKeyValuePairs;

    TArray<UOPSS_String> StringBasket;

    const char* Store(const FString& String)
    {
        StringBasket.Add(String);
        return StringBasket.Last();
    }
};

class UOPSS_MatchmakingCustomQueryData
{
public:

    UOPSS_MatchmakingCustomQueryData(const FOculusMatchmakingCustomQueryData& Data)
    {
        MatchmakingQueryData = FMemory::Malloc(sizeof(ovrMatchmakingCustomQueryData));

        MatchmakingQueryData->ovrKeyValuePair = FMemory::Malloc(sizeof(ovrKeyValuePair) * Data.CustomQueryDataMap.Num());
        MatchmakingQueryData->customQueryDataArrayCount = Data.CustomQueryDataMap.Num();

        size_t Index = 0;
        for (auto& KeyValuePair : Data.CustomQueryDataMap)
        {
            MatchmakingQueryData->ovrKeyValuePair[Index].key = Store(KeyValuePair.Key);
            MatchmakingQueryData->ovrKeyValuePair[Index].valueType = ConvertKeyValuePairType(KeyValuePair.Value.Type);
            switch (KeyValuePair.Value.Type)
            {
                case EOculusKeyValuePairType::String:
                    MatchmakingQueryData->ovrKeyValuePair[Index].stringValue = Store(KeyValuePair.Value.StringValue);
                    break;
                case EOculusKeyValuePairType::Int:
                    MatchmakingQueryData->ovrKeyValuePair[Index].intValue = KeyValuePair.Value.IntValue;
                    break;
                case EOculusKeyValuePairType::Double:
                    MatchmakingQueryData->ovrKeyValuePair[Index].doubleValue = KeyValuePair.Value.FloatValue;
                    break;
                default:
                    break;
            }

            Index++;
        }

        MatchmakingQueryData->customQueryCriterionArray = FMemory::Malloc(sizeof(ovrMatchmakingCriterion) * Data.CustomQueryCriterionMap.Num());
        MatchmakingQueryData->customQueryCriterionArrayCount = Data.CustomQueryCriterionMap.Num();

        Index = 0;
        for (auto& KeyValuePair : Data.CustomQueryCriterionMap)
        {
            MatchmakingQueryData->customQueryCriterionArray[Index].key = Store(KeyValuePair.Key);
            MatchmakingQueryData->customQueryCriterionArray[Index].importance = ConvertMatchmakingCriterionImportance(KeyValuePair.Value.Importance);
            MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray = FMemory::Malloc(sizeof(ovrKeyValuePair) * KeyValuePair.Value.ParameterMap.Num());
            MatchmakingQueryData->customQueryCriterionArray[Index].parameterArrayCount = KeyValuePair.Value.ParameterMap.Num();

            size_t Index2 = 0;
            for (auto& KeyValuePair2 : KeyValuePair.Value.ParameterMap)
            {
                MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray[Index2].key = Store(KeyValuePair2.Key);
                MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray[Index2].valueType = ConvertKeyValuePairType(KeyValuePair2.Value.Type);
                switch (KeyValuePair2.Value.Type)
                {
                    case EOculusKeyValuePairType::String:
                        MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray[Index2].stringValue = Store(KeyValuePair2.Value.StringValue);
                        break;
                    case EOculusKeyValuePairType::Int:
                        MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray[Index2].intValue = KeyValuePair2.Value.IntValue;
                        break;
                    case EOculusKeyValuePairType::Double:
                        MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray[Index2].doubleValue = KeyValuePair2.Value.FloatValue;
                        break;
                    default:
                        break;
                }

                Index2++;
            }
        }
    }

    ~UOPSS_MatchmakingCustomQueryData()
    {
        FMemory::Free(MatchmakingQueryData->ovrKeyValuePair);

        for (size_t Index = 0; Index < MatchmakingQueryData->customQueryCriterionArrayCount; Index++)
        {
            FMemory::Free(MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray);
        }
        FMemory::Free(MatchmakingQueryData->customQueryCriterionArray);

        FMemory::Free(MatchmakingQueryData);
    }

    operator const ovrMatchmakingCustomQueryData* ()
    {
        return MatchmakingQueryData;
    }

private:

    ovrMatchmakingCustomQueryData* MatchmakingQueryData;

    TArray<UOPSS_String> StringBasket;

    const char* Store(const FString& String)
    {
        StringBasket.Add(String);
        return StringBasket.Last();
    }
};
