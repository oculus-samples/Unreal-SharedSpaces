/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/Buffer.h"
#include "PhotonVoice-cpp/inc/Enums/Codec.h"
#include "PhotonVoice-cpp/inc/VoiceInfo.h"

namespace ExitGames
{
	namespace Voice
	{
		class VoiceInfo;

#if EG_PHOTON_VOICE_VIDEO_ENABLE
		namespace ImageFormat
		{
			enum Enum
			{
				Undefined,
				I420, // native vpx (no format conversion before encoding)
				YV12, // native vpx (no format conversion before encoding)
				Android420,
				RGBA,
				ABGR,
				BGRA,
				ARGB,
			};
		}

		namespace Rotation
		{
			enum Enum
			{
				Undefined = -1,
				Rotate0 = 0,      // No rotation.
				Rotate90 = 90,    // Rotate 90 degrees clockwise.
				Rotate180 = 180,  // Rotate 180 degrees.
				Rotate270 = 270,  // Rotate 270 degrees clockwise.
			};
		}

		namespace Flip
		{
			enum Enum
			{
				Undefined = -1,
				None,
				Vertical,
				Horizontal
			};
		}

#endif
		/// <summary>Generic encoder interface.</summary>
		/// Depending on implementation, encoder should either call Output on eaach data frame or return next data frame in DequeueOutput() call.
		class IEncoder
		{
		public:
			virtual ~IEncoder(void) {}

			/// <summary>If not null, the object is in invalid state.</summary>
			virtual Common::JString getError(void) const = 0;
			/// <summary>Set callback encoder calls on each encoded data frame (if such output supported).</summary>
			virtual void setOutput(void* opaque, void(*output)(void*, const Buffer<nByte>&)) = 0;
			/// <summary>Returns next encoded data frame (if such output supported).</summary>
			virtual Buffer<nByte> dequeueOutput() = 0;
		};


		/// <summary>Interface for an encoder which consumes input data via explicit call.</summary>
		template<typename B>
		class IEncoderDirect : public IEncoder
		{
		public:
			/// <summary>Consumes the given raw data.</summary>
			/// <param name="buf">Array containing raw data (e.g. audio samples).</param>
			virtual void input(const B& buf) = 0;
		};

		/// <summary>Generic decoder interface.</summary>
		class IDecoder
		{
		public:
			virtual ~IDecoder(void) {}

			/// <summary>Open (initialize) the decoder.</summary>
			/// <param name="info">Properties of the data stream to decode.</param>
			virtual void open(const VoiceInfo& info) = 0;			
			/// <summary>If not null, the object is in invalid state.</summary>
			virtual Common::JString getError(void) const = 0;
			/// <summary>Consumes the given encoded data.</summary>
			virtual void input(const Buffer<nByte>& buf) = 0;
		};

#if EG_PHOTON_VOICE_VIDEO_ENABLE
		// Buffer for IEncoderDirect encoding images
		struct ImageInputBuf
		{
			void* buf;
			int width;
			int height;
			int* stride;
			ImageFormat::Enum imageFormat;
			Rotation::Enum rotation;
			Flip::Enum flip;
		};

		// Buffer for output actions of image decoders
		struct ImageOutputBuf
		{
			void* buf;
			int width;
			int height;
			int stride;
		};

		class IDecoderQueuedOutputImage : public IDecoder // IDecoderQueuedOutputImageNative in dotenet
		{
		public:
			virtual void setOutputImageFormat(ImageFormat::Enum) = 0;
			virtual void setOutputImageFlip(Flip::Enum) = 0;
			// if provided, decoder writes output to it
			virtual void setOutputImageBufferGetter(void*(*getter)(int, int)) = 0;
		};
#endif		
		class UnsupportedCodecError : public IEncoder, public IDecoder
		{
		public:
			UnsupportedCodecError(const Common::JString& info, int codec, const ILogger& logger);

			virtual Common::JString getError(void) const;
			virtual void open(const VoiceInfo& info);
			virtual void setOutput(void* opaque, void(*output)(void*, const Buffer<nByte>&));
			virtual Buffer<nByte> dequeueOutput(void);
			virtual void input(const Buffer<nByte>& buf);
		private:
			Common::JString mError;
		};
	}
}