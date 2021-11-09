/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/DictionaryBase.h"
#include "Common-cpp/inc/UTF8String.h"
#ifdef EG_PLATFORM_SUPPORTS_MOVE_SEMANTICS
#	include "Common-cpp/inc/Helpers/Data.h"
#endif

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			class SerializerImplementation : public Base
			{
			public:
				using ToString::toString;

				SerializerImplementation(void);
				~SerializerImplementation(void);

				const nByte* getData(void) const;
				int getDataOffset(void) const;

				template<typename T> bool push(T* data, bool setType=false);
				bool pushObject(const Object* serObject, bool setType);
				void pushByteArray(nByte* byteArr, int length, bool setType);
				void pushCustom(void* data, nByte customType, bool setType);

				virtual JString& toString(JString& retStr, bool withTypes=false) const;

#ifdef EG_PLATFORM_SUPPORTS_MOVE_SEMANTICS
				Helpers::Data release(void);
#endif
			protected:
				void extendInternalBuffer(int size);

				template<typename T> bool write(const T& data);
				bool writeByte(nByte data);
				bool write(const JString& str);
				bool write(const Hashtable& hash);
				bool write(const DictionaryBase& dict, bool setKeyValueTypes);
				bool writeCustom(const void* data, nByte customType);
				bool writeObject(const Object* obj, bool setType);
				void writeByteArray(const nByte* byteArr, int length);
				bool writeArray(const Object* obj);
				bool writeArrayHelper(const void* pData, nByte type, nByte customType, unsigned int dimensions, short* arraySizes, unsigned int recursionDepth);
				bool writeArrayType(const void* pData, nByte type, nByte customType, short i);

				int getBufferSize() const { return mBufferSize; }

				void writeInvertedData(const void* data, int size);

				template<typename T> unsigned int getTypeSize(const T* = NULL) const { return sizeof(T); }
				unsigned int getTypeSize(const Hashtable* tbl) const;
				unsigned int getTypeSize(const JString* str) const;
				unsigned int getTypeSize(const DictionaryBase* dict) const;

				unsigned int getCustomSize(const void* data, nByte customType) const;
				unsigned int getObjectSize(const Object* serObject, bool setType) const;
				unsigned int getByteArraySize(int length) const;
				bool calcArraySize(const void* pData, nByte type, nByte customType, unsigned int dimensions, const short* arraySizes, unsigned int recursionDepth, unsigned int& result) const;
			private:
				int mBufferSize;
				int mDataOffset;
				nByte* mpData;
			};



			template<typename T>
			bool SerializerImplementation::push(T* data, bool setType)
			{
				extendInternalBuffer(getTypeSize(data) + (setType?getTypeSize<nByte>():0));
				if(setType)
					writeByte(Helpers::ConfirmAllowed<T>::typeName);
				return write(*data);
			}

			template<typename T>
			bool SerializerImplementation::write(const T& data)
			{
				writeInvertedData(&data, sizeof(T));
				return true;
			}
		}
	}
}