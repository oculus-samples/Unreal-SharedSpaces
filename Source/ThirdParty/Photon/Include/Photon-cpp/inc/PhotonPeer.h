/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Photon-cpp/inc/PhotonListener.h"
#include "Photon-cpp/inc/OperationRequest.h"
#include "Photon-cpp/inc/TrafficStats.h"
#include "Photon-cpp/inc/TrafficStatsGameLevel.h"
#include "Photon-cpp/inc/Version.h"
#include "Photon-cpp/inc/Enums/ConnectionProtocol.h"
#include "Photon-cpp/inc/Enums/ErrorCode.h"
#include "Photon-cpp/inc/Enums/NetworkPort.h"
#include "Photon-cpp/inc/Enums/PeerState.h"
#include "Photon-cpp/inc/Enums/StatusCode.h"

#if (defined _EG_MICROSOFT_PLATFORM && !(defined _EG_WINDOWSSTORE_PLATFORM && _MSC_VER < 1900)) || (defined _EG_APPLE_PLATFORM && !defined _EG_TVOS_PLATFORM && !defined _EG_IPHONE_MACCATALYST_PLATFORM) || defined _EG_ANDROID_PLATFORM || defined EG_DOC
#	define _EG_ENCRYPTOR_AVAILABLE
#	if defined _EG_ANDROID_PLATFORM || defined _EG_APPLE_PLATFORM // || defined _EG_WINDOWS_PLATFORM 
#		define _EG_ENCRYPTOR_OPENSSL
#	endif
#endif
#define EG_CHAINING_MODE_CBC_GCM(CBC, GCM) GCM

class EGObjCPhotonPeer;

namespace ExitGames
{
	namespace Photon
	{
		namespace Internal
		{
			class EnetPeer;
			class TPeer;
			class PeerData;
		}

		class PhotonPeer
		{
		private:
			static const unsigned int MAX_APP_ID_LENGTH = 32;
		public:
			PhotonPeer(PhotonListener& listener, nByte connectionProtocol=ConnectionProtocol::DEFAULT);
			virtual ~PhotonPeer(void);

			virtual bool connect(const Common::JString& ipAddr, const Common::JString& appID=Common::JString());
			template<typename Ftype> bool connect(const Common::JString& ipAddr, const Common::JString& appID, const Ftype& customData);
			template<typename Ftype> bool connect(const Common::JString& ipAddr, const Common::JString& appID, const Ftype pCustomDataArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize);
			template<typename Ftype> bool connect(const Common::JString& ipAddr, const Common::JString& appID, const Ftype pCustomDataArray, const short* pArrSizes);
			virtual void disconnect(void);
			virtual void service(bool dispatchIncomingCommands=true);
			virtual void serviceBasic(void);
			virtual bool opCustom(const OperationRequest& operationRequest, bool sendReliable, nByte channelID=0, bool encrypt=false);
			virtual bool sendOutgoingCommands(void);
			virtual bool sendAcksOnly(void);
			virtual bool dispatchIncomingCommands(void);
			virtual bool establishEncryption(void);
			virtual void fetchServerTimestamp(void);
			virtual void resetTrafficStats(void);
			virtual void resetTrafficStatsMaximumCounters(void);
			virtual Common::JString vitalStatsToString(bool all) const;
#if defined EG_PLATFORM_SUPPORTS_CPP11 && defined EG_PLATFORM_SUPPORTS_MULTITHREADING
			virtual void pingServer(const Common::JString& address, unsigned int pingAttempts);
#endif
			virtual void initUserDataEncryption(const Common::JVector<nByte>& secret);
#if defined _EG_ENCRYPTOR_AVAILABLE
			virtual void initUDPEncryption(const Common::JVector<nByte>& encryptSecret, const Common::JVector<nByte>& HMACSecret=Common::JVector<nByte>());
#endif

			PhotonListener* getListener(void);
			int getServerTimeOffset(void) const;
			int getServerTime(void) const;
			int getBytesOut(void) const;
			int getBytesIn(void) const;
			int getByteCountCurrentDispatch(void) const;
			int getByteCountLastOperation(void) const;
			int getPeerState(void) const;
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
			Common::JString getServerAddress(void) const;
			bool getIsPayloadEncryptionAvailable(void) const;
			bool getIsEncryptionAvailable(void) const;
			int getResentReliableCommands(void) const;
			int getLimitOfUnreliableCommands(void) const;
			void setLimitOfUnreliableCommands(int value);
			bool getCRCEnabled(void) const;
			void setCRCEnabled(bool crcEnabled);
			int getPacketLossByCRC(void) const;
			bool getTrafficStatsEnabled(void) const;
			void setTrafficStatsEnabled(bool trafficStasEnabled);
			int getTrafficStatsElapsedMs(void) const;
			const TrafficStats& getTrafficStatsIncoming(void) const;
			const TrafficStats& getTrafficStatsOutgoing(void) const;
			const TrafficStatsGameLevel& getTrafficStatsGameLevel(void) const;
			nByte getQuickResendAttempts(void) const;
			void setQuickResendAttempts(nByte quickResendAttempts);
			nByte getConnectionProtocol(void) const;
			void setConnectionProtocol(nByte connectionProtocol);
			nByte getChannelCountUserChannels(void) const;

