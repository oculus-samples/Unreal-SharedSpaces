/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
* http://www.photonengine.com
* mailto:developer@photonengine.com
*/

#pragma once

#include "Common-cpp/inc/Helpers/CompileTimeAssertTrue.h"
#include "Common-cpp/inc/Object.h"
#include "Common-cpp/inc/Enums/TypeCode.h"

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename CType, unsigned int N=0> struct ConfirmAllowedKey
			{
				COMPILE_TIME_ASSERT_TRUE_MSG(N-N, ERROR_UNSUPPORTED_KEY_TYPE); // N-N instead of false delays the assert to actual instantiation
			};
			template<> struct ConfirmAllowedKey<nByte>
			{
				typedef nByte type;
				static const nByte typeName = TypeCode::BYTE;
			};
			template<> struct ConfirmAllowedKey<short>
			{
				typedef short type;
				static const nByte typeName = TypeCode::SHORT;
			};
			template<> struct ConfirmAllowedKey<int>
			{
				typedef int type;
				static const nByte typeName = TypeCode::INTEGER;
			};
			template<> struct ConfirmAllowedKey<int64>
			{
				typedef int64 type;
				static const nByte typeName = TypeCode::LONG;
			};
			template<> struct ConfirmAllowedKey<float>
			{
				typedef float type;
				static const nByte typeName = TypeCode::EG_FLOAT;
			};
			template<> struct ConfirmAllowedKey<double>
			{
				typedef double type;
				static const nByte typeName = TypeCode::DOUBLE;
			};
			template<> struct ConfirmAllowedKey<JString>
			{
				typedef JString type;
				static const nByte typeName = TypeCode::STRING;
			};
			template<> struct ConfirmAllowedKey<char*>
			{
				typedef JString type;
				static const nByte typeName = TypeCode::STRING;
			};
			template<> struct ConfirmAllowedKey<const char*>
			{
				typedef JString type;
				static const nByte typeName = TypeCode::STRING;
			};
			template<unsigned int N> struct ConfirmAllowedKey<char[N]>
			{
				typedef JString type;
				static const nByte typeName = TypeCode::STRING;
			};
			template<unsigned int N> struct ConfirmAllowedKey<const char[N]>
			{
				typedef JString type;
				static const nByte typeName = TypeCode::STRING;
			};
			template<> struct ConfirmAllowedKey<wchar_t*>
			{
				typedef JString type;
				static const nByte typeName = TypeCode::STRING;
			};
			template<> struct ConfirmAllowedKey<const wchar_t*>
			{
				typedef JString type;
				static const nByte typeName = TypeCode::STRING;
			};
			template<unsigned int N> struct ConfirmAllowedKey<wchar_t[N]>
			{
				typedef JString type;
				static const nByte typeName = TypeCode::STRING;
			};
			template<unsigned int N> struct ConfirmAllowedKey<const wchar_t[N]>
			{
				typedef JString type;
				static const nByte typeName = TypeCode::STRING;
			};
			template<> struct ConfirmAllowedKey<Object>
			{
				typedef Object type;
				typedef Object scalarType;
				static const unsigned int dimensions;
				static const nByte typeName = TypeCode::OBJECT;
				static const nByte customTypeName = 0;
			};
		}
	}
}