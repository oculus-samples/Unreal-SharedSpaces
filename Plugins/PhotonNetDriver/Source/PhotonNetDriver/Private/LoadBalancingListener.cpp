// Copyright (c) Facebook Technologies, LLC and its affiliates.  All rights reserved.

#include "LoadBalancingListener.h"
#include <iostream>
#include <stdlib.h>
#include "Engine/GameEngine.h"


#ifdef _EG_ANDROID_PLATFORM
#	include <stdarg.h>
#	include <android/log.h>
#endif

using namespace ExitGames::Common;
using namespace ExitGames::LoadBalancing;


const JString PeerStatesStr[] = {
	JString(L"Uninitialized"),
	JString(L"PeerCreated"),
	JString(L"ConnectingToNameserver"),
	JString(L"ConnectedToNameserver"),
	JString(L"DisconnectingFromNameserver"),
	JString(L"Connecting"),
	JString(L"Connected"),
	JString(L"WaitingForCustomAuthenticationNextStepCall"),
	JString(L"Authenticated"),
	JString(L"JoinedLobby"),
	JString(L"DisconnectingFromMasterserver"),
	JString(L"ConnectingToGameserver"),
	JString(L"ConnectedToGameserver"),
	JString(L"AuthenticatedOnGameServer"),
	JString(L"Joining"),
	JString(L"Joined"),
	JString(L"Leaving"),
	JString(L"Left"),
	JString(L"DisconnectingFromGameserver"),
	JString(L"ConnectingToMasterserver"),
	JString(L"ConnectedComingFromGameserver"),
	JString(L"AuthenticatedComingFromGameserver"),
	JString(L"Disconnecting"),
	JString(L"Disconnected")
};

// TODO: update PeerStatesStr when PeerStates changes
// Checker below checks count match only
class PeerStatesStrChecker
{
public:
	PeerStatesStrChecker(void)
	{
		DEBUG_ASSERT(sizeof(PeerStatesStr)/sizeof(JString) == PeerStates::Disconnected + 1);
	}
} checker;

LoadBalancingListener::LoadBalancingListener(BaseView* pView) : mpLbc(NULL), mpView(pView), mLocalPlayerNr(0)
{
}

LoadBalancingListener::~LoadBalancingListener(void)
{
	delete mpView;
}

void LoadBalancingListener::setLBC(ExitGames::LoadBalancing::Client* pLbc)
{
	this->mpLbc = pLbc;
}

void LoadBalancingListener::connect(const JString& userName)
{
	mpLbc->connect(ConnectOptions(AuthenticationValues().setUserID(JString()+GETTIMEMS()), userName));
}

void LoadBalancingListener::debugReturn(int debugLevel, const JString& string)
{
	switch (debugLevel)
	{
		case (ExitGames::Common::DebugLevel::ERRORS):
		{
			UE_LOG(LogNet, Error, TEXT("%s"), *toFString(string));
			return;
		}
		case (ExitGames::Common::DebugLevel::WARNINGS):
		{
			UE_LOG(LogNet, Warning, TEXT("%s"), *toFString(string));
			return;
		}
	}

	UE_LOG(LogNet, Verbose, TEXT("%s"), *toFString(string));
}

void LoadBalancingListener::connectionErrorReturn(int errorCode)
{
	UE_LOG(LogNet, Error, TEXT("connection failed with error %d"), errorCode);
	updateState();
	mpView->Disconnected();
}

void LoadBalancingListener::clientErrorReturn(int errorCode)
{
	UE_LOG(LogNet, Error, TEXT("received error %d from client"), errorCode);
	updateState();
}

void LoadBalancingListener::warningReturn(int warningCode)
{
	UE_LOG(LogNet, Verbose, TEXT("received warning %d from client"), warningCode);
}

void LoadBalancingListener::serverErrorReturn(int errorCode)
{
	UE_LOG(LogNet, Error, TEXT("received error %d from server"), errorCode);
	updateState();
}

void LoadBalancingListener::joinRoomEventAction(int playerNr, const JVector<int>& playernrs, const Player& player)
{
	UE_LOG(LogNet, Verbose, TEXT("player %d %s has joined the game"), playerNr, *toFString(player.getName()));
}

FSingleIntDelegate* LoadBalancingListener::GetAddPlayerDelegate()
{
	return PlayerJoinedDelegate;
}

void LoadBalancingListener::leaveRoomEventAction(int playerNr, bool isInactive)
{
	if(isInactive)
	{
		UE_LOG(LogNet, Log, TEXT("player %d has suspended the game"), playerNr);
	}
	else
	{
		UE_LOG(LogNet, Log, TEXT("player %d has abandoned the game"), playerNr);
		mpView->removePlayer(playerNr);
	}
}

IncomingPacket* LoadBalancingListener::ReadPacket()
{
	IncomingPacket* packet = NULL;
	
	if (mPacketsReceived.Num() > 0)
	{
		packet = &mPacketsReceived[0];
	}

	return packet;
}

void LoadBalancingListener::RemovePacket()
{
	if (mPacketsReceived.Num() > 0)
	{
		mPacketsReceived.RemoveAt(0);
	}
}

