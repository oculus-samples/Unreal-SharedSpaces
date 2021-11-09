/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/VoiceCodec.h"

namespace ExitGames
{
	namespace Voice
	{
		class IEncoder;
		class IDecoder;
		class VoiceClient;

		/// <summary>
		/// Represents outgoing data stream.
		/// </summary>
		class LocalVoice : public Common::ToString
		{
		public:
			using ToString::toString;

			virtual ~LocalVoice(void);

			void removeSelf(void);

			nByte getId(void) const;
			int getChannelId(void) const;
			const VoiceInfo& getInfo(void) const;
			nByte getEvNumber(void) const;
			bool getReliable(void) const;
			void setReliable(bool reliable);
			bool getEncrypt(void) const;
			void setEncrypt(bool encrypt);
			nByte getInterestGroup(void) const;
			void setInterestGroup(nByte group);
			bool getTransmitEnabled(void) const;
			void setTransmitEnabled(bool transmitEnabled);
			bool getIsCurrentlyTransmitting(void) const;
			int getFramesSent(void) const;
			int getFramesSentBytes(void) const;

			bool getDebugEchoMode(void) const;
			void setDebugEchoMode(bool debugEchoMode);

			const ILogger& getLogger(void) const;
			Common::JString getName(void) const;
			Common::JString getLogPrefix(void) const;

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;

			static const int DATA_POOL_CAPACITY = 50; // TODO: may depend on data type and properties, set for average audio stream
		protected:
			LocalVoice(void); // for dummy voices
			LocalVoice(VoiceClient* pVoiceClient, Common::Helpers::SharedPointer<IEncoder> spEncoder, nByte id, const VoiceInfo& voiceInfo, int channelId);

			virtual void service(void);
			void sendFrame(const Buffer<nByte>& compressed);
			void setupEncoder(void); // setup moved out of constructor because it calls virtual createDefaultEncoder
			virtual IEncoder* createDefaultEncoder(const VoiceInfo& info);
			void resetNoTransmitCnt(void);

			nByte mId;
			int mChannelId;
			nByte mEvNumber; // sequence used by receivers to detect loss. will overflow.
			VoiceInfo mInfo;
			bool mDebugEchoMode;
			VoiceClient* mpVoiceClient;
			Common::Helpers::SharedPointer<IEncoder> mspEncoder;
			Common::Helpers::SpinLockable<Common::JDictionary<nByte, int> > mEventTimestamps;
		private:
			LocalVoice(const LocalVoice&);
			LocalVoice& operator=(const LocalVoice&); // non-copyable

			static void sendFrame(void* opaque, const Buffer<nByte>& buffer);

			nByte mInterestGroup;
			bool mTransmitEnabled;
			bool mIsCurrentlyTransmitting;
			int mFramesSent;
			int mFramesSentBytes;
			bool mReliable;
			bool mEncrypt;
			int mNoTransmitCnt;

			friend class VoiceClient;
		};
	}
}