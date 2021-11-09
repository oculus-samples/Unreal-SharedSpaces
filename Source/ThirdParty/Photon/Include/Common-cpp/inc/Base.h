/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/LoggingBase.h"

namespace ExitGames
{
	namespace Common
	{
		class Base : public LoggingBase<Base>
		{
		public:
			virtual ~Base(void) = 0;
		protected:
			static Logger mLogger;
		};
	}
}