void LoadBalancingListener::customEventAction(int playerNr, nByte eventCode, const Object& eventContentObj)
{
	ExitGames::Common::Hashtable eventContent = ExitGames::Common::ValueObject<ExitGames::Common::Hashtable>(eventContentObj).getDataCopy();
	if (eventCode == EVENTCODE_PACKET)
	{
		// NetDriver packet
		// extract sender id and data length
		// pack into struct for later use
		// 1 = senderID
		// 2 = length
		// 3 = data
		// Store data to be read later by PhotonIpNetDriver::TickDispatch()
		Object const* obj = eventContent.getValue("1");
		if(!obj) obj = eventContent.getValue((nByte)1);

		if (obj)
		{
			int64 sender = ((ValueObject<int64>*)obj)->getDataCopy();
			ovrID senderID = static_cast<ovrID>(sender);

			obj = eventContent.getValue((nByte)2);

			if (obj)
			{
				short length = ((ValueObject<short>*)obj)->getDataCopy();

				obj = eventContent.getValue((nByte)3);

				if (obj)
				{
					if(obj->getType() == TypeCode::BYTE)
					{
						nByte* data = ((ValueObject<nByte*>*)obj)->getDataCopy();
						
						IncomingPacket* packet = new IncomingPacket();
						packet->senderID = senderID;
						packet->length = length;
						packet->data = data;

						UE_LOG(LogNet, VeryVerbose, TEXT("Received Packet - sender %llu size %d"), senderID, length);

						mPacketsReceived.Add(*packet);
						return;
					}
				}
			}
		}
		
		UE_LOG(LogNet, Error, TEXT("Bad PhotonNetDriver data packet event"));
		return;
	}
	else if (eventCode == EVENTCODE_CONNECT) // Connect
	{
		connectToListenServer(playerNr, *mpLbc->getCurrentlyJoinedRoom().getPlayerForNumber(playerNr));
	}
}

void LoadBalancingListener::connectToListenServer(int playerNr, const Player& player)
{
	UE_LOG(LogNet, Verbose, TEXT("player %d %s connected to master client"), playerNr, *toFString(player.getName()));
	bool isLocalPlayer = (player.getNumber() == mpLbc->getLocalPlayer().getNumber());
	
	if (!isLocalPlayer)
	{
		mpView->playerJoined(playerNr);
	}

	mpView->addPlayer(playerNr, player.getUserID(), isLocalPlayer);
}

void LoadBalancingListener::connectReturn(int errorCode, const JString& errorString, const JString& region, const JString& cluster)
{
	updateState();
	bool success = (errorCode == ErrorCode::OK);
	if(success)
	{
		UE_LOG(LogNet, Verbose, TEXT("connected to cluster %s of region %s"), *toFString(cluster), *toFString(region));
	}
	else
	{
		UE_LOG(LogNet, Error, TEXT("Warn: connect failed %s %s"), errorCode, *toFString(errorString));
	}

	mpView->ConnectReturn(success);
}

void LoadBalancingListener::disconnectReturn(void)
{
	updateState();
	UE_LOG(LogNet, Log, TEXT("disconnected"));
	mpView->Disconnected();
}

void LoadBalancingListener::joinOrCreateRoomReturn(int localPlayerNr, const Hashtable& gameProperties, const Hashtable& playerProperties, int errorCode, const JString& errorString)
{
	bool success = (errorCode == ErrorCode::OK);
	mpView->JoinOrCreateRoomReturn(success, errorCode, errorString);

	updateState();
	if(success)
	{
		UE_LOG(LogNet, Log, TEXT("room has been entered"));
	}
	else
	{
		UE_LOG(LogNet, Error, TEXT("Warn: opJoinOrCreateRoom() failed: %s"), *toFString(errorString));
	}
}

void LoadBalancingListener::leaveRoomReturn(int errorCode, const JString& errorString)
{
	bool success = (errorCode == ErrorCode::OK);
	
	updateState();
	if(success)
	{
		UE_LOG(LogNet, Log, TEXT("game room has been successfully left"));
	}
	else
	{
		UE_LOG(LogNet, Error, TEXT("opLeaveRoom() failed: %s"), *toFString(errorString));
	}
	mpView->initPlayers();

	mpView->LeaveRoomReturn(success);
}

void LoadBalancingListener::onRoomListUpdate()
{
	const JVector<Room*>& rooms = mpLbc->getRoomList();
	JVector<JString> names(rooms.getSize());
	for(unsigned int i=0; i<rooms.getSize(); ++i)
		names.addElement(rooms[i]->getName());
	mpView->updateRoomList(names);
}

void LoadBalancingListener::updateState()
{
	int state = mpLbc->getState();
	mpView->updateState(state, PeerStatesStr[state], state == PeerStates::Joined ? mpLbc->getCurrentlyJoinedRoom().getName() : JString());
}

void LoadBalancingListener::service(void)
{
	
}

void LoadBalancingListener::onMasterClientChanged(int id, int oldId)
{
	UE_LOG(LogNet, Log, TEXT("onMasterClientChanged id=%d oldId=%d"), id, oldId);

	mpView->OnMasterClientChanged(id, oldId);
}


void LoadBalancingListener::onRoomPropertiesChange(const ExitGames::Common::Hashtable& changes)
{
	
}
