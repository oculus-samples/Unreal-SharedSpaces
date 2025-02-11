// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_COWATCHING_H
#define OVR_REQUESTS_COWATCHING_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_CowatchViewerArray.h"

/// Get the next page of entries
///
/// A message with type ::ovrMessage_Cowatching_GetNextCowatchViewerArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrCowatchViewerArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetCowatchViewerArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_GetNextCowatchViewerArrayPage(ovrCowatchViewerArrayHandle handle);

/// Retrieve the presenter data that drives an active cowatching session. This
/// method can be called when there is an ongoing cowatching session, allowing
/// developers to access and utilize the presenter data to enhance the user
/// experience.
///
/// A message with type ::ovrMessage_Cowatching_GetPresenterData will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ovr_Message_GetString().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_GetPresenterData();

/// Retrieve the viewer data of everyone who is in a cowatching session whose
/// data was set by ovr_Cowatching_SetViewerData() viewer_data. This can be
/// called when there is an active cowatching session.
///
/// A message with type ::ovrMessage_Cowatching_GetViewersData will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrCowatchViewerArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetCowatchViewerArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_GetViewersData();

/// Check whether the current user is participating in the ongoing cowatching
/// session. It returns a boolean value ovr_CowatchingState_GetInSession()
/// indicating the user's presence in the session.
///
/// A message with type ::ovrMessage_Cowatching_IsInSession will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrCowatchingStateHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetCowatchingState().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_IsInSession();

/// Join the ongoing cowatching session as a viewer, updating data only
/// possible for users already in the session.
///
/// A message with type ::ovrMessage_Cowatching_JoinSession will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_JoinSession();

/// Launch a dialog for inviting users to cowatch in Copresent Home.
///
/// A message with type ::ovrMessage_Cowatching_LaunchInviteDialog will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_LaunchInviteDialog();

/// Leave the current cowatching session, rendering viewer data obsolete and no
/// longer relevant to the ongoing experience.
///
/// A message with type ::ovrMessage_Cowatching_LeaveSession will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_LeaveSession();

/// Request to initiate a cowatching session as the presenter while being
/// copresent in a shared virtual home environment.
///
/// A message with type ::ovrMessage_Cowatching_RequestToPresent will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_RequestToPresent();

/// Stop being the presenter and terminate the ongoing cowatching session. This
/// action will effectively end the shared media experience.
///
/// A message with type ::ovrMessage_Cowatching_ResignFromPresenting will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_ResignFromPresenting();

/// Set the data that drives a cowatching session. This method is only callable
/// by the presenter. The video title cannot exceed 100 characters, and the
/// data size is limited to 500 characters. The data will be eventually
/// consistent across all users.
/// \param video_title A string representing the title of the video being played in the cowatching session. This parameter must not exceed 100 characters in length.
/// \param presenter_data A string containing data that drives the cowatching session, such as video metadata or playback information. This parameter is limited to 500 characters in length and will be eventually consistent across all users participating in the session.
///
/// A message with type ::ovrMessage_Cowatching_SetPresenterData will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_SetPresenterData(const char *video_title, const char *presenter_data);

/// Set the current user's viewer data to be shared with copresent users. This
/// can be called when there is an active cowatching session. The data size is
/// limited to 500 characters, and it will eventually become consistent across
/// all users.
/// \param viewer_data A string containing data about the current user's viewer state, such as their preferences or settings. This data is shared with copresent users during an active cowatching session and is limited to 500 characters in size. The data will eventually become consistent across all users participating in the session.
///
/// A message with type ::ovrMessage_Cowatching_SetViewerData will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_Cowatching_SetViewerData(const char *viewer_data);

#endif
