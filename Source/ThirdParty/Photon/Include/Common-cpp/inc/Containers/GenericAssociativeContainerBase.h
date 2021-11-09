/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/JVector.h"
#include "Common-cpp/inc/Helpers/ArrayLengthType.h"
#include "Common-cpp/inc/MemoryManagement/Allocate.h"
#include "Common-cpp/inc/MemoryManagement/Internal/Interface.h"

namespace ExitGames
{
	namespace Common
	{
		template<typename T, typename TImplementation, typename TObject>
		class GenericAssociativeContainerBase : public Base
		{
		public:
			using ToString::toString;

			virtual ~GenericAssociativeContainerBase(void) = 0;

			virtual bool operator==(const T& toCompare) const;
			virtual bool operator!=(const T& toCompare) const;

			virtual void put(const T& src);
			virtual void removeAt(unsigned int index);
			virtual void removeAllElements(void);

			virtual JString& toString(JString& retStr, bool withTypes=false) const;

			virtual const TImplementation& getHashtable(void) const;
			virtual unsigned int getSize(void) const;
		protected:
			GenericAssociativeContainerBase(void);

			GenericAssociativeContainerBase(const GenericAssociativeContainerBase<T, TImplementation, TObject>& toCopy);
			template<typename FT> GenericAssociativeContainerBase(const GenericAssociativeContainerBase<FT, TImplementation, TObject>& toCopy);

