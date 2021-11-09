/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/AssociativeContainerBase.h"
#include "Common-cpp/inc/Helpers/KeyToObject.h"
#include "Common-cpp/inc/Helpers/ValueToObject.h"
#include "Common-cpp/inc/Object.h"

namespace ExitGames
{
	namespace Common
	{
		class Hashtable : public AssociativeContainerBase<Hashtable, Object>
		{
		public:
			virtual void put(const Hashtable& src);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType& val);
			template<typename FKeyType> void put(const FKeyType& key);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType pVal, typename Common::Helpers::ArrayLengthType<FValueType>::type size);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType pVal, const short* sizes);
		private:
			typedef AssociativeContainerBase<Hashtable, Object> super;

			virtual void putImplementation(const Object& key, const Object& val);
		};



		/** @copydoc AssociativeContainerBase::put(const FKeyType&,const FValueType&) */
		template<typename FKeyType, typename FValueType>
		void Hashtable::put(const FKeyType& key, const FValueType& val)
		{
			typename Helpers::ConfirmAllowedKey<FKeyType>::type forceCompilationToFailForUnsupportedKeyTypes; (void)forceCompilationToFailForUnsupportedKeyTypes;
			typename Helpers::ConfirmAllowed<FValueType>::type forceCompilationToFailForUnsupportedValueTypes; (void)forceCompilationToFailForUnsupportedValueTypes;
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Helpers::ConfirmAllowed<typename Helpers::ConfirmAllowed<FValueType>::type>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			putImplementation(Helpers::KeyToObject<Object>::get(key), Helpers::ValueToObject<Object>::get(val));
		}
		
		/**
		   @overload
		   @details
		   This overload adds an empty object as value for the provided key. */
		template<typename FKeyType>
		void Hashtable::put(const FKeyType& key)
		{
			putImplementation(Helpers::KeyToObject<Object>::get(key), Object());
		}

		/** @copydoc AssociativeContainerBase::put(const FKeyType&,FValueType,typename Common::Helpers::ArrayLengthType<FValueType>::type) */
		template<typename FKeyType, typename FValueType>
		void Hashtable::put(const FKeyType& key, const FValueType pVal, typename Common::Helpers::ArrayLengthType<FValueType>::type size)
		{
			typename Helpers::ConfirmAllowedKey<FKeyType>::type forceCompilationToFailForUnsupportedKeyTypes; (void)forceCompilationToFailForUnsupportedKeyTypes;
			typename Helpers::ConfirmAllowed<FValueType>::type forceCompilationToFailForUnsupportedValueTypes; (void)forceCompilationToFailForUnsupportedValueTypes;
			COMPILE_TIME_ASSERT2_TRUE_MSG(Helpers::ConfirmAllowed<typename Helpers::ConfirmAllowed<FValueType>::type>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			putImplementation(Helpers::KeyToObject<Object>::get(key), Helpers::ValueToObject<Object>::get(pVal, size));
		}

		/** @copydoc AssociativeContainerBase::put(const FKeyType&,FValueType,const short*) */
		template<typename FKeyType, typename FValueType>
		void Hashtable::put(const FKeyType& key, const FValueType pVal, const short* const sizes)
		{
			typename Helpers::ConfirmAllowedKey<FKeyType>::type forceCompilationToFailForUnsupportedKeyTypes; (void)forceCompilationToFailForUnsupportedKeyTypes;
			typename Helpers::ConfirmAllowed<FValueType>::type forceCompilationToFailForUnsupportedValueTypes; (void)forceCompilationToFailForUnsupportedValueTypes;
			COMPILE_TIME_ASSERT2_TRUE_MSG((bool)Helpers::ConfirmAllowed<typename Helpers::ConfirmAllowed<FValueType>::type>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_FOR_ARRAYS);
			putImplementation(Helpers::KeyToObject<Object>::get(key), Helpers::ValueToObject<Object>::get(pVal, sizes));
		}
	}
}