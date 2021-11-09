/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/MemoryManagement/Allocate.h"
#include "Common-cpp/inc/ValueObject.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename OT>
			class ValueToObject
			{
			public:
				template<typename Ftype> static OT get(const Ftype& value);
				static const OT& get(const OT& value);
				static OT get(const char* value);
				static OT get(const wchar_t* value);
				template<unsigned int N> static OT get(const char value[N]);
				template<unsigned int N> static OT get(const wchar_t value[N]);
				template<typename Ftype> static OT get(Ftype* pValue, typename Common::Helpers::ArrayLengthType<Ftype*>::type size);
				static OT get(char** pValue, short size);
				static OT get(const char** pValue, short size);
				static OT get(wchar_t** pValue, short size);
				static OT get(const wchar_t** pValue, short size);
				template<typename Ftype> static OT get(Ftype** pValue, const short* sizes);
			private:
				template<typename Ftype> static OT stringArrayHelper(Ftype** pValue, short size);

				template<typename T, typename Otype> struct VO {typedef Otype type;};
				template<typename T> struct VO<T, Object> {typedef ValueObject<T> type;};
			};



			template<typename OT>
			template<typename Ftype>
			OT ValueToObject<OT>::get(const Ftype& value)
			{
				return typename VO<Ftype, OT>::type(value);
			}

			template<typename OT>
			const OT& ValueToObject<OT>::get(const OT& value)
			{
				return value;
			}

			template<typename OT>
			OT ValueToObject<OT>::get(const char* value)
			{
				return get(JString(value));
			}

			template<typename OT>
			OT ValueToObject<OT>::get(const wchar_t* value)
			{
				return get(JString(value));
			}

			template<typename OT>
			template<unsigned int N>
			OT ValueToObject<OT>::get(const char value[N])
			{
				return get(JString(value));
			}

			template<typename OT>
			template<unsigned int N>
			OT ValueToObject<OT>::get(const wchar_t value[N])
			{
				return get(JString(value));
			}

			template<typename OT>
			template<typename Ftype>
			OT ValueToObject<OT>::get(Ftype* pValue, typename Common::Helpers::ArrayLengthType<Ftype*>::type size)
			{
				return typename VO<Ftype*, OT>::type(pValue, size);
			}

			template<typename OT>
			OT ValueToObject<OT>::get(char** pValue, short size)
			{
				return stringArrayHelper(pValue, size);
			}

			template<typename OT>
			OT ValueToObject<OT>::get(const char** pValue, short size)
			{
				return stringArrayHelper(pValue, size);
			}

			template<typename OT>
			OT ValueToObject<OT>::get(wchar_t** pValue, short size)
			{
				return stringArrayHelper(pValue, size);
			}

			template<typename OT>
			OT ValueToObject<OT>::get(const wchar_t** pValue, short size)
			{
				return stringArrayHelper(pValue, size);
			}

			template<typename OT>
			template<typename Ftype>
			OT ValueToObject<OT>::get(Ftype** pValue, const short* sizes)
			{
				return typename VO<Ftype**, OT>::type(pValue, sizes);
			}

			template<typename OT>
			template<typename Ftype>
			OT ValueToObject<OT>::stringArrayHelper(Ftype** pValue, short size)
			{
				JString* pArr = MemoryManagement::allocateArray<JString>(size);
				for(short i=0; i<size; ++i)
					pArr[i] = pValue[i];
				OT retVal = VO<JString*, OT>::type(pArr, size);
				MemoryManagement::deallocateArray(pArr);
				return retVal;
			}
		}
	}
}