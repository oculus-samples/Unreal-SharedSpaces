/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/VoiceFramed.h"

namespace ExitGames
{
	namespace Voice
	{       /// <summary>Collection of Audio Utility functions and classes.</summary>
		namespace AudioUtil
		{
			template<typename T> void resample(const Buffer<T>& src, Buffer<T>& dst, int dstCount, int channels);
			void resampleAndConvert(const Buffer<short>& src, Buffer<float>& dst, int dstCount, int channels);
			void resampleAndConvert(const Buffer<float>& src, Buffer<short>& dst, int dstCount, int channels);
			void convert(const Buffer<float>& src, Buffer<short>& dst, int dstCount);
			void convert(const Buffer<short>& src, Buffer<float>& dst, int dstCount);
			template<typename T> void forceToStereo(const Buffer<T>& src, Buffer<T>& dst, int srcChannels);

			template<typename T>
			class Resampler : public IProcessor<T>
			{
			public:
				Resampler(int dstSize, int channels);
				virtual Buffer<T> process(Buffer<T> buf);
			protected:
				Buffer<T> mFrameResampled;
			private:
				int mChannels;
			};

			/// <summary>Audio Level Metering interface.</summary>
			class ILevelMeter
			{
			public:
				virtual float getCurrentAvgAmp(void) const = 0;
				virtual float getCurrentPeakAmp(void) const = 0;
				virtual float getAccumAvgPeakAmp(void) const = 0;
				virtual void resetAccumAvgPeakAmp(void) = 0;

				virtual ~ILevelMeter(void) {}
			};

			/// <summary>Dummy Audio Level Meter that doesn't actually do anything.</summary>
			class LevelMeterDummy : public ILevelMeter
			{
			public:
				virtual float getCurrentAvgAmp(void) const { return 0; }
				virtual float getCurrentPeakAmp(void) const { return 0; }
				virtual float getAccumAvgPeakAmp(void) const { return 0; }
				virtual void resetAccumAvgPeakAmp(void) {}
			};

			/// <summary>
			/// Audio Level Meter.
			/// </summary>
			template<typename T>
			class LevelMeter : public IProcessor<T>, public ILevelMeter
			{
			public:
				LevelMeter(int samplingRate, int numChannels);

				virtual Buffer<T> process(Buffer<T> buf);

				virtual float getCurrentAvgAmp(void) const;
				virtual float getCurrentPeakAmp(void) const;
				virtual float getAccumAvgPeakAmp(void) const;
				virtual void resetAccumAvgPeakAmp(void);
			protected:
				// sum of all values in buffer
				float mAmpSum;
				// max of values from start buffer to current pos
				float mAmpPeak;
				Buffer<T> mPrevValues; // accumulator
				int mPrevValuesHead;

				float mAccumAvgPeakAmpSum;
				int mAccumAvgPeakAmpCount;
				float mCurrentPeakAmp;
			};

			/// <summary>Voice Activity Detector interface.</summary>
			class IVoiceDetector
			{
			public:
				/// <summary>If true, voice detection enabled.</summary>
				virtual bool getOn(void) const = 0;
				virtual void setOn(bool) = 0;
				/// <summary>Voice detected as soon as signal level exceeds threshold.</summary>
				virtual float getThreshold(void) const = 0;
				virtual void setThreshold(float) = 0;
				/// <summary>If true, voice detected.</summary>
				virtual bool getDetected(void) const = 0;
				/// <summary>Last time when switched to detected state.</summary>
				virtual int getDetectedTime(void) const = 0;
				/// <summary>Called when switched to detected state.</summary>
				virtual void setOnDetected(void(*pCallback)(void)) = 0;
				/// <summary>Keep detected state during this time after signal level dropped below threshold.</summary>
				virtual int getActivityDelayMs(void) const = 0;
				virtual void setActivityDelayMs(int) = 0;

				virtual ~IVoiceDetector(void) {}
			protected:
				virtual void setDetected(bool) = 0;
			};

