/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Photon-cpp/inc/PhotonPeer.h"

namespace ExitGames
{
	namespace LoadBalancing
	{
		namespace Internal
		{
			namespace EncryptionMode
			{
				static const nByte USER_DATA_ENCRYPTION_NO_DIFFIE_HELLMAN     =  0;
				static const nByte UDP_TRAFFIC_ENCRYPTION_RANDOM_SEQUENCE_CBC = 11; // deprecated
				static const nByte UDP_TRAFFIC_ENCRYPTION_RANDOM_SEQUENCE_GCM = 13;
				static const nByte UDP_TRAFFIC_ENCRYPTION_RANDOM_SEQUENCE_DEFAULT = EG_CHAINING_MODE_CBC_GCM(UDP_TRAFFIC_ENCRYPTION_RANDOM_SEQUENCE_CBC, UDP_TRAFFIC_ENCRYPTION_RANDOM_SEQUENCE_GCM);
			}
		}
	}
}