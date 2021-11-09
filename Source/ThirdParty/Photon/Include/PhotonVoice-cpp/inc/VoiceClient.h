/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/Internal/RemoteVoice.h"
#include "PhotonVoice-cpp/inc/RemoteVoiceInfo.h"
#include "PhotonVoice-cpp/inc/Voice.h"

namespace ExitGames
{
	namespace Voice
	{
		class VoiceClient;
		class VoiceInfo;
		class LocalVoice;
		template<typename T> class LocalVoiceFramed;
		template<typename T> class LocalVoiceAudio;
		template<typename T> class IAudioPusher;
		class RemoteVoiceOptions;
		class IEncoder;

		class IVoiceTransport : public ILogger
		{
		public:
			IVoiceTransport(void) : mpVoiceClient(NULL) {}
			virtual ~IVoiceTransport(void) {}

			virtual bool isChannelJoined(int channelId) = 0;
			virtual void sendVoicesInfo(const Common::JVector<const LocalVoice*>& voices, int channelId, int targetPlayerId) = 0;
			virtual void sendVoiceRemove(const LocalVoice& voice, int channelId, int targetPlayerId) = 0;
			virtual void sendFrame(Buffer<nByte> data, nByte evNumber, nByte voiceId, int channelId, const LocalVoice& localVoice) = 0;
			virtual Common::JString channelIdStr(int channelId) = 0;
			virtual Common::JString playerIdStr(int playerId) = 0;
			virtual void setDebugEchoMode(const LocalVoice& voice) = 0;
		protected:
			VoiceClient* mpVoiceClient; // set by Voice Client in constructor
		private:
			friend class VoiceClient;
		};

		/// <summary>
		/// Voice client interacts with other clients on network via IVoiceTransport.
		/// </summary>        
		class VoiceClient
		{
		public:
			VoiceClient(IVoiceTransport* transport);
			virtual ~VoiceClient(void);

			typedef void(RemoteVoiceInfoCallback)(void* opaque, int channelId, int playerId, nByte voiceId, const VoiceInfo& voiceInfo, RemoteVoiceOptions& options);
			void setOnRemoteVoiceInfoAction(void* opaque, RemoteVoiceInfoCallback* callback);
			void service(void);
			IVoiceTransport* getTransport(void) const;
			void  forEachLocalVoice(void* opaque, void(*op)(void*, const LocalVoice&)) const;
			void forEachLocalVoiceInChannel(int channelId, void* opaque, void(*op)(void*, const LocalVoice&)) const;
			Common::JVector<RemoteVoiceInfo> getRemoteVoiceInfos(void) const;

			int getFramesLost(void) const;
			int getFramesReceived(void) const;
			int getFramesSent(void) const;
			int getFramesSentBytes(void) const;
			int getRoundTripTime(void) const;
			int getRoundTripTimeVariance(void) const;
			bool getSuppressInfoDuplicateWarning(void) const;
			void setSuppressInfoDuplicateWarning(bool yes);
			int getDebugLostPercent(void) const;
			void setDebugLostPercent(int debugLostPercent);

			// LovalVoice create utility
			LocalVoice* createLocalVoice(const VoiceInfo& voiceInfo, int channelId=0, Common::Helpers::SharedPointer<IEncoder> encoder=static_cast<IEncoder*>(NULL));
			template <typename T>LocalVoiceFramed<T>* createLocalVoiceFramed(const VoiceInfo& voiceInfo, int frameSize, int channelId=0, Common::Helpers::SharedPointer<IEncoder> encoder=static_cast<IEncoder*>(NULL));
			template <typename T>LocalVoiceAudio<T>* createLocalVoiceAudio(const VoiceInfo& voiceInfo, const IAudioDesc& audioSourceDesc, int channelId=0, Common::Helpers::SharedPointer<IEncoder> encoder=static_cast<IEncoder*>(NULL));
			template <typename T>LocalVoiceAudio<T>* createLocalVoiceAudioFromSource(const VoiceInfo& voiceInfo, IAudioPusher<T>& source, int channelId=0, Common::Helpers::SharedPointer<IEncoder> encoder=static_cast<IEncoder*>(NULL));

#if EG_PHOTON_VOICE_VIDEO_ENABLE
//			LocalVoiceVideo* CreateLocalVoiceVideo(const VoiceInfo& voiceInfo, int channelId = CHANNEL_AUTO, Common::Helpers::SharedPointer<IEncoder> encoder = static_cast<IEncoder*>(NULL));
#endif
			void removeLocalVoice(LocalVoice& voice);

