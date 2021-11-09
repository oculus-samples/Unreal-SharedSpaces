/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Base.h"

namespace ExitGames
{
	namespace Common
	{
		class JTime : public Base
		{
		public:
			using ToString::toString;

			JTime(int time=GETTIMEMS());
			~JTime(void);

			JTime(const JTime& toCopy);
			JTime& operator=(const JTime& toCopy);

			JTime& operator=(int time);
			JTime& operator+=(const JTime& time);
			JTime& operator+=(int time);
			JTime& operator-=(const JTime& time);
			JTime& operator-=(int time);

			bool operator<(const JTime& time) const;
			bool operator>(const JTime& time) const;
			bool operator<=(const JTime& time) const;
			bool operator>=(const JTime& time) const;
			bool operator==(const JTime& time) const;
			bool operator!=(const JTime& time) const;

			operator int(void) const;

			bool overflowed(const JTime& time) const;
			virtual JString& toString(JString& retStr, bool withTypes=false) const;
		private:
			static const unsigned int TIME_OVERFLOW = 86400000u;

			int t;
		};

		int& operator+=(int& Lsh, const JTime& Rsh);
		int& operator-=(int& Lsh, const JTime& Rsh);
		JTime operator+(const JTime& Lsh, const JTime& Rsh);
		JTime operator+(const JTime& Lsh, int Rsh);
		JTime operator+(int Lsh, const JTime& Rsh);
		JTime operator-(const JTime& Lsh, const JTime& Rsh);
		JTime operator-(const JTime& Lsh, int Rsh);
		JTime operator-(int Lsh, const JTime& Rsh);
		bool operator==(const JTime& Lsh, int Rsh);
		bool operator==(int Lsh, const JTime& Rsh);
		bool operator!=(const JTime& Lsh, int Rsh);
		bool operator!=(int Lsh, const JTime& Rsh);
		bool operator<(const JTime& Lsh, int Rsh);
		bool operator<(int Lsh, const JTime& Rsh);
		bool operator>(const JTime& Lsh, int Rsh);
		bool operator>(int Lsh, const JTime& Rsh);
		bool operator<=(const JTime& Lsh, int Rsh);
		bool operator<=(int Lsh, const JTime& Rsh);
		bool operator>=(const JTime& Lsh, int Rsh);
		bool operator>=(int Lsh, const JTime& Rsh);
	}
}