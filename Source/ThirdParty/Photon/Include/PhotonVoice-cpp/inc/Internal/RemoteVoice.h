/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/RemoteVoiceOptions.h"

namespace ExitGames
{
	namespace Voice
	{
		class VoiceClient;
		class VoiceInfo;
		class IDecoder;
		class IDecoderDirect;

		class RemoteVoice : public Common::ToString
		{
		public:
			using ToString::toString;

			RemoteVoice(VoiceClient* pClient, const RemoteVoiceOptions& options, int channelId, int playerId, nByte voiceId, const VoiceInfo& info, nByte lastEventNumber);
			virtual ~RemoteVoice(void);

			// Client.RemoteVoiceInfos support
			const VoiceInfo& getInfo(void) const;
			const RemoteVoiceOptions& getOptions(void) const;
			int getChannelId(void) const;

			void receiveBytes(Buffer<nByte> receivedBytes, nByte evNumber);

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		protected:
			Common::JString getName(void) const;
			Common::JString getLogPrefix(void) const;
		private:
			void receiveFrame(Buffer<nByte> buf);
			void receiveNullFrames(int count);			
			void decodeThread(void); // IDecoder* decoder			

			IDecoder* createDefaultDecoder(void);

			void static decodeThreadStarter(void* args);

			VoiceClient* mpVoiceClient; // TODO: only minor features of client needed in RemoteVoice

			VoiceInfo mInfo;
			RemoteVoiceOptions mOptions;
			int mChannelId;
			int mPlayerId;
			nByte mVoiceId;

			Common::Helpers::Spinlock mDecodeThreadLock;
			std::atomic<bool> mDecodeThreadExit;
			std::atomic<bool> mDecodeThreadExited;

			nByte mLastEvNumber;
			Common::Helpers::SpinLockable<Common::JQueue<Buffer<nByte> > > mFrameQueue;
			Common::Helpers::AutoResetEvent mFrameQueueReady;
		};
	}
}