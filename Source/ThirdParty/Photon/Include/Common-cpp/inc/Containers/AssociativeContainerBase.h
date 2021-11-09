/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/JVector.h"
#include "Common-cpp/inc/Helpers/ArrayLengthType.h"
#include "Common-cpp/inc/Helpers/KeyToObject.h"
#include "Common-cpp/inc/Helpers/ValueToObject.h"

namespace ExitGames
{
	namespace Common
	{
		template<typename T, typename OT>
		class AssociativeContainerBase : public Base
		{
		public:
			using ToString::toString;

			virtual ~AssociativeContainerBase(void) = 0;

			AssociativeContainerBase<T, OT>& operator=(const AssociativeContainerBase<T, OT>& toCopy);

			virtual bool operator==(const AssociativeContainerBase<T, OT>& toCompare) const;
			virtual bool operator!=(const AssociativeContainerBase<T, OT>& toCompare) const;
			virtual const OT& operator[](unsigned int index) const;
			virtual const OT& operator[](int index) const;
			virtual OT& operator[](unsigned int index);
			virtual OT& operator[](int index);

			virtual void put(const T& src);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType& val);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType pVal, typename Common::Helpers::ArrayLengthType<FValueType>::type size);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType pVal, const short* sizes);

			template<typename FKeyType> const OT* getValue(const FKeyType& key) const;
			template<typename FKeyType> OT* getValue(const FKeyType& key);
			virtual unsigned int getSize(void) const;
			virtual const JVector<OT>& getKeys(void) const;
			template<typename FKeyType> void remove(const FKeyType& key);
			virtual void removeAt(unsigned int index);
			template<typename FKeyType> bool contains(const FKeyType& key) const;
			virtual void removeAllElements(void);
			virtual JString& toString(JString& retStr, bool withTypes=false) const;
		protected:
			AssociativeContainerBase(void);

			AssociativeContainerBase(const AssociativeContainerBase<T, OT>& toCopy);

			virtual void putImplementation(const OT& key, const OT& val);
			virtual const OT* getValueImplementation(const OT& key) const;
			virtual OT* getValueImplementation(const OT& key);
			virtual void removeImplementation(const OT& key);
			virtual bool containsImplementation(const OT& key) const;

			JVector<OT> mKeytable;
			JVector<OT> mValtable;
		};



		/** @file */

		template<typename T, typename OT>
		AssociativeContainerBase<T, OT>::AssociativeContainerBase(void)
		{
		}

		/**
		   Destructor. */
		template<typename T, typename OT>
		AssociativeContainerBase<T, OT>::~AssociativeContainerBase(void)
		{
		}

		template<typename T, typename OT>
		AssociativeContainerBase<T, OT>::AssociativeContainerBase(const AssociativeContainerBase<T, OT>& toCopy)
		{
			mKeytable = toCopy.mKeytable;
			mValtable = toCopy.mValtable;
		}
	
		/**
		   operator=. Makes a deep copy of its right operand into its
		   left operand. This overwrites old data in the left operand. */
		template<typename T, typename OT>
		AssociativeContainerBase<T, OT>& AssociativeContainerBase<T, OT>::operator=(const AssociativeContainerBase<T, OT>& toCopy)
		{
			mKeytable = toCopy.mKeytable;
			mValtable = toCopy.mValtable;
			return *this;
		}

		/**
		   operator==.
		   @returns true, if both operands are equal, false otherwise.

		   Two instances are considered equal if they each hold the same number of entries and, for a given key, the corresponding values
		   equal each other.
		   
		   Two values are considered equal to each other, if instances of class OT, that are holding them as payloads, equal each other.
		   
		   @sa OT::operator==() */
		template<typename T, typename OT>
		bool AssociativeContainerBase<T, OT>::operator==(const AssociativeContainerBase<T, OT>& toCompare) const
		{
			if(getSize() != toCompare.getSize())
				return false;
			const OT* pVal1, *pVal2;
			for(unsigned int i=0; i<getSize(); ++i)
				if((pVal1=getValue(getKeys()[i]))==NULL || (pVal2=toCompare.getValue(getKeys()[i]))==NULL || *pVal1 != *pVal2)
					return false;
			return true;
		}

		/**
		   operator!=.
		   @returns false, if operator==() would return true, true otherwise. */
		template<typename T, typename OT>
		bool AssociativeContainerBase<T, OT>::operator!=(const AssociativeContainerBase<T, OT>& toCompare) const
		{
			return !(*this == toCompare);
		}

		/**
		   operator[].

		   Accesses the value at the given index like in an array.
		   This does not check for valid indexes and shows
		   undefined behavior for invalid indexes */
		template<typename T, typename OT>
		const OT& AssociativeContainerBase<T, OT>::operator[](int index) const
		{
			return mValtable[index];
		}

		/**
		   operator[].

		   Accesses the value at the given index like in an array.
		   This does not check for valid indexes and shows
		   undefined behavior for invalid indexes */
		template<typename T, typename OT>
		const OT& AssociativeContainerBase<T, OT>::operator[](unsigned int index) const
		{
			return mValtable[index];
		}

		/**
		   operator[].

		   Accesses the value at the given index like in an array.
		   This does not check for valid indexes and shows
		   undefined behavior for invalid indexes */
		template<typename T, typename OT>
		OT& AssociativeContainerBase<T, OT>::operator[](int index)
		{
			return mValtable[index];
		}

		/**
		   operator[].

		   Accesses the value at the given index like in an array.
		   This does not check for valid indexes and shows
		   undefined behavior for invalid indexes */
		template<typename T, typename OT>
		OT& AssociativeContainerBase<T, OT>::operator[](unsigned int index)
		{
			return mValtable[index];
		}

		/**
		   Adds all pairs of a key and a corresponding value from the
		   passed instance to the instance, on which it is called on.
		   If a key is already existing, then its old value will be
		   replaced with the new one.
		   @param src instance, from which to add the content
		   @returns
		   nothing. */
		template<typename T, typename OT>
		void AssociativeContainerBase<T, OT>::put(const T& src)
		{
			for(unsigned int i=0; i<src.getSize(); i++)
				putImplementation(src.getKeys()[i], *src.getValueImplementation(src.getKeys()[i]));
		}

		template<typename T, typename OT>
		void AssociativeContainerBase<T, OT>::putImplementation(const OT& key, const OT& val)
		{
			int index = mKeytable.getIndexOf(key);
			if(index == -1)
			{
				mKeytable.addElement(key);
				mValtable.addElement(val);
			}
			else
			{
				mKeytable.setElementAt(key, index);
				mValtable.setElementAt(val, index);
			}
		}

		template<typename T, typename OT>
		void AssociativeContainerBase<T, OT>::removeImplementation(const OT& key)
		{
			int index = mKeytable.getIndexOf(key);
			if(index == -1)
				return;
			mKeytable.removeElementAt(index);
			mValtable.removeElementAt(index);
		}

		template<typename T, typename OT>
		bool AssociativeContainerBase<T, OT>::containsImplementation(const OT& key) const
		{
			return mKeytable.contains(key);
		}

		template<typename T, typename OT>
		const OT* AssociativeContainerBase<T, OT>::getValueImplementation(const OT& key) const
		{
			int index = mKeytable.getIndexOf(key);
			return index==-1?NULL:&(mValtable[index]);
		}

		template<typename T, typename OT>
		OT* AssociativeContainerBase<T, OT>::getValueImplementation(const OT& key)
		{
			int index = mKeytable.getIndexOf(key);
			return index==-1?NULL:&(mValtable[index]);
		}

		/**
		   @returns a JVector holding all keys contained in the Hashtable. */
		template<typename T, typename OT>
		const JVector<OT>& AssociativeContainerBase<T, OT>::getKeys(void) const
		{
			return mKeytable;
		}

		/**
		   Deletes the key and the value at the specified index, if the specified index is smaller than the return value of getSize().
		   @param index the index at which the key and value should be deleted.
		   @returns
		   nothing.
		   @sa
		   remove(), removeAllElements()    */
		template<typename T, typename OT>
		void AssociativeContainerBase<T, OT>::removeAt(unsigned int index)
		{
			if(index >= getSize())
				return;
			mKeytable.removeElementAt(index);
			mValtable.removeElementAt(index);
		}

		/**
		   Clears the Hashtable, which means deleting all its content.
		   @returns
		   nothing.
		   @sa
		   remove(), removeAt()       */
		template<typename T, typename OT>
		void AssociativeContainerBase<T, OT>::removeAllElements(void)
		{
			mKeytable.removeAllElements();
			mValtable.removeAllElements();
		}

		/**
		   @returns the number of key/value pairs stored in the Hashtable.                                           */
		template<typename T, typename OT>
		unsigned int AssociativeContainerBase<T, OT>::getSize(void) const
		{
			return mKeytable.getSize();
		}

		template<typename T, typename OT>
		JString& AssociativeContainerBase<T, OT>::toString(JString& retStr, bool withTypes) const
		{
			retStr += L"{";
			for(unsigned int i=0; i<getSize(); i++)
			{
				getKeys()[i].toString(retStr, withTypes);
				retStr += L"=";
				mValtable[i].toString(retStr, withTypes);
				if(i < getSize()-1)
					retStr += L", ";
			}
			retStr += L"}";
			return retStr;
		}

		/** 
		   Adds a pair of a key and a corresponding value to the instance.
		   @details
		   If the key is already existing, then it's old value will be
		   replaced with the new one.
		   Please have a look at the @link Datatypes table of datatypes\endlink for a list of supported types for keys and values
		   @param key the key to add
		   @param val the value to add */
		template<typename T, typename OT>
		template<typename FKeyType, typename FValueType>
		void AssociativeContainerBase<T, OT>::put(const FKeyType& key, const FValueType& val)
		{
			putImplementation(Helpers::KeyToObject<OT>::get(key), Helpers::ValueToObject<OT>::get(val));
		}

		/**
		   @overload
		   @details
		   This overload accepts singledimensional arrays and NULL-pointers passed for parameter pVal. NULL pointers are only legal input, if size is 0
		   @param key the key to add
		   @param pVal the value array to add
		   @param size the size of the value array */
		template<typename T, typename OT>
		template<typename FKeyType, typename FValueType>
		void AssociativeContainerBase<T, OT>::put(const FKeyType& key, const FValueType pVal, typename Common::Helpers::ArrayLengthType<FValueType>::type size)
		{
			putImplementation(Helpers::KeyToObject<OT>::get(key), Helpers::ValueToObject<OT>::get(pVal, size));
		}

		/**
		   @overload
		   @details
		   This overload accepts multidimensional arrays and NULL-pointers passed for parameter pVal.
		   The array that is passed for parameter pVal has to be a pointer of the correct abstraction level, meaning a normal pointer for
		   a singledimensional array, a doublepointer for a twodimensional array, a triplepointer for a threedimensional array and so on.
		   For pVal NULL pointers are only legal input, if sizes[0] is 0.
		   For sizes NULL is no valid input.
		   @param key the key to add
		   @param pVal the value array to add
		   @param sizes the sizes for every dimension of the value array - the length of this array has to match the dimensions of pVal */
		template<typename T, typename OT>
		template<typename FKeyType, typename FValueType>
		void AssociativeContainerBase<T, OT>::put(const FKeyType& key, const FValueType pVal, const short* const sizes)
		{
			putImplementation(Helpers::KeyToObject<OT>::get(key), Helpers::ValueToObject<OT>::get(pVal, sizes));
		}


		
		/**
		   Deletes the specified key and the corresponding value, if
		   found in the Hashtable.
		   @param key Pointer to the key of the key/value-pair to remove.
		   @sa
		   removeAt(), removeAllElements()    */
		template<typename T, typename OT>
		template<typename FKeyType>
		void AssociativeContainerBase<T, OT>::remove(const FKeyType& key)
		{
			removeImplementation(Helpers::KeyToObject<OT>::get(key));
		}
		
		/**
		   Checks, whether the Hashtable contains a certain key.
		   @param key Pointer to the key to look up.
		   @returns
		   true if the specified key was found, false otherwise. */
		template<typename T, typename OT>
		template<typename FKeyType>
		bool AssociativeContainerBase<T, OT>::contains(const FKeyType& key) const
		{
			return containsImplementation(Helpers::KeyToObject<OT>::get(key));
		}

		/**
		   Returns a pointer to the corresponding value for a specified key.
		   @param key  Reference to the key to return the corresponding value for.
		   @returns
		   a pointer to the corresponding value if the Hashtable
		   contains the specified key, NULL otherwise.
		   
		   @sa
		   put()                                                               */
		template<typename T, typename OT>
		template<typename FKeyType>
		const OT* AssociativeContainerBase<T, OT>::getValue(const FKeyType& key) const
		{
			return getValueImplementation(Helpers::KeyToObject<OT>::get(key));
		}

		/**
		   Returns a pointer to the corresponding value for a specified key.
		   @param key  Reference to the key to return the corresponding value for.
		   @returns
		   a pointer to the corresponding value if the Hashtable
		   contains the specified key, NULL otherwise.
		   
		   @sa
		   put()                                                               */
		template<typename T, typename OT>
		template<typename FKeyType>
		OT* AssociativeContainerBase<T, OT>::getValue(const FKeyType& key)
		{
			return getValueImplementation(Helpers::KeyToObject<OT>::get(key));
		}
	}
}