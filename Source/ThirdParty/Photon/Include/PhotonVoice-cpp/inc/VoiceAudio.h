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
		/// <summary>Audio description interface.</summary>
		class IAudioDesc
		{
		public:
			virtual ~IAudioDesc(void) {}

			/// <summary>Sampling rate of the audio signal (in Hz).</summary>
			virtual int getSamplingRate(void) const = 0;
			/// <summary>Number of channels in the audio signal.</summary>
			virtual int getChannels(void) const = 0;
			/// <summary>If not null, audio object is in invalid state.</summary>
			virtual Common::JString getError(void) const = 0;
		};

		// Audio description implementation. Use to provide audio info w/o audio source (IAudioPusher)
		class AudioDesc : public IAudioDesc
		{
		public:
			AudioDesc(int samplingRate, int channels);

			virtual int getSamplingRate(void) const;
			virtual int getChannels(void) const;
			virtual Common::JString getError(void) const;
		private:
			int mSamplingRate;
			int mChannels;
			Common::JString mError;
		};

		/// <summary>Audio Pusher interface.</summary>
		/// an IAudioPusher will push its audio data whenever it is ready,
		template<typename T>
		class IAudioPusher : public Common::Helpers::Retainable<IAudioDesc>, virtual public Common::ToString
		{
		public:
			virtual ~IAudioPusher(void) {}

			/// <summary>Set the callback function used for pushing data.</summary>
			/// <param name="pLocalVoice">Outgoing audio stream, for context.</param>
			/// <param name="pCallback">Callback function to use.</param>
			virtual void setCallback(void* pLocalVoice, void(*pCallback)(void*, const Buffer<T>&)) = 0;
		};

		/// <summary>Interface for an outgoing audio stream.</summary>
		/// A LocalVoice always brings a LevelMeter and a VoiceDetector, which you can access using this interface.
		class ILocalVoiceAudio
		{
		public:
			virtual ~ILocalVoiceAudio(void) {}

			/// <summary>The VoiceDetector in use.</summary>
			/// Use it to enable or disable voice detector and set its parameters.
			virtual AudioUtil::IVoiceDetector* getVoiceDetector(void) const = 0;
			/// <summary>The LevelMeter utility in use.</summary>
			virtual AudioUtil::ILevelMeter* getLevelMeter(void) const = 0;
			/// <summary>If true, voice detector calibration is in progress.</summary>
			virtual bool getIsVoiceDetectorCalibrating(void) const = 0;
			/// <summary>
			/// Trigger voice detector calibration process.
			/// </summary>
			/// While calibrating, keep silence. Voice detector sets threshold based on measured background noise level.
			/// <param name="durationMs">Duration of calibration (in milliseconds).</param>
			virtual void voiceDetectorCalibrate(int durationMs) = 0;
		};

		/// <summary>Outgoing audio stream.</summary>
		template<typename T>
		class LocalVoiceAudio : public LocalVoiceFramed<T>, public ILocalVoiceAudio
		{
		public:
			virtual ~LocalVoiceAudio(void);

			virtual AudioUtil::IVoiceDetector* getVoiceDetector(void) const;
			virtual AudioUtil::ILevelMeter* getLevelMeter(void) const;
			virtual bool getIsVoiceDetectorCalibrating(void) const;

			virtual void voiceDetectorCalibrate(int durationMs);
		protected:
			LocalVoiceAudio(VoiceClient* pVoiceClient, Common::Helpers::SharedPointer<IEncoder> spEncoder, nByte id, const VoiceInfo& voiceInfo, const IAudioDesc& audioSourceDesc, int channelId); // created by VoiceClient	

			virtual IEncoder* createDefaultEncoder(const VoiceInfo& info);
		private:
			// direct references to built-in processors stored in processors SharedPointer's list
			// these references are for public getters only
			AudioUtil::LevelMeter<T>* mpLevelMeter;
			AudioUtil::VoiceDetector<T>* mpVoiceDetector;
			AudioUtil::VoiceDetectorCalibration<T>* mpVoiceDetectorCalibration;

			int mChannels;

			friend class VoiceClient;
		};

		/// <summary>Dummy LocalVoiceAudio</summary>
		/// For testing, this LocalVoiceAudio implementation features a <see cref="AudioUtil::VoiceDetectorDummy"></see> and a <see cref="AudioUtil.LevelMeterDummy"></see>
		class LocalVoiceAudioDummy : public LocalVoice, public ILocalVoiceAudio
		{
		public:
			LocalVoiceAudioDummy(void);
			~LocalVoiceAudioDummy(void);

			virtual AudioUtil::IVoiceDetector* getVoiceDetector(void) const;
			virtual AudioUtil::ILevelMeter* getLevelMeter(void) const;
			virtual bool getIsVoiceDetectorCalibrating(void) const;
			virtual void voiceDetectorCalibrate(int durationMs);

			static LocalVoiceAudioDummy& getDummy(void);
		private:
			AudioUtil::VoiceDetectorDummy* mpVoiceDetector;
			AudioUtil::LevelMeterDummy* mpLevelMeter;
			static LocalVoiceAudioDummy mDummy;
		};
	}
}