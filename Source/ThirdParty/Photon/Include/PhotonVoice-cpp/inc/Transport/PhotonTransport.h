/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "PhotonVoice-cpp/inc/Buffer.h"
#include "PhotonVoice-cpp/inc/VoiceInfo.h"

namespace ExitGames
{
	namespace Voice
	{
		class VoiceClient;
		class LocalVoice;
		class ILogger;

		// Photon transports basic support
		class PhotonTransportProtocol
		{
		public:
			PhotonTransportProtocol(const ILogger& logger);
			virtual ~PhotonTransportProtocol(void);

			Common::ValueObject<Common::Object*> buildVoicesInfo(const Common::JVector<const LocalVoice*>& voicesToSend, bool logInfo) const;
			Common::ValueObject<Common::Object*> buildVoiceRemoveMessage(const LocalVoice& v) const;
			Common::ValueObject<Common::Object*> buildFrameMessage(nByte voiceId, nByte evNumber, Buffer<nByte> data);
			void onVoiceEvent(VoiceClient& voiceClient, const Common::Object& content, int channelId, int playerId, int localPlayerId);
		private:
			void onVoiceInfo(VoiceClient& voiceClient, int channelId, int playerId, const Common::Object& payload);
			void onVoiceRemove(VoiceClient& voiceClient, int channelId, int playerId, const Common::Object& payload);
			VoiceInfo createVoiceInfoFromEventPayload(const Common::Dictionary<nByte, Common::Object>& h);

			const ILogger& mLogger;
		};
	}
}