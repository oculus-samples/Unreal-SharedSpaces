/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
* http://www.photonengine.com
* mailto:developer@photonengine.com
*/

#pragma once

#include "Common-cpp/inc/Helpers/TypeTraits/RemovePointer.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
#ifdef _EG_BIGENDIAN_PLATFORM
			// this won't work on architectures, where sizeof(longer integer type)%sizeof(shorter integer type) isn't 0 (which actually is allowed by the standard, but let's assume that this code won't ever run on such an exotic platform)
			template<typename CpOuttype, typename Cintype, bool bigToShort>
			class EndianCorrectCastImplementation
			{
				EndianCorrectCastImplementation(void){};
				CpOuttype operator()(Cintype* pIn){return reinterpret_cast<CpOuttype>(pIn)+sizeof(Cintype)/sizeof(RemovePointer<CpOuttype>::type)-1;}
				template<typename FpOuttype, typename Fintype> friend FpOuttype endianCorrectCast(Fintype*);
			};

			template<typename CpOuttype, typename Cintype>
			class EndianCorrectCastImplementation<CpOuttype, Cintype, false>
			{
				EndianCorrectCastImplementation(void){};
				CpOuttype operator()(Cintype* pIn){return reinterpret_cast<CpOuttype>(pIn-sizeof(RemovePointer<CpOuttype>::type)/sizeof(Cintype)+1);}
				template<typename FpOuttype, typename Fintype> friend FpOuttype endianCorrectCast(Fintype*);
			};
#else
			template<typename CpOuttype, typename Cintype, bool bigToShort>
			class EndianCorrectCastImplementation
			{
				EndianCorrectCastImplementation(void){};
				CpOuttype operator()(Cintype* pIn){return reinterpret_cast<CpOuttype>(pIn);}
				template<typename FpOuttype, typename Fintype> friend FpOuttype endianCorrectCast(Fintype*);
			};
#endif
		}
	}
}