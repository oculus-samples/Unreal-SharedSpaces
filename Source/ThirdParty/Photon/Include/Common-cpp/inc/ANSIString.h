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
		class ANSIString : public BaseCharString
		{
		public:
			ANSIString(void);
			ANSIString(const ANSIString& str);
			ANSIString(const JString& str);
			ANSIString(const char* str);
			ANSIString(const EG_CHAR* str);
			~ANSIString(void);

			ANSIString& operator=(const ANSIString& Rhs);
			ANSIString& operator=(const JString& Rhs);
			ANSIString& operator=(const char* Rhs);
			ANSIString& operator=(const EG_CHAR* Rhs);

			operator const char* (void) const;
			operator JString (void) const;

			JString JStringRepresentation(void) const;
			unsigned int size(void) const;
		private:
			class ANSIConverter : public Base
			{
			public:
				static char* Unicode2ANSI(const EG_CHAR* wstr, char* str, unsigned int strSize);
				static EG_CHAR* ANSI2Unicode(const char* str, EG_CHAR* wstr, unsigned int wstrLen);
#ifdef _EG_PS4_OR_NEWER_PLATFORM
			private:
				static bool mInitialized;
#endif
			};
		};
	}
}