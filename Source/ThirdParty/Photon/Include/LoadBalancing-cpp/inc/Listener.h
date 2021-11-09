/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Photon-cpp/inc/OperationResponse.h"
#include "LoadBalancing-cpp/inc/LobbyStatsResponse.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class Player;
		class Room;

		class Listener: public virtual Common::BaseListener
		{
		public:
			virtual ~Listener(void){}

			// receive and print out debug out here
			virtual void debugReturn(int debugLevel, const Common::JString& string) = 0;

			// implement your error-handling here
			virtual void connectionErrorReturn(int errorCode) = 0;
			virtual void clientErrorReturn(int errorCode) = 0;
			virtual void warningReturn(int warningCode) = 0;
			virtual void serverErrorReturn(int errorCode) = 0;

			// events, triggered by certain operations of all players in the same room
			virtual void joinRoomEventAction(int playerNr, const Common::JVector<int>& playernrs, const Player& player) = 0;
			virtual void leaveRoomEventAction(int playerNr, bool isInactive) = 0;

			virtual void customEventAction(int playerNr, nByte eventCode, const Common::Object& eventContent) = 0;

			// callbacks for operations on the server
			virtual void connectReturn(int errorCode, const Common::JString& errorString, const Common::JString& region, const Common::JString& cluster) = 0;
			virtual void disconnectReturn(void) = 0;
			virtual void createRoomReturn(int /*localPlayerNr*/, const Common::Hashtable& /*roomProperties*/, const Common::Hashtable& /*playerProperties*/, int /*errorCode*/, const Common::JString& /*errorString*/) {}
			virtual void joinOrCreateRoomReturn(int /*localPlayerNr*/, const Common::Hashtable& /*roomProperties*/, const Common::Hashtable& /*playerProperties*/, int /*errorCode*/, const Common::JString& /*errorString*/) {}
			virtual void joinRandomOrCreateRoomReturn(int /*localPlayerNr*/, const Common::Hashtable& /*roomProperties*/, const Common::Hashtable& /*playerProperties*/, int /*errorCode*/, const Common::JString& /*errorString*/) {}
			virtual void joinRoomReturn(int /*localPlayerNr*/, const Common::Hashtable& /*roomProperties*/, const Common::Hashtable& /*playerProperties*/, int /*errorCode*/, const Common::JString& /*errorString*/) {}
			virtual void joinRandomRoomReturn(int /*localPlayerNr*/, const Common::Hashtable& /*roomProperties*/, const Common::Hashtable& /*playerProperties*/, int /*errorCode*/, const Common::JString& /*errorString*/) {}
			virtual void leaveRoomReturn(int errorCode, const Common::JString& errorString) = 0;
			virtual void joinLobbyReturn(void) {}
			virtual void leaveLobbyReturn(void) {}
			virtual void onFindFriendsResponse(void) {}
			virtual void onLobbyStatsResponse(const Common::JVector<LobbyStatsResponse>& /*lobbyStats*/) {}
			virtual void webRpcReturn(int /*errorCode*/, const Common::JString& /*errorString*/, const Common::JString& /*uriPath*/, int /*resultCode*/, const Common::Dictionary<Common::Object, Common::Object>& /*returnData*/) {}

			// info, that certain values have been updated
			virtual void onRoomListUpdate(void) {}
			virtual void onRoomPropertiesChange(const Common::Hashtable& /*changes*/) {}
			virtual void onPlayerPropertiesChange(int /*playerNr*/, const Common::Hashtable& /*changes*/) {}
			virtual void onAppStatsUpdate(void) {}
			virtual void onLobbyStatsUpdate(const Common::JVector<LobbyStatsResponse>& /*lobbyStats*/) {}
			virtual void onCacheSliceChanged(int /*cacheSliceIndex*/) {}
			virtual void onMasterClientChanged(int /*id*/, int /*oldID*/) {}

			// custom authentication
			virtual void onCustomAuthenticationIntermediateStep(const Common::Dictionary<Common::JString, Common::Object>& /*customResponseData*/){}

			// receive the available server regions during the connect workflow (if you have specified in the constructor, that you want to select a region)
			virtual void onAvailableRegions(const Common::JVector<Common::JString>& /*availableRegions*/, const Common::JVector<Common::JString>& /*availableRegionServers*/){}

			virtual void onSecretReceival(const Common::JString& /*secret*/){}

			virtual void onDirectConnectionEstablished(int /*remoteID*/){}
			virtual void onDirectConnectionFailedToEstablish(int /*remoteID*/) {}
			virtual void onDirectMessage(const Common::Object& /*msg*/, int /*remoteID*/, bool /*relay*/) {}

			virtual void onCustomOperationResponse(const Photon::OperationResponse& /*operationResponse*/) {}

			virtual void onGetRoomListResponse(const Common::JVector<Common::Helpers::SharedPointer<Room> >& /*roomList*/, const Common::JVector<Common::JString>& /*roomNameList*/) {}
		};
		/** @file */
	}
}