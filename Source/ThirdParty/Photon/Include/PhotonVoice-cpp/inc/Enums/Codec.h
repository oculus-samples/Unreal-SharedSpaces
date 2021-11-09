/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"
#include "PhotonVoice-cpp/inc/defines.h"

namespace ExitGames
{
	namespace Voice
	{
		/// <summary>Enum for Media Codecs supported by PhotonVoice.</summary>
		/// <remarks>Transmitted in <see cref="VoiceInfo"></see>. Do not change the values of this Enum!</remarks>
		namespace Codec
		{
			/// <summary>OPUS audio</summary>
			static const int AUDIO_OPUS = 11;
#if EG_PHOTON_VOICE_VIDEO_ENABLE
			static const int VIDEO_VP8 = 21;
			static const int List[] = {AUDIO_OPUS, VIDEO_VP8};
#else 
			static const int List[] = {AUDIO_OPUS};
#endif
			inline size_t count(void)
			{
				return sizeof(List)/sizeof(int);
			}
		}
	}
}