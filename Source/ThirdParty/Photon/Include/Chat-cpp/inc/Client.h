/* Exit Games Photon Chat - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Chat-cpp/inc/Channel.h"
#include "Chat-cpp/inc/Listener.h"
#include "Chat-cpp/inc/Peer.h"
#include "Chat-cpp/inc/Enums/ClientState.h"
#include "Chat-cpp/inc/Enums/DisconnectCause.h"
#include "Chat-cpp/inc/Enums/ErrorCode.h"
#include "Chat-cpp/inc/Enums/UserStatus.h"

namespace ExitGames
{
	namespace Chat
	{
		class Client : protected Photon::PhotonListener
		{
		public:
			Client(Listener& listener, const Common::JString& applicationID, const Common::JString& appVersion, nByte connectionProtocol=Photon::ConnectionProtocol::DEFAULT);
			virtual ~Client(void);

			virtual bool connect(const AuthenticationValues& authenticationValues=AuthenticationValues(), const Common::JString& nameServerAddress=M_NAMESERVER);
			virtual void disconnect(void);

			virtual void service(bool dispatchIncomingCommands=true);
			virtual void serviceBasic(void);
			virtual bool sendOutgoingCommands(void);
			virtual bool sendAcksOnly(void);
			virtual bool dispatchIncomingCommands(void);
			virtual void fetchServerTimestamp(void);
			virtual void resetTrafficStats(void);
			virtual void resetTrafficStatsMaximumCounters(void);
			virtual Common::JString vitalStatsToString(bool all) const;

			virtual bool opSubscribe(const Common::JVector<Common::JString>& channels, int messagesFromHistory=0);
			virtual bool opUnsubscribe(const Common::JVector<Common::JString>& channels);
			template<typename Ftype> bool opPublishMessage(const Common::JString& channelName, const Ftype& message);
			template<typename Ftype> bool opPublishMessage(const Common::JString& channelName, const Ftype pMessageArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize);
			template<typename Ftype> bool opPublishMessage(const Common::JString& channelName, const Ftype pMessageArray, const short* pArrSizes);
			template<typename Ftype> bool opSendPrivateMessage(const Common::JString& userName, const Ftype& message, bool encrypt=false);
			template<typename Ftype> bool opSendPrivateMessage(const Common::JString& userName, const Ftype pMessageArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize, bool encrypt=false);
			template<typename Ftype> bool opSendPrivateMessage(const Common::JString& userName, const Ftype pMessageArray, const short* pArrSizes, bool encrypt=false);
			virtual bool opSetOnlineStatus(int status);
			template<typename Ftype> bool opSetOnlineStatus(int status, const Ftype& message);
			template<typename Ftype> bool opSetOnlineStatus(int status, const Ftype pMessageArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize);
			template<typename Ftype> bool opSetOnlineStatus(int status, const Ftype pMessageArray, const short* pArrSizes);
			virtual bool opAddFriends(const Common::JVector<Common::JString>& userIDs);
			virtual bool opRemoveFriends(const Common::JVector<Common::JString>& userIDs);

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

			const Common::JString& getUserID(void) const;
			int getState(void) const;
			int getDisconnectedCause(void) const;
			const Common::JString& getRegion(void) const;
			void setRegion(const Common::JString& region);
			const Common::JVector<Channel*>& getPublicChannels(void) const;
			const Common::JVector<Channel*>& getPrivateChannels(void) const;
			const Channel* getPublicChannel(const Common::JString& channelName) const;
			const Channel* getPrivateChannel(const Common::JString& userName) const;
		protected:
			// From Photon::PhotonListener
			virtual void onOperationResponse(const Photon::OperationResponse& operationResponse);
			virtual void onStatusChanged(int statusCode);
			virtual void onEvent(const Photon::EventData& eventData);
			virtual void onMessage(const Common::Object& message);
			virtual void onRawMessage(nByte* inBuff, int inBuffBodyLength);
			virtual void debugReturn(int debugLevel, const Common::JString& string);
		private:
			virtual bool opPublishMessage(const Common::JString& channelName, const Common::Object& message);
			virtual bool opSendPrivateMessage(const Common::JString& userName, const Common::Object& message, bool encrypt);
			virtual bool opSetOnlineStatus(int status, const Common::Object& message, bool skipMessage);

			void handleConnectionFlowError(int oldState, int errorCode, const Common::JString& errorString);
			void handleAuthResponse(const Photon::OperationResponse& operationResponse);
			void handleSubscribeResponse(const Photon::EventData& operationResponse);
			void handleUnsubscribeResponse(const Photon::EventData& operationResponse);

			Channel* getChannel(Common::JVector<Channel*>& channels, const Common::JString& name);
			Channel* getOrAddChannel(Common::JVector<Channel*>& channels, const Common::JString& name, int id, bool isPrivate);
			void removeChannel(Common::JVector<Channel*>& channels, const Common::JString& name);

			Peer mPeer;
			Listener& mListener;
			Common::Logger mLogger;
			Common::JString mAppVersion;
			Common::JString mAppID;
			Common::JString mAppIDPeerInit; // appID adapted to the size suported by PhotonPeer
			Common::JString mFrontEndAddress;
			int mState;
			AuthenticationValues mAuthenticationValues;
			int mDisconnectedCause;
			bool mDidAuthenticate;
			Common::JString mRegion;

			Common::JVector<Channel*> mPublicChannels;
			Common::JVector<Channel*> mPrivateChannels;

			const nByte M_CONNECTION_PROTOCOL;

			static const Common::JString M_NAMESERVER;
		};



		template<typename Ftype>
		bool Client::opPublishMessage(const Common::JString& channelName, const Ftype& message)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Common::Helpers::ConfirmAllowed<Ftype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			return opPublishMessage(channelName, Common::Helpers::ValueToObject<Common::Object>::get(message));
		}

		template<typename Ftype>
		bool Client::opPublishMessage(const Common::JString& channelName, const Ftype pMessageArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(Common::Helpers::ConfirmAllowed<Ftype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			return opPublishMessage(channelName, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, arrSize));
		}

		template<typename Ftype>
		bool Client::opPublishMessage(const Common::JString& channelName, const Ftype pMessageArray, const short* pArrSizes)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG((Common::Helpers::ConfirmAllowed<Ftype>::dimensions>1), ERROR_THIS_OVERLOAD_IS_ONLY_FOR_MULTIDIMENSIONAL_ARRAYS);
			return opPublishMessage(channelName, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, pArrSizes));
		}

		template<typename Ftype>
		bool Client::opSendPrivateMessage(const Common::JString& userName, const Ftype& message, bool encrypt)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Common::Helpers::ConfirmAllowed<Ftype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			return opSendPrivateMessage(userName, Common::Helpers::ValueToObject<Common::Object>::get(message), encrypt);
		}

		template<typename Ftype>
		bool Client::opSendPrivateMessage(const Common::JString& userName, const Ftype pMessageArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize, bool encrypt)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(Common::Helpers::ConfirmAllowed<Ftype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			return opSendPrivateMessage(userName, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, arrSize), encrypt);
		}

		template<typename Ftype>
		bool Client::opSendPrivateMessage(const Common::JString& userName, const Ftype pMessageArray, const short* pArrSizes, bool encrypt)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG((Common::Helpers::ConfirmAllowed<Ftype>::dimensions>1), ERROR_THIS_OVERLOAD_IS_ONLY_FOR_MULTIDIMENSIONAL_ARRAYS);
			return opSendPrivateMessage(userName, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, pArrSizes), encrypt);
		}

		template<typename Ftype>
		bool Client::opSetOnlineStatus(int status, const Ftype& message)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Common::Helpers::ConfirmAllowed<Ftype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			return opSetOnlineStatus(status, Common::Helpers::ValueToObject<Common::Object>::get(message), false);
		}

		template<typename Ftype>
		bool Client::opSetOnlineStatus(int status, const Ftype pMessageArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(Common::Helpers::ConfirmAllowed<Ftype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			return opSetOnlineStatus(status, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, arrSize), false);
		}

		template<typename Ftype>
		bool Client::opSetOnlineStatus(int status, const Ftype pMessageArray, const short* pArrSizes)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG((Common::Helpers::ConfirmAllowed<Ftype>::dimensions>1), ERROR_THIS_OVERLOAD_IS_ONLY_FOR_MULTIDIMENSIONAL_ARRAYS);
			return opSetOnlineStatus(status, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, pArrSizes), false);
		}
	}
}