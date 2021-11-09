/* Exit Games Photon Voice - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Voice 
	{
		class ILogger
		{
		public:
			virtual ~ILogger(void) {}

			virtual void logError(const Common::JString& msg) const = 0;
			virtual void logWarning(const Common::JString& msg) const = 0;
			virtual void logInfo(const Common::JString& msg) const = 0;
			virtual void logDebug(const Common::JString& msg) const = 0;
		};
	}
}