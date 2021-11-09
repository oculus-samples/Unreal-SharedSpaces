// Copyright (c) Facebook, Inc. and its affiliates.

#include "NetConnectionForOculus.h"
#include "IPAddressOculus.h"

#include "Net/DataChannel.h"

void UNetConnectionForOculus::InitBase(UNetDriver* InDriver, class FSocket* InSocket, const FURL& InURL, EConnectionState InState, int32 InMaxPacket, int32 InPacketOverhead)
{
	if (bIsPassThrough)
	{
		UIpConnection::InitBase(InDriver, InSocket, InURL, InState, InMaxPacket, InPacketOverhead);
		return;
	}

	DisableAddressResolution();

	// Pass the call up the chain
	UNetConnection::InitBase(InDriver, InSocket, InURL, InState,
		// Use the default packet size/overhead unless overridden by a child class
		InMaxPacket == 0 ? MAX_PACKET_SIZE : InMaxPacket,
		/* PacketOverhead */ 1);

	// We handle our own overhead
	PacketOverhead = 0;

	// Initalize the send buffer
	InitSendBuffer();
}

void UNetConnectionForOculus::InitLocalConnection(UNetDriver* InDriver, class FSocket* InSocket, const FURL& InURL, EConnectionState InState, int32 InMaxPacket, int32 InPacketOverhead)
{
	if (InDriver->GetSocketSubsystem() != nullptr)
	{
		bIsPassThrough = true;
		UIpConnection::InitLocalConnection(InDriver, InSocket, InURL, InState, InMaxPacket, InPacketOverhead);
		return;
	}

	bIsPassThrough = false;
	InitBase(InDriver, InSocket, InURL, InState,
		// Use the default packet size/overhead unless overridden by a child class
		InMaxPacket == 0 ? MAX_PACKET_SIZE : InMaxPacket,
		0);

	auto OculusAddr = FInternetAddrOculus(InURL);
	PeerID = OculusAddr.GetID();
}

void UNetConnectionForOculus::InitRemoteConnection(UNetDriver* InDriver, class FSocket* InSocket, const FURL& InURL, const class FInternetAddr& InRemoteAddr, EConnectionState InState, int32 InMaxPacket, int32 InPacketOverhead)
{
	if (InDriver->GetSocketSubsystem() != nullptr)
	{
		bIsPassThrough = true;
		UIpConnection::InitRemoteConnection(InDriver, InSocket, InURL, InRemoteAddr, InState, InMaxPacket, InPacketOverhead);
		return;
	}

	bIsPassThrough = false;
	InitBase(InDriver, InSocket, InURL, InState,
		// Use the default packet size/overhead unless overridden by a child class
		InMaxPacket == 0 ? MAX_PACKET_SIZE : InMaxPacket,
		0);

	RemoteAddr = InRemoteAddr.Clone();
	PeerID = StaticCastSharedPtr<FInternetAddrOculus>(RemoteAddr)->GetID();

	// This is for a client that needs to log in, setup ClientLoginState and ExpectedClientLoginMsgType to reflect that
	SetClientLoginState(EClientLoginState::LoggingIn);
	SetExpectedClientLoginMsgType(NMT_Hello);
}

void UNetConnectionForOculus::LowLevelSend(void* Data, int32 CountBits, FOutPacketTraits& Traits)
{
	if (bIsPassThrough)
	{
		UIpConnection::LowLevelSend(Data, CountBits, Traits);
		return;
	}

	check(PeerID);

	// Do not send packets over a closed connection
	// This can unintentionally re-open the connection
	if (State == EConnectionState::USOCK_Closed && ovr_Net_IsConnected(PeerID))
	{
		return;
	}

	const uint8* DataToSend = reinterpret_cast<uint8*>(Data);

	// Process any packet modifiers
	if (Handler.IsValid() && !Handler->GetRawSend())
	{
		const ProcessedPacket ProcessedData = Handler->Outgoing(reinterpret_cast<uint8*>(Data), CountBits, Traits);

		if (!ProcessedData.bError)
		{
			DataToSend = ProcessedData.Data;
			CountBits = ProcessedData.CountBits;
		}
		else
		{
			CountBits = 0;
		}
	}

	bool bBlockSend = false;
	uint32 CountBytes = FMath::DivideAndRoundUp(CountBits, 8);

#if !UE_BUILD_SHIPPING
	LowLevelSendDel.ExecuteIfBound((void*)DataToSend, CountBytes, bBlockSend);
#endif

	if (!bBlockSend && CountBytes > 0)
	{
		UE_LOG(LogNetTraffic, VeryVerbose, TEXT("Low level send to: %llu Count: %d"), PeerID, CountBytes);
		ovr_Net_SendPacket(PeerID, static_cast<size_t>(CountBytes), DataToSend, (IsInternalAck()) ? ovrSend_Reliable : ovrSend_Unreliable);
	}
}

FString UNetConnectionForOculus::LowLevelGetRemoteAddress(bool bAppendPort)
{
	if (bIsPassThrough)
	{
		return UIpConnection::LowLevelGetRemoteAddress(bAppendPort);
	}
	return FString::Printf(TEXT("%llu.oculus"), PeerID);
}

FString UNetConnectionForOculus::LowLevelDescribe()
{
	if (bIsPassThrough)
	{
		return UIpConnection::LowLevelDescribe();
	}
	return FString::Printf(TEXT("PeerId=%llu"), PeerID);
}

void UNetConnectionForOculus::FinishDestroy()
{
	if (bIsPassThrough)
	{
		UIpConnection::FinishDestroy();
		return;
	}
	// Keep track if it's this call that is closing the connection before cleanup is called
	const bool bIsClosingOpenConnection = State != EConnectionState::USOCK_Closed;
	UNetConnection::FinishDestroy();

	// If this connection was open, then close it
	if (PeerID != 0 && bIsClosingOpenConnection)
	{
		UE_LOG(LogNet, Verbose, TEXT("Oculus Net Connection closed to %llu"), PeerID);
		ovr_Net_Close(PeerID);
	}
}

FString UNetConnectionForOculus::RemoteAddressToString()
{
	if (bIsPassThrough)
	{
		return UIpConnection::RemoteAddressToString();
	}
	return LowLevelGetRemoteAddress(/* bAppendPort */ false);
}
