// Copyright (c) Facebook Technologies, LLC and its affiliates.  All rights reserved.

#pragma once

#ifdef _EG_WINDOWS_PLATFORM
#include "Windows/AllowWindowsPlatformTypes.h"
#endif
#include "LoadBalancing-cpp/inc/Client.h"
#ifdef _EG_WINDOWS_PLATFORM
#include "Windows/HideWindowsPlatformTypes.h"
#endif

#include "BaseView.h"
#include "Delegates/DelegateCombinations.h" // for DECLARE_DELEGATE_OneParam
#include "OVR_Types.h"

#define EVENTCODE_PACKET 1
#define EVENTCODE_CONNECT 2

struct IncomingPacket
{
	ovrID senderID;
	short length;
	nByte* data;
};

DECLARE_DELEGATE_OneParam(FSingleIntDelegate, int);

static FString toFString(ExitGames::Common::JString jstr)
{
	return FString(jstr.UTF8Representation().cstr());
}

static ExitGames::Common::JString toJString(FString fstr)
{
	return ExitGames::Common::JString(TCHAR_TO_UTF8(*fstr));
}

class LoadBalancingListener : public ExitGames::LoadBalancing::Listener
{
public: 
	LoadBalancingListener(BaseView* pView);
	~LoadBalancingListener(void);

	void setLBC(ExitGames::LoadBalancing::Client* pLbc);
	void connect(const ExitGames::Common::JString& userName);
	void service(void);
	IncomingPacket* ReadPacket(void);
	void RemovePacket();
	FSingleIntDelegate* GetAddPlayerDelegate();

private:
	//From Common::BaseListener

	// receive and print out debug out here
	virtual void debugReturn(int debugLevel, const ExitGames::Common::JString& string);

	//From LoadBalancing::LoadBalancingListener

	// implement your error-handling here
	virtual void connectionErrorReturn(int errorCode);
	virtual void clientErrorReturn(int errorCode);
	virtual void warningReturn(int warningCode);
	virtual void serverErrorReturn(int errorCode);

	// events, triggered by certain operations of all players in the same room
	virtual void joinRoomEventAction(int playerNr, const ExitGames::Common::JVector<int>& playernrs, const ExitGames::LoadBalancing::Player& player);
	virtual void leaveRoomEventAction(int playerNr, bool isInactive);
	virtual void customEventAction(int playerNr, nByte eventCode, const ExitGames::Common::Object& eventContent);

	// callbacks for operations on PhotonLoadBalancing server
	virtual void connectReturn(int errorCode, const ExitGames::Common::JString& errorString, const ExitGames::Common::JString& region, const ExitGames::Common::JString& cluster);
	virtual void disconnectReturn(void);
	virtual void joinOrCreateRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
	virtual void leaveRoomReturn(int errorCode, const ExitGames::Common::JString& errorString);
	virtual void onRoomListUpdate(void);
	virtual void onRoomPropertiesChange(const ExitGames::Common::Hashtable& changes);
	virtual void onMasterClientChanged(int id, int oldId);

	void updateState(void);
	void connectToListenServer(int playerNr, const ExitGames::LoadBalancing::Player& player);
	
	ExitGames::LoadBalancing::Client* mpLbc;
	BaseView* mpView;
	int mLocalPlayerNr;
	
	TArray<IncomingPacket> mPacketsReceived;

	FSingleIntDelegate* PlayerJoinedDelegate;
};