			/*internal*/ Common::JString channelStr(int channelId);
			/*internal*/ Common::JString playerStr(int playerId);

			// transport to voice client interface (TODO: not public to user code)
			
			void onJoinChannel(int channel);
			void onLeaveChannel(int channel);
			void onLeaveAllChannels();
			void onPlayerJoin(int channelId, int playerId);
			void onPlayerLeave(int channelId, int playerId);
			void onVoiceInfo(int channelId, int playerId, nByte voiceId, nByte eventNumber, const VoiceInfo& info);
			void onVoiceRemove(int channelId, int playerId, const Common::JVector<nByte>& voiceIds);

			nByte getGlobalInterestGroup(void) const;
			void setGlobalInterestGroup(nByte group);

			/*internal*/ void onFrame(int channelId, int playerId, nByte voiceId, nByte evNumber, Buffer<nByte> receivedBytes, bool isLocalPlayer);
		private:
			VoiceClient(const VoiceClient&);
			VoiceClient& operator=(const VoiceClient&); // non-copyable

			LocalVoice* tryAddLocalVoice(LocalVoice* pLocalVoice);
			nByte getNewVoiceId(void);
			void addLocalVoice(nByte newId, int channelId, LocalVoice* pV);
			void clearRemoteVoices(void);
			void clearRemoteVoicesInChannel(int channelId);
			void clearRemoteVoicesInChannelForPlayer(int channelId, int playerId);
			void sendVoicesInfo(int channelId, int targetPlayerId) const;
			void sendChannelVoicesInfo(int channelId, int targetPlayerId) const;

			IVoiceTransport* mpTransport;
			nByte mGlobalInterestGroup;
			nByte mVoiceIdCnt;

			// voice id -> LocalVoice* 
			// because LocalVoice instances are deleted explicitly by the user, SharedPointer does not make much sense for them and even makes elements removal harder
			Common::JDictionary<nByte, Common::Helpers::SharedPointer<LocalVoice> > mLocalVoices;
			Common::JDictionary<int, Common::JVector<Common::Helpers::SharedPointer<LocalVoice> > > mLocalVoicesPerChannel;
			mutable Common::Helpers::Spinlock mLocalVoicesLock; // controls access to both dictionaries above
			// player id -> voice id -> RemoteVoice*
			// SharedPointer simplifies RemoteVoice instances management in multiple threads
			Common::JDictionary<int, Common::JDictionary<nByte, Common::Helpers::SharedPointer<RemoteVoice> > > mRemoteVoices;
			mutable Common::Helpers::Spinlock mRemoteVoicesLock;

			int mPrevRtt;
			int mFramesLost;
			int mFramesReceived;
			int mFramesSent;
			int mFramesSentBytes;
			int mRoundTripTime;
			int mRoundTripTimeVariance;
			bool mSuppressInfoDuplicateWarning;
			RemoteVoiceInfoCallback* mpOnRemoteVoiceInfoAction;
			void* mpOnRemoteVoiceInfoActionOpaque;
			int mDebugLostPercent;

			friend class RemoteVoice;
		};



		/// <summary>
		/// Creates basic outgoing stream w/o data processing support. Provided encoder should generate output data stream.
		/// </summary>
		/// <param name="voiceInfo">Outgoing stream parameters. Set applicable fields to read them by encoder and by receiving client when voice created.</param>
		/// <param name="channelId">Transport channel specific to transport.</param>
		/// <param name="encoder">Encoder producing the stream.</param>
		/// <returns>Outgoing stream handler.</returns>
		inline LocalVoice* VoiceClient::createLocalVoice(const VoiceInfo& voiceInfo, int channelId, Common::Helpers::SharedPointer<IEncoder> encoder)
		{
			LocalVoice* v;
			ALLOCATE(LocalVoice, v, this, encoder, getNewVoiceId(), voiceInfo, channelId);
			return tryAddLocalVoice(v);
		}

