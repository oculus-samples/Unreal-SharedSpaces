/* Exit Games Photon - C++ Client Lib
* Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
* http://www.photonengine.com
* mailto:developer@photonengine.com
*/

#pragma once

#include "Common-cpp/inc/Common.h"

namespace ExitGames
{
	namespace Photon
	{
		typedef Common::Dictionary<nByte, Common::Object> OperationRequestParameters;

		class OperationRequest
		{
		public:
			OperationRequest(nByte operationCode, const OperationRequestParameters& parameters=OperationRequestParameters());
			~OperationRequest(void);

			OperationRequest(const OperationRequest& toCopy);
			OperationRequest& operator=(const OperationRequest& toCopy);

			const Common::Object& operator[](unsigned int index) const;

			Common::JString toString(bool withParameters=false, bool withParameterTypes=false) const;
			Common::Object getParameterForCode(nByte parameterCode) const;

			nByte getOperationCode(void) const;
			const OperationRequestParameters& getParameters(void) const;
			OperationRequestParameters& getParameters(void);
			void setParameters(const OperationRequestParameters& parameters);
		private:
			nByte mOperationCode;
			OperationRequestParameters mParameters;
		};
	}
}