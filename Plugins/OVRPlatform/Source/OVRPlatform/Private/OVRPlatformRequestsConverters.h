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

// These are converters for translation of data structures from UE to C and vice-versa.

class OvrPlatformString
{
public:

    OvrPlatformString(const FString& InString)
    {
        size_t OutStringLength = FTCHARToUTF8_Convert::ConvertedLength(*InString, InString.Len());
        OutString = (char*) FMemory::Malloc(sizeof(char) * (OutStringLength+1));
        FTCHARToUTF8_Convert::Convert(
            OutString,
            (int32)(OutStringLength),
            *InString,
            InString.Len());
        OutString[OutStringLength] = '\0';
    }

    ~OvrPlatformString()
    {
        FMemory::Free((void*) OutString);
    }

    operator char* ()
    {
        return OutString;
    }

    operator const char* ()
    {
        return const_cast<const char*>(OutString);
    }

private:

    char* OutString;
};

class OvrPlatformStringArray
{
public:

    OvrPlatformStringArray(const TArray<FString>& InStrings)
    {
        size_t NumBytes = sizeof(char*) * InStrings.Num();
        size_t Offset = NumBytes;

        for (size_t Index = 0; Index < InStrings.Num(); ++Index)
        {
            int32 StringLen =
            FTCHARToUTF8_Convert::ConvertedLength(*InStrings[Index], InStrings[Index].Len());
            NumBytes += StringLen + 1;
        }

        StringArray = FMemory::Malloc(NumBytes);
        char** Strings = (char**)StringArray;
        char* String = ((char*)StringArray) + Offset;
        char* StringLim = ((char*)StringArray) + NumBytes;

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

    ~OvrPlatformStringArray()
    {
        FMemory::Free(StringArray);
    }

    operator char**() const
    {
        return reinterpret_cast<char**>(StringArray);
    }

    operator const char**() const
    {
        return reinterpret_cast<const char**>(StringArray);
    }

private:

    void* StringArray;
};

class OvrPlatformByteArray
{
public:

    OvrPlatformByteArray(const TArray<uint8>& InBytes)
    {
        NumOutBytes = InBytes.Num();
        OutBytes = (uint8*) FMemory::Malloc(sizeof(uint8) * NumOutBytes);

        for (size_t Index = 0; Index < NumOutBytes; ++Index)
        {
            OutBytes[Index] = InBytes[Index];
        }
    }

    ~OvrPlatformByteArray()
    {
        FMemory::Free(OutBytes);
    }

    operator uint8* ()
    {
        return OutBytes;
    }

    operator void* ()
    {
        return (void*) OutBytes;
    }

private:

    uint8* OutBytes;
    size_t NumOutBytes;
};

class OvrPlatformFloatArray
{
public:

    OvrPlatformFloatArray(const TArray<float>& InFloats)
    {
        NumOutFloats = InFloats.Num();
        OutFloats = (float*) FMemory::Malloc(sizeof(float) * NumOutFloats);

        for (size_t Index = 0; Index < NumOutFloats; ++Index)
        {
            OutFloats[Index] = InFloats[Index];
        }
    }

    ~OvrPlatformFloatArray()
    {
        FMemory::Free(OutFloats);
    }

    operator float* ()
    {
        return OutFloats;
    }

private:

    float* OutFloats;
    size_t NumOutFloats;
};

class OvrPlatformShortArray
{
public:

    OvrPlatformShortArray(const TArray<int32>& InShorts)
    {
        NumOutShorts = InShorts.Num();
        OutShorts = (int16*) FMemory::Malloc(sizeof(int16) * NumOutShorts);

        for (size_t Index = 0; Index < NumOutShorts; ++Index)
        {
            // UE blueprint doesn't support shorts, so we coerce down from 32 to 16 bits.
            OutShorts[Index] = static_cast<int16>(InShorts[Index]&0xFF);
        }
    }

    ~OvrPlatformShortArray()
    {
        FMemory::Free(OutShorts);
    }

    operator int16* ()
    {
        return OutShorts;
    }

private:

    int16* OutShorts;
    size_t NumOutShorts;
};

class OvrPlatformIntArray
{
public:

    OvrPlatformIntArray(const TArray<int32>& InInts)
    {
        NumOutInts = InInts.Num();
        OutInts = (int32*) FMemory::Malloc(sizeof(int32) * NumOutInts);

        for (size_t Index = 0; Index < NumOutInts; ++Index)
        {
            OutInts[Index] = InInts[Index];
        }
    }

    ~OvrPlatformIntArray()
    {
        FMemory::Free(OutInts);
    }

    operator int32* ()
    {
        return OutInts;
    }

    operator uint32* ()
    {
        // UE blueprint doesn't support unsigned values, so we coerce to unsigned for the C as needed.
        return (uint32*) OutInts;
    }

private:

