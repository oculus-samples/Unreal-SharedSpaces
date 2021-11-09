/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Base.h"

class EGUtilsHelper;

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			class SerializerImplementation;
			class DeSerializerImplementation;
		}

		class Object : public Base
		{
		public:
			using ToString::toString;

			Object(void);
			virtual ~Object(void);

			Object(const Object& toCopy);
			virtual Object& operator=(const Object& toCopy);

			bool operator==(const Object& toCompare) const;
			bool operator!=(const Object& toCompare) const;

			nByte getType(void) const;
			nByte getCustomType(void) const;
			const short* getSizes(void) const;
			unsigned int getDimensions(void) const;
			virtual JString& toString(JString& retStr, bool withTypes=false) const;
		protected:
			Object(const void* data, nByte type, nByte customType, bool makeCopy);
			Object(const void* data, nByte type, nByte customType, int size, bool makeCopy);
			Object(const nByte* data, int size, bool makeCopy);
			Object(const void* data, nByte type, nByte customType, unsigned int dimensions, const short* sizes, bool makeCopy);

			const void* getData(void) const;
			const void* const* getDataPointer(void) const;
			virtual Object& assign(const Object& toCopy);
		private:
			union Data
			{
				nByte byteData;
				short shortData;
				int intData;
				int64 int64Data;
				float floatData;
				double doubleData;
				bool boolData;
			};

			void setSizes(const short* sizes, unsigned int dimensions=1);
			void setDimensions(unsigned int dimensions);
			void setData(const void* data);
			void setDataNoCopy(void* data);
			void setType(nByte type);
			void setCustomType(nByte customType);
			void set(const void* data, nByte type, nByte customType, bool makeCopy);
			void set(const void* data, nByte type, nByte customType, int size, bool makeCopy);
			void set(const void* data, nByte type, nByte customType, unsigned int dimensions, const short* sizes, bool makeCopy);
			void setWithoutCleanup(const void* data, nByte type, nByte customType, bool makeCopy);
			void setWithoutCleanup(const void* data, nByte type, nByte customType, int size, bool makeCopy);
			void setWithoutCleanup(const void* data, nByte type, nByte customType, unsigned int dimensions, const short* sizes, bool makeCopy);
			void setToNULL(void);
			void cleanup(const void* pData=0, unsigned int recursionDepth=0);
			void copyArray(const void* pDataIn, void** pDataOut, unsigned int recursionDepth=0) const;
			bool equalsArray(const void* pData1, const void* pData2, unsigned int recursionDepth=0) const;
			static JString& toStringHelper(const Object& object, JString& retStr, bool withTypes=false, bool butWithOutTopLevelTypes=false);
			JString payloadTypeToString(void) const;
			bool compareHelper(const void* pData1, const void* pData2, nByte type, nByte customType, unsigned int dimensions, const short* arraySizes, unsigned int recursionDepth) const;
			static Data constructDataInstance(nByte payload);
			static Data constructDataInstance(short payload);
			static Data constructDataInstance(int payload);
			static Data constructDataInstance(int64 payload);
			static Data constructDataInstance(float payload);
			static Data constructDataInstance(double payload);
			static Data constructDataInstance(bool payload);

			Data mData;
			void* mpData;
			int mSize;
			short* mpSizes;
			nByte mType;
			nByte mCustomType;
			unsigned int mDimensions;

			friend class DictionaryBase;
			template<typename EKeyType, typename EValueType> friend class Dictionary;
			friend class Hashtable;
			friend class Helpers::SerializerImplementation;
			friend class Helpers::DeSerializerImplementation;
			friend class ::EGUtilsHelper;
		};
	}
}