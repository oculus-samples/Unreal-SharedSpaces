/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Containers/Hashtable.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			class DeSerializerImplementation : public Base
			{
			public:
				using ToString::toString;

				DeSerializerImplementation(const nByte* data);

				int getReadPosition(void) const;

				bool pop(Object& object);
				bool popType(nByte param, Object& object);
				void popByte(Object& object);
				void popByteArray(Object& object);
				void popShort(Object& object);
				void popInteger(Object& object);
				void popLong(Object& object);
				void popFloat(Object& object);
				void popDouble(Object& object);
				void popBoolean(Object& object);
				void popString(Object& object);
				void popHashTable(Object& object);
				void popDictionary(Object& object);
				void popCustom(Object& object, nByte customType);

				nByte readByte(void);
				short readShort(void);
				int readInt(void);
				int64 readLong(void);
				float readFloat(void);
				double readDouble(void);
				bool readBoolean(void);

				virtual JString& toString(JString& retStr, bool withTypes=false) const;
			protected:
				void popStringHelper(JString& str);
				void popHashTableHelper(Hashtable& hash);
				void popArrayOfDictionaries(Object& dict, short arraySize, int dimensions=0);
				const DictionaryBase* popDictionaryHelper(nByte* pKeyTypes, nByte* pValueTypes, unsigned int* pDimensionsOfNestedValues, nByte customType);
				void popCustomHelper(Object& object, nByte customType, short arraySize, int dimensions=0);
				void popArray(Object& array); 
				void popObjectArray(Object& array);

				void readDictionaryTypes(nByte** ppKeyTypes, nByte** ppValTypes, unsigned int** ppDimensionsOfNestedValues, nByte* pCustomType);
			private:
				int mDataOffset;
				nByte* mpData;
			};
		}
	}
}