/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/GenericAssociativeContainerBase.h"
#include "Common-cpp/inc/Containers/JHashtable.h"

namespace ExitGames
{
	namespace Common
	{
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		class GenericAssociativeContainer : public GenericAssociativeContainerBase<T<EKeyType, EValueType>, JHashtable, JObject>
		{
		private:
			typedef GenericAssociativeContainerBase<T<EKeyType, EValueType>, JHashtable, JObject> super;
		public:
			virtual ~GenericAssociativeContainer(void) = 0;

			virtual GenericAssociativeContainer<T, EKeyType, EValueType>& operator=(const GenericAssociativeContainer<T, EKeyType, EValueType>& toCopy);
			template<template<typename, typename> class FT> GenericAssociativeContainer<T, EKeyType, EValueType>& operator=(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy);

			virtual bool operator==(const T<EKeyType, EValueType>& toCompare) const;
			virtual bool operator!=(const T<EKeyType, EValueType>& toCompare) const;
			virtual const EValueType& operator[](unsigned int index) const;
			virtual const EValueType& operator[](int index) const;
			virtual EValueType& operator[](unsigned int index);
			virtual EValueType& operator[](int index);

			virtual void put(const T<EKeyType, EValueType>& src);
			template<template<typename, typename> class FT> void put(const GenericAssociativeContainer<FT, EKeyType, EValueType>& src);
			void put(const EKeyType& key, const EValueType& val);
			void put(const EKeyType& key, const EValueType pVal, typename Common::Helpers::ArrayLengthType<EValueType>::type size);
			void put(const EKeyType& key, const EValueType pVal, const short* sizes);
			virtual void remove(const EKeyType& key);
			virtual bool contains(const EKeyType& key) const;

			virtual const EValueType* getValue(const EKeyType& key) const;
			virtual EValueType* getValue(const EKeyType& key);
			virtual JVector<EKeyType> getKeys(void) const;
		protected:
			GenericAssociativeContainer(void);

			template<template<typename, typename> class FT> GenericAssociativeContainer(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy);
		private:
			template<typename FKeyType, typename FValueType> const FValueType* getValueImplementation(const FKeyType& key, const FValueType* pDummyDeducer) const;
			template<typename FKeyType, typename FValueType> FValueType* getValueImplementation(const FKeyType& key, const FValueType* pDummyDeducer);
			template<typename FKeyType> JVector<FKeyType> getKeysImplementation(const FKeyType* pDummyDeducer) const;
			template<typename FValueType> const FValueType& getValueAtImplementation(unsigned int index, const FValueType* pDummyDeducer) const;
			template<typename FValueType> FValueType& getValueAtImplementation(unsigned int index, const FValueType* pDummyDeducer);

			virtual bool compare(const T<EKeyType, EValueType>& toCompare) const;
			virtual T<EKeyType, EValueType>* copy(short amount) const;

			friend super;
		};



		/** @file */

		/** @copydoc DictionaryBase::DictionaryBase(void) */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		GenericAssociativeContainer<T, EKeyType, EValueType>::GenericAssociativeContainer(void) : super()
		{
		}

		/** @copydoc ExitGames::Common::DictionaryBase::~DictionaryBase(void) */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		GenericAssociativeContainer<T, EKeyType, EValueType>::~GenericAssociativeContainer(void)
		{
		}

		/** @copydoc DictionaryBase::DictionaryBase(const DictionaryBase&) */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		template<template<typename, typename> class FT>
		GenericAssociativeContainer<T, EKeyType, EValueType>::GenericAssociativeContainer(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy) : super(toCopy)
		{
		}

		/** @copydoc DictionaryBase::operator=() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		GenericAssociativeContainer<T, EKeyType, EValueType>& GenericAssociativeContainer<T, EKeyType, EValueType>::operator=(const GenericAssociativeContainer<T, EKeyType, EValueType>& toCopy)
		{
			return static_cast<T<EKeyType, EValueType>&>(*this) = static_cast<const T<EKeyType, EValueType>&>(toCopy);
		}

		/** @copydoc ExitGames::Common::DictionaryBase::operator=() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		template<template<typename, typename> class FT>
		GenericAssociativeContainer<T, EKeyType, EValueType>& GenericAssociativeContainer<T, EKeyType, EValueType>::operator=(const GenericAssociativeContainer<FT, EKeyType, EValueType>& toCopy)
		{
			return static_cast<T<EKeyType, EValueType>&>(*this) = FT<EKeyType, EValueType>(toCopy);
		}

		/** @copydoc DictionaryBase::operator==() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		bool GenericAssociativeContainer<T, EKeyType, EValueType>::operator==(const T<EKeyType, EValueType>& toCompare) const
		{
			return this->compare(toCompare);
		}

		/** @copydoc DictionaryBase::operator!=() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		bool GenericAssociativeContainer<T, EKeyType, EValueType>::operator!=(const T<EKeyType, EValueType>& toCompare) const
		{
			return !this->compare(toCompare);
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::operator[]() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		const EValueType& GenericAssociativeContainer<T, EKeyType, EValueType>::operator[](unsigned int index) const
		{
			return GenericAssociativeContainer<T, EKeyType, EValueType>::getValueAt(index, reinterpret_cast<EValueType*>(NULL));
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::operator[]() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		const EValueType& GenericAssociativeContainer<T, EKeyType, EValueType>::operator[](int index) const
		{
			return GenericAssociativeContainer<T, EKeyType, EValueType>::getValueAt(index, reinterpret_cast<EValueType*>(NULL));
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::operator[]() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		EValueType& GenericAssociativeContainer<T, EKeyType, EValueType>::operator[](unsigned int index)
		{
			return GenericAssociativeContainer<T, EKeyType, EValueType>::getValueAt(index, reinterpret_cast<EValueType*>(NULL));
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::operator[]() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		EValueType& GenericAssociativeContainer<T, EKeyType, EValueType>::operator[](int index)
		{
			return GenericAssociativeContainer<T, EKeyType, EValueType>::getValueAt(index, reinterpret_cast<EValueType*>(NULL));
		}

		/** @copydoc ExitGames::Common::Hashtable::put(const Hashtable&) */ //NOTE: the "ExitGames::Common" part is needed here, as otherwise doxygen, although still actually finding the copydoc target, throws a warning about not being able to find it
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		void GenericAssociativeContainer<T, EKeyType, EValueType>::put(const T<EKeyType, EValueType>& src)
		{
			super::put(src);
		}

