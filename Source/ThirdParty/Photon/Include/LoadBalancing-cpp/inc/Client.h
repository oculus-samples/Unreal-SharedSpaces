/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "LoadBalancing-cpp/inc/ConnectOptions.h"
#include "LoadBalancing-cpp/inc/Enums/DisconnectCause.h"
#include "LoadBalancing-cpp/inc/Enums/ErrorCode.h"
#include "LoadBalancing-cpp/inc/Enums/PeerStates.h"
#include "LoadBalancing-cpp/inc/Enums/RegionSelectionMode.h"
#include "LoadBalancing-cpp/inc/Enums/ServerType.h"
#include "LoadBalancing-cpp/inc/FriendInfo.h"
#include "LoadBalancing-cpp/inc/Listener.h"
#include "LoadBalancing-cpp/inc/MutablePlayer.h"
#include "LoadBalancing-cpp/inc/MutableRoom.h"
#include "LoadBalancing-cpp/inc/SendDirectOptions.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		namespace Internal
		{
			class PuncherClient;
		}

		class Client : protected Photon::PhotonListener
		{
		public:
			Client(LoadBalancing::Listener& listener, const Common::JString& applicationID, const Common::JString& appVersion, nByte connectionProtocol=Photon::ConnectionProtocol::DEFAULT, bool autoLobbyStats=false, nByte regionSelectionMode=RegionSelectionMode::DEFAULT, bool useAlternativePorts=false);
			virtual ~Client(void);

			virtual bool connect(const ConnectOptions& connectOptions=ConnectOptions());
			virtual void disconnect(void);

			virtual void service(bool dispatchIncomingCommands=true);
			virtual void serviceBasic(void);
			virtual bool opCustom(const Photon::OperationRequest& operationRequest, bool sendReliable, nByte channelID=0, bool encrypt=false);
			virtual bool sendOutgoingCommands(void);
			virtual bool sendAcksOnly(void);
			virtual bool dispatchIncomingCommands(void);
			virtual void fetchServerTimestamp(void);
			virtual void resetTrafficStats(void);
			virtual void resetTrafficStatsMaximumCounters(void);
			virtual Common::JString vitalStatsToString(bool all) const;

			virtual bool opJoinLobby(const Common::JString& lobbyName=Common::JString(), nByte lobbyType=LobbyType::DEFAULT);
			virtual bool opLeaveLobby(void);
			virtual bool opCreateRoom(const Common::JString& gameID=Common::JString(), const RoomOptions& options=RoomOptions(), const Common::JVector<Common::JString>& expectedUsers=Common::JVector<Common::JString>());
			virtual bool opJoinOrCreateRoom(const Common::JString& gameID, const RoomOptions& options=RoomOptions(), int cacheSliceIndex=0, const Common::JVector<Common::JString>& expectedUsers=Common::JVector<Common::JString>());
			virtual bool opJoinRandomOrCreateRoom(const Common::JString& gameID=Common::JString(), const RoomOptions& options=RoomOptions(), const Common::Hashtable& customRoomProperties=Common::Hashtable(), nByte maxPlayers=0, nByte matchmakingMode=MatchmakingMode::FILL_ROOM, const Common::JString& lobbyName=Common::JString(), nByte lobbyType=LobbyType::DEFAULT, const Common::JString& sqlLobbyFilter=Common::JString(), const Common::JVector<Common::JString>& expectedUsers=Common::JVector<Common::JString>());
			virtual bool opJoinRoom(const Common::JString& gameID, bool rejoin=false, int cacheSliceIndex=0, const Common::JVector<Common::JString>& expectedUsers=Common::JVector<Common::JString>());
			virtual bool opJoinRandomRoom(const Common::Hashtable& customRoomProperties=Common::Hashtable(), nByte maxPlayers=0, nByte matchmakingMode=MatchmakingMode::FILL_ROOM, const Common::JString& lobbyName=Common::JString(), nByte lobbyType=LobbyType::DEFAULT, const Common::JString& sqlLobbyFilter=Common::JString(), const Common::JVector<Common::JString>& expectedUsers=Common::JVector<Common::JString>());
			virtual bool opLeaveRoom(bool willComeBack=false, bool sendAuthCookie=false);
			template<typename Ftype> bool opRaiseEvent(bool reliable, const Ftype& parameters, nByte eventCode, const RaiseEventOptions& options=RaiseEventOptions());
			template<typename Ftype> bool opRaiseEvent(bool reliable, const Ftype pParameterArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize, nByte eventCode, const RaiseEventOptions& options=RaiseEventOptions());
			template<typename Ftype> bool opRaiseEvent(bool reliable, const Ftype pParameterArray, const short* pArrSizes, nByte eventCode, const RaiseEventOptions& options=RaiseEventOptions());
			virtual bool opFindFriends(const Common::JString* friendsToFind, short numFriendsToFind);
			virtual bool opLobbyStats(const Common::JVector<LoadBalancing::LobbyStatsRequest>& lobbiesToQuery=Common::JVector<LoadBalancing::LobbyStatsRequest>());
			virtual bool opChangeGroups(const Common::JVector<nByte>* pGroupsToRemove, const Common::JVector<nByte>* pGroupsToAdd);
			virtual bool opCustomAuthenticationSendNextStepData(const AuthenticationValues& authenticationValues);
			virtual bool opWebRpc(const Common::JString& uriPath);
			template<typename Ftype> bool opWebRpc(const Common::JString& uriPath, const Ftype& parameters, bool sendAuthCookie=false);
			template<typename Ftype> bool opWebRpc(const Common::JString& uriPath, const Ftype pParameterArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize, bool sendAuthCookie=false);
			template<typename Ftype> bool opWebRpc(const Common::JString& uriPath, const Ftype pParameterArray, const short* pArrSizes, bool sendAuthCookie=false);
			virtual bool opGetRoomList(const Common::JString& lobby, const Common::JString& sqlLobbyFilter);

			virtual bool selectRegion(const Common::JString& selectedRegion);
			virtual bool reconnectAndRejoin(void);
			template<typename Ftype> int sendDirect(const Ftype& parameters, const SendDirectOptions& options=SendDirectOptions());
			template<typename Ftype> int sendDirect(const Ftype pParameterArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize, const SendDirectOptions& options=SendDirectOptions());
			template<typename Ftype> int sendDirect(const Ftype pParameterArray, const short* pArrSizes, const SendDirectOptions& options=SendDirectOptions());

			int getServerTimeOffset(void) const;
			int getServerTime(void) const;
			int getBytesOut(void) const;
			int getBytesIn(void) const;
			int getByteCountCurrentDispatch(void) const;
			int getByteCountLastOperation(void) const;
			int getSentCountAllowance(void) const;
			void setSentCountAllowance(int sentCountAllowance);
			int getTimePingInterval(void) const;
			void setTimePingInterval(int timePingInterval);
			int getRoundTripTime(void) const;
			int getRoundTripTimeVariance(void) const;
			int getTimestampOfLastSocketReceive(void) const;
			int getDebugOutputLevel(void) const;
			bool setDebugOutputLevel(int debugLevel);
			const Common::LogFormatOptions& getLogFormatOptions(void) const;
			void setLogFormatOptions(const Common::LogFormatOptions& formatOptions);
			int getIncomingReliableCommandsCount(void) const;
			short getPeerID(void) const;
			int getDisconnectTimeout(void) const;
			void setDisconnectTimeout(int disconnectTimeout);
			int getQueuedIncomingCommands(void) const;
			int getQueuedOutgoingCommands(void) const;
			bool getIsPayloadEncryptionAvailable(void) const;
			bool getIsEncryptionAvailable(void) const;
			int getResentReliableCommands(void) const;
			int getLimitOfUnreliableCommands(void) const;
			void setLimitOfUnreliableCommands(int value);
			bool getCRCEnabled(void) const;
			void setCRCEnabled(bool crcEnabled);
			int getPacketLossByCRC(void) const;
			bool getTrafficStatsEnabled(void) const;
			void setTrafficStatsEnabled(bool trafficStatsEnabled);
			int getTrafficStatsElapsedMs(void) const;
			const Photon::TrafficStats& getTrafficStatsIncoming(void) const;
			const Photon::TrafficStats& getTrafficStatsOutgoing(void) const;
			const Photon::TrafficStatsGameLevel& getTrafficStatsGameLevel(void) const;
			nByte getQuickResendAttempts(void) const;
			void setQuickResendAttempts(nByte quickResendAttempts);
			nByte getChannelCountUserChannels(void) const;

			static short getPeerCount(void);

			int getState(void) const;
			const Common::JString& getMasterserverAddress(void) const;
			int getCountPlayersIngame(void) const;
			int getCountGamesRunning(void) const;
			int getCountPlayersOnline(void) const;
			MutableRoom& getCurrentlyJoinedRoom(void);
			const Common::JVector<Room*>& getRoomList(void) const;
			const Common::JVector<Common::JString>& getRoomNameList(void) const;
			bool getIsInRoom(void) const;
			bool getIsInGameRoom(void) const;
			bool getIsInLobby(void) const;
			bool getAutoJoinLobby(void) const;
			void setAutoJoinLobby(bool autoJoinLobby);
			MutablePlayer& getLocalPlayer(void);
			const Common::JVector<FriendInfo>& getFriendList(void) const;
			int getFriendListAge(void) const;
			int getDisconnectedCause(void) const;
			const Common::JString& getUserID(void) const;
#if defined EG_PLATFORM_SUPPORTS_CPP11 && defined EG_PLATFORM_SUPPORTS_MULTITHREADING
			const Common::JString& getRegionWithBestPing(void) const;
#endif
		protected:
			virtual bool opSetPropertiesOfPlayer(int playerNr, const Common::Hashtable& properties, const Common::Hashtable& expectedProperties=Common::Hashtable(), WebFlags webFlags=WebFlags());
			virtual bool opSetPropertiesOfRoom(const Common::Hashtable& properties, const Common::Hashtable& expectedProperties=Common::Hashtable(), WebFlags webFlags=WebFlags());

			virtual Room* createRoom(const Common::JString& name, const Common::Hashtable& properties);
			virtual void destroyRoom(const Room* pRoom) const;
			virtual Internal::MutablePlayerFactory* getMutablePlayerFactory(void) const;
			virtual Internal::MutableRoomFactory* getMutableRoomFactory(void) const;

			// From Photon::PhotonListener
			virtual void onOperationResponse(const Photon::OperationResponse& operationResponse);
			virtual void onStatusChanged(int statusCode);
			virtual void onEvent(const Photon::EventData& eventData);
			virtual void onPingResponse(const Common::JString& address, unsigned int result);
			virtual void debugReturn(int debugLevel, const Common::JString& string);
		private:
			void readoutProperties(Common::Hashtable& roomProperties, Common::Hashtable& playerProperties, bool multiplePlayers, int targetPlayerNr);
			void handleConnectionFlowError(int oldState, int errorCode, const Common::JString& errorString);
			void onConnectToMasterFinished(bool comingFromGameserver);
			void onArrivalAndAuthentication(void);
			MutablePlayer* createMutablePlayer(int number, const Common::Hashtable& properties);
			void destroyMutablePlayer(const MutablePlayer* pPlayer) const;
			MutableRoom* createMutableRoom(const Common::JString& name, const Common::Hashtable& properties, const Common::JVector<Common::JString>& propsListedInLobby, int playerTtl, int emptyRoomTtl, bool suppressRoomEvents, const Common::JVector<Common::JString>* pPlugins, bool publishUserID, const Common::JVector<Common::JString>& expectedUsers);
			void destroyMutableRoom(const MutableRoom* pRoom) const;
#if defined EG_PLATFORM_SUPPORTS_CPP11 && defined EG_PLATFORM_SUPPORTS_MULTITHREADING
			virtual void pingBestRegion(unsigned int pingsPerRegion);
#endif
			bool callPeerConnect(const Common::JString& address);
			bool authenticate(void);
			Common::JString addPortToAddress(const Common::JString& address, nByte serverType);
			unsigned short getDefaultPort(nByte serverType, bool useAlternativePorts);
			int sendDirect(const Common::JVector<nByte>& buffer, const SendDirectOptions& options);
			bool initPuncher(void);
			bool startPunch(int playerNr);	
			void onMasterClientChanged(int id, int oldID);
			bool opRaiseEvent(bool reliable, const Common::Object& parameters, nByte eventCode, const RaiseEventOptions& options);

			bool getIsOnGameServer(void) const;

			Listener& mListener;
			Peer* mpPeer;
			Common::Logger mLogger;
			Common::JString mGameserver;
			Common::JString mAppVersion;
			Common::JString mRoomName;
			Common::JString mAppID;
			Common::JString mAppIDPeerInit; // appID adapted to the size supported by PhotonPeer
			int mPeerCount;
			int mRoomCount;
			int mMasterPeerCount;
			nByte mLastJoinType;
			nByte mLastLobbyJoinType;
			bool mLastJoinWasRejoin;
			int mLastCacheSliceIndex;
			MutableRoom* mpCurrentlyJoinedRoom;
			Common::JVector<Room*> mRoomList;
			Common::JVector<Common::JString> mRoomNameList;
			int mCachedErrorCodeFromGameServer;
			Common::JString mCachedErrorStringFromGameServer;
			bool mAutoJoinLobby;
			MutablePlayer* mpLocalPlayer;
			Common::JVector<FriendInfo> mFriendList;
			Common::JVector<Common::JString> mLastFindFriendsRequest;
			int mFriendListTimestamp;
			bool mIsFetchingFriendList;
			Common::JVector<LobbyStatsRequest> mLobbyStatsRequestList;
			int mState;
			AuthenticationValues mAuthenticationValues;
			bool mAutoLobbyStats;
			Internal::MutablePlayerFactory* mpMutablePlayerFactory;
			Internal::MutableRoomFactory* mpMutableRoomFactory;
			int mDisconnectedCause;
			Common::JVector<Common::JString> mAvailableRegions;
			Common::JVector<Common::JString> mAvailableRegionServers;
			Common::JString mSelectedRegion;
			const nByte M_REGION_SELECTION_MODE;
			Common::JString mMasterserver;
			const nByte M_CONNECTION_PROTOCOL;
			unsigned int mPingsPerRegion;
			Common::JVector<Common::JVector<unsigned int> > mPingResponses;
			Common::JString mRegionWithBestPing;
			bool mUseAuthOnce;
			bool mUseUDPEncryption;
			Common::JString mCluster;
			bool mUseAlternativePorts;
			Internal::PuncherClient* mpPuncherClient;

			static const unsigned int M_PINGS_PER_REGION = 5;

			friend class MutablePlayer;
			friend class MutableRoom;
		};



		template<typename Ftype>
		bool Client::opRaiseEvent(bool reliable, const Ftype& parameters, nByte eventCode, const RaiseEventOptions& options)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Common::Helpers::ConfirmAllowed<Ftype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			return opRaiseEvent(reliable, Common::Helpers::ValueToObject<Common::Object>::get(parameters), eventCode, options);
		}

		template<typename Ftype>
		bool Client::opRaiseEvent(bool reliable, const Ftype pParameterArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize, nByte eventCode, const RaiseEventOptions& options)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(Common::Helpers::ConfirmAllowed<Ftype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			return opRaiseEvent(reliable, Common::Helpers::ValueToObject<Common::Object>::get(pParameterArray, arrSize), eventCode, options);
		}

		template<typename Ftype>
		bool Client::opRaiseEvent(bool reliable, const Ftype pParameterArray, const short* pArrSizes, nByte eventCode, const RaiseEventOptions& options)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG((Common::Helpers::ConfirmAllowed<Ftype>::dimensions>1), ERROR_THIS_OVERLOAD_IS_ONLY_FOR_MULTIDIMENSIONAL_ARRAYS);
			return opRaiseEvent(reliable, Common::Helpers::ValueToObject<Common::Object>::get(pParameterArray, pArrSizes), eventCode, options);
		}

		template<typename Ftype>
		bool Client::opWebRpc(const Common::JString& uriPath, const Ftype& parameters, bool sendAuthCookie)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Common::Helpers::ConfirmAllowed<Ftype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			return mpPeer->opWebRpc(uriPath, parameters, sendAuthCookie);
		}

		template<typename Ftype>
		bool Client::opWebRpc(const Common::JString& uriPath, const Ftype pParameterArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize, bool sendAuthCookie)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(Common::Helpers::ConfirmAllowed<Ftype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			return mpPeer->opWebRpc(uriPath, pParameterArray, arrSize, sendAuthCookie);
		}

		template<typename Ftype>
		bool Client::opWebRpc(const Common::JString& uriPath, const Ftype pParameterArray, const short* pArrSizes, bool sendAuthCookie)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG((Common::Helpers::ConfirmAllowed<Ftype>::dimensions>1), ERROR_THIS_OVERLOAD_IS_ONLY_FOR_MULTIDIMENSIONAL_ARRAYS);
			return mpPeer->opWebRpc(uriPath, pParameterArray, pArrSizes, sendAuthCookie);
		}

		template<typename Ftype>
		int Client::sendDirect(const Ftype& parameters, const SendDirectOptions& options)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Common::Helpers::ConfirmAllowed<Ftype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			Common::Serializer s;
			s.push(parameters);
			return sendDirect(Common::JVector<nByte>(s.getData(), s.getSize()), options);
		}

		template<typename Ftype>
		int Client::sendDirect(const Ftype pParameterArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize, const SendDirectOptions& options)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(Common::Helpers::ConfirmAllowed<Ftype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			Common::Serializer s;
			s.push(pParameterArray, arrSize);
			return sendDirect(Common::JVector<nByte>(s.getData(), s.getSize()), options);
		}

		template<typename Ftype>
		int Client::sendDirect(const Ftype pParameterArray, const short* pArrSizes, const SendDirectOptions& options)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG((Common::Helpers::ConfirmAllowed<Ftype>::dimensions>1), ERROR_THIS_OVERLOAD_IS_ONLY_FOR_MULTIDIMENSIONAL_ARRAYS);
			Common::Serializer s;
			s.push(pParameterArray, pArrSizes);
			return sendDirect(Common::JVector<nByte>(s.getData(), s.getSize()), options);
		}
	}
}