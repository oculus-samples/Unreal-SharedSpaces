/* Exit Games Photon LoadBalancing - C++ Client Lib
 * Copyright (C) 2004-2021 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

namespace ExitGames
{
	namespace LoadBalancing
	{
		/** 
			Enumaration of causes for Disconnects (used in LoadBalancingClient.DisconnectedCause).
			Read the individual descriptions to find out what to do about this type of disconnect.*/
		namespace DisconnectCause
		{
			static const int NONE = 0; ///<No error was tracked.
			static const int DISCONNECT_BY_SERVER_USER_LIMIT        =  1; ///<OnStatusChanged: The CCUs count of your Photon Server License is exausted (temporarily).
			static const int EXCEPTION_ON_CONNECT                   =  2; ///<OnStatusChanged: The server is not available or the address is wrong. Make sure the port is provided and the server is up.
			static const int DISCONNECT_BY_SERVER                   =  3; ///<OnStatusChanged: The server disconnected this client. Most likely the server's send buffer is full (receiving too much from other clients).
			static const int DISCONNECT_BY_SERVER_LOGIC             =  4; ///<OnStatusChanged: The server disconnected this client due to server's logic (received a disconnect command).
			static const int TIMEOUT_DISCONNECT                     =  5; ///<OnStatusChanged: This client detected that the server's responses are not received in due time. Maybe you send / receive too much?
			static const int EXCEPTION                              =  6; ///<OnStatusChanged: Some internal exception caused the socket code to fail. Contact Exit Games.
			static const int INVALID_AUTHENTICATION                 =  7; ///<OnOperationResponse: Authenticate in the Photon Cloud with invalid AppId. Update your subscription or contact Exit Games.
			static const int MAX_CCU_REACHED                        =  8; ///<OnOperationResponse: Authenticate (temporarily) failed when using a Photon Cloud subscription without CCU Burst. Update your subscription.
			static const int INVALID_REGION                         =  9; ///<OnOperationResponse: Authenticate when the app's Photon Cloud subscription is locked to some (other) region(s). Update your subscription or master server address.
			static const int OPERATION_NOT_ALLOWED_IN_CURRENT_STATE = 10; ///<OnOperationResponse: Operation that's (currently) not available for this client (not authorized usually). Only tracked for op Authenticate.
			static const int CUSTOM_AUTHENTICATION_FAILED           = 11; ///<OnOperationResponse: Authenticate in the Photon Cloud with invalid client values or custom authentication setup in Cloud Dashboard.
		}
		/** @file */
	}
}