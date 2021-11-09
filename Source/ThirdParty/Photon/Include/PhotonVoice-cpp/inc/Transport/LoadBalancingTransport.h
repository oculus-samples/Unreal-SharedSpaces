/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "LoadBalancing-cpp/inc/Client.h"
#include "PhotonVoice-cpp/inc/Transport/PhotonTransport.h"
#include "PhotonVoice-cpp/inc/VoiceClient.h"

namespace ExitGames
{
	namespace Voice
	{
		/// <summary>
		/// Provides transport for VoiceClient based on given LoadBalancing Client
		/// Creates and maintains VoiceClient
		/// </summary>
		/// <remarks>
		class LoadBalancingTransport : public IVoiceTransport, public Common::LoggingBase<LoadBalancingTransport>
		{
		public:
			using ToString::toString;

			LoadBalancingTransport(LoadBalancing::Client& lbClient, Common::BaseListener& debugReturn, bool direct=false);
			virtual ~LoadBalancingTransport(void);

			virtual void logError(const Common::JString& msg) const;
			virtual void logWarning(const Common::JString& msg) const;
			virtual void logInfo(const Common::JString& msg) const;
			virtual void logDebug(const Common::JString& msg) const;

			virtual bool isChannelJoined(int channelId);
			virtual void sendVoicesInfo(const Common::JVector<const LocalVoice*>& voices, int channelId, int targetPlayerId);
			virtual void sendVoiceRemove(const LocalVoice& voice, int channelId, int targetPlayerId);
			virtual void sendFrame(Buffer<nByte> data, nByte evNumber, nByte voiceId, int channelId, const LocalVoice& localVoice);
			virtual Common::JString channelIdStr(int channelId);
			virtual Common::JString playerIdStr(int playerId);
			virtual void setDebugEchoMode(const LocalVoice& voice);
			
			nByte getGlobalInterestGroup(void) const;
			void setGlobalInterestGroup(nByte);

			// Call this regularly (in LoadBalancing::Client::service)
			void service(void);
			// Call this on each incoming event (in LoadBalancing::Listener::customEventAction).
			void onCustomEvent(int playerNr, nByte eventCode, const Common::Object& eventContent);
			// Call this on each incoming direct event (in LoadBalancing::Listener::onDirectMessage).
			void onDirectMessage(const Common::Object& msg, int playerNr, bool relay);
			// Call this when LoadBalancing Client joins a room.
			void onJoinRoom(void);
			// Call this when LoadBalancing Client leaves a room or gets disconnected.
			void onLeaveRoom(void);
			// Call this when other player joins a room.
			void onPlayerJoinRoom(int playerNr);
			// Call this when other player leaves a room.
			void onPlayerLeaveRoom(int playerNr);

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		protected:
			static Common::Helpers::LockableNonAssignable<Common::Logger> mLogger;
		private:
			nByte photonChannelForCodec(int codec) const;
			void sendDebugEchoVoicesInfo(int channelId);

			void sendFrameRaiseEvents(void);
			void onVoiceEvent(int playerNr, const Common::Object& eventContent);

			LoadBalancing::Client& mLBClient;
			PhotonTransportProtocol* mpProtocol;
			bool mDirect;

			// raising frame events in main thread 
			struct SendFrameEventParams : public Common::ToString
			{
				using ToString::toString;

				virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;

				Buffer<nByte> mData;
				nByte mEvNumber;
				nByte mVoiceId;
				nByte mChannelId;
				bool mReliable;
				nByte mInterestGroup;
				bool mDebugEchoMode;
			};

			Common::Helpers::SpinLockable<Common::JQueue<SendFrameEventParams> > mSendFrameRaiseEventQueue;
		};
	}
}