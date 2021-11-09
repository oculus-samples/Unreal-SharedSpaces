/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/ArrayLengthType.h"
#include "Common-cpp/inc/Helpers/ConfirmAllowed.h"
#include "Common-cpp/inc/Helpers/EndianCorrectCast.h"
#include "Common-cpp/inc/Object.h"

namespace ExitGames
{
	namespace Common
	{
		class DictionaryBase;

		/**
		   Container class template for objects to be stored as values in a Hashtable or Dictionary.
		   @remarks
		   In most cases the library will do the work of storing a value in a ValueObject for you, so for example you don't have to
		   explicitly create an instance of this class, when storing a key-value pair in a Dictionary or Hashtable instance. However there
		   are some situations, where you will receive instances of class Object or want to create them (for example Hashtable::getValue()
		   will return an Object) and in that case casting those instances into ValueObject-instances can be a convenient way of assuring
		   a type-safe access to their payloads. */
		template<typename Etype>
		class ValueObject : public Object
		{
		public:
			ValueObject(const ValueObject<Etype>& toCopy);
			ValueObject(const Object& obj);
			ValueObject(const Object* obj);
			ValueObject(const typename Helpers::ConfirmAllowed<Etype>::type& data);
			ValueObject(const typename Helpers::ConfirmAllowed<Etype>::type pData, typename Helpers::ArrayLengthType<Etype>::type size);
			ValueObject(const typename Helpers::ConfirmAllowed<Etype>::type pData, const short* sizes);
			virtual ~ValueObject(void);

			virtual ValueObject<Etype>& operator=(const ValueObject<Etype>& toCopy);
			virtual ValueObject<Etype>& operator=(const Object& toCopy);

			const typename Helpers::ArrayLengthType<Etype>::type* getSizes(void) const;

			Etype getDataCopy(void) const;
			Etype* getDataAddress(void) const;
		protected:
			virtual ValueObject<Etype>& assign(const Object& toCopy);
		private:
			typedef Object super;

			template<typename Ftype> struct getDataCopyImplementation {Ftype operator()(const void* pData, const short* pSizes, nByte type, unsigned int dimensions) const;};
			template<typename Ftype> struct getDataCopyImplementation<Ftype*> {Ftype* operator()(const void* pData, const typename Helpers::ArrayLengthType<Ftype*>::type* pSizes, nByte type, unsigned int dimensions) const; private: void* dimensionRecursion(void* pArrayOut, const void* pArrayIn, const typename Helpers::ArrayLengthType<Ftype*>::type* pSizes, nByte type, unsigned int dimensions, unsigned int recursionDepth) const; void* lastDimension(const void* ArrayIn, typename Helpers::ArrayLengthType<Ftype*>::type size) const;};
			template<typename Ftype> struct getDataAddressImplementation {Ftype* operator()(const void* const* ppData) const;};
			template<typename Ftype> struct getDataAddressImplementation<Ftype*> {Ftype** operator()(const void* const* ppData) const;};
			void convert(const Object* obj, nByte type, unsigned int dimensions);
		};



		/** @file */

		/**
		   Copy-Constructor.

		   Creates an object out of a deep copy of its parameter.

		   The parameter has to be of the same template instantiation as the
		   object, you want to create.
		   @param toCopy The object to copy.                                */
		template<typename Etype>
		ValueObject<Etype>::ValueObject(const ValueObject<Etype>& toCopy) : Object(toCopy)
		{
		}

		/**
		   Constructor.

		   Creates an object out of a deep copy of the passed Object&.

		   If the type of the content of the passed object does not
		   match the template instantiation of the object to create, an empty
		   object is created instead of a copy of the passed object,
		   which leads to getDataCopy()
		   and getDataAddress()
		   returning 0.
		   @param obj The Object& to copy.                                 */
		template<typename Etype>
		ValueObject<Etype>::ValueObject(const Object& obj)
		{
			convert(&obj, Helpers::ConfirmAllowed<Etype>::typeName, Helpers::ConfirmAllowed<Etype>::dimensions);
		}

		/**
		   Constructor.

		   Creates an object out of a deep copy of the passed Object*.

		   If the type of the content of the passed object does not
		   match the template instantiation of the object to create, an empty
		   object is created instead of a copy of the passed object,
		   which leads to getDataCopy()
		   and getDataAddress()
		   return 0.
		   @param obj The Object* to copy.                                 */
		template<typename Etype>
		ValueObject<Etype>::ValueObject(const Object* const obj)
		{
			convert(obj, Helpers::ConfirmAllowed<Etype>::typeName, Helpers::ConfirmAllowed<Etype>::dimensions);
		}

