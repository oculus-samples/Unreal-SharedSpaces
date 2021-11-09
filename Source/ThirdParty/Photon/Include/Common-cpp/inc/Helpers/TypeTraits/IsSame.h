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
			template<typename First, typename Second> struct IsSame{static const bool is = false;};
			template<typename First> struct IsSame<First, First>{static const bool is = true;};
		}
	}
}