			static short getPeerCount(void);
			static unsigned int getMaxAppIDLength(void);
		protected:
			PhotonPeer(PhotonListener& listener, bool usingObjC, nByte connectionProtocol=ConnectionProtocol::DEFAULT);

			Common::Logger mLogger;
		private:
			void init(PhotonListener& listener, nByte connectionProtocol=ConnectionProtocol::DEFAULT);
			virtual bool connect(const Common::JString& ipAddr, const Common::JString& appID, const Common::Object& customData);
			void createPeerBase(void);

			Common::Helpers::UniquePointer<Internal::PeerData> mupPeerData;
			Internal::PeerBase* mpPeerBase;
			nByte mConnectionProtocol;

			friend class Internal::PeerData;
			friend class Internal::PeerBase;
			friend class Internal::EnetPeer;
			friend class Internal::TPeer;
			friend class ::EGObjCPhotonPeer;
		};


		
			/**
			   @overload
			   @param ipAddr A Null terminated string containing the IP address or domain name and optionally a port of the server to connect to. Should be in the usual format:  "address[:port]",
			   for example: "192.168.0.1:5055" or "udp.gameserver.com". If no port is given, port 5055  will be used by default.
			   @param appID the appID (default: an empty string)
			   @param customData custom data to send to the server when initializing the connection - has to be provided in the form of one of the supported data types, specified at @link Datatypes Table of Datatypes\endlink*/
			template<typename Ftype>
			bool PhotonPeer::connect(const Common::JString& ipAddr, const Common::JString& appID, const Ftype& customData)
			{
				COMPILE_TIME_ASSERT2_TRUE_MSG(!Common::Helpers::ConfirmAllowed<Ftype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
				return connect(ipAddr, appID, Common::Helpers::ValueToObject<Common::Object>::get(customData));
			}

			/**
			   @overload
			   @details
			   This overload accepts singledimensional arrays and NULL-pointers passed for parameter pCustomDataArray. NULL pointers are only legal input, if arrSize is 0
			   @param ipAddr  Null terminated string containing IP address or domain name and optionally a port of server to connect. Should be in usual format:  "address[:port]",
			   for example: "192.168.0.1:5055" or "udp.gameserver.com". If no port is given, port 5055  will be used by default.
			   @param appID the appID (default: an empty string)
			   @param pCustomDataArray custom data to send to the server when initializing the connection - has to be provided in the form of a 1D array of one of the supported data types, specified at @link Datatypes Table of Datatypes\endlink
			   @param arrSize the element count of the customData array */
			template<typename Ftype>
			bool PhotonPeer::connect(const Common::JString& ipAddr, const Common::JString& appID, const Ftype pCustomDataArray, typename Common::Helpers::ArrayLengthType<Ftype>::type arrSize)
			{
				COMPILE_TIME_ASSERT2_TRUE_MSG(Common::Helpers::ConfirmAllowed<Ftype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
				return connect(ipAddr, appID, Common::Helpers::ValueToObject<Common::Object>::get(pCustomDataArray, arrSize));
			}

			/**
			   @overload
			   @details
			   This overload accepts multidimensional arrays and NULL-pointers passed for parameter pCustomDataArray.
			   The array that is passed for parameter pCustomDataArray has to be a pointer of the correct abstraction level, meaning a normal pointer for
			   a singledimensional array, a doublepointer for a twodimensional array, a triplepointer for a threedimensional array and so on.
			   For pCustomDataArray NULL pointers are only legal input, if pArrSizes[0] is 0.
			   For pArrSizes NULL is no valid input.
			   @param ipAddr  Null terminated string containing IP address or domain name and optionally a port of server to connect. Should be in usual format:  "address[:port]",
			   for example: "192.168.0.1:5055" or "udp.gameserver.com". If no port is given, port 5055  will be used by default.
			   @param appID the appID (default: an empty string)
			   @param pCustomDataArray custom data to send to the server when initializing the connection - has to be provided in the form of an array of one of the supported data types, specified at @link Datatypes Table of Datatypes\endlink
			   @param pArrSizes the element counts for every dimension of the custom data array - the element count of this array has to match the dimensions of the custom data array */
			template<typename Ftype>
			bool PhotonPeer::connect(const Common::JString& ipAddr, const Common::JString& appID, const Ftype pCustomDataArray, const short* pArrSizes)
			{
				COMPILE_TIME_ASSERT2_TRUE_MSG((Common::Helpers::ConfirmAllowed<Ftype>::dimensions>1), ERROR_THIS_OVERLOAD_IS_ONLY_FOR_MULTIDIMENSIONAL_ARRAYS);
				return connect(ipAddr, appID, Common::Helpers::ValueToObject<Common::Object>::get(pCustomDataArray, pArrSizes));
			}
	}
}
