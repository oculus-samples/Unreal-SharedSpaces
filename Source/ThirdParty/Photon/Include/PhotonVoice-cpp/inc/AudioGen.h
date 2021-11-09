/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/VoiceAudio.h"

namespace ExitGames
{
	namespace Voice
	{
		namespace AudioUtil
		{
			/// <summary>IAudioPusher that provides a constant tone signal.</summary>
			// Helpful for debug
			template<typename T>
			class ToneAudioPusher : public IAudioPusher<T>
			{
			public:
				using Common::ToString::toString;

				ToneAudioPusher(int frequency=440, int bufSizeMs=100, int samplingRate=44100, int channels=2);
				virtual ~ToneAudioPusher(void);

				virtual int getSamplingRate(void) const;
				virtual int getChannels(void) const;
				virtual Common::JString getError(void) const;
				virtual void setCallback(void* pLocalVoice, void(*pCallback)(void*, const Buffer<T>&));

				virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
			private:
				static void workerStarter(void*);
				void worker(void);

				std::atomic<int> mSamplingRate;
				std::atomic<int> mChannels;
				float mAmp;
				double mK;
				int mBufSizeSamples;
				int mTimeMs;

				void* mpLocalVoice;
				void(*mpCallback)(void*, const Buffer<T>&);
			};
		}
	}
}