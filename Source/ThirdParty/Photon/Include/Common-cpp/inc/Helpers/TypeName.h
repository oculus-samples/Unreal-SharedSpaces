/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

// clang rtti
#if defined __clang__
#	if !defined __GXX_RTTI && __has_feature(cxx_rtti)
#		define __GXX_RTTI 1
#	endif
#endif

// msvc rtti || gcc rtti || gcc version from a time, when it hasn't offered an rtti define ( == llvm gcc frontend for Marmalade OS X x86 builds!)
#if defined _CPPRTTI || defined __GXX_RTTI
#	include <typeinfo>
#	define TYPENAME(arg) cut((typeid(arg).name()))
// else assume rtti to be disabled
#else
#	define TYPENAME(arg) ("?")
#endif

#include "Common-cpp/inc/JString.h"

#if !defined _EG_MICROSOFT_PLATFORM && !defined _EG_MARMALADE_PLATFORM && !defined _EG_ANDROID_PLATFORM && !defined _EG_BLACKBERRY_PLATFORM && !defined _EG_SONY_PLATFORM && !defined _EG_EMSCRIPTEN_PLATFORM && !defined _EG_SWITCH_WINDOWS_PLATFORM
#	include <cxxabi.h>
#elif defined _EG_MARMALADE_PLATFORM && (defined __GNUC__ && !defined I3D_ARCH_MIPS && !defined S3E_ANDROID_X86) || defined _EG_BLACKBERRY_PLATFORM
	namespace abi
	{
		extern "C" char* __cxa_demangle(const char* mangled_name, char* buf, size_t* n, int* status);
	}
#endif

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			namespace TypeName
			{
				template<typename Etype> JString get(void);
				template<typename Etype> JString get(Etype& arg);
				template<typename Etype> JString get(Etype* pArg);
				JString cut(const char* rawTypeName);
			}



			template<typename Etype>
			JString TypeName::get(void)
			{
				return JString(TYPENAME(Etype));
			}

			template<typename Etype>
			JString TypeName::get(Etype& arg)
			{
				return JString(TYPENAME(arg));
			}

			template<typename Etype>
			JString TypeName::get(Etype* pArg)
			{
				return JString(TYPENAME(*pArg));
			}
		}
	}
}