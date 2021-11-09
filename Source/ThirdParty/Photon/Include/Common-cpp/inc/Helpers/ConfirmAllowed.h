/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
* http://www.photonengine.com
* mailto:developer@photonengine.com
*/

#pragma once

#include "Common-cpp/inc/CustomType.h"
#include "Common-cpp/inc/Enums/TypeCode.h"
#include "Common-cpp/inc/Helpers/CompileTimeAssertTrue.h"
#include "Common-cpp/inc/Helpers/TypeTraits/IsDerivedFrom.h"

namespace ExitGames
{
	namespace Common
	{
		class Object;
		template<typename EType> class JVector;
		class Hashtable;
		template<typename EKeyType, typename EValueType> class Dictionary;

		namespace Helpers
		{
			template<typename CType, unsigned int N=0> struct ConfirmAllowed
			{
				COMPILE_TIME_ASSERT_TRUE_MSG((IsDerivedFrom<CType, CustomType<CType, CType::TypeCode> >::is), ERROR_UNSUPPORTED_VALUE_TYPE);
				typedef CType type;
				typedef CType scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::CUSTOM;
				static const nByte customTypeName = CType::TypeCode;
			};
			template<typename Key, typename Val> struct ConfirmAllowed<Dictionary<Key, Val> >
			{
				typedef Dictionary<Key, Val> type;
				typedef Dictionary<Key, Val> scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::DICTIONARY;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<nByte>
			{
				typedef nByte type;
				typedef nByte scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::BYTE;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<short>
			{
				typedef short type;
				typedef short scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::SHORT;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<int>
			{
				typedef int type;
				typedef int scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::INTEGER;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<int64>
			{
				typedef int64 type;
				typedef int64 scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::LONG;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<float>
			{
				typedef float type;
				typedef float scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::EG_FLOAT;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<double>
			{
				typedef double type;
				typedef double scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::DOUBLE;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<bool>
			{
				typedef bool type;
				typedef bool scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::BOOLEAN;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<JString>
			{
				typedef JString type;
				typedef JString scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::STRING;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<char*>
			{
				typedef JString type;
				typedef JString scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::STRING;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<const char*>
			{
				typedef JString type;
				typedef JString scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::STRING;
				static const nByte customTypeName = 0;
			};
			template<unsigned int N> struct ConfirmAllowed<char[N]>
			{
				typedef JString type;
				typedef JString scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::STRING;
				static const nByte customTypeName = 0;
			};
			template<unsigned int N> struct ConfirmAllowed<const char[N]>
			{
				typedef JString type;
				typedef JString scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::STRING;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<wchar_t*>
			{
				typedef JString type;
				typedef JString scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::STRING;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<const wchar_t*>
			{
				typedef JString type;
				typedef JString scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::STRING;
				static const nByte customTypeName = 0;
			};
			template<unsigned int N> struct ConfirmAllowed<wchar_t[N]>
			{
				typedef JString type;
				typedef JString scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::STRING;
				static const nByte customTypeName = 0;
			};
			template<unsigned int N> struct ConfirmAllowed<const wchar_t[N]>
			{
				typedef JString type;
				typedef JString scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::STRING;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<Hashtable>
			{
				typedef Hashtable type;
				typedef Hashtable scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::HASHTABLE;
				static const nByte customTypeName = 0;
			};
			template<> struct ConfirmAllowed<Object>
			{
				typedef Object type;
				typedef Object scalarType;
				static const unsigned int dimensions = 0;
				static const nByte typeName = TypeCode::OBJECT;
				static const nByte customTypeName = 0;
			};
			template<typename CType> struct ConfirmAllowed<const CType>
			{
				typedef const typename ConfirmAllowed<CType>::type type;
				typedef const typename ConfirmAllowed<CType>::scalarType scalarType;
				static const unsigned int dimensions = ConfirmAllowed<CType>::dimensions;
				static const nByte typeName =ConfirmAllowed<CType>::typeName;
				static const nByte customTypeName = ConfirmAllowed<CType>::customTypeName;
			};
			template<typename CType> struct ConfirmAllowed<CType*>
			{
				typedef typename ConfirmAllowed<CType>::type* type;
				typedef typename ConfirmAllowed<CType>::scalarType scalarType;
				static const unsigned int dimensions = ConfirmAllowed<CType>::dimensions+1;
				static const nByte typeName = ConfirmAllowed<CType>::typeName;
				static const nByte customTypeName = ConfirmAllowed<CType>::customTypeName;
			};
			template<typename CType> struct ConfirmAllowed<const CType*>
			{
				typedef typename ConfirmAllowed<const CType>::type* type;
				typedef typename ConfirmAllowed<const CType>::scalarType scalarType;
				static const unsigned int dimensions = ConfirmAllowed<const CType>::dimensions+1;
				static const nByte typeName = ConfirmAllowed<const CType>::typeName;
				static const nByte customTypeName = ConfirmAllowed<const CType>::customTypeName;
			};
			template<typename CType, unsigned int N> struct ConfirmAllowed<CType[N]>
			{
				typedef typename ConfirmAllowed<CType>::type* type;
				typedef typename ConfirmAllowed<CType>::scalarType scalarType;
				static const unsigned int dimensions = ConfirmAllowed<CType>::dimensions+1;
				static const nByte typeName = ConfirmAllowed<CType>::typeName;
				static const nByte customTypeName = ConfirmAllowed<CType>::customTypeName;
			};
			template<typename CType, unsigned int N> struct ConfirmAllowed<const CType[N]>
			{
				typedef typename ConfirmAllowed<const CType>::type* type;
				typedef typename ConfirmAllowed<const CType>::scalarType scalarType;
				static const unsigned int dimensions = ConfirmAllowed<const CType>::dimensions+1;
				static const nByte typeName = ConfirmAllowed<const CType>::typeName;
				static const nByte customTypeName = ConfirmAllowed<const CType>::customTypeName;
			};
		}
	}
}