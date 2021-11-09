/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/ConfirmAllowedKey.h"

namespace ExitGames
{
	namespace Common
	{
		/**
		   Container class template for objects to be stored as keys in a Hashtable or Dictionary.
		   @remarks
		   In most cases the library will do the work of storing a key in a KeyObject for you, so for example you don't have to explicitly
		   create an instance of this class, when storing a key-value pair in a Dictionary or Hashtable instance. However there are some
		   situations, where you will receive instances of class Object or want to create them (for example Hashtable::getKeys() will
		   return a JVector<Object>) and in that case casting those instances into KeyObject-instances can be a convenient way of assuring
		   a type-safe access to their payloads. */
		template<typename Etype>
		class KeyObject : public Object
		{
		public:
			KeyObject(const KeyObject<Etype>& toCopy);
			KeyObject(const Object& obj);
			KeyObject(const Object* obj);
			KeyObject(const typename Helpers::ConfirmAllowedKey<Etype>::type& data);
			virtual ~KeyObject(void);

			virtual KeyObject<Etype>& operator=(const KeyObject<Etype>& toCopy);
			virtual KeyObject<Etype>& operator=(const Object& toCopy);

			Etype getDataCopy(void) const;
			Etype* getDataAddress(void) const;
		protected:
			virtual KeyObject<Etype>& assign(const Object& toCopy);
		private:
			typedef Object super;

			void convert(const Object* obj, nByte type);
		};



		/** @file */

		/**
		   Copy-Constructor.

		   Creates an object out of a deep copy of its parameter.

		   The parameter has to be of the same template instantiation as the
		   object, you want to create.
		   @param toCopy The object to copy.                                */
		template<typename Etype>
		KeyObject<Etype>::KeyObject(const KeyObject<Etype>& toCopy) : Object(toCopy)
		{
		}

		/**
		   Constructor.
	   
		   Creates an object out of a deep copy of the passed Object&.
	   
		   If the type of the content of the passed object does not
		   match the template instantiation of the object to create, an empty
		   object is created instead of a copy of the passed object,
		   which leads to getDataCopy()
		   and getDataAddress() return
		   0.
		   @param obj The Object& to copy.                                 */
		template<typename Etype>
		KeyObject<Etype>::KeyObject(const Object& obj)
		{
			convert(&obj, Helpers::ConfirmAllowedKey<Etype>::typeName);
		}

		/**
		   Constructor.
	   
		   Creates an object out of a deep copy of the passed Object*.
	   
		   If the type of the content of the passed object does not
		   match the template instantiation of the object to create, an empty
		   object is created instead of a copy of the passed object,
		   which leads to getDataCopy()
		   and getDataAddress() return
		   0.
		   @param obj The Object* to copy.                                 */
		template<typename Etype>
		KeyObject<Etype>::KeyObject(const Object* const obj)
		{
			convert(obj, Helpers::ConfirmAllowedKey<Etype>::typeName);
		}

		/**
		   Constructor.
	   
		   Creates an object out of a deep copy of the passed Etype.
	   
		   @param data The value to copy. Has to be of a supported type.         */
		template<typename Etype>
		KeyObject<Etype>::KeyObject(const typename Helpers::ConfirmAllowedKey<Etype>::type& data) : Object(&data, Helpers::ConfirmAllowedKey<Etype>::typeName, 0, true)
		{
		}

		/**
		   Destructor. */
		template<typename Etype>
		KeyObject<Etype>::~KeyObject(void)
		{
		}

		/**
		   operator= : Makes a deep copy of its right operand into its
		   left operand. This overwrites old data in the left operand.  */
		template<typename Etype>
		KeyObject<Etype>& KeyObject<Etype>::operator=(const KeyObject<Etype>& toCopy)
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
		KeyObject<Etype>& KeyObject<Etype>::operator=(const Object& toCopy)
		{
			return assign(toCopy);
		}

		template<typename Etype>
		KeyObject<Etype>& KeyObject<Etype>::assign(const Object& toCopy)
		{
			if(Helpers::ConfirmAllowedKey<Etype>::typeName == toCopy.getType())
				super::assign(toCopy);
			return *this;
		}

		/**
		   Returns a deep copy of the content of the object. If you
		   only need access to the content, while the object still
		   exists, you can use getDataAddress()
		   instead to avoid the deep copy. That is especially
		   interesting for large content, of course.
	   
		   If successful, the template instantiations for array types of this
		   function allocate the data for the copy, so you have to free
		   (for arrays of primitive types) or delete (for arrays of
		   class objects) it, as soon, as you do not need the array
		   anymore. All non-array copies free there memory
		   automatically, as soon as they leave their scope, same as the
		   single indices of the array, as soon, as the array is freed.
	   
		   In case of an error this function returns 0 for primitive
		   return types and empty objects for classes.
		   @returns
		   a deep copy of the content of the object if successful, 0 or
		   an empty object otherwise.                                             */
		template<typename Etype>
		inline Etype KeyObject<Etype>::getDataCopy(void) const
		{
			if(getType() == Helpers::ConfirmAllowedKey<Etype>::typeName)
				return *(Etype*)getData();
			else
				return Etype();
		}

		/**
		   Returns the address of the original content of the object.
		   If you need access to the data above lifetime of the object,
		   call getDataCopy().
	   
		   The return type is a pointer to the data, so it is a
		   double-pointer, of course, for template instantiations, which data
		   already is a pointer.
	   
		   In case of an error, this function returns 0.
		   @returns
		   the address of the original content of the object, if
		   successful, 0 otherwise.                                      */
		template<typename Etype>
		inline Etype* KeyObject<Etype>::getDataAddress(void) const
		{
			if(getType() == Helpers::ConfirmAllowedKey<Etype>::typeName)
				return (Etype*)getData();
			else
				return 0;
		}

		template<typename Etype>
		void KeyObject<Etype>::convert(const Object* const obj, nByte type)
		{
			super::assign((obj && type == obj->getType())?*obj:Object());
		}
	}
}