/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/AudioUtil.h"

namespace ExitGames
{
	namespace Voice
	{
		// Synchronizes provided ISyncAudioOut instance playback position with input stream position by pausing and unpausing ISyncAudioOut instance
		template<typename T>
		class AudioStreamPlayer : public IAudioOut<T>
		{
		public:
			AudioStreamPlayer(const ILogger& logger, ISyncAudioOut<T>& audioOut, const Common::JString& logPrefix, bool debugInfo);

			virtual bool isPlaying(void) const;
			virtual void start(int frequency, int channels, int frameSamples, int playDelayMs);
			virtual void stop(void);
			virtual void push(Buffer<T> frame);
			virtual void service(void);
			virtual int getLag(void) const;
		private:
			int mMaxPlayLagSamples;
			// buffering by playing few samples back
			int mPlayDelaySamples;
			int mFrameSize;
			int mFrameSamples;
			int mStreamSamplePos;

			// jitter-free stream position
			int mStreamSamplePosAvg;
			/// <summary>Smoothed difference between (jittering) stream and (clock-driven) player.</summary>        
			int mCurrentBufferLag; // public property turned to private field; upper camel case name preserved to minify diff

			ISyncAudioOut<T>& mAudioOut;
			const ILogger& mLogger;

			bool mAudioOutStarted;
			Common::JString mLogPrefix;
			bool mDebugInfo;
		};
	}
}