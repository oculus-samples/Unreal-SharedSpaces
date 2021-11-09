/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/GenericAssociativeContainerBase.h"
#include "Common-cpp/inc/Containers/Hashtable.h"

namespace ExitGames
{
	namespace Common
	{
		class DictionaryBase : public GenericAssociativeContainerBase<DictionaryBase, Hashtable, Object>
		{
		private:
			typedef GenericAssociativeContainerBase<DictionaryBase, Hashtable, Object> super;
		public:
			using ToString::toString;

			virtual ~DictionaryBase(void);

			DictionaryBase(const DictionaryBase& toCopy);
			virtual DictionaryBase& operator=(const DictionaryBase& toCopy);

			virtual const nByte* getKeyTypes(void) const;
			virtual const nByte* getValueTypes(void) const;
			template<typename FKeyType> const short* getValueSizes(const FKeyType& key) const;
			virtual const unsigned int* getValueDimensions(void) const;
			virtual nByte getValueCustomType(void) const;

			JString typeToString(void) const;
			virtual JString& toString(JString& retStr, bool withTypes=false) const;
		protected:
			DictionaryBase(void);

			virtual DictionaryBase& assign(const GenericAssociativeContainerBase<DictionaryBase, Hashtable, Object>& toCopy);
			virtual DictionaryBase& assign(const DictionaryBase& toCopy);
		private:
			DictionaryBase(const nByte* pKeyTypes, const nByte* pValueTypes, const unsigned int* pValueDimensions, nByte customType);

			template<typename FKeyType, typename FValueType> const FValueType* getValueImplementation(const FKeyType& key, const FValueType* pDummyDeducer) const;
			template<typename FKeyType, typename FValueType> FValueType* getValueImplementation(const FKeyType& key, const FValueType* pDummyDeducer);
			template<typename FKeyType> JVector<FKeyType> getKeysImplementation(const FKeyType* pDummyDeducer) const;
			template<typename FValueType> const FValueType& getValueAtImplementation(unsigned int index, const FValueType* pDummyDeducer) const;
			template<typename FValueType> FValueType& getValueAtImplementation(unsigned int index, const FValueType* pDummyDeducer);

			virtual DictionaryBase* copy(short amount) const;

			class TypeInfo : public Base
			{
			public:
				using ToString::toString;
				using ToString::typeToString;

				TypeInfo(const nByte* pKeyTypes, const nByte* pValueTypes, const unsigned int* pValueDimensions, nByte customType);
				TypeInfo(const TypeInfo& toCopy);
				TypeInfo& operator=(const TypeInfo& toCopy);
				~TypeInfo(void);

				virtual JString& toString(JString& retStr, bool withTypes=false) const;
				const nByte* getKeyTypes(void) const;
				const nByte* getValueTypes(void) const;
				const unsigned int* getValueDimensions(void) const;
				nByte getValueCustomType(void) const;
			private:
				void init(const nByte* pKeyTypes, const nByte* pValueTypes, const unsigned int* pValueDimensions, nByte customType);
				void cleanup(void);
				JString toStringRecursor(bool withTypes, unsigned int recursionDepth=0) const;
				static JString typeToString(nByte typeCode);

				nByte* mpKeyTypes;
				nByte* mpValueTypes;
				unsigned int* mpValueDimensions;
				nByte mValueCustomType; 
			};

			TypeInfo* mpTypeInfo;

			friend super;
			friend class Helpers::DeSerializerImplementation;
			friend class Object;
			friend class ::EGUtilsHelper;
		};



		/** @returns Object::getSizes() of the value, that corresponds to the passed key.
		    @param key Reference to the key to return the corresponding value sizes for
			*/
		template<typename FKeyType>
		const short* DictionaryBase::getValueSizes(const FKeyType& key) const
		{
			return getHashtable().getValue(key)->getSizes();
		}

		template<typename FKeyType, typename FValueType>
		const FValueType* DictionaryBase::getValueImplementation(const FKeyType& key, const FValueType* /*pDummyDeducer*/) const
		{
			const ValueObject<FValueType>* pRetObject = static_cast<const ValueObject<FValueType>*>(getHashtable().getValue(key));
			return pRetObject?pRetObject->getDataAddress():NULL;
		}

		template<typename FKeyType, typename FValueType>
		FValueType* DictionaryBase::getValueImplementation(const FKeyType& key, const FValueType* /*pDummyDeducer*/)
		{
			ValueObject<FValueType>* pRetObject = static_cast<ValueObject<FValueType>*>(mHashtable.getValue(key));
			return pRetObject?pRetObject->getDataAddress():NULL;
		}

		template<typename FKeyType>
		JVector<FKeyType> DictionaryBase::getKeysImplementation(const FKeyType* /*pDummyDeducer*/) const
		{
			JVector<FKeyType> keys;
			JVector<Object> keyObjs = getHashtable().getKeys();
			for(unsigned int i=0; i<keyObjs.getSize(); ++i)
				keys.addElement(static_cast<KeyObject<FKeyType>&>(keyObjs[i]).getDataCopy());
			return keys;
		}

		template<typename FValueType>
		const FValueType& DictionaryBase::getValueAtImplementation(unsigned int index, const FValueType* /*pDummyDeducer*/) const
		{
			return *static_cast<const ValueObject<FValueType>&>(getHashtable()[index]).getDataAddress();
		}

		template<typename FValueType>
		FValueType& DictionaryBase::getValueAtImplementation(unsigned int index, const FValueType* /*pDummyDeducer*/)
		{
			return *static_cast<ValueObject<FValueType>&>(mHashtable[index]).getDataAddress();
		}
	}
}