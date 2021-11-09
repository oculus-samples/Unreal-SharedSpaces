/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/KeyObject.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename OT>
			class KeyToObject
			{
			public:
				template<typename Ftype> static OT get(const Ftype& key);
				static const OT& get(const OT& key);
				static OT get(const char* key);
				static OT get(const wchar_t* key);
			private:
				template<typename T, typename Otype> struct KO {typedef Otype type;};
				template<typename T> struct KO<T, Object> {typedef KeyObject<T> type;};
			};



			template<typename OT>
			template<typename Ftype>
			OT KeyToObject<OT>::get(const Ftype& key)
			{
				return typename KO<Ftype, OT>::type(key);
			}

			template<typename OT>
			const OT& KeyToObject<OT>::get(const OT& key)
			{
				return key;
			}

			template<typename OT>
			OT KeyToObject<OT>::get(const char* key)
			{
				return get(JString(key));
			}

			template<typename OT>
			OT KeyToObject<OT>::get(const wchar_t* key)
			{
				return get(JString(key));
			}
		}
	}
}