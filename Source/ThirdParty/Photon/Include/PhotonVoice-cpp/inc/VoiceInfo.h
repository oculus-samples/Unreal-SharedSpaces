/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/defines.h"
#include "PhotonVoice-cpp/inc/ILogger.h"

namespace ExitGames
{
	namespace Voice
	{
		class IAudioDesc;
		/// <summary>Describes stream properties.</summary>
		class VoiceInfo : public Common::ToString
		{
		public:
			using ToString::toString;

			VoiceInfo(void);

			int getCodec(void) const;
			VoiceInfo& setCodec(int codec);
			int getSamplingRate(void) const;
			VoiceInfo& setSamplingRate(int samplingRate);
			int getChannels(void) const;
			VoiceInfo& setChannels(int channels);
			int getFrameDurationUs(void) const;
			VoiceInfo& setFrameDurationUs(int frameDurationUs);
			int getBitrate(void) const;
			VoiceInfo& setBitrate(int bitrate);
			const Common::Object& getUserData(void) const;
			VoiceInfo& setUserData(const Common::Object& userData);

			int getFrameDurationSamples(void) const;
			int getFrameSize(void) const;
			int getWidth(void) const;
			VoiceInfo& setWidth(int width);
			int getHeight(void) const;
			VoiceInfo& setHeight(int height);

			static VoiceInfo createAudioOpus(int samplingRate, int channels, int frameDurationUs, int bitrate, const Common::Object& userdata=Common::Object());
#if EG_PHOTON_VOICE_VIDEO_ENABLE
			static VoiceInfo createVideoVP8(int bitrate, int width=0, int heigth=-1, const Common::Object& userdata=Common::Object());
#endif
			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			int mCodec;

			// audio
			int mSamplingRate;
			int mChannels;
			int mFrameDurationUs;
			int mBitrate;
			Common::Object mUserData;

			// video
			int mWidth;
			int mHeight;

			friend class VoiceClient;
		};
	}
}