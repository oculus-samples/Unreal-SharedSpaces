/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/VoiceInfo.h"

namespace ExitGames
{
	namespace Voice
	{    
		/// <summary>Information about a remote voice (incoming stream).</summary>
		class RemoteVoiceInfo : public Common::ToString
		{
		public:
			using ToString::toString;

			RemoteVoiceInfo(int channelId, int playerId, nByte voiceId, VoiceInfo info);

			const VoiceInfo& getInfo(void) const;
			int getChannelId(void) const;
			int getPlayerId(void) const;
			nByte getVoiceId(void) const;

			virtual Common::JString& toString(Common::JString& retStr, bool withTypes=false) const;
	private:
			int mChannelId;
			int mPlayerId;
			nByte mVoiceId;
			VoiceInfo mInfo;
		};
	}
}