		/**
		   Constructor.
	   
		   Creates an object out of a deep copy of the passed single-value Etype.
	   
		   @param data The value to copy. Has to be of a supported type.                         */
		template<typename Etype>
		ValueObject<Etype>::ValueObject(const typename Helpers::ConfirmAllowed<Etype>::type& data) : Object(&data, Helpers::ConfirmAllowed<Etype>::typeName, Helpers::ConfirmAllowed<Etype>::customTypeName, true)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Helpers::ConfirmAllowed<Etype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
		}

		/**
		   Constructor.
	   
		   Creates an object out of a deep copy of the passed single-dimensional Etype-array.
	   
		   @param pData The array to copy.
		   @param size The element count of data.                               */
		template<typename Etype>
		ValueObject<Etype>::ValueObject(const typename Helpers::ConfirmAllowed<Etype>::type pData, typename Helpers::ArrayLengthType<Etype>::type size) : Object(pData, Helpers::ConfirmAllowed<Etype>::typeName, Helpers::ConfirmAllowed<Etype>::customTypeName, size, true)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(Helpers::ConfirmAllowed<Etype>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
		}

		/**
		   Constructor.
	   
		   Creates an object out of a deep copy of the passed multi-dimensional Etype-array.
	   
		   @param pData The array to copy.
		   @param sizes The array of element counts for the different dimensions of data.                               */
		template<typename Etype>
		ValueObject<Etype>::ValueObject(const typename Helpers::ConfirmAllowed<Etype>::type pData, const short* const sizes) : Object(pData, Helpers::ConfirmAllowed<Etype>::typeName, Helpers::ConfirmAllowed<Etype>::customTypeName, Helpers::ConfirmAllowed<Etype>::dimensions, sizes, true)
		{
			COMPILE_TIME_ASSERT2_TRUE_MSG(!!Helpers::ConfirmAllowed<Etype>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_FOR_ARRAYS);
		}

		/**
		   Destructor.*/
		template<typename Etype>
		ValueObject<Etype>::~ValueObject(void)
		{
		}

		/**
		   operator= : Makes a deep copy of its right operand into its
		   left operand. This overwrites old data in the left operand.  */
		template<typename Etype>
		ValueObject<Etype>& ValueObject<Etype>::operator=(const ValueObject<Etype>& toCopy)
		{
			return assign(toCopy);
		}

		/**
		   operator= : Makes a deep copy of its right operand into its
		   left operand. This overwrites old data in the left operand.

		   If the type of the content of the right operand does not
		   match the template instantiation of the left operand, then the left
		   operand stays unchanged.  */
		template<typename Etype>
		ValueObject<Etype>& ValueObject<Etype>::operator=(const Object& toCopy)
		{
			return assign(toCopy);
		}

		template<typename Etype>
		ValueObject<Etype>& ValueObject<Etype>::assign(const Object& toCopy)
		{
			if(Helpers::ConfirmAllowed<Etype>::typeName == toCopy.getType())
				super::assign(toCopy);
			return *this;
		}

		template<typename Etype>
		const typename Helpers::ArrayLengthType<Etype>::type* ValueObject<Etype>::getSizes(void) const
		{
			return Helpers::endianCorrectCast<const typename Helpers::ArrayLengthType<Etype>::type*>(super::getSizes());
		}

		/**
		   Returns a deep copy of the content of the object. If you
		   only need access to the content, while the object still
		   exists, you can use getDataAddress()
		   instead to avoid the deep copy. That is especially
		   interesting for large content, of course.

		   If successful, the template instantiations for array types of this
		   function allocate the data for the copy by calling
		   allocateArray<Etype>(), so you have to call deallocateArray()
		   on it, as soon, as you do not need the array anymore.
		   All non-array copies free their memory automatically, as soon
		   as they leave their scope, same as the single indices of the
		   array, as soon, as the array is freed.

		   In case of an error this function returns 0 for primitive
		   return types and for arrays and an empty object for classes.
		   @returns
		   a deep copy of the content of the object if successful, 0 or
		   an empty object otherwise.                                               */

		template<typename Etype>
		Etype ValueObject<Etype>::getDataCopy(void) const
		{
			return getDataCopyImplementation<Etype>()(getData(), getSizes(), getType(), getDimensions());
		}

