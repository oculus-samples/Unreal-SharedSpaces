/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Helpers/SmartPointers/UniquePointer.h"
#include "Common-cpp/inc/Helpers/Stringification/Stringifier.h"
#include "Common-cpp/inc/Helpers/TypeID.h"
#include "Common-cpp/inc/Helpers/TypeName.h"

namespace ExitGames
{
	namespace Common
	{
		class JObject : public Base
		{
		public:
			using ToString::toString;

			template<typename FT> JObject(const FT& payload);
			template<typename FT> JObject(FT* payloadArray, unsigned int elementCount);

			JObject(const JObject& toCopy);
			JObject& operator=(const JObject& toCopy);

			bool operator==(const JObject& toCompare) const;
			bool operator!=(const JObject& toCompare) const;

			template<typename FT> const FT& getPayload(void) const;
			template<typename FT> FT& getPayload(void);
			unsigned int getElementCount(void) const;

			virtual JString& toString(JString& retStr, bool withTypes=false) const;
		private:
			class Storage : public Base
			{
			public:
				virtual bool operator==(const Storage& toCompare) const = 0;
				virtual bool operator!=(const Storage& toCompare) const;

				virtual unsigned int getElementCount(void) const = 0;

				virtual Storage* clone(void) const = 0;
				virtual size_t getPayloadTypeID(void) const = 0;
			};

			template<typename T>
			class StorageImplementation : public Storage
			{
			public:
				using ToString::toString;

				StorageImplementation(const T& payload);

				virtual bool operator==(const Storage& toCompare) const;

				const T& getPayload(void) const;
				T& getPayload(void);
				virtual unsigned int getElementCount(void) const;

				virtual Storage* clone(void) const;
				virtual size_t getPayloadTypeID(void) const;

				virtual JString& toString(JString& retStr, bool withTypes=false) const;
			private:
				StorageImplementation(const StorageImplementation& toCopy);
				StorageImplementation& operator=(const StorageImplementation& toCopy);

				T mPayload;
			};

			template<typename T>
			class StorageImplementation<T*> : public Storage
			{
			public:
				using ToString::toString;

				StorageImplementation(T* pPayloadArray, unsigned int elementCount);
				~StorageImplementation(void);

				virtual bool operator==(const Storage& toCompare) const;

				T* const& getPayload(void) const;
				T*& getPayload(void);
				virtual unsigned int getElementCount(void) const;

				virtual Storage* clone(void) const;
				virtual size_t getPayloadTypeID(void) const;

				virtual JString& toString(JString& retStr, bool withTypes=false) const;
			private:
				StorageImplementation(const StorageImplementation& toCopy);
				StorageImplementation& operator=(const StorageImplementation& toCopy);

				T* mpPayload;
				unsigned int mElementCount;
			};

			Helpers::UniquePointer<Storage> mupStorage;
		};



		template<typename FT>
		JObject::JObject(const FT& payload)
		{
			mupStorage = MemoryManagement::allocate<StorageImplementation<const FT> >(payload);
		}

		template<typename FT>
		JObject::JObject(FT* payloadArray, unsigned int elementCount)
		{
			mupStorage = MemoryManagement::allocate<StorageImplementation<FT*> >(payloadArray, elementCount);
		}

		template<typename FT>
		const FT& JObject::getPayload(void) const
		{
			return static_cast<const StorageImplementation<FT>&>(*mupStorage).getPayload();
		}

		template<typename FT>
		FT& JObject::getPayload(void)
		{
			return static_cast<StorageImplementation<FT>&>(*mupStorage).getPayload();
		}



		template<typename T>
		JObject::StorageImplementation<T>::StorageImplementation(const T& payload)
			: mPayload(payload)
		{
		}

		template<typename T>
		bool JObject::StorageImplementation<T>::operator==(const Storage& toCompare) const
		{
			return getPayloadTypeID() == toCompare.getPayloadTypeID() && mPayload == static_cast<const StorageImplementation<T>&>(toCompare).mPayload;
		}

		template<typename T>
		const T& JObject::StorageImplementation<T>::getPayload(void) const
		{
			return mPayload;
		}

		template<typename T>
		T& JObject::StorageImplementation<T>::getPayload(void)
		{
			return mPayload;
		}

		template<typename T>
		unsigned int JObject::StorageImplementation<T>::getElementCount(void) const
		{
			return 1;
		}

		template<typename T>
		JObject::Storage* JObject::StorageImplementation<T>::clone(void) const
		{
			return MemoryManagement::allocate<StorageImplementation<T> >(mPayload);
		}

		template<typename T>
		size_t JObject::StorageImplementation<T>::getPayloadTypeID(void) const
		{
			return Helpers::TypeID<T>::get();
		}

		template<typename T>
		JString& JObject::StorageImplementation<T>::toString(JString& retStr, bool /*withTypes*/) const
		{
			return retStr += L"(" + Helpers::TypeName::get<T>() + L")" + Helpers::Stringifier<T>::toString(mPayload);
		}



		template<typename T>
		JObject::StorageImplementation<T*>::StorageImplementation(T* pPayloadArray, unsigned int elementCount)
			: mpPayload(MemoryManagement::allocateArray<T>(elementCount))
			, mElementCount(elementCount)
		{
			for(size_t i=0; i<elementCount; ++i)
				mpPayload[i] = pPayloadArray[i];
		}

		template<typename T>
		JObject::StorageImplementation<T*>::~StorageImplementation(void)
		{
			MemoryManagement::deallocateArray(mpPayload);
		}

		template<typename T>
		bool JObject::StorageImplementation<T*>::operator==(const Storage& toCompare) const
		{
			const StorageImplementation<T*>& tC = static_cast<const StorageImplementation<T*>&>(toCompare);
			if(getPayloadTypeID() != toCompare.getPayloadTypeID() || mElementCount != tC.mElementCount)
				return false;
			for(size_t i=0; i<mElementCount; ++i)
				if(mpPayload[i] != tC.mpPayload[i])
					return false;
			return true;
		}

		template<typename T>
		T* const& JObject::StorageImplementation<T*>::getPayload(void) const
		{
			return mpPayload;
		}

		template<typename T>
		T*& JObject::StorageImplementation<T*>::getPayload(void)
		{
			return mpPayload;
		}

		template<typename T>
		unsigned int JObject::StorageImplementation<T*>::getElementCount(void) const
		{
			return mElementCount;
		}

		template<typename T>
		JObject::Storage* JObject::StorageImplementation<T*>::clone(void) const
		{
			return MemoryManagement::allocate<StorageImplementation<T*> >(mpPayload, mElementCount);
		}

		template<typename T>
		size_t JObject::StorageImplementation<T*>::getPayloadTypeID(void) const
		{
			return Helpers::TypeID<T*>::get();
		}

		template<typename T>
		JString& JObject::StorageImplementation<T*>::toString(JString& retStr, bool /*withTypes*/) const
		{
			return retStr += L"(" + Helpers::TypeName::get<T>() + L")" + Helpers::Stringifier<T>::toString(mpPayload, getElementCount());
		}
	}
}