/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include <functional>

#include "OVRPlatformModels.h"
#include "OVRPlatformOptions.h"

#include "OVRPlatformFunctions.generated.h"

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOvrVoipFilterCallback, TArray<int32>, pcmData, int32, frequency, int32, numChannels);

UCLASS()
class OVRPLATFORM_API UOvrFunctionsBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /** Returns information about how the application was started. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|ApplicationLifecycle")
    static FOvrLaunchDetails ApplicationLifecycle_GetLaunchDetails();

    /** Logs if the user successfully deeplinked to a destination. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|ApplicationLifecycle")
    static void ApplicationLifecycle_LogDeeplinkResult(FString TrackingID, EOvrLaunchResult Result);

    /**
     * Allow `peerID` to establish a peer-to-peer connection to this host.
     * 
     * Call this after receiving FOvrNotification_Networking_PeerConnectRequest.
     * 
     * This function is a no-op if there are no pending connection attempts from
     * peerID.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Networking")
    static void Net_Accept(FOvrId PeerID);

    /**
     * Automatically accept all current and future connection attempts from
     * members of the current room. Note that the room has to be created or
     * joined by calling one of the existing room/matchmaking functions.
     * Returns false if the user currently isn't in a room.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Networking")
    static bool Net_AcceptForCurrentRoom();

    /**
     * Destroy the connection to peerID, if one exists.  Note that in most cases
     * this is not needed, as the library manages the pool of connections and
     * discards unused ones.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Networking")
    static void Net_Close(FOvrId PeerID);

    /**
     * Close the connection to everyone in the current room. This is typically called
     * before leaving the room. Can be called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Networking")
    static void Net_CloseForCurrentRoom();

    /**
     * Connects to the peer with the specified user ID.  This function returns immediately.
     * 
     * Once the connection is established, a FOvrNotification_Networking_ConnectionStateChange
     * message will be enqueued.
     * 
     * 
     * Can be called from any thread.
     * 
     * 
     * Note that Net_SendPacket() implicitly connects. However, it does not
     * buffer messages in unreliable mode. Net_Connect() allows the application
     * to delay sending messages until an actual connection is established.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Networking")
    static void Net_Connect(FOvrId PeerID);

    /**
     * Returns true only when there is an open connection to peerID.  Can be called
     * from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Networking")
    static bool Net_IsConnected(FOvrId PeerID);

    /**
     * Ping the user with the given ID.
     * 
     * Once the request completes, a FOvrNotification_Networking_PingResult message is enqueued.
     * 
     * Can be called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Networking")
    static FOvrId Net_Ping(FOvrId PeerID);

    /**
     * Read the next incoming packet. Returns null when no more packets
     * are available. Returned handle points to an object representing data
     * read from the network. Ownership of that object is transferred to the
     * application; use field FOvrPacket::?no field found? to release memory.
     * 
     * 
     * For example:
     * 
     * <codeblock>
     *   ovrPacketHandle packet;
     *   while (packet = ovr_Net_ReadPacket()) {
     *     ovrID sender = ovr_Packet_GetSender(packet);
     *     // dispatch packet
     *     ovr_Packet_Free(packet);
     *   }
     * </codeblock>
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Networking")
    static FOvrPacket Net_ReadPacket();

    /**
     * Send a sequence of bytes to another user. The length must be less
     * than or equal to the allocated length of bytes.  A new connection
     * to userID will be established (asynchronously) unless one already
     * exists.
     * 
     * 
     * Depending on the policy, this message might be buffered until a valid
     * connection to the peer exists. The function returns false if the
     * packet can't be enqueued for sending (e.g., there's not enough memory)
     * or the policy prohibits buffering.  See ovrSendPolicy and Net_Connect().
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Networking")
    static bool Net_SendPacket(FOvrId UserID, TArray<uint8> Bytes, EOvrSendPolicy Policy);

    /**
     * Sends a packet to all members of the room, excluding the currently logged
     * in user. Note that the room has to be created or joined by calling one of
     * the existing room/matchmaking functions, with subscribe_to_updates
     * enabled.  See Net_SendPacket() for a description of parameters.
     * This function returns false if the user currently isn't in a room.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Networking")
    static bool Net_SendPacketToCurrentRoom(TArray<uint8> Bytes, EOvrSendPolicy Policy);

    /** Accepts a VoIP connection from a given user. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_Accept(FOvrId UserID);

    /**
     * Gets whether or not a voice connection is using discontinuous transmission (DTX).
     * Both sides must set to using DTX when their connection is established in order for this
     * to be true. Returns unknown if there is no connection.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static EOvrVoipDtxState Voip_GetIsConnectionUsingDtx(FOvrId PeerID);

    /**
     * Gets the current local bitrate used for the connection to the specified user.  This is set
     * by the current client. Returns unknown if there is no connection.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static EOvrVoipBitrate Voip_GetLocalBitrate(FOvrId PeerID);

    /**
     * Returns the size of the internal ringbuffer used by the voip system in elements.  This size is the maximum
     * number of elements that can ever be returned by Voip_GetPCM().
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static int64 Voip_GetOutputBufferMaxSize();

    /**
     * Gets all available samples of voice data for the specified peer and
     * copies it into outputBuffer. The voip system will generate data at roughly
     * the rate of 480 samples per 10ms. This function should be called every frame
     * with 50ms (2400 elements) of buffer size to account for frame rate
     * variations. The data format is 16 bit fixed point 48khz mono.
     * 
     * 
     * This function can be safely called from any thread.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Voip_GetPCM(ovrID senderID, int16_t *outputBuffer, size_t outputBufferNumElements);
     */

    /**
     * Gets all available samples of voice data for the specified peer and
     * copies it into outputBuffer. The voip system will generate data at roughly
     * the rate of 480 samples per 10ms. This function should be called every frame
     * with 50ms (2400 elements) of buffer size to account for frame rate
     * variations. The data format is 32 bit floating point 48khz mono.
     * 
     * 
     * This function can be safely called from any thread.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Voip_GetPCMFloat(ovrID senderID, float *outputBuffer, size_t outputBufferNumElements);
     */

    /**
     * Returns the current number of audio samples available to read for the specified user.
     * This function is inherently racy; it's possible that more data can be added between a
     * call to this function and a subsequent call to Voip_GetPCM().
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static int64 Voip_GetPCMSize(FOvrId SenderID);

    /**
     * Like Voip_GetPCM(), this function copies available audio samples
     * into a provided buffer, but also stores the timestamp of the first sample
     * in the output parameter 'timestamp'.  This timestamp can be used for
     * synchronization; see Voip_GetSyncTimestamp() for more details.
     * 
     * This function returns a number of samples copied.  Note that it may
     * return early, even if there's more data available, in order to keep the
     * batch of audio samples with a single timestamp small; for example, if
     * there's 30ms worth of audio in the buffer, this function may return
     * 480 samples (10ms) each time it's called.  Therefore, it's recommended
     * to call this as long as there's data in the buffer (i.e. the function
     * returns a non-zero result).
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Voip_GetPCMWithTimestamp(ovrID senderID, int16_t *outputBuffer, size_t outputBufferNumElements, uint32_t *timestamp);
     */

    /**
     * See Voip_GetPCMWithTimestamp(). Uses a 32-bit floating-point data
     * format.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Voip_GetPCMWithTimestampFloat(ovrID senderID, float *outputBuffer, size_t outputBufferNumElements, uint32_t *timestamp);
     */

    /**
     * Gets the current remote bitrate used for the connection to the specified user.  This is set
     * by the client on the other side of the connection.  Returns unknown if there is no connection.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static EOvrVoipBitrate Voip_GetRemoteBitrate(FOvrId PeerID);

    /**
     * Returns a timestamp used for synchronizing audio samples sent to the
     * given user with an external data stream.
     * 
     * Timestamps associated with audio frames are implicitly transmitted to
     * remote peers; on the receiving side, they can be obtained by using
     * Voip_GetPCMWithTimestamp().  Voip_GetPCMWithTimestamp() is used to fetch
     * those timestamps on the sending side -- an application can insert the
     * value returned by this function into each data packet and compare it to
     * the value returned by GetPCMWithTimestamp() on the receiving side in
     * order to determine the ordering of two events (sampling audio and
     * composing a data packet).
     * 
     * Note: the timestamp is generated by an unspecified clock; it's doesn't
     * generally represent wall-clock time.  Use Voip_GetSyncTimestampDifference()
     * to convert the difference between two timestamps to microseconds.
     * 
     * This function assumes that a voice connection to the user already
     * exists; it returns 0 if that isn't the case.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static int32 Voip_GetSyncTimestamp(FOvrId UserID);

    /**
     * Calculates the difference between two sync timestamps, returned by
     * either Voip_GetSyncTimestamp() or Voip_GetPCMWithTimestamp(),
     * and converts it to microseconds.
     * 
     * Return value will be negative if lhs is smaller than rhs, zero if both
     * timestamps are the same, and positive otherwise.  The absolute value of
     * the result is the time in microseconds between two sync timestamps.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static int64 Voip_GetSyncTimestampDifference(int32 Lhs, int32 Rhs);

    /** Returns SystemVoip microphone's mute state. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static EOvrVoipMuteState Voip_GetSystemVoipMicrophoneMuted();

    /** Returns SystemVoip status. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static EOvrSystemVoipStatus Voip_GetSystemVoipStatus();

    /**
     *   This function allows you to set a callback that will be called every time audio data is captured by the microphone.
     *   The callback function must match this signature: void filterCallback(int16_t pcmData[], size_t pcmDataLength, int frequency, int numChannels);
     *   The pcmData param is used for both input and output. pcmDataLength is the size of pcmData in elements. numChannels will be 1 or 2.
     *   If numChannels is 2, then the channel data will be interleaved in pcmData.
     *   Frequency is the input data sample rate in hertz.
     * 
     * 
     * This function can be safely called from any thread.
     */
    /*
     * Not exposed to blueprints, call C API directly: void ovr_Voip_SetMicrophoneFilterCallback(VoipFilterCallback cb);
     */

    /**
     * This function is used to enable or disable the local microphone.  When muted, the microphone will not transmit any audio.
     * Voip connections are unaffected by this state.  New connections can be established or closed whether the microphone is muted or not.
     * This can be used to implement push-to-talk, or a local mute button.  The default state is unmuted.
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_SetMicrophoneMuted(EOvrVoipMuteState State);

    /**
     * The options set for newly created connections to use. Existing connections will continue
     * to use their current settings until they are destroyed and recreated.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_SetNewConnectionOptions(FOvrVoipOptions VoipOptions);

    /**
     * Sets the output sample rate.  Audio data will be resampled as it is placed into the internal ringbuffer.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_SetOutputSampleRate(EOvrVoipSampleRate Rate);

    /**
     * Attempts to establish a VoIP session with the specified user.
     * 
     * A message of type FOvrNotification_Voip_StateChange will be posted when the session is
     * established.
     * 
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_Start(FOvrId UserID);

    /**
     * Terminates a VoIP session with the specified user.  Note that a muting
     * functionality should be used to temporarily stop sending audio; restarting
     * a VoIP session after tearing it down may be an expensive operation.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_Stop(FOvrId UserID);


    // Returns true if the platform has been initialized.
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Platform")
    static bool Platform_IsInitialized();

    // Returns the id of the currently logged in user, or a 0 id if there is none.
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Platform")
    static FOvrId Platform_GetLoggedInUserID();

    // Returns the currently logged-in user's locale as a string, or empty string on error.
    // Return value format conforms to BCP47: https://tools.ietf.org/html/bcp47
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Platform")
    static FString Platform_GetLoggedInUserLocale();

    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Platform")
    static void Platform_SetDeveloperAccessToken(FString AccessToken);
};
