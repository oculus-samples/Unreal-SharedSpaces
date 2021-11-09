/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/ToString.h"
#include "Common-cpp/inc/defines.h"

#ifndef EG_NOSTDLIB
#	include <iostream>
#endif

namespace ExitGames
{
	namespace Common
	{
		class UTF8String;
		class ANSIString;

		class JString : public ToString
		{
		public:
			using ToString::toString;

			explicit JString(unsigned int bufferlen=0);
			explicit JString(const char* Value);
			explicit JString(const EG_CHAR* Value);
			JString(const JString& Value);
			JString(const UTF8String& Value);
			JString(const ANSIString& Value);
			~JString(void);

			JString& operator=(const JString& Rhs);
			JString& operator=(const char* Rhs);
			JString& operator=(const EG_CHAR* Rhs);
			JString& operator=(const UTF8String& Rhs);
			JString& operator=(const ANSIString& Rhs);
			JString& operator=(char Rhs);
			JString& operator=(signed char Rhs);
			JString& operator=(unsigned char Rhs);
			JString& operator=(EG_CHAR Rhs);
			JString& operator=(short aNum);
			JString& operator=(unsigned short aNum);
			JString& operator=(int aNum);
			JString& operator=(unsigned int aNum);
			JString& operator=(long aNum);
			JString& operator=(unsigned long aNum);
			JString& operator=(long long aNum);
			JString& operator=(unsigned long long aNum);
			JString& operator=(float aNum);
			JString& operator=(double aNum);
			JString& operator=(long double aNum);
			JString& operator=(bool aBool);

			operator const EG_CHAR* (void) const;

			JString& operator+=(const JString& Rhs);
			template<typename Etype> JString& operator+=(const Etype& Rhs);

			bool operator==(const JString& Rhs) const;
			bool operator!=(const JString& Rhs) const;
			bool operator<(const JString& Rhs) const;
			bool operator>(const JString& Rhs) const;
			bool operator<=(const JString& Rhs) const;
			bool operator>=(const JString& Rhs) const;

			EG_CHAR operator[](unsigned int Index) const;
			EG_CHAR& operator[](unsigned int Index);

			unsigned int capacity(void) const;
			EG_CHAR charAt(unsigned int index) const;
			int compareTo(const JString& anotherString) const;
			const JString& concat(const JString& str);
			const EG_CHAR* cstr(void) const;
			JString deleteChars(unsigned int start, unsigned int length) const;
			bool endsWith(const JString& suffix) const;
			void ensureCapacity(unsigned int minCapacity);
			bool equals(const JString& anotherString) const;
			bool equalsIgnoreCase(const JString& anotherString) const;
			int indexOf(char ch) const;
			int indexOf(char ch, unsigned int fromIndex) const;
			int indexOf(EG_CHAR ch) const;
			int indexOf(EG_CHAR ch, unsigned int fromIndex) const;
			int indexOf(const JString& str) const;
			int indexOf(const JString& str, unsigned int fromIndex) const;
			int lastIndexOf(char ch) const;
			int lastIndexOf(char ch, unsigned int fromIndex) const;
			int lastIndexOf(EG_CHAR ch) const;
			int lastIndexOf(EG_CHAR ch, unsigned int fromIndex) const;
			int lastIndexOf(const JString& str) const;
			int lastIndexOf(const JString& str, unsigned int fromIndex) const;
			unsigned int length(void) const;
			JString replace(char oldChar, char newChar) const;
			JString replace(EG_CHAR oldChar, EG_CHAR newChar) const;
			JString replace(const JString& match, const JString& replacement) const;
			bool startsWith(const JString& prefix) const;
			bool startsWith(const JString& prefix, unsigned int offset) const;
			JString substring(unsigned int beginIndex) const;
			JString substring(unsigned int beginIndex, unsigned int endIndex) const;
			JString toLowerCase(void) const;
			JString toUpperCase(void) const;
			int toInt(void) const;
			JString trim(void);
			UTF8String UTF8Representation(void) const;
			ANSIString ANSIRepresentation(void) const;
			virtual JString& toString(JString& retStr, bool withTypes=false) const;
		private:
			void GetBuffer(unsigned int MaxStrLen);
			void verifyIndex(unsigned int number) const;
			template<typename Etype> JString& assign(const Etype& Rhs, unsigned int bufferLen, const EG_CHAR* formatSpecifier);

			EG_CHAR* mBuffer;        // Stores the characters
			unsigned int mBufferLen; // Max strlen for Buffer
			unsigned int mLength;    // length of string
		};

#ifndef EG_NOSTDLIB
		template<typename _Elem, typename _Traits> ::std::basic_ostream<_Elem, _Traits>& operator<<(::std::basic_ostream<_Elem, _Traits>& stream, const JString& string);
#endif
		JString operator+(const JString& Lsh, const JString& Rsh);
		template<typename Etype> JString operator+(const JString& Lsh, const Etype& Rsh);
		template<typename Etype> JString operator+(const Etype& Lsh, const JString& Rsh);
		template<typename Etype> bool operator==(const JString& Lsh, const Etype& Rsh);
		template<typename Etype> bool operator==(const Etype& Lsh, const JString& Rsh);
		template<typename Etype> bool operator!=(const JString& Lsh, const Etype& Rsh);
		template<typename Etype> bool operator!=(const Etype& Lsh, const JString& Rsh);
		template<typename Etype> bool operator<(const JString& Lsh, const Etype& Rsh);
		template<typename Etype> bool operator<(const Etype& Lsh, const JString& Rsh);
		template<typename Etype> bool operator>(const JString& Lsh, const Etype& Rsh);
		template<typename Etype> bool operator>(const Etype& Lsh, const JString& Rsh);
		template<typename Etype> bool operator<=(const JString& Lsh, const Etype& Rsh);
		template<typename Etype> bool operator<=(const Etype& Lsh, const JString& Rsh);
		template<typename Etype> bool operator>=(const JString& Lsh, const Etype& Rsh);
		template<typename Etype> bool operator>=(const Etype& Lsh, const JString& Rsh);



