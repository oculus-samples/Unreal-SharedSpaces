#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Punchthrough
		{
			class PunchListener
			{
			public:
				virtual ~PunchListener(void){};

				virtual void onDirectConnectionEstablished(int /*remoteID*/) {}
				virtual void onDirectConnectionFailedToEstablish(int /*remoteID*/) {}
				virtual void onReceiveDirect(const Common::JVector<nByte>& inBuf, int remoteID, bool relay) = 0;
			};
		}
	}
}