/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

namespace ExitGames
{
	namespace Common
	{
			/** Amount of DebugReturn callbacks. Each debug level includes output for lower ones: OFF, ERRORS, WARNINGS, INFO, ALL. */
		namespace DebugLevel
		{
			static const int OFF      = 0; ///<No debug out.
			static const int ERRORS   = 1; ///<Only error descriptions.
			static const int WARNINGS = 2; ///<Warnings and errors.
			static const int INFO     = 3; ///<Information about internal workflows, warnings and errors.
			static const int ALL      = 4; ///<Most complete workflow description (but lots of debug output), info, warnings and errors.
		}
		/** @file */
	}
}