		/**
		   operator+=.
	   
		   Attaches its right operand to its left operand.*/
		template<typename Etype>
		JString& JString::operator+=(const Etype& Rhs)
		{
			JString str;
			str = Rhs;
			return *this += str;
		}

#ifndef EG_NOSTDLIB
		/**
		   @related JString
		   operator<<.

		   Used to print the JString to a std::wostream.*/
		template<typename _Elem, typename _Traits>
		::std::basic_ostream<_Elem, _Traits>& operator<<(::std::basic_ostream<_Elem, _Traits>& stream, const JString& string)
		{
			return stream << string.cstr();
		}
#endif
	
		/**
		   @related JString
		   operator+.

		   Adds its right operand to its left operand and returns the result as a new JString.*/
		template<typename Etype>
		JString operator+(const JString& Lsh, const Etype& Rsh)
		{
			return JString(Lsh) += Rsh;
		}

		/**
		   @related JString
		   operator+.

		   Adds its right operand to its left operand and returns the result as a new JString.*/
		template<typename Etype>
		JString operator+(const Etype& Lsh, const JString& Rsh)
		{
			return (JString() += Lsh) += Rsh;
		}
	
		/**
		   @related JString
		   operator==.
		   @returns true, if both operands are equal, false otherwise.*/
		template<typename Etype>
		bool operator==(const JString& Lsh, const Etype& Rsh)
		{
			return Lsh == JString(Rsh);
		}
	
		/**
		   @related JString
		   operator==.
		   @returns true, if both operands are equal, false otherwise.*/
		template<typename Etype>
		bool operator==(const Etype& Lsh, const JString& Rsh)
		{
			return JString(Lsh) == Rsh;
		}

		/**
		   @related JString
		   operator!=.
		   @returns false, if both operands are equal, true otherwise.*/
		template<typename Etype>
		bool operator!=(const JString& Lsh, const Etype& Rsh)
		{
			return Lsh != JString(Rsh);
		}

		/**
		   @related JString
		   operator!=.
		   @returns false, if both operands are equal, true otherwise.*/
		template<typename Etype>
		bool operator!=(const Etype& Lsh, const JString& Rsh)
		{
			return JString(Lsh) != Rsh;
		}
	
		/**
		   @related JString
		   operator<.
		   The return value indicates the lexicographic relation between the operands.
		   @returns true, if left operand is less than right operand, false otherwise.*/
		template<typename Etype>
		bool operator<(const JString& Lsh, const Etype& Rsh)
		{
			return Lsh < JString(Rsh);
		}
	
		/**
		   @related JString
		   operator<.
		   The return value indicates the lexicographic relation between the operands.
		   @returns true, if left operand is less than right operand, false otherwise.*/
		template<typename Etype>
		bool operator<(const Etype& Lsh, const JString& Rsh)
		{
			return JString(Lsh) < Rsh;
		}
	
		/**
		   @related JString
		   operator>.
		   The return value indicates the lexicographic relation between the operands.
		   @returns true, if left operand is greater than right operand, false otherwise.*/
		template<typename Etype>
		bool operator>(const JString& Lsh, const Etype& Rsh)
		{
			return Lsh > JString(Rsh);
		}
	
		/**
		   @related JString
		   operator>.
		   The return value indicates the lexicographic relation between the operands.
		   @returns true, if left operand is greater than right operand, false otherwise.*/
		template<typename Etype>
		bool operator>(const Etype& Lsh, const JString& Rsh)
		{
			return JString(Lsh) > Rsh;
		}
	
		/**
		   @related JString
		   operator<=.
		   The return value indicates the lexicographic relation between the operands.
		   @returns true, if the left operand is less than or equal to the right operand, false otherwise.*/
		template<typename Etype>
		bool operator<=(const JString& Lsh, const Etype& Rsh)
		{
			return Lsh <= JString(Rsh);
		}
	
		/**
		   @related JString
		   operator<=.
		   The return value indicates the lexicographic relation between the operands.
		   @returns true, if the left operand is less than or equal to the right operand, false otherwise.*/
		template<typename Etype>
		bool operator<=(const Etype& Lsh, const JString& Rsh)
		{
			return JString(Lsh) <= Rsh;
		}
	
		/**
		   @related JString
		   operator>=.
		   The return value indicates the lexicographic relation between the operands.
		   @returns true, if the left operand is greater than or equal to the right operand, false otherwise.*/
		template<typename Etype>
		bool operator>=(const JString& Lsh, const Etype& Rsh)
		{
			return Lsh >= JString(Rsh);
		}
	
		/**
		   @related JString
		   operator>=.
		   The return value indicates the lexicographic relation between the operands.
		   @returns true, if the left operand is greater than or equal to the right operand, false otherwise.*/
		template<typename Etype>
		bool operator>=(const Etype& Lsh, const JString& Rsh)
		{
			return JString(Lsh) >= Rsh;
		}
	}
}