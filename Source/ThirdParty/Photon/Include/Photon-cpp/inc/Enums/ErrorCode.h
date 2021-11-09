/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

namespace ExitGames
{
	namespace Photon
	{
		/** Photon library error codes - can be returned as operationcode in callbacks, if the returncode indicates an error */
		namespace ErrorCode
		{
			static const int SUCCESS       =     0; ///<No error
			static const int EFAILED       =     1; ///<General failure
			static const int ENOMEMORY     =     2; ///<Out of memory
			static const int EBADCLASS     =    10; ///<NULL class object
			static const int EBADPARM      =    14; ///<Invalid parameter
			static const int EITEMBUSY     =    32; ///<Context (system, interface, etc.) is busy

			static const int NET_SUCCESS   =     0; ///<No network error, successful operation  
			static const int NET_ERROR     =    -1; ///<Unsuccessful operation
			static const int NET_ENETNONET = 0x216; ///<Network subsystem unavailable
			static const int NET_MSGSIZE   = 0x21B; ///<Message too long. A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram was smaller than the datagram itself.
			static const int NET_ENOTCONN  = 0x21C;
		}
		/** @file */
	}
}