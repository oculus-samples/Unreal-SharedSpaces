/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Enums/DebugLevel.h"
#include "Common-cpp/inc/JString.h"

namespace ExitGames
{
	namespace Common
	{
		class BaseListener
		{
		public:
			virtual ~BaseListener() {};
			virtual void debugReturn(int debugLevel, const JString& string) = 0;
		};

		/** @file */

		/** @class BaseListener
			This class defines the listener interface for the debug
			callback mechanism.
			@sa
			Base, Base::setListener()                                     */

			/** @fn BaseListener::debugReturn(int debugLevel, const JString& string)
				This is the callback function for debug-messages.
				@param debugLevel one of the values in DebugLevel
				@param string the formatted debug string
				@sa
				BaseListener                                          */
	}
}