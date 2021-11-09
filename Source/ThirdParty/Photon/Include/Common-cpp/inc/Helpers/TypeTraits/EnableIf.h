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
			template<bool B, typename T=void> struct EnableIf
			{
			};

			template<typename T> struct EnableIf<true, T>
			{
				typedef T type;
			};
		}
	}
}