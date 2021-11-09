/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "LoadBalancing-cpp/inc/Enums/DirectMode.h"
#include "LoadBalancing-cpp/inc/Enums/LobbyType.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		class RoomOptions : public Common::ToString
		{
		public:
			using ToString::toString;

			RoomOptions(bool isVisible=true, bool isOpen=true, nByte maxPlayers=0, const Common::Hashtable& customRoomProperties=Common::Hashtable(), const Common::JVector<Common::JString>& propsListedInLobby=Common::JVector<Common::JString>(), const Common::JString& lobbyName=Common::JString(), nByte lobbyType=LobbyType::DEFAULT, int playerTtl=0, int emptyRoomTtl=0, bool suppressRoomEvents=false, const Common::JVector<Common::JString>* pPlugins=NULL, bool publishUserID=false, nByte directMode=DirectMode::NONE);
			~RoomOptions(void);

			RoomOptions(const RoomOptions& toCopy);
			RoomOptions& operator=(const RoomOptions& toCopy);

			bool getIsVisible(void) const;
			RoomOptions& setIsVisible(bool isVisible);
			bool getIsOpen(void) const;
			RoomOptions& setIsOpen(bool isOpen);
			nByte getMaxPlayers(void) const;
			RoomOptions& setMaxPlayers(nByte maxPlayers);
			const Common::Hashtable& getCustomRoomProperties(void) const;
			RoomOptions& setCustomRoomProperties(const Common::Hashtable& customRoomProperties);
			const Common::JVector<Common::JString>& getPropsListedInLobby(void) const;
			RoomOptions& setPropsListedInLobby(const Common::JVector<Common::JString>& propsListedInLobby);
			const Common::JString& getLobbyName(void) const;
			RoomOptions& setLobbyName(const Common::JString& lobbyName);
			nByte getLobbyType(void) const;
			RoomOptions& setLobbyType(nByte lobbyType);
			int getPlayerTtl(void) const;
			RoomOptions& setPlayerTtl(int playerTtl);
			int getEmptyRoomTtl(void) const;
			RoomOptions& setEmptyRoomTtl(int emptyRoomTtl);
			bool getSuppressRoomEvents(void) const;
			RoomOptions& setSuppressRoomEvents(bool suppressRoomEvents);
			const Common::JVector<Common::JString>* getPlugins(void) const;
			RoomOptions& setPlugins(const Common::JVector<Common::JString>* pPlugins);
			bool getPublishUserID(void) const;
			RoomOptions& setPublishUserID(bool publishUserID);
			nByte getDirectMode(void) const;
			RoomOptions& setDirectMode(nByte directMode);

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			bool mIsVisible;
			bool mIsOpen;
			nByte mMaxPlayers;
			Common::Hashtable mCustomRoomProperties;
			Common::JVector<Common::JString> mPropsListedInLobby;
			Common::JString mLobbyName;
			nByte mLobbyType;
			int mPlayerTtl;
			int mEmptyRoomTtl;
			bool mSuppressRoomEvents;
			Common::Helpers::UniquePointer<Common::JVector<Common::JString> > mupPlugins;
			bool mPublishUserID;
			nByte mDirectMode;
		};
	}
}