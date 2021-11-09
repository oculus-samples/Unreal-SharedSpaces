// Copyright (c) Facebook, Inc. and its affiliates.

#pragma once

#include "Common-cpp/inc/Common.h"
#include "OculusPlatform/Private/IPAddressOculus.h"

class BaseView
{
public:
	virtual ~BaseView(void) {}
	virtual void updateState(int state, const ExitGames::Common::JString& stateStr, const ExitGames::Common::JString& joinedRoomName) = 0;
	virtual void initPlayers(void) {}
	virtual void addPlayer(int playerNr, const ExitGames::Common::JString& playerId, bool local) = 0;
	virtual void removePlayer(int playerNr) = 0;
	virtual void updateRoomList(const ExitGames::Common::JVector<ExitGames::Common::JString>& roomNames) = 0;
	virtual void playerJoined(int playerNr) = 0;
	virtual void SetPlayerNum(int playerNr, const ExitGames::Common::JString& playerId) = 0;
	virtual  int GetLocalID(void) { return 0; }
	virtual void JoinOrCreateRoomReturn(bool bSuccessful, int errorCode, const ExitGames::Common::JString& errorString) = 0;
	virtual void LeaveRoomReturn(bool bSuccessful) = 0;
	virtual void OnMasterClientChanged(int id, int oldId) = 0;
	virtual void ConnectReturn(bool bSuccessful) = 0;
	virtual void Disconnected() = 0;
};