			virtual T& assign(const GenericAssociativeContainerBase<T, TImplementation, TObject>& toCopy);

			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType& val);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType pVal, typename Common::Helpers::ArrayLengthType<FValueType>::type size);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType pVal, const short* sizes);

			template<typename FKeyType> void remove(const FKeyType& key);
			template<typename FKeyType> bool contains(const FKeyType& key) const;

			template<typename FKeyType, typename FValueType> const FValueType* getValue(const FKeyType& key, const FValueType* /*pDummyDeducer*/) const;
			template<typename FKeyType> const TObject* getValue(const FKeyType& key, const TObject* /*pDummyDeducer*/) const;
			template<typename FKeyType, typename FValueType> FValueType* getValue(const FKeyType& key, const FValueType* /*pDummyDeducer*/);
			template<typename FKeyType> TObject* getValue(const FKeyType& key, const TObject* /*pDummyDeducer*/);

			template<typename FValueType> const FValueType& getValueAt(unsigned int index, const FValueType* /*pDummyDeducer*/) const;
			const TObject& getValueAt(unsigned int index, const TObject* /*pDummyDeducer*/) const;
			template<typename FValueType> FValueType& getValueAt(unsigned int index, const FValueType* /*pDummyDeducer*/);
			TObject& getValueAt(unsigned int index, const TObject* /*pDummyDeducer*/);

			template<typename FKeyType> JVector<FKeyType> getKeys(const FKeyType* pDummyDeducer) const;
			const JVector<TObject>& getKeys(const TObject* /*pDummyDeducer*/) const;

			TImplementation mHashtable;
		private:
			GenericAssociativeContainerBase<T, TImplementation, TObject>& operator=(const GenericAssociativeContainerBase<T, TImplementation, TObject>& toCopy);

			template<typename FT> void init(const GenericAssociativeContainerBase<FT, TImplementation, TObject>& toCopy);

			virtual bool compare(const T& toCompare) const;

			template<typename CT, typename CTImplementation, typename CTObject> friend class GenericAssociativeContainerBase;
		};



		/** @file */
		
		template<typename T, typename TImplementation, typename TObject>
		GenericAssociativeContainerBase<T, TImplementation, TObject>::GenericAssociativeContainerBase(void)
		{
			static MemoryManagement::AllocatorInterface* pAllocator = MemoryManagement::Internal::Interface::getAllocator(0); // this assures that the allocator gets constructed now and hence will still be around when the destructor is called, even when we construct a global/static instance with an initialCapacity of 0 as the very first user of the allocator
			if(pAllocator){} // this silences the unused variable warning - this line gets optimized out by the compiler in release configurations
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::~AssociativeContainerBase(void) */
		template<typename T, typename TImplementation, typename TObject>
		GenericAssociativeContainerBase<T, TImplementation, TObject>::~GenericAssociativeContainerBase(void)
		{
		}

		/** @copydoc AssociativeContainerBase::AssociativeContainerBase(const AssociativeContainerBase&) */
		template<typename T, typename TImplementation, typename TObject>
		GenericAssociativeContainerBase<T, TImplementation, TObject>::GenericAssociativeContainerBase(const GenericAssociativeContainerBase<T, TImplementation, TObject>& toCopy)
		{
			init(toCopy);
		}

		/** @copydoc AssociativeContainerBase::AssociativeContainerBase(const AssociativeContainerBase&) */
		template<typename T, typename TImplementation, typename TObject>
		template<typename FT>
		GenericAssociativeContainerBase<T, TImplementation, TObject>::GenericAssociativeContainerBase(const GenericAssociativeContainerBase<FT, TImplementation, TObject>& toCopy)
		{
			init(toCopy);
		}

		template<typename T, typename TImplementation, typename TObject>
		template<typename FT>
		void GenericAssociativeContainerBase<T, TImplementation, TObject>::init(const GenericAssociativeContainerBase<FT, TImplementation, TObject>& toCopy)
		{
			mHashtable = toCopy.mHashtable;
		}

		/** @copydoc AssociativeContainerBase::operator==() */
		template<typename T, typename TImplementation, typename TObject>
		bool GenericAssociativeContainerBase<T, TImplementation, TObject>::operator==(const T& toCompare) const
		{
			return this->compare(toCompare);
		}

		/** @copydoc AssociativeContainerBase::operator!=() */
		template<typename T, typename TImplementation, typename TObject>
		bool GenericAssociativeContainerBase<T, TImplementation, TObject>::operator!=(const T& toCompare) const
		{
			return !this->compare(toCompare);
		}

		template<typename T, typename TImplementation, typename TObject>
		T& GenericAssociativeContainerBase<T, TImplementation, TObject>::assign(const GenericAssociativeContainerBase<T, TImplementation, TObject>& toCopy)
		{
			init(toCopy);
			return static_cast<T&>(*this);
		}

		/** @copydoc ExitGames::Common::Hashtable::put(const Hashtable&) */
		template<typename T, typename TImplementation, typename TObject>
		void GenericAssociativeContainerBase<T, TImplementation, TObject>::put(const T& src)
		{
			mHashtable.put(src.getHashtable());
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::removeAllElements() */
		template<typename T, typename TImplementation, typename TObject>
		void GenericAssociativeContainerBase<T, TImplementation, TObject>::removeAllElements(void)
		{
			mHashtable.removeAllElements();
		}

		template<typename T, typename TImplementation, typename TObject>
		JString& GenericAssociativeContainerBase<T, TImplementation, TObject>::toString(JString& retStr, bool withTypes) const
		{
			retStr += L"{";
			for(unsigned int i=0; i<getSize(); ++i)
			{
				getHashtable().getKeys()[i].toString(retStr, withTypes);
				retStr += L"=";
				getHashtable()[i].toString(retStr, withTypes);
				if(i < getSize()-1)
					retStr += L", ";
			}
			retStr += L"}";
			return retStr;
		}

		/**
		   @returns a readonly reference to a TImplementation representation of the Dictionary instance. The returned reference refers to the
		   original payload data of the Dictionary, so its payload will change, if the payload of the according Dictionary instance changes.*/
		template<typename T, typename TImplementation, typename TObject>
		const TImplementation& GenericAssociativeContainerBase<T, TImplementation, TObject>::getHashtable(void) const
		{
			return mHashtable;
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::getSize() */
		template<typename T, typename TImplementation, typename TObject>
		unsigned int GenericAssociativeContainerBase<T, TImplementation, TObject>::getSize(void) const
		{
			return mHashtable.getSize();
		}

		/** @copydoc AssociativeContainerBase::getKeys() */
		template<typename T, typename TImplementation, typename TObject>
		const JVector<TObject>& GenericAssociativeContainerBase<T, TImplementation, TObject>::getKeys(const TObject* /*pDummyDeducer*/) const
		{
			return getHashtable().getKeys();
		}

		template<typename T, typename TImplementation, typename TObject>
		bool GenericAssociativeContainerBase<T, TImplementation, TObject>::compare(const T& toCompare) const
		{
			return getHashtable() == toCompare.getHashtable();
		}

		template<typename T, typename TImplementation, typename TObject>
		const TObject& GenericAssociativeContainerBase<T, TImplementation, TObject>::getValueAt(unsigned int index, const TObject* /*pDummyDeducer*/) const
		{
			return getHashtable()[index];
		}

		template<typename T, typename TImplementation, typename TObject>
		TObject& GenericAssociativeContainerBase<T, TImplementation, TObject>::getValueAt(unsigned int index, const TObject* /*pDummyDeducer*/)
		{
			return mHashtable[index];
		}

		/** @copydoc AssociativeContainerBase::remove() */
		template<typename T, typename TImplementation, typename TObject>
		template<typename FKeyType>
		void GenericAssociativeContainerBase<T, TImplementation, TObject>::remove(const FKeyType& key)
		{
			mHashtable.remove(key);
		}

		/** @copydoc ExitGames::Common::AssociativeContainerBase::removeAt() */
		template<typename T, typename TImplementation, typename TObject>
		void GenericAssociativeContainerBase<T, TImplementation, TObject>::removeAt(unsigned int index)
		{
			mHashtable.removeAt(index);
		}

		/** @copydoc AssociativeContainerBase::contains() */
		template<typename T, typename TImplementation, typename TObject>
		template<typename FKeyType>
		bool GenericAssociativeContainerBase<T, TImplementation, TObject>::contains(const FKeyType& key) const
		{
			return getHashtable().contains(key);
		}

		template<typename T, typename TImplementation, typename TObject>
		template<typename FKeyType, typename FValueType>
		void GenericAssociativeContainerBase<T, TImplementation, TObject>::put(const FKeyType& key, const FValueType& val)
		{
			mHashtable.put(key, val);
		}

		template<typename T, typename TImplementation, typename TObject>
		template<typename FKeyType, typename FValueType>
		void GenericAssociativeContainerBase<T, TImplementation, TObject>::put(const FKeyType& key, FValueType pVal, typename Common::Helpers::ArrayLengthType<FValueType>::type size)
		{
			mHashtable.put(key, pVal, size);
		}

		template<typename T, typename TImplementation, typename TObject>
		template<typename FKeyType, typename FValueType>
		void GenericAssociativeContainerBase<T, TImplementation, TObject>::put(const FKeyType& key, FValueType pVal, const short* const sizes)
		{
			mHashtable.put(key, pVal, sizes);
		}

		/** @copydoc AssociativeContainerBase::getValue() */
		template<typename T, typename TImplementation, typename TObject>
		template<typename FKeyType, typename FValueType>
		const FValueType* GenericAssociativeContainerBase<T, TImplementation, TObject>::getValue(const FKeyType& key, const FValueType* pDummyDeducer) const
		{
			return static_cast<const T&>(*this).getValueImplementation(key, pDummyDeducer);
		}
		
		/** @copydoc AssociativeContainerBase::getValue() */
		template<typename T, typename TImplementation, typename TObject>
		template<typename FKeyType>
		const TObject* GenericAssociativeContainerBase<T, TImplementation, TObject>::getValue(const FKeyType& key, const TObject* /*pDummyDeducer*/) const
		{
			return getHashtable().getValue(key);
		}

		/** @copydoc AssociativeContainerBase::getValue() */
		template<typename T, typename TImplementation, typename TObject>
		template<typename FKeyType, typename FValueType>
		FValueType* GenericAssociativeContainerBase<T, TImplementation, TObject>::getValue(const FKeyType& key, const FValueType* pDummyDeducer)
		{
			return static_cast<T&>(*this).getValueImplementation(key, pDummyDeducer);
		}

		/** @copydoc AssociativeContainerBase::getValue() */
		template<typename T, typename TImplementation, typename TObject>
		template<typename FKeyType>
		TObject* GenericAssociativeContainerBase<T, TImplementation, TObject>::getValue(const FKeyType& key, const TObject* /*pDummyDeducer*/)
		{
			return mHashtable.getValue(key);
		}

		/** @copydoc AssociativeContainerBase::getKeys() */
		template<typename T, typename TImplementation, typename TObject>
		template<typename FKeyType>
		JVector<FKeyType> GenericAssociativeContainerBase<T, TImplementation, TObject>::getKeys(const FKeyType* pDummyDeducer) const
		{
			return static_cast<const T&>(*this).getKeysImplementation(pDummyDeducer);
		}

		template<typename T, typename TImplementation, typename TObject>
		template<typename FValueType>
		const FValueType& GenericAssociativeContainerBase<T, TImplementation, TObject>::getValueAt(unsigned int index, const FValueType* pDummyDeducer) const
		{
			return static_cast<const T&>(*this).getValueAtImplementation(index, pDummyDeducer);
		}

		template<typename T, typename TImplementation, typename TObject>
		template<typename FValueType>
		FValueType& GenericAssociativeContainerBase<T, TImplementation, TObject>::getValueAt(unsigned int index, const FValueType* pDummyDeducer)
		{
			return static_cast<T&>(*this).getValueAtImplementation(index, pDummyDeducer);
		}
	}
}