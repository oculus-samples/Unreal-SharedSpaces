/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/BaseCharString.h"

namespace ExitGames
{
	namespace Common
	{
		class UTF8String : public BaseCharString
		{
		public:
			UTF8String(void);
			UTF8String(const UTF8String& str);
			UTF8String(const JString& str);
			UTF8String(const char* str);
			UTF8String(const EG_CHAR* str);
			~UTF8String(void);

			UTF8String& operator=(const UTF8String& Rhs);
			UTF8String& operator=(const JString& Rhs);
			UTF8String& operator=(const char* Rhs);
			UTF8String& operator=(const EG_CHAR* Rhs);

			operator const char* (void) const;
			operator JString (void) const;

			JString JStringRepresentation(void) const;
			unsigned int size(void) const;

			static unsigned int size(const JString& str);
		private:
			static unsigned int bytesPerChar(char c);
			static unsigned int lenForSize(const char* str, unsigned int size);
			static unsigned int sizeForLen(const char* str, unsigned int len);
			static unsigned int countOfWideCharsForSize(const char* str, unsigned int size);

			class UTF8Converter : public Base
			{
			public:
				static char* Unicode2UTF8(const EG_CHAR* wstr, unsigned int src_len, char* dst, unsigned int dst_size);
				static EG_CHAR* UTF82Unicode(const unsigned char* str, unsigned int src_size, EG_CHAR* dst, unsigned int dst_len);
				static unsigned int SizeOfWStrAsUTF8(const EG_CHAR* str, unsigned int len);
			};
		};
	}
}