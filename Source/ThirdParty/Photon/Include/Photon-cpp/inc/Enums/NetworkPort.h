/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

namespace ExitGames
{
	namespace Photon
	{
		namespace NetworkPort
		{
			struct Protocol
			{
				const unsigned short MASTER;
				const unsigned short GAME;
				const unsigned short NAME;
			protected:
				Protocol(unsigned short master, unsigned short game, unsigned short name);
			private:
				Protocol& operator=(const Protocol& toCopy);
			};

			struct UDP : public Protocol
			{
				UDP(void);

				static const unsigned short MASTER;
				static const unsigned short GAME;
				static const unsigned short NAME;
			};

			struct UDPAlternative : public Protocol
			{
				UDPAlternative(void);

				static const unsigned short NAME;
				static const unsigned short MASTER;
				static const unsigned short GAME;
			};

			struct TCP : public Protocol
			{
				TCP(void);

				static const unsigned short MASTER;
				static const unsigned short GAME;
				static const unsigned short NAME;
			};

			struct WS : public Protocol
			{
				WS(void);

				static const unsigned short MASTER;
				static const unsigned short GAME;
				static const unsigned short NAME;
			};

			struct WSS : public Protocol
			{
				WSS(void);

				static const unsigned short MASTER;
				static const unsigned short GAME;
				static const unsigned short NAME;
			};
		}
	}
}