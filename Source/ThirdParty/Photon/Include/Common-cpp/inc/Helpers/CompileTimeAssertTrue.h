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
			template<bool> struct CompileTimeAssertTrue;
			template<> struct CompileTimeAssertTrue<true> {};
		}
	}
}

#undef COMPILE_TIME_ASSERT_TRUE

#define COMPILE_TIME_ASSERT_TRUE(expr) ExitGames::Common::Helpers::CompileTimeAssertTrue<expr> ASSERTION_FAILED
#define COMPILE_TIME_ASSERT_TRUE_MSG(expr, msg) ExitGames::Common::Helpers::CompileTimeAssertTrue<expr> ASSERTION_FAILED_##msg
#define COMPILE_TIME_ASSERT2_TRUE(expr) {ExitGames::Common::Helpers::CompileTimeAssertTrue<expr> ASSERTION_FAILED; (void)ASSERTION_FAILED;}
#define COMPILE_TIME_ASSERT2_TRUE_MSG(expr, msg) {ExitGames::Common::Helpers::CompileTimeAssertTrue<expr> ASSERTION_FAILED_##msg; (void)ASSERTION_FAILED_##msg;}