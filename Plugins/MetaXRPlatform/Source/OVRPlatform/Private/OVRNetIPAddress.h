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
#include "IPAddress.h"
#include "Algo/Reverse.h"
#include "Engine/EngineBaseTypes.h"
#include "OvrPlatform.h"
#include "OvrPlatformTypes.h"

/**
* Fake an internet ip address but in reality using an ovrID
*/
class OVRPLATFORM_API FOvrInternetAddr : public FInternetAddr
{
public:
	ovrID OculusId;

	/**
	 * Copy Constructor
	 */
	FOvrInternetAddr(const FOvrInternetAddr& Src) :
		OculusId(Src.OculusId)
	{}

	/**
	 * Constructor. Sets address to default state
	 */
	FOvrInternetAddr() :
		OculusId(0ull)
	{}

	/**
	 * Constructor
	 */
	explicit FOvrInternetAddr(ovrID InOculusId) :
		OculusId(InOculusId)
	{}

	/**
	 * Constructor
	 */
	explicit FOvrInternetAddr(FString InString) :
		OculusId(FCString::Strtoui64(*InString, NULL, 10))
	{}

	/**
	 * Constructor
	 */
	explicit FOvrInternetAddr(const FURL& ConnectURL)
	{
		auto Host = ConnectURL.Host;

		// Parse the URL: unreal://<oculus_id>.oculus or unreal://<oculus_id>
		int32 DotIndex;
		auto OculusStringID = (Host.FindChar('.', DotIndex)) ? Host.Left(DotIndex) : Host;
		OculusId = strtoull(TCHAR_TO_ANSI(*OculusStringID), nullptr, 10);
	}

	ovrID GetID() const
	{
		return OculusId;
	}

	virtual TArray<uint8> GetRawIp() const override
	{
		TArray<uint8> RawAddressArray;
		const uint8* OculusIdWalk = reinterpret_cast<const uint8*>(&OculusId);
		while (RawAddressArray.Num() < sizeof(OculusId))
		{
			RawAddressArray.Add(*OculusIdWalk);
			++OculusIdWalk;
		}

		// We want to make sure that these arrays are in big endian format.
#if PLATFORM_LITTLE_ENDIAN
		Algo::Reverse(RawAddressArray);
#endif

		return RawAddressArray;
	}

	virtual void SetRawIp(const TArray<uint8>& RawAddr) override
	{
		OculusId = 0;
		uint8* OculusIdWalk = reinterpret_cast<uint8*>(&OculusId);

		// If we're little endian, we need to reverse so that the shifts turn out correct
#if PLATFORM_LITTLE_ENDIAN
		OculusIdWalk += sizeof(OculusId)-1;
		for (int32 i = 0; i < sizeof(OculusId); ++i)
		{
			*OculusIdWalk-- = RawAddr[i];
		}
#else
		for (int32 i = 0; i < sizeof(OculusId); ++i)
		{
			*OculusIdWalk++ = RawAddr[i];
		}
#endif
	}

	/**
	 * Sets the ip address from a host byte order uint32
	 *
	 * @param InAddr the new address to use (must convert to network byte order)
	 */
	void SetIp(uint32 InAddr) override
	{
		/** Not used */
	}

	/**
	 * Sets the ip address from a string ("A.B.C.D")
	 *
	 * @param InAddr the string containing the new ip address to use
	 */
	void SetIp(const TCHAR* InAddr, bool& bIsValid) override
	{
		/** Not used */
	}

	/**
	 * Copies the network byte order ip address to a host byte order dword
	 *
	 * @param OutAddr the out param receiving the ip address
	 */
	void GetIp(uint32& OutAddr) const override
	{
		/** Not used */
	}

	/**
	 * Sets the port number from a host byte order int
	 *
	 * @param InPort the new port to use (must convert to network byte order)
	 */
	void SetPort(int32 InPort) override
	{
		/** Not used */
	}

	/**
	 * Copies the port number from this address and places it into a host byte order int
	 *
	 * @param OutPort the host byte order int that receives the port
	 */
	void GetPort(int32& OutPort) const override
	{
		/** Not used */
	}

	/**
	 * Returns the port number from this address in host byte order
	 */
	int32 GetPort() const override
	{
		/** Not used */
		return 0;
	}

	/** Sets the address to be any address */
	void SetAnyAddress() override
	{
		/** Not used */
	}

	/** Sets the address to broadcast */
	void SetBroadcastAddress() override
	{
		/** Not used */
	}

	/** Sets the address to loopback */
	void SetLoopbackAddress() override
	{
		/** Not used */
	}

	/**
	 * Converts this internet ip address to string form
	 *
	 * @param bAppendPort whether to append the port information or not
	 */
	FString ToString(bool bAppendPort) const override
	{
		return FString::Printf(TEXT("%llu.oculus"), OculusId);
	}

	/**
	 * Compares two internet ip addresses for equality
	 *
	 * @param Other the address to compare against
	 */
	virtual bool operator==(const FInternetAddr& Other) const override
	{
		FOvrInternetAddr& OculusOther = (FOvrInternetAddr&)Other;
		return OculusId == OculusOther.OculusId;
	}

	bool operator!=(const FOvrInternetAddr& Other) const
	{
		return !(FOvrInternetAddr::operator==(Other));
	}

	virtual uint32 GetTypeHash() const override
	{
		return ::GetTypeHash(OculusId);
	}

	virtual FName GetProtocolType() const override
	{
		return FNetworkProtocolTypes::OvrPlatform;
	}

	/**
	 * Is this a well formed internet address
	 *
	 * @return true if a valid Oculus id, false otherwise
	 */
	virtual bool IsValid() const override
	{
		return true;
	}

	virtual TSharedRef<FInternetAddr> Clone() const override
	{
		TSharedRef<FOvrInternetAddr> NewAddress = MakeShareable(new FOvrInternetAddr);
		NewAddress->OculusId = OculusId;
		return NewAddress;
	}
};
