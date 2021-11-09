/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
* http://www.photonengine.com
* mailto:developer@photonengine.com
*/

#pragma once

#include "Common-cpp/inc/Helpers/EndianCorrectCastImplementation.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename outtype, typename Cintype>
			outtype endianCorrectCast(Cintype in)
			{
				return reinterpret_cast<outtype>(in);
			}

			template<typename FpOuttype, typename Fintype>
			FpOuttype endianCorrectCast(Fintype* pIn)
			{
				return EndianCorrectCastImplementation<FpOuttype, Fintype, sizeof(typename RemovePointer<FpOuttype>::type)<sizeof(Fintype)>()(pIn);
			}
		}
	}
}