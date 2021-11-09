/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/VoiceCodec.h"
#include "PhotonVoice-cpp/opus/include/opus.h"

namespace ExitGames
{
	namespace Voice
	{
		namespace Opus
		{
			namespace FrameDuration
			{
				static const int FRAME_2_DOT_5_MS =  2500;
				static const int FRAME_5_MS       =  5000;
				static const int FRAME_10_MS      = 10000;
				static const int FRAME_20_MS      = 20000;
				static const int FRAME_40_MS      = 40000;
				static const int FRAME_60_MS      = 60000;
			}

			class LocalVoice;

			template<typename T>
			class Encoder : public IEncoderDirect<Buffer<T> >
			{
			public:
				static const int RECOMMENDED_MAX_PACKET_SIZE = 4000;

				Encoder(const VoiceInfo& info, const ILogger& logger);
				virtual ~Encoder(void);

				virtual Common::JString getError(void) const;
				virtual void setOutput(void* opaque, void(*output)(void*, const Buffer<nByte>&));
				virtual Buffer<nByte> dequeueOutput(void) { return Buffer<nByte>::getEmpty(); }
				virtual void input(const Buffer<T>& buf);
			private:
				OpusEncoder* mpEncoder;
				Common::JString mError;
				void* mpOutputOpaque;
				void(*mpOutput)(void*, const Buffer<nByte>&);
				const ILogger& mLogger;
				int mChannels;
				Buffer<nByte> mOutBuf;
			};

			template <typename T>
			class Decoder : public IDecoder
			{
			public:
				Decoder(void* outputOpaque, void(*output)(void*, const Buffer<T>&), const ILogger& logger);
				virtual ~Decoder(void);

				virtual void open(const VoiceInfo& i);
				virtual Common::JString getError(void) const;
				virtual void input(const Buffer<nByte>& buf);
			private:
				int decodeTyped(Buffer<nByte> buf, T* outArray);

				VoiceInfo mInfo;
				OpusDecoder* mpDecoder;
				void* mpOutputOpaque;
				void(*mpOutput)(void*, const Buffer<T>&);
				Common::JString mError;
				const ILogger& mLogger;
			};
		}
	}
}