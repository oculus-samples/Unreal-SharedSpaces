/* Exit Games Photon Chat - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Photon-cpp/inc/PhotonPeer.h"
#include "Chat-cpp/inc/AuthenticationValues.h"

namespace ExitGames
{
	namespace Chat
	{
		class Peer : public Photon::PhotonPeer
		{
		public:
			Peer(Photon::PhotonListener& listener, nByte connectionProtocol=Photon::ConnectionProtocol::DEFAULT);
			virtual ~Peer(void);

			virtual bool opAuthenticateOnNameServer(const Common::JString& appID, const Common::JString& appVersion, const Common::JString& region, const AuthenticationValues& authenticationValues=AuthenticationValues());
			virtual bool opAuthenticateOnFrontEnd(const Common::JString& secret);

			virtual bool opSubscribe(const Common::JVector<Common::JString>& channels, int messagesFromHistory);
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
		private:
			virtual bool opPublishMessage(const Common::JString& channelName, const Common::Object& message);
			virtual bool opSendPrivateMessage(const Common::JString& userName, const Common::Object& message, bool encrypt);
			virtual bool opSetOnlineStatus(int status, const Common::Object& message, bool skipMessage);
			bool sendChannelOperation(const Common::JVector<Common::JString>& channels, nByte operation, int messagesFromHistory=0);

			typedef PhotonPeer super;

			friend class Client;
		};



		template<typename Ftype>
		bool Peer::opPublishMessage(const Common::JString& channelName, const Ftype& message)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Common::Helpers::ConfirmAllowed<Ftype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			return opPublishMessage(channelName, Common::Helpers::ValueToObject<Common::Object>::get(message));
		}

		template<typename Ftype>
		bool Peer::opPublishMessage(const Common::JString& channelName, const Ftype pMessageArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(Common::Helpers::ConfirmAllowed<Ftype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			return opPublishMessage(channelName, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, arrSize));
		}

		template<typename Ftype>
		bool Peer::opPublishMessage(const Common::JString& channelName, const Ftype pMessageArray, const short* pArrSizes)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG((Common::Helpers::ConfirmAllowed<Ftype>::dimensions>1), ERROR_THIS_OVERLOAD_IS_ONLY_FOR_MULTIDIMENSIONAL_ARRAYS);
			return opPublishMessage(channelName, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, pArrSizes));
		}

		template<typename Ftype>
		bool Peer::opSendPrivateMessage(const Common::JString& userName, const Ftype& message, bool encrypt)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Common::Helpers::ConfirmAllowed<Ftype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			return opSendPrivateMessage(userName, Common::Helpers::ValueToObject<Common::Object>::get(message), encrypt);
		}

		template<typename Ftype>
		bool Peer::opSendPrivateMessage(const Common::JString& userName, const Ftype pMessageArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize, bool encrypt)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(Common::Helpers::ConfirmAllowed<Ftype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			return opSendPrivateMessage(userName, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, arrSize), encrypt);
		}

		template<typename Ftype>
		bool Peer::opSendPrivateMessage(const Common::JString& userName, const Ftype pMessageArray, const short* pArrSizes, bool encrypt)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG((Common::Helpers::ConfirmAllowed<Ftype>::dimensions>1), ERROR_THIS_OVERLOAD_IS_ONLY_FOR_MULTIDIMENSIONAL_ARRAYS);
			return opSendPrivateMessage(userName, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, pArrSizes), encrypt);
		}

		template<typename Ftype>
		bool Peer::opSetOnlineStatus(int status, const Ftype& message)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Common::Helpers::ConfirmAllowed<Ftype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			return opSetOnlineStatus(status, Common::Helpers::ValueToObject<Common::Object>::get(message), false);
		}

		template<typename Ftype>
		bool Peer::opSetOnlineStatus(int status, const Ftype pMessageArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(Common::Helpers::ConfirmAllowed<Ftype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			return opSetOnlineStatus(status, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, arrSize), false);
		}

		template<typename Ftype>
		bool Peer::opSetOnlineStatus(int status, const Ftype pMessageArray, const short* pArrSizes)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG((Common::Helpers::ConfirmAllowed<Ftype>::dimensions>1), ERROR_THIS_OVERLOAD_IS_ONLY_FOR_MULTIDIMENSIONAL_ARRAYS);
			return opSetOnlineStatus(status, Common::Helpers::ValueToObject<Common::Object>::get(pMessageArray, pArrSizes), false);
		}
	}
}