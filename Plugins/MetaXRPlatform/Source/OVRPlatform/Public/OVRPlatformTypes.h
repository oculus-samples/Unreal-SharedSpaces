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

#include <memory>

#include "CoreMinimal.h"
#include "OVR_Platform.h"
#include "Misc/CString.h"

#include "OVRPlatformEnums.h"
#include "OVRPlatformTypes.generated.h"

/** UE type corresponding to OVR Platform ovrID */
USTRUCT(BlueprintType, Category = "OvrPlatform|CustomModels|ID")
struct OVRPLATFORM_API FOvrId
{
    GENERATED_USTRUCT_BODY()

    FOvrId() : Id(0) {}
    FOvrId(ovrID ID) : Id(ID) {}
    FOvrId(const FString& StrId) : Id(FCString::Strtoui64(*StrId, nullptr, 10)) {}

    operator ovrID() const
    {
        return Id;
    }

    bool operator==(const FOvrId& Other)
    {
      return Id == Other.Id;
    }

    friend uint32 GetTypeHash(const FOvrId& Other)
    {
      return GetTypeHash(Other.Id);
    }

private:

    UPROPERTY()
    uint64 Id;
};

/** UE type corresponding to OVR Platform ovrKeyValuePair */
USTRUCT(BlueprintType, Category = "OvrPlatform|CustomModels|Variant")
struct OVRPLATFORM_API FOvrVariant
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "OvrPlatform|CustomModels|Variant|Field")
    EOvrKeyValuePairType Type;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(EditCondition="Type == EOvrVariantType::String", EditConditionHides), Category = "OvrPlatform|CustomModels|Variant|Field")
    FString StringValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(EditCondition="Type == EOvrVariantType::Int", EditConditionHides), Category = "OvrPlatform|CustomModels|Variant|Field")
    int IntValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(EditCondition="Type == EOvrVariantType::Double", EditConditionHides), Category = "OvrPlatform|CustomModels|Variant|Field")
    float FloatValue;

    FOvrVariant()
    {
        Type = EOvrKeyValuePairType::Unknown;
        StringValue = TEXT("");
        IntValue = 0;
        FloatValue = 0.0f;
    }
};

// Wrapper to manage ovrMessageHandle lifetime.
// Some payloads, like paged arrays, require the message that transports them
// to outlive the lifetime of their initial handlers, as they get deallocated
// at the same time.  See OVRPlatformModelsPageRequests.h/.cpp.
class TOvrMessageHandle
{
public:
	TOvrMessageHandle():
		Handle(nullptr)
	{}

	explicit TOvrMessageHandle(ovrMessageHandle Handle):
		Handle(Handle)
	{}

	~TOvrMessageHandle()
	{
		ovr_FreeMessage(Handle);
		Handle = nullptr;
	}

	operator ovrMessageHandle() const { return Handle; }

private:
	ovrMessageHandle Handle;
};

typedef std::shared_ptr<TOvrMessageHandle> TOvrMessageHandlePtr;
