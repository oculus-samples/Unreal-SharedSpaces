/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/ToString.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename T>
			class Stringifyable : public T, public ToString
			{
			public:
				using T::operator=;
				using ToString::toString;

				                                                                          Stringifyable(void)                                                                 : T(),                   ToString() {}
				template<typename P1>                                                     Stringifyable(      P1& p1)                                                         : T(p1),                 ToString() {}
				template<typename P1>                                                     Stringifyable(const P1& p1)                                                         : T(p1),                 ToString() {}
				template<typename P1, typename P2>                                        Stringifyable(      P1& p1,       P2& p2)                                           : T(p1, p2),             ToString() {}
				template<typename P1, typename P2>                                        Stringifyable(      P1& p1, const P2& p2)                                           : T(p1, p2),             ToString() {}
				template<typename P1, typename P2>                                        Stringifyable(const P1& p1,       P2& p2)                                           : T(p1, p2),             ToString() {}
				template<typename P1, typename P2>                                        Stringifyable(const P1& p1, const P2& p2)                                           : T(p1, p2),             ToString() {}
				template<typename P1, typename P2, typename P3>                           Stringifyable(      P1& p1,       P2& p2,       P3& p3)                             : T(p1, p2, p3),         ToString() {}
				template<typename P1, typename P2, typename P3>                           Stringifyable(      P1& p1,       P2& p2, const P3& p3)                             : T(p1, p2, p3),         ToString() {}
				template<typename P1, typename P2, typename P3>                           Stringifyable(      P1& p1, const P2& p2,       P3& p3)                             : T(p1, p2, p3),         ToString() {}
				template<typename P1, typename P2, typename P3>                           Stringifyable(      P1& p1, const P2& p2, const P3& p3)                             : T(p1, p2, p3),         ToString() {}
				template<typename P1, typename P2, typename P3>                           Stringifyable(const P1& p1,       P2& p2,       P3& p3)                             : T(p1, p2, p3),         ToString() {}
				template<typename P1, typename P2, typename P3>                           Stringifyable(const P1& p1,       P2& p2, const P3& p3)                             : T(p1, p2, p3),         ToString() {}
				template<typename P1, typename P2, typename P3>                           Stringifyable(const P1& p1, const P2& p2,       P3& p3)                             : T(p1, p2, p3),         ToString() {}
				template<typename P1, typename P2, typename P3>                           Stringifyable(const P1& p1, const P2& p2, const P3& p3)                             : T(p1, p2, p3),         ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(      P1& p1,       P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(      P1& p1,       P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(      P1& p1,       P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(      P1& p1,       P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(      P1& p1, const P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(      P1& p1, const P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(      P1& p1, const P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(      P1& p1, const P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(const P1& p1,       P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(const P1& p1,       P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(const P1& p1,       P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(const P1& p1,       P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(const P1& p1, const P2& p2,       P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(const P1& p1, const P2& p2,       P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(const P1& p1, const P2& p2, const P3& p3,       P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4>              Stringifyable(const P1& p1, const P2& p2, const P3& p3, const P4& p4)               : T(p1, p2, p3, p4),     ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1,       P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1,       P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1,       P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1,       P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1,       P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1,       P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1,       P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1,       P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1, const P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1, const P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1, const P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1, const P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1, const P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1, const P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1, const P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(      P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1,       P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1,       P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1,       P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1,       P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1,       P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1,       P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1,       P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1,       P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1, const P2& p2,       P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1, const P2& p2,       P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1, const P2& p2,       P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1, const P2& p2,       P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1, const P2& p2, const P3& p3,       P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1, const P2& p2, const P3& p3,       P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1, const P2& p2, const P3& p3, const P4& p4,       P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				template<typename P1, typename P2, typename P3, typename P4, typename P5> Stringifyable(const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5) : T(p1, p2, p3, p4, p5), ToString() {}
				virtual ~Stringifyable(void) {}

				Stringifyable<T>(const T& toCopy) : T(toCopy), ToString(toCopy) {}
				virtual Stringifyable<T>& operator=(const T& toCopy);

				virtual JString& toString(JString& retStr, bool withTypes=false) const;
			};

			template<typename T>
			Stringifyable<T>& Stringifyable<T>::operator=(const T& toCopy)
			{
				T::operator=(toCopy);
				return *this;
			}

			template<typename T>
			JString& Stringifyable<T>::toString(JString& retStr, bool /*withTypes*/) const
			{
				return retStr += L"{" + TypeName::get(static_cast<const T*>(this)) + L"}";
			}
		}
	}
}