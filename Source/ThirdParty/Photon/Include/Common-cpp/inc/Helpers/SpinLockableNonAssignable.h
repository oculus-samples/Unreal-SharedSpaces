/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/Spinlock.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename T>
			class SpinLockableNonAssignable : public T, public Spinlock
			{
			public:
				                                                                          SpinLockableNonAssignable(void)                                                                 : T(),                   Spinlock() {}
				template<typename P1>                                                     SpinLockableNonAssignable(      P1& p1)                                                         : T(p1),                 Spinlock() {}
				template<typename P1>                                                     SpinLockableNonAssignable(const P1& p1)                                                         : T(p1),                 Spinlock() {}
				template<typename P1, typename P2>                                        SpinLockableNonAssignable(      P1& p1,       P2& p2)                                           : T(p1, p2),             Spinlock() {}
				template<typename P1, typename P2>                                        SpinLockableNonAssignable(      P1& p1, const P2& p2)                                           : T(p1, p2),             Spinlock() {}
				template<typename P1, typename P2>                                        SpinLockableNonAssignable(const P1& p1,       P2& p2)                                           : T(p1, p2),             Spinlock() {}
				template<typename P1, typename P2>                                        SpinLockableNonAssignable(const P1& p1, const P2& p2)                                           : T(p1, p2),             Spinlock() {}
				template<typename P1, typename P2, typename P3>                           SpinLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3)                             : T(p1, p2, p3),         Spinlock() {}
				template<typename P1, typename P2, typename P3>                           SpinLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3)                             : T(p1, p2, p3),         Spinlock() {}
				template<typename P1, typename P2, typename P3>                           SpinLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3)                             : T(p1, p2, p3),         Spinlock() {}
				template<typename P1, typename P2, typename P3>                           SpinLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3)                             : T(p1, p2, p3),         Spinlock() {}
				template<typename P1, typename P2, typename P3>                           SpinLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3)                             : T(p1, p2, p3),         Spinlock() {}
				template<typename P1, typename P2, typename P3>                           SpinLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3)                             : T(p1, p2, p3),         Spinlock() {}
				template<typename P1, typename P2, typename P3>                           SpinLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3)                             : T(p1, p2, p3),         Spinlock() {}
				template<typename P1, typename P2, typename P3>                           SpinLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3)                             : T(p1, p2, p3),         Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4>              SpinLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1,       P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1,       P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1, const P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(      P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1,       P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1,       P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1, const P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> SpinLockableNonAssignable(const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), Spinlock() {}
				virtual ~SpinLockableNonAssignable(void) {}

				SpinLockableNonAssignable<T>(const T& toCopy) : T(toCopy), Spinlock() {}
			};
		}
	}
}