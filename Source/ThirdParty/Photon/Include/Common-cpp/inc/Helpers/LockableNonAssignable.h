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
			class LockableNonAssignable : public T, public std::mutex
			{
			public:
				                                                                          LockableNonAssignable(void)                                                                 : T(),                   std::mutex() {}
				template<typename P1>                                                     LockableNonAssignable(      P1& p1)                                                         : T(p1),                 std::mutex() {}
				template<typename P1>                                                     LockableNonAssignable(const P1& p1)                                                         : T(p1),                 std::mutex() {}
				template<typename P1, typename P2>                                        LockableNonAssignable(      P1& p1,       P2& p2)                                           : T(p1, p2),             std::mutex() {}
				template<typename P1, typename P2>                                        LockableNonAssignable(      P1& p1, const P2& p2)                                           : T(p1, p2),             std::mutex() {}
				template<typename P1, typename P2>                                        LockableNonAssignable(const P1& p1,       P2& p2)                                           : T(p1, p2),             std::mutex() {}
				template<typename P1, typename P2>                                        LockableNonAssignable(const P1& p1, const P2& p2)                                           : T(p1, p2),             std::mutex() {}
				template<typename P1, typename P2, typename P3>                           LockableNonAssignable(      P1& p1,       P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           LockableNonAssignable(      P1& p1,       P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           LockableNonAssignable(      P1& p1, const P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           LockableNonAssignable(      P1& p1, const P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           LockableNonAssignable(const P1& p1,       P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           LockableNonAssignable(const P1& p1,       P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           LockableNonAssignable(const P1& p1, const P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           LockableNonAssignable(const P1& p1, const P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(      P1& p1,       P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(      P1& p1,       P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(      P1& p1,       P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(      P1& p1,       P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(      P1& p1, const P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(      P1& p1, const P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(      P1& p1, const P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(      P1& p1, const P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(const P1& p1,       P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(const P1& p1,       P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(const P1& p1,       P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(const P1& p1,       P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(const P1& p1, const P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(const P1& p1, const P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(const P1& p1, const P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              LockableNonAssignable(const P1& p1, const P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1,       P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1,       P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1,       P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1,       P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1,       P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1,       P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1,       P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1,       P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1, const P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1, const P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1, const P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1, const P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1, const P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1, const P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1, const P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(      P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1,       P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1,       P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1,       P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1,       P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1,       P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1,       P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1,       P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1,       P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1, const P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1, const P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1, const P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1, const P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1, const P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1, const P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1, const P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> LockableNonAssignable(const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				virtual ~LockableNonAssignable(void) {}

				LockableNonAssignable<T>(const T& toCopy) : T(toCopy), std::mutex() {}
			};
		}
	}
}
#endif