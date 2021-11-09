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
			class Lockable : public T, public std::mutex
			{
			public:
				using T::operator=;

				                                                                          Lockable(void)                                                                 : T(),                   std::mutex() {}
				template<typename P1>                                                     Lockable(      P1& p1)                                                         : T(p1),                 std::mutex() {}
				template<typename P1>                                                     Lockable(const P1& p1)                                                         : T(p1),                 std::mutex() {}
				template<typename P1, typename P2>                                        Lockable(      P1& p1,       P2& p2)                                           : T(p1, p2),             std::mutex() {}
				template<typename P1, typename P2>                                        Lockable(      P1& p1, const P2& p2)                                           : T(p1, p2),             std::mutex() {}
				template<typename P1, typename P2>                                        Lockable(const P1& p1,       P2& p2)                                           : T(p1, p2),             std::mutex() {}
				template<typename P1, typename P2>                                        Lockable(const P1& p1, const P2& p2)                                           : T(p1, p2),             std::mutex() {}
				template<typename P1, typename P2, typename P3>                           Lockable(      P1& p1,       P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           Lockable(      P1& p1,       P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           Lockable(      P1& p1, const P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           Lockable(      P1& p1, const P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           Lockable(const P1& p1,       P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           Lockable(const P1& p1,       P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           Lockable(const P1& p1, const P2& p2,       P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3>                           Lockable(const P1& p1, const P2& p2, const P3& p3)                             : T(p1, p2, p3),         std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(      P1& p1,       P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(      P1& p1,       P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(      P1& p1,       P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(      P1& p1,       P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(      P1& p1, const P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(      P1& p1, const P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(      P1& p1, const P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(      P1& p1, const P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(const P1& p1,       P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(const P1& p1,       P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(const P1& p1,       P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(const P1& p1,       P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(const P1& p1, const P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(const P1& p1, const P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(const P1& p1, const P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4>              Lockable(const P1& p1, const P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1,       P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1,       P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1,       P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1,       P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1,       P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1,       P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1,       P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1,       P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1, const P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1, const P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1, const P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1, const P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1, const P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1, const P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1, const P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(      P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1,       P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1,       P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1,       P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1,       P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1,       P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1,       P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1,       P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1,       P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1, const P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1, const P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1, const P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1, const P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1, const P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1, const P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1, const P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Lockable(const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), std::mutex() {}
				virtual ~Lockable(void) {}

				Lockable<T>(const T& toCopy) : T(toCopy), std::mutex() {}

				virtual Lockable<T>& operator=(const T& toCopy);
			};



			template<typename T>
			Lockable<T>& Lockable<T>::operator=(const T& toCopy)
			{
				T::operator=(toCopy);
				return *this;
			}
		}
	}
}
#endif