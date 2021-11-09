/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/SerializerImplementation.h"

namespace ExitGames
{
	namespace Common
	{
		class Serializer : public Base
		{
		public:
			using ToString::toString;

			const nByte* getData(void) const;
			int getSize(void) const;

			template<typename T> bool push(const T& data);
			template<typename T> bool push(const T pData, typename Helpers::ArrayLengthType<T>::type arraySize);
			template<typename T> bool push(const T pData, const short* arraySizes);

			virtual JString& toString(JString& retStr, bool withTypes=false) const;
		private:
			Helpers::SerializerImplementation mImp;
		};



		/**
		   Adds a serialized representation of parameter data to the Serializer-instance on which it is called.
		   @tparam T type of parameter data - has to be of one of the @link Datatypes supported datatypes\endlink
		   @param data data to serialize
		   @returns true if successful, false in case of an error */
		template<typename T>
		bool Serializer::push(const T& data)
		{
			typename Helpers::ConfirmAllowed<T>::type forceCompilationToFailForUnsupportedTypes; (void)forceCompilationToFailForUnsupportedTypes;
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Helpers::ConfirmAllowed<typename Helpers::ConfirmAllowed<T>::type>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			Object obj = Helpers::ValueToObject<Object>::get(data);
			return mImp.pushObject(&obj, true);
		}
		
		/**
		   @overload
		   @details
		   This overload accepts singledimensional arrays and NULL-pointers passed for parameter pData.
		   @param pData array of data to serialize
		   @param arraySize the size of the value array */
		template<typename T>
		bool Serializer::push(const T pData, typename Helpers::ArrayLengthType<T>::type arraySize)
		{
			typename Helpers::ConfirmAllowed<T>::type forceCompilationToFailForUnsupportedTypes; (void)forceCompilationToFailForUnsupportedTypes;
			COMPILE_TIME_ASSERT2_TRUE_MSG(Helpers::ConfirmAllowed<typename Helpers::ConfirmAllowed<T>::type>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			Object obj = Helpers::ValueToObject<Object>::get(pData, arraySize);
			return mImp.pushObject(&obj, true);
		}
		
		/**
		   @overload
		   @details
		   This overload accepts multidimensional arrays and NULL-pointers passed for parameter val.
		   The array, passed for parameter pData has to be a pointer of the correct abstraction level, meaning a normal pointer for
		   a singledimensional array, a doublepointer for a twodimensional array, a triplepointer for a threedimensional array and so on.
		   @param pData array of data to serialize
		   @param arraySizes the sizes for every dimension of the array  */
		template<typename T>
		bool Serializer::push(const T pData, const short* arraySizes)
		{
			typename Helpers::ConfirmAllowed<T>::type forceCompilationToFailForUnsupportedTypes; (void)forceCompilationToFailForUnsupportedTypes;
			COMPILE_TIME_ASSERT2_TRUE_MSG((bool)Helpers::ConfirmAllowed<typename Helpers::ConfirmAllowed<T>::type>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_FOR_ARRAYS);
			Object obj = Helpers::ValueToObject<Object>::get(pData, arraySizes);
			return mImp.pushObject(&obj, true);
		}
	}
}