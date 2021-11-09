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
			template<typename Ctype> struct IsIntegral{static const bool is = false;};
			template<> struct IsIntegral<char>{static const bool is = true;};
			template<> struct IsIntegral<signed char>{static const bool is = true;};
			template<> struct IsIntegral<unsigned char>{static const bool is = true;};
			template<> struct IsIntegral<short>{static const bool is = true;};
			template<> struct IsIntegral<unsigned short>{static const bool is = true;};
			template<> struct IsIntegral<int>{static const bool is = true;};
			template<> struct IsIntegral<unsigned int>{static const bool is = true;};
			template<> struct IsIntegral<long>{static const bool is = true;};
			template<> struct IsIntegral<unsigned long>{static const bool is = true;};
			template<> struct IsIntegral<long long>{static const bool is = true;};
			template<> struct IsIntegral<unsigned long long>{static const bool is = true;};
			template<> struct IsIntegral<bool>{static const bool is = true;};
			template<> struct IsIntegral<wchar_t>{static const bool is = true;};

			/** @file */
		}
	}
}