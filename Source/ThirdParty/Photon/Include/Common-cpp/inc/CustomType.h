/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
* http://www.photonengine.com
* mailto:developer@photonengine.com
*/

#pragma once

#include "Common-cpp/inc/CustomTypeBase.h"
#include "Common-cpp/inc/Helpers/CustomTypeFactory.h"

namespace ExitGames
{
	namespace Common
	{
		template<typename T, nByte typeCode>
		class CustomType : public CustomTypeBase
		{
		public:
			static void registerType(void);
			static void unregisterType(void);

			static const nByte TypeCode = typeCode;
		protected:
			CustomType(void);
			CustomType(const CustomType& toCopy);
			~CustomType(void);
		private:
			typedef CustomTypeBase super;

			static void* ccalloc(short count, nByte customTypeCode);
			static void cfree(const void* pData, nByte customTypeCode);
			static unsigned int csizeOf(nByte customTypeCode);

			static Helpers::CustomTypeFactory<T, typeCode>* mpFactory;
		};



		/** @file */

		template<typename T, nByte typeCode>
		Helpers::CustomTypeFactory<T, typeCode>* CustomType<T, typeCode>::mpFactory = NULL;

		/** @class CustomType
		   The CustomType class provides you with an interface, to add support for additional data-types.
		   @details
		   We only support a certain subset of @link Datatypes Datatypes\endlink out of the box.
		   If you need support for further datatypes, then you can easily add this support yourself by subclassing this
		   class template and providing suitable implementations for the pure virtual functions, which are inherited from CustomTypeBase,
		   in your subclass.
		   You should only subclass every typecode once. typeCode 0 should be considered as reserved.
		   So your first custom type would inherit from CustomType<1>, the second one from CustomType<2> and so on.
		   Subclassing the same typecode multiple times will lead into undefined behavior as the typecode will determine the class
		   as instance of which serialized data should be interpreted.
		   @remarks
		   When you are subclassing a specialization of CustomType, then you will also have to subclass the according specialization of
		   CustomTypeFactory (the one for the same typecode).
		   @sa CustomTypeBase, CustomTypeFactory
		   */

		/** @var CustomType::TypeCode
		    Check this public constant to find out the typecode of a custom type at runtime.
			This should normally not be of any interest.*/
		
		/**
		   This static function registers the custom type and has to be called once on each concrete subclass, before any instance of that
		   concrete subclass gets created.
		   @sa unregisterType()*/
		template<typename T, nByte typeCode>
		void CustomType<T, typeCode>::registerType(void)
		{
			super::constructClass(typeCode, &ccalloc, &cfree, &csizeOf);
			mpFactory = MemoryManagement::allocate<Helpers::CustomTypeFactory<T, typeCode> >();
		}
		
		/**
		   This static function unregisters a custom type and has to be called once for each concrete subclass after the last instance of that
		   subclass has been deallocated.
		   @sa registerType() */
		template<typename T, nByte typeCode>
		void CustomType<T, typeCode>::unregisterType(void)
		{
			super::destructClass(typeCode);
			MemoryManagement::deallocate(mpFactory);
		}

		template<typename T, nByte typeCode>
		CustomType<T, typeCode>::CustomType(void)
		{
		}

		template<typename T, nByte typeCode>
		CustomType<T, typeCode>::CustomType(const CustomType& /*toCopy*/)
		{
		}

		template<typename T, nByte typeCode>
		CustomType<T, typeCode>::~CustomType(void)
		{
		}

		template<typename T, nByte typeCode>
		void* CustomType<T, typeCode>::ccalloc(short count, nByte /*customTypeCode*/)
		{
			return mpFactory->create(count);
		}

		template<typename T, nByte typeCode>
		void CustomType<T, typeCode>::cfree(const void* pData, nByte /*customTypeCode*/)
		{
			mpFactory->destroy(static_cast<const CustomType<T, typeCode>*>(pData));
		}

		template<typename T, nByte typeCode>
		unsigned int CustomType<T, typeCode>::csizeOf(nByte /*customTypeCode*/)
		{
			return mpFactory->sizeOf();
		}
	}
}