		/// <summary>
		/// Creates outgoing stream consuming sequence of values passed in array buffers of arbitrary length which repacked in frames of constant length for further processing and encoding.
		/// </summary>
		/// <typeparam name="T">Type of data consumed by outgoing stream (element type of array buffers).</typeparam>
		/// <param name="voiceInfo">Outgoing stream parameters. Set applicable fields to read them by encoder and by receiving client when voice created.</param>
		/// <param name="frameSize">Size of buffer LocalVoiceFramed repacks input data stream to.</param>
		/// <param name="channelId">Transport channel specific to transport.</param>
		/// <param name="encoder">Encoder compressing data stream in pipeline.</param>
		/// <returns>Outgoing stream handler.</returns>
		template<typename T>
		inline LocalVoiceFramed<T>* VoiceClient::createLocalVoiceFramed(const VoiceInfo& voiceInfo, int frameSize, int channelId, Common::Helpers::SharedPointer<IEncoder> encoder)
		{
			LocalVoiceFramed<T>* v;
			ALLOCATE(LocalVoiceFramed<T>, v, this, encoder, getNewVoiceId(), voiceInfo, channelId, frameSize);
			return tryAddLocalVoice(v) ? v : NULL;
		}

		/// <summary>
		/// Creates outgoing audio stream. Adds audio specific features (e.g. resampling, level meter) to processing pipeline and to returning stream handler.
		/// </summary>
		/// <typeparam name="T">Element type of audio array buffers.</typeparam>
		/// <param name="voiceInfo">Outgoing audio stream parameters. Set applicable fields to read them by encoder and by receiving client when voice created.</param>
		/// <param name="audioSourceDesc">Streaming audio source description.</param>
		/// <param name="channelId">Transport channel specific to transport.</param>
		/// <param name="encoder">Audio encoder. Set to null to use default Opus encoder.</param>
		/// <returns>Outgoing stream handler.</returns>
		/// <remarks>
		/// Sampling rates of audioSourceDesc voiceInfo may do not match. Automatic resampling will occur in this case.
		/// </remarks>
		template<typename T>
		inline LocalVoiceAudio<T>* VoiceClient::createLocalVoiceAudio(const VoiceInfo& voiceInfo, const IAudioDesc& audioSourceDesc, int channelId, Common::Helpers::SharedPointer<IEncoder> encoder)
		{
			LocalVoiceAudio<T>* v;
			ALLOCATE(LocalVoiceAudio<T>, v, this, encoder, getNewVoiceId(), voiceInfo, audioSourceDesc, channelId);
			return tryAddLocalVoice(v) ? v : NULL;
		}

		template<typename T>
		static void audioPusherSourceCallback(void* obj, const Buffer<T>& buf)
		{
			LocalVoiceAudio<T>* localVoice = static_cast<LocalVoiceAudio<T>*>(obj);
			localVoice->pushDataAsync(buf);
		}

		/// <summary>
		/// Creates outgoing audio stream.
		/// Adds audio specific features (e.g. resampling, level meter) to processing pipeline and to returning stream handler.
		/// </summary>
		/// <param name="voiceInfo">Outgoing audio stream parameters. Set applicable fields to read them by encoder and by receiving client when voice created.</param>
		/// <param name="source">Streaming audio source.</param>
		/// <param name="channelId">Transport channel specific to transport.</param>
		/// <param name="encoder">Audio encoder. Set to null to use default Opus encoder.</param>
		/// <returns>Outgoing stream handler.</returns>
		/// <remarks>
		/// Sampling rates of audioSourceDesc voiceInfo may do not match. Automatic resampling will occur in this case.
		/// </remarks>
		template <typename T>
		inline LocalVoiceAudio<T>* VoiceClient::createLocalVoiceAudioFromSource(const VoiceInfo& voiceInfo, IAudioPusher<T>& source, int channelId, Common::Helpers::SharedPointer<IEncoder> encoder)
		{
			LocalVoiceAudio<T>* localVoice = createLocalVoiceAudio<T>(voiceInfo, source, channelId, encoder);
			source.setCallback(localVoice, audioPusherSourceCallback);
			return localVoice;
		}
	}
}