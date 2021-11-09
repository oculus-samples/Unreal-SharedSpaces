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
		namespace StatusCode
		{
			static const int EXCEPTION_ON_CONNECT              = 1023; ///<the PhotonPeer encountered an exception while opening the incoming connection to the server. The server could be down / not running.
			static const int CONNECT                           = 1024; ///<the PhotonPeer is connected.
			static const int DISCONNECT                        = 1025; ///<the PhotonPeer just disconnected.
			static const int EXCEPTION                         = 1026; ///<the PhotonPeer encountered an exception and will disconnect, too.
			static const int QUEUE_OUTGOING_RELIABLE_WARNING   = 1027; ///<PhotonPeer outgoing queue is filling up. Send more often.
			static const int QUEUE_OUTGOING_UNRELIABLE_WARNING = 1029; ///<PhotonPeer outgoing queue is filling up. Send more often.
			static const int SEND_ERROR                        = 1030; ///<Sending command failed. Either not connected, or the requested channel is bigger than the number of initialized channels.
			static const int QUEUE_OUTGOING_ACKS_WARNING       = 1031; ///<PhotonPeer outgoing queue is filling up. Send more often.
			static const int QUEUE_INCOMING_RELIABLE_WARNING   = 1033; ///<PhotonPeer incoming reliable queue is filling up. Dispatch more often.
			static const int QUEUE_INCOMING_UNRELIABLE_WARNING = 1035; ///<PhotonPeer incoming unreliable queue is filling up. Dispatch more often.
			static const int QUEUE_SENT_WARNING                = 1037; ///<PhotonPeer sent queue is filling up. Check, why the server does not acknowledge your sent reliable commands.
			static const int INTERNAL_RECEIVE_EXCEPTION        = 1039; ///<Exception, if a server cannot be connected. Most likely, the server is not responding. Ask the user to try again later.
			static const int TIMEOUT_DISCONNECT                = 1040; ///<Disconnection due to a timeout (client did no longer receive ACKs from server).
			static const int DISCONNECT_BY_SERVER              = 1041; ///<Disconnect by server due to timeout (received a disconnect command, cause server misses ACKs of client).
			static const int DISCONNECT_BY_SERVER_USER_LIMIT   = 1042; ///<Disconnect by server due to concurrent user limit reached (received a disconnect command).
			static const int DISCONNECT_BY_SERVER_LOGIC        = 1043; ///<Disconnect by server due to server's logic (received a disconnect command).
			static const int ENCRYPTION_ESTABLISHED            = 1048; ///<The encryption-setup for secure communication finished successfully.
			static const int ENCRYPTION_FAILED_TO_ESTABLISH    = 1049; ///<The encryption-setup failed for some reason. Check debug logs.
		}
		/** @file */
	}
}