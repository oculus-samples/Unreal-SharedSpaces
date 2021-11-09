/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/defines.h"
#ifdef EG_PLATFORM_SUPPORTS_CPP11
#	include <mutex>

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename T>
			class RecursivelyLockableNonAssignable : public T, public std::recursive_mutex
			{
			public:
				RecursivelyLockableNonAssignable(void)                                                                 : T(),                   std::recursive_mutex() {}
				template<typename P1>                                                     RecursivelyLockableNonAssignable(      P1& p1)                                                         : T(p1),                 std::recursive_mutex() {}
				template<typename P1>                                                     RecursivelyLockableNonAssignable(const P1& p1)                                                         : T(p1),                 std::recursive_mutex() {}
				template<typename P1, typename P2>                                        RecursivelyLockableNonAssignable(      P1& p1,       P2& p2)                                           : T(p1, p2),             std::recursive_mutex() {}
				template<typename P1, typename P2>                                        RecursivelyLockableNonAssignable(      P1& p1, const P2& p2)                                           : T(p1, p2),             std::recursive_mutex() {}
				template<typename P1, typename P2>                                        RecursivelyLockableNonAssignable(const P1& p1,       P2& p2)                                           : T(p1, p2),             std::recursive_mutex() {}
				template<typename P1, typename P2>                                        RecursivelyLockableNonAssignable(const P1& p1, const P2& p2)                                           : T(p1, p2),             std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3>                           RecursivelyLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3>                           RecursivelyLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3>                           RecursivelyLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3>                           RecursivelyLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3>                           RecursivelyLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3>                           RecursivelyLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3>                           RecursivelyLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3>                           RecursivelyLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              RecursivelyLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> RecursivelyLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::recursive_mutex() {}
				virtual ~RecursivelyLockableNonAssignable(void) {}

				RecursivelyLockableNonAssignable<T>(const T& toCopy) : T(toCopy), std::recursive_mutex() {}
			};
		}
	}
}
#endif