		template<typename Etype>
		template<typename Ftype>
		Ftype ValueObject<Etype>::getDataCopyImplementation<Ftype>::operator()(const void* const pData, const short* const /*pSizes*/, nByte type, unsigned int dimensions) const
		{
			if(type == Helpers::ConfirmAllowed<Ftype>::typeName && !dimensions)
				return *(Ftype*)pData;
			else
				return Ftype();
		}

		template<typename Etype>
		template<typename Ftype>
		Ftype* ValueObject<Etype>::getDataCopyImplementation<Ftype*>::operator()(const void* const pData, const typename Helpers::ArrayLengthType<Ftype*>::type* const pSizes, nByte type, unsigned int dimensions) const
		{
			if(type == Helpers::ConfirmAllowed<Ftype*>::typeName && dimensions)
				return reinterpret_cast<Ftype*>(dimensionRecursion(NULL, pData, pSizes, type, dimensions, 0));
			else
				return NULL;
		}

		/** @cond DOXYGEN_IGNORE */
		template<typename Etype>
		template<typename Ftype>
		void* ValueObject<Etype>::getDataCopyImplementation<Ftype*>::dimensionRecursion(void* pArrayOut, const void* const pArrayIn, const typename Helpers::ArrayLengthType<Ftype*>::type* const pSizes, nByte type, unsigned int dimensions, unsigned int recursionDepth) const
		{
			if(dimensions && recursionDepth < dimensions-1)
			{
				pArrayOut = MemoryManagement::allocateArray<void*>(pSizes[recursionDepth]);
				for(typename Helpers::ArrayLengthType<Ftype>::type i=0; i<pSizes[recursionDepth]; ++i)
					((void**)pArrayOut)[i] = dimensionRecursion(((void**)pArrayOut)[i], ((void**)pArrayIn)[i], pSizes, type, dimensions, recursionDepth+1);
				return pArrayOut;
			}
			else
				return pArrayOut = lastDimension(pArrayIn, pSizes[recursionDepth]);
		}

		template<typename Etype>
		template<typename Ftype>
		void* ValueObject<Etype>::getDataCopyImplementation<Ftype*>::lastDimension(const void* const pArrayIn, typename Helpers::ArrayLengthType<Ftype*>::type size) const
		{
			// Helpers::ConfirmAllowed<Ftype*>::scalarType* will be a 1d pointer, even if Ftype* has multiple pointer abstraction levels
			typename Helpers::ConfirmAllowed<Ftype*>::scalarType* pRetVal = size?MemoryManagement::allocateArray<typename Helpers::ConfirmAllowed<Ftype*>::scalarType>(size):NULL;
			for(typename Helpers::ArrayLengthType<Ftype*>::type i=0; i<size; i++)
				pRetVal[i] = ((typename Helpers::ConfirmAllowed<Ftype*>::scalarType*)pArrayIn)[i];
			return pRetVal;
		}
		/** @endcond */

		/**
		   Returns the address of the original content of the object.
		   If you need access to the data beyond the lifetime of the object,
		   call getDataCopy() instead of this function.

		   The return type is a pointer to the data, so it is a
		   double-pointer for template instantiations, for which the data itself
		   already is a pointer.

		   In case of an error, this function returns NULL.
		   @returns
		   the address of the original content of the object, if
		   successful, NULL otherwise.                                      */
		template<typename Etype>
		Etype* ValueObject<Etype>::getDataAddress(void) const
		{
			return (getType() == Helpers::ConfirmAllowed<Etype>::typeName && getDimensions() == Helpers::ConfirmAllowed<Etype>::dimensions)?getDataAddressImplementation<Etype>()(getDataPointer()):NULL;
		}

		template<typename Etype>
		template<typename Ftype>
		Ftype* ValueObject<Etype>::getDataAddressImplementation<Ftype>::operator()(const void* const* const ppData) const
		{
			return const_cast<Ftype*>(reinterpret_cast<const Ftype*>(ppData));
		}

		template<typename Etype>
		template<typename Ftype>
		Ftype** ValueObject<Etype>::getDataAddressImplementation<Ftype*>::operator()(const void* const* const ppData) const
		{
			return const_cast<Ftype**>(reinterpret_cast<const Ftype* const*>(ppData));
		}

		template<typename Etype>
		void ValueObject<Etype>::convert(const Object* const obj, nByte type, unsigned int dimensions)
		{
			if(obj && type == obj->getType()  && dimensions == obj->getDimensions())
				super::assign(*obj);
			else
				super::assign(Object());
		}
	}
}