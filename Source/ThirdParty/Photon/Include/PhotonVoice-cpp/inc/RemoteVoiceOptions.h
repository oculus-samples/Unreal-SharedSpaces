/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/VoiceCodec.h"

namespace ExitGames
{
	namespace Voice
	{
		class LocalVoice;
		class VoiceClient;
		class IEncoder;
		class IDecoder;

		/// <summary>Event Actions and other options for a remote voice (incoming stream).</summary>
		class RemoteVoiceOptions : public Common::ToString
		{
		public:
			using ToString::toString;

			RemoteVoiceOptions(void);

			void setRemoteVoiceRemoveAction(void* opaque, void(*action)(void*));
			void setOutput(void* opaque, void(*output)(void*, const Buffer<float>&));
			void setOutput(void* opaque, void(*output)(void*, const Buffer<short>&));
#if EG_PHOTON_VOICE_VIDEO_ENABLE
			void setOutput(void* opaque, void(*output)(void*, const ImageOutputBuf&));

			void setOutputImageFormat(ImageFormat::Enum);
			void setOutputImageFlip(Flip::Enum);
#endif
			void setDecoder(Common::Helpers::SharedPointer<IDecoder> decoder);

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
		private:
			void* mpRemoteVoiceRemoveActionOpaque;
			void(*mpRemoteVoiceRemoveAction)(void*);
			struct OutputType { enum Enum { None, Float, Short, Image }; }; 
			OutputType::Enum mOutputType;
			void* mpOutputOpaque;
			union Output
			{
				Output(void) : mpFloatOutput(NULL){}
				void(*mpFloatOutput)(void*, const Buffer<float>&);
				void(*mpShortOutput)(void*, const Buffer<short>&);
#if EG_PHOTON_VOICE_VIDEO_ENABLE
				void(*mpImageOutput)(void*, const ImageOutputBuf&);
#endif
			} mOutput;

#if EG_PHOTON_VOICE_VIDEO_ENABLE
			ImageFormat::Enum mOutputImageFormat;
			Flip::Enum mOutputImageFlip;
#endif
			Common::Helpers::SharedPointer<IDecoder> mspDecoder;

			friend class RemoteVoice;
		};
	}
}