		/** @overload */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		template<template<typename, typename> class FT>
		void GenericAssociativeContainer<T, EKeyType, EValueType>::put(const GenericAssociativeContainer<FT, EKeyType, EValueType>& src)
		{
			this->mHashtable.put(src.getHashtable());
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::put(const FKeyType&,const FValueType&) */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		void GenericAssociativeContainer<T, EKeyType, EValueType>::put(const EKeyType& key, const EValueType& val)
		{
			super::put(key, val);
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::put(const FKeyType&,FValueType,typename Common::Helpers::ArrayLengthType<FValueType>::type) */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		void GenericAssociativeContainer<T, EKeyType, EValueType>::put(const EKeyType& key, const EValueType pVal, typename Common::Helpers::ArrayLengthType<EValueType>::type size)
		{
			super::put(key, pVal, size);
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::put(const FKeyType&,FValueType,const short*) */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		void GenericAssociativeContainer<T, EKeyType, EValueType>::put(const EKeyType& key, const EValueType pVal, const short* const sizes)
		{
			super::put(key, pVal, sizes);
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::getValue() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		const EValueType* GenericAssociativeContainer<T, EKeyType, EValueType>::getValue(const EKeyType& key) const
		{
			return super::getValue(key, reinterpret_cast<EValueType*>(NULL));
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::getValue() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		EValueType* GenericAssociativeContainer<T, EKeyType, EValueType>::getValue(const EKeyType& key)
		{
			return super::getValue(key, reinterpret_cast<EValueType*>(NULL));
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::getKeys() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		JVector<EKeyType> GenericAssociativeContainer<T, EKeyType, EValueType>::getKeys(void) const
		{
			return super::getKeys(reinterpret_cast<EKeyType*>(NULL));
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::remove() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		void GenericAssociativeContainer<T, EKeyType, EValueType>::remove(const EKeyType& key)
		{
			super::remove(key);
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::contains() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		bool GenericAssociativeContainer<T, EKeyType, EValueType>::contains(const EKeyType& key) const
		{
			return super::contains(key);
		}

		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		bool GenericAssociativeContainer<T, EKeyType, EValueType>::compare(const T<EKeyType, EValueType>& toCompare) const
		{
			return this->getHashtable() == toCompare.getHashtable();
		}

		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		T<EKeyType, EValueType>* GenericAssociativeContainer<T, EKeyType, EValueType>::copy(short amount) const
		{
			T<EKeyType, EValueType>* pRetVal = MemoryManagement::allocateArray<T<EKeyType, EValueType> >(amount);
			for(short i=0; i<amount; i++)
				pRetVal[i] = static_cast<const T<EKeyType, EValueType>&>(this[i]);
			return pRetVal;
		}

		/** @copydoc AssociativeContainerBase::getValue() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		template<typename FKeyType, typename FValueType>
		const FValueType* GenericAssociativeContainer<T, EKeyType, EValueType>::getValueImplementation(const FKeyType& key, const FValueType* /*pDummyDeducer*/) const
		{
			const JObject* pRetObject = this->getHashtable().getValue(key);
			return pRetObject?&pRetObject->getPayload<const FValueType>():NULL;
		}

		/** @copydoc AssociativeContainerBase::getValue() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		template<typename FKeyType, typename FValueType>
		FValueType* GenericAssociativeContainer<T, EKeyType, EValueType>::getValueImplementation(const FKeyType& key, const FValueType* /*pDummyDeducer*/)
		{
			JObject* pRetObject = this->mHashtable.getValue(key);
			return pRetObject?&pRetObject->getPayload<FValueType>():NULL;
		}

		/** @copydoc AssociativeContainerBase::getKeys() */
		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		template<typename FKeyType>
		JVector<FKeyType> GenericAssociativeContainer<T, EKeyType, EValueType>::getKeysImplementation(const FKeyType* /*pDummyDeducer*/) const
		{
			JVector<FKeyType> keys;
			JVector<JObject> keyObjs = this->getHashtable().getKeys();
			for(unsigned int i=0; i<keyObjs.getSize(); ++i)
				keys.addElement(keyObjs[i].getPayload<FKeyType>());
			return keys;
		}

		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		template<typename FValueType>
		const FValueType& GenericAssociativeContainer<T, EKeyType, EValueType>::getValueAtImplementation(unsigned int index, const FValueType* /*pDummyDeducer*/) const
		{
			return this->getHashtable()[index].template getPayload<const FValueType>();
		}

		template<template<typename, typename> class T, typename EKeyType, typename EValueType>
		template<typename FValueType>
		FValueType& GenericAssociativeContainer<T, EKeyType, EValueType>::getValueAtImplementation(unsigned int index, const FValueType* /*pDummyDeducer*/)
		{
			return this->mHashtable[index].template getPayload<FValueType>();
		}
	}
}