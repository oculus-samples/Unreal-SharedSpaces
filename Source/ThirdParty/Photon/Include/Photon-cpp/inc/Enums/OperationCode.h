/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2012 by Exit Games. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Lite
	{
		namespace OperationCode
		{
			static const nByte JOIN          = 255;
			static const nByte LEAVE         = 254;
			static const nByte RAISE_EV      = 253;
			static const nByte SETPROPERTIES = 252;
			static const nByte GETPROPERTIES = 251;
			static const nByte CHANGE_GROUPS = 248;
		}
		/** @file */
	}
}