    int32* OutInts;
    size_t NumOutInts;
};

class OvrPlatformIdArray
{
public:

    OvrPlatformIdArray(const TArray<FOvrId>& InIds)
    {
        NumOutIds = InIds.Num();
        OutIds = (ovrID*) FMemory::Malloc(sizeof(ovrID) * NumOutIds);

        for (size_t Index = 0; Index < NumOutIds; ++Index)
        {
            OutIds[Index] = InIds[Index];
        }
    }

    ~OvrPlatformIdArray()
    {
        FMemory::Free(OutIds);
    }

    operator ovrID* ()
    {
        return OutIds;
    }

    operator const ovrID* ()
    {
        return const_cast<const ovrID*>(OutIds);
    }

private:

    ovrID* OutIds;
    size_t NumOutIds;
};

class OvrPlatformKeyValuePairArray
{
public:

    OvrPlatformKeyValuePairArray(const TMap<FString, FOvrVariant>& KeyValuePairMap)
    {
        size_t NumOutKeyValuePairs = KeyValuePairMap.Num();
        OutKeyValuePairs = (ovrKeyValuePair*) FMemory::Malloc(sizeof(ovrKeyValuePair) * NumOutKeyValuePairs);

        size_t Index = 0;
        for (auto& KeyValuePair : KeyValuePairMap)
        {
            OutKeyValuePairs[Index].key = Store(KeyValuePair.Key);
            OutKeyValuePairs[Index].valueType = ConvertKeyValuePairType(KeyValuePair.Value.Type);
            switch (KeyValuePair.Value.Type)
            {
                case EOvrKeyValuePairType::String:
                    OutKeyValuePairs[Index].stringValue = Store(KeyValuePair.Value.StringValue);
                    break;
                case EOvrKeyValuePairType::Int:
                    OutKeyValuePairs[Index].intValue = KeyValuePair.Value.IntValue;
                    break;
                case EOvrKeyValuePairType::Double:
                    OutKeyValuePairs[Index].doubleValue = KeyValuePair.Value.FloatValue;
                    break;
                default:
                    break;
            }

            Index++;
        }
    }

    ~OvrPlatformKeyValuePairArray()
    {
        FMemory::Free(OutKeyValuePairs);
    }

    operator ovrKeyValuePair* ()
    {
        return OutKeyValuePairs;
    }

    operator const ovrKeyValuePair* ()
    {
        return const_cast<const ovrKeyValuePair*>(OutKeyValuePairs);
    }

private:

    ovrKeyValuePair* OutKeyValuePairs;

    TArray<OvrPlatformString> StringBasket;

    char* Store(const FString& String)
    {
        StringBasket.Add(String);
        return StringBasket.Last();
    }
};

class OvrPlatformCByteArray
{
public:

    OvrPlatformCByteArray(size_t DataLength)
    {
        // ? Make sure FMemory::Malloc uses memory pools.
        Size = DataLength;
        Data = (uint8*) FMemory::Malloc(sizeof(uint8) * DataLength);
    }

    ~OvrPlatformCByteArray()
    {
        FMemory::Free(Data);
    }

    operator uint8*()
    {
        return Data;
    }

    void ToUE(TArray<uint8>& UEData)
    {
        UEData.Empty(Size);
        for (int Index = 0; Index < Size; Index++)
        {
            UEData.Add(Data[Index]);
        }
    }

private:

    uint8 *Data;
    size_t Size;
};

class OvrPlatformCInt16Array
{
public:

    OvrPlatformCInt16Array(size_t DataLength)
    {
        // ? Make sure FMemory::Malloc uses memory pools.
        Size = DataLength;
        Data = (int16*) FMemory::Malloc(sizeof(int16) * DataLength);
    }

    ~OvrPlatformCInt16Array()
    {
        FMemory::Free(Data);
    }

    operator int16*()
    {
        return Data;
    }

    void ToUE(TArray<int32>& UEData)
    {
        UEData.Empty(Size);
        for (int Index = 0; Index < Size; Index++)
        {
            UEData.Add(int32(Data[Index]));
        }
    }

private:

    int16 *Data;
    size_t Size;
};

class OvrPlatformCFloatArray
{
public:

    OvrPlatformCFloatArray(size_t DataLength)
    {
        // ? Make sure FMemory::Malloc uses memory pools.
        Size = DataLength;
        Data = (float*) FMemory::Malloc(sizeof(float) * DataLength);
    }

    ~OvrPlatformCFloatArray()
    {
        FMemory::Free(Data);
    }

    operator float*()
    {
        return Data;
    }

    void ToUE(TArray<float>& UEData)
    {
        UEData.Empty(Size);
        for (int Index = 0; Index < Size; Index++)
        {
            UEData.Add(Data[Index]);
        }
    }

private:

    float *Data;
    size_t Size;
};


class OvrPlatformMatchmakingCustomQueryData
{
public:

    OvrPlatformMatchmakingCustomQueryData(const FOvrMatchmakingCustomQueryData& Data)
    {
        MatchmakingQueryData = (ovrMatchmakingCustomQueryData*) FMemory::Malloc(sizeof(ovrMatchmakingCustomQueryData));

        MatchmakingQueryData->customQueryDataArray = (ovrKeyValuePair*) FMemory::Malloc(sizeof(ovrKeyValuePair) * Data.CustomQueryDataMap.Num());
        MatchmakingQueryData->customQueryDataArrayCount = Data.CustomQueryDataMap.Num();

        size_t Index = 0;
        for (auto& KeyValuePair : Data.CustomQueryDataMap)
        {
            MatchmakingQueryData->customQueryDataArray[Index].key = Store(KeyValuePair.Key);
            MatchmakingQueryData->customQueryDataArray[Index].valueType = ConvertKeyValuePairType(KeyValuePair.Value.Type);
            switch (KeyValuePair.Value.Type)
            {
                case EOvrKeyValuePairType::String:
                    MatchmakingQueryData->customQueryDataArray[Index].stringValue = Store(KeyValuePair.Value.StringValue);
                    break;
                case EOvrKeyValuePairType::Int:
                    MatchmakingQueryData->customQueryDataArray[Index].intValue = KeyValuePair.Value.IntValue;
                    break;
                case EOvrKeyValuePairType::Double:
                    MatchmakingQueryData->customQueryDataArray[Index].doubleValue = KeyValuePair.Value.FloatValue;
                    break;
                default:
                    break;
            }

            Index++;
        }

        MatchmakingQueryData->customQueryCriterionArray = (ovrMatchmakingCriterion*) FMemory::Malloc(sizeof(ovrMatchmakingCriterion) * Data.CustomQueryCriterionMap.Num());
        MatchmakingQueryData->customQueryCriterionArrayCount = Data.CustomQueryCriterionMap.Num();

        Index = 0;
        for (auto& KeyValuePair : Data.CustomQueryCriterionMap)
        {
            MatchmakingQueryData->customQueryCriterionArray[Index].key = Store(KeyValuePair.Key);
            MatchmakingQueryData->customQueryCriterionArray[Index].importance = ConvertMatchmakingCriterionImportance(KeyValuePair.Value.Importance);
            MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray = (ovrKeyValuePair*) FMemory::Malloc(sizeof(ovrKeyValuePair) * KeyValuePair.Value.ParameterMap.Num());
            MatchmakingQueryData->customQueryCriterionArray[Index].parameterArrayCount = KeyValuePair.Value.ParameterMap.Num();

            size_t Index2 = 0;
            for (auto& KeyValuePair2 : KeyValuePair.Value.ParameterMap)
            {
                MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray[Index2].key = Store(KeyValuePair2.Key);
                MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray[Index2].valueType = ConvertKeyValuePairType(KeyValuePair2.Value.Type);
                switch (KeyValuePair2.Value.Type)
                {
                    case EOvrKeyValuePairType::String:
                        MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray[Index2].stringValue = Store(KeyValuePair2.Value.StringValue);
                        break;
                    case EOvrKeyValuePairType::Int:
                        MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray[Index2].intValue = KeyValuePair2.Value.IntValue;
                        break;
                    case EOvrKeyValuePairType::Double:
                        MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray[Index2].doubleValue = KeyValuePair2.Value.FloatValue;
                        break;
                    default:
                        break;
                }

                Index2++;
            }
        }
    }

    ~OvrPlatformMatchmakingCustomQueryData()
    {
        FMemory::Free(MatchmakingQueryData->customQueryDataArray);

        for (size_t Index = 0; Index < MatchmakingQueryData->customQueryCriterionArrayCount; Index++)
        {
            FMemory::Free(MatchmakingQueryData->customQueryCriterionArray[Index].parameterArray);
        }
        FMemory::Free(MatchmakingQueryData->customQueryCriterionArray);

        FMemory::Free(MatchmakingQueryData);
    }

    operator ovrMatchmakingCustomQueryData* ()
    {
        return MatchmakingQueryData;
    }

    operator const ovrMatchmakingCustomQueryData* ()
    {
        return const_cast<const ovrMatchmakingCustomQueryData*>(MatchmakingQueryData);
    }

private:

    ovrMatchmakingCustomQueryData* MatchmakingQueryData;

    TArray<OvrPlatformString> StringBasket;

    char* Store(const FString& String)
    {
        StringBasket.Add(String);
        return StringBasket.Last();
    }
};
