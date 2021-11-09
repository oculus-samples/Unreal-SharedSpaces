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
		namespace Helpers
		{
			template<typename Ctype> struct IsVoid{static const bool is = false;};
			template<> struct IsVoid<void>{static const bool is = true;};
			template<> struct IsVoid<const void>{static const bool is = true;};

			/** @file */
		}
	}
}