			/// <summary>Dummy VoiceDetector that doesn't actually do anything.</summary>
			class VoiceDetectorDummy : public IVoiceDetector
			{
			public:
				virtual bool getOn(void) const { return 0; }
				virtual void setOn(bool) {}
				/// <summary>Voice detected as soon as signal level exceeds threshold.</summary>
				virtual float getThreshold(void) const { return 0; }
				virtual void setThreshold(float) {}
				/// <summary>If true, voice detected.</summary>
				virtual bool getDetected(void) const { return 0; }
				/// <summary>Last time when switched to detected state.</summary>
				virtual int getDetectedTime(void) const { return 0; }
				/// <summary>Called when switched to detected state.</summary>
				virtual void setOnDetected(void(* /*callback*/)(void)) {};
				/// <summary>Keep detected state during this time after signal level dropped below threshold.</summary>
				virtual int getActivityDelayMs(void) const { return 0; }
				virtual void setActivityDelayMs(int) {}
			protected:
				virtual void setDetected(bool) {}
			};

			/// <summary>Calibration Utility for Voice Detector</summary>.
			/// Using this audio processor, you can calibrate the Threshold property of IVoiceDetector.
			template<typename T>
			class VoiceDetectorCalibration : public IProcessor<T>
			{
			public:
				VoiceDetectorCalibration(IVoiceDetector* pVoiceDetector, ILevelMeter* pLevelMeter, int samplingRate, int channels);

				bool isCalibrating(void) const;
				void calibrate(int durationMs);				

				virtual Buffer<T> process(Buffer<T> buf);
			private:
				IVoiceDetector* mpVoiceDetector;
				ILevelMeter* mpLevelMeter;
				int mValuesPerSec;
				int mCalibrateCount;
			};

			/// <summary>
			/// Simple voice activity detector triggered by signal level.
			/// </summary>
			template<typename T>
			class VoiceDetector : public IProcessor<T>, public IVoiceDetector
			{
			public:
				VoiceDetector(int samplingRate, int numChannels);

				virtual Buffer<T> process(Buffer<T> buf);

				virtual bool getOn(void) const;
				virtual void setOn(bool);
				virtual float getThreshold(void) const;
				virtual void setThreshold(float);
				virtual bool getDetected(void) const;
				virtual int getDetectedTime(void) const;
				virtual void setOnDetected(void(*pCallback)(void));
				virtual int getActivityDelayMs(void) const;
				virtual void setActivityDelayMs(int);
			protected:
				virtual void setDetected(bool);
			private:
				int mAutoSilenceCounter;
				int mValuesCountPerSec;
				int mActivityDelayValuesCount;
				int mActivityDelayMs;

				bool mOn;
				float mThreshold;
				bool mDetected;
				int mDetectedTime;

				void(*mpOnDetected)(void);
			};

			/// <summary>Utility Audio Processor Voice Detection Calibration.</summary>
			/// Encapsulates level meter, voice detector and voice detector calibrator in single instance.
			template<typename T>
			class VoiceLevelDetectCalibrate : public IProcessor<T>
			{
			public:
				VoiceLevelDetectCalibrate(int samplingRate, int channels);
				virtual ~VoiceLevelDetectCalibrate(void);

				void calibrate(int durationMs);
				ILevelMeter* getLevelMeter(void) const;
				IVoiceDetector* getDetector(void) const;

				virtual Buffer<T> process(Buffer<T> buf);
			private:
				LevelMeter<T>* mpLevelMeter;
				VoiceDetector<T>* mpVoiceDetector;
				VoiceDetectorCalibration<T>* mpCalibration;
			};
		}

		// audio packets sink
		template<typename T>
		class IAudioOut
		{
		public:
			virtual bool isPlaying(void) const = 0;
			virtual void start(int frequency, int channels, int frameSamplesPerChannel, int playDelayMs) = 0;
			virtual void stop(void) = 0;
			virtual void push(Buffer<T> frame) = 0;
			virtual void service(void) = 0;
			// used for debug
			virtual int getLag(void) const = 0;

			virtual ~IAudioOut(void) {}
		};

		// audio packets sink with external synchronization
		template<typename T>
		class ISyncAudioOut : public IAudioOut<T>
		{
		public:
			// player adjusts input stream to output position
			virtual int getPlaySamplePos(void) const = 0;
			// player either skips samples in input stream
			virtual void setPlaySamplePos(int) = 0;
			// or pauses playback
			virtual void pause(void) = 0;
			virtual void unPause(void) = 0;
		};
	}
}