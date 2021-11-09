/* Exit Games Common - C++ Client Lib
* Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
* http://www.photonengine.com
* mailto:developer@photonengine.com
*/

#pragma once

namespace ExitGames
{
	namespace Common
	{
		namespace Helpers
		{
			template<typename Derived, typename Base>
			class IsDerivedFrom
			{
			private:
				class No
				{
				};

				class Yes
				{
					No no[3];
				};

				static Yes test(const Base*); // not defined
				static No test(...); // not defined

				static void constraints(Derived* p)
				{
					Base* pb = p;
					pb = p;
				}

			public:
				static const bool is = sizeof(test(static_cast<Derived*>(0))) == sizeof(Yes);

				IsDerivedFrom(void)
				{
					void(*p)(Derived*) = constraints;
				}
			};
		}
	}
}