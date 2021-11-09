#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Photon
	{
		namespace Punchthrough
		{
			class RelayClient
			{
			public:
				virtual ~RelayClient(void){};

				virtual int getLocalID(void) = 0;
				virtual bool sendRelay(const Common::JVector<nByte>& buffer, const Common::JVector<int>& targetIDs) = 0;
			};
		}
	}
}