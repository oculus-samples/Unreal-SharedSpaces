/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/Voice.h"

namespace ExitGames
{
	namespace Voice
	{
		class VoiceInfo;

		/// <summary>Audio Processor interface.</summary>
		template<typename T>
		class IProcessor : public Common::ToStringDefaultImplementation
		{
		public:
			/// <summary>Process a frame of audio data.</summary>
			/// <param name="buf">Buffer containing input audio data</param>
			/// <returns>Buffer containing output audio data</returns>
			virtual Buffer<T> process(Buffer<T> buf) = 0;

			virtual ~IProcessor(void) {}
		};

		/// <summary>Utility class to re-frame audio packets.</summary>
		template<typename T>
		class Framer
		{
		public:
			Framer(int frameSize);
			~Framer(void);

			int count(int bufLen) const;
			void frame(const Buffer<T>& buf, void* opaque, void(*op)(void*, const Buffer<T>&));
		private:
			Buffer<T> mFrame;
			int mFramePos;
		};

		/// <summary>
		/// Typed re-framing LocalVoice
		/// </summary>
		/// Consumes data in array buffers of arbitrary length. Repacks them in frames of constant length for further processing and encoding.
		/// <param name="voiceInfo">Outgoing stream parameters. Set applicable fields to read them by encoder and by receiving client when voice created.</param>
		/// <param name="channelId">Transport channel specific to transport.</param>
		/// <param name="encoder">Encoder producing the stream.</param>
		/// <returns>Outgoing stream handler.</returns>
		template<typename T>
		class LocalVoiceFramed : public LocalVoice
		{
		public:
			~LocalVoiceFramed(void);

			int getFrameSize(void) const;
			void addPostProcessor(Common::Helpers::SharedPointer<IProcessor<T> > processor);
			void addPreProcessor(Common::Helpers::SharedPointer<IProcessor<T> > processor);
			void clearProcessors(void);
			bool isPushDataAsyncReady(void);
			void pushDataAsync(const Buffer<T>& buf);
			void pushData(const Buffer<T>& buf);
		protected:
			LocalVoiceFramed(VoiceClient* pVoiceClient, Common::Helpers::SharedPointer<IEncoder> encoder, nByte id, const VoiceInfo& voiceInfo, int channelId, int frameSize);
		private:
			int mFrameSize;
			Framer<T> mFramer;

			int mPreProcessorsCnt;
			Common::Helpers::SpinLockable<Common::JVector<Common::Helpers::SharedPointer<IProcessor<T> > > > mProcessors;
			std::atomic<bool> mEncodeThreadStarted;
			std::atomic<bool> mExitDecodeThread;
			Common::Helpers::SpinLockable<Common::JQueue<Buffer<T> > > mPushDataQueue;
			Common::Helpers::AutoResetEvent mPushDataQueueReady;

			int mFramesSkippedNextLog;
			int mFramesSkipped;

			void pushDataAsyncThread(void);
			// Optionally process input data. 
			// Should return arrays exactly of info.FrameSize size or null to skip sending
			Buffer<T> processFrame(const Buffer<T>& buf);

			static void encodeThreadStarter(void* pArgs);
			static void framerOp(void* opaque, const Buffer<T>& framed);

			friend class VoiceClient;
		};
	}
}