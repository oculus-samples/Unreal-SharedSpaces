# Oculus Platform Plugin

We have built the Oculus Platform Plugin as a thin layer above the Oculus VR Platform SDK to give the Unreal Engine access
to the new
[Group Presence](../../../../../Engine/Source/ThirdParty/Oculus/LibOVRPlatform/LibOVRPlatform/include/OVR_Requests_GroupPresence.h)
APIs.  In the past, most of the Oculus functionality was exposed through the Oculus Online SubSystem (OSS).  Here instead
we give you an example on how to directly talk to our APIs in a lightweight and targeted way.

## A. The Oculus Platform Subsystem

The core of the plugin is the Oculus Platform Subsystem, a
[UGameInstanceSubsystem](https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/Subsystems/).

It is worth getting familiar with UE4 subsystem.  Quoting from the UE4 documentation:

	Subsystems are particularly useful when creating plugins. You do not need to have instructions about
	the code needed to make the plugin work. The user can just add the plugin to the game, and you know
	exactly when the plugin will be instanced and initialized. As a result, you can focus on how to use the API
	and the functionality provided in UE4.

This means that by simply adding this plugin to your project, you immediately extend the functionality
of your current game instance without the need of code changes.

Let's dive into the header file [OculusPlatformSubsystem.h](../Source/OculusPlatform/Public/OculusPlatformSubsystem.h).

### A1. Message Pump

The subsystem implements
[FTickableGameObject](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Engine/FTickableGameObject/)
in order to be called every game tick to get a chance to process the messages received from the 
Oculus platform (see _UOculusPlatformSubsystem::Tick(float DeltaTime)_).
The [ovr_PopMessage](../../../../../Engine/Source/ThirdParty/Oculus/LibOVRPlatform/LibOVRPlatform/include/OVR_Platform.h)
function dequeues the next message and checks if it is a response to a pending request.
If that's the case, the __request delegate__ is called back to further process the message and its payload.
Messages can also be notifications that are not bound to a prior request, in that case we extract
the message type and broadcast the message to all __notification delegates__ registered to handle it.

### A2. Delegates and Multicast Delegates

At the top of
[OculusPlatformSubsystem.h](../Source/OculusPlatform/Public/OculusPlatformSubsystem.h)
are a number of
[delegate](https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Delegates/)
declarations.  These represent callback signatures used to register notification and response handlers.
Most are [dynamic](https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Delegates/Dynamic/)
which is required to use them in blueprints.

The request response handlers are created with macros of the form _DECLARE_DYNAMIC_DELEGATE*_.  These are for a single
callback endpoint.  Let's take *FOculusPlatformOnGroupPresenceSet* as an example.  In the header file we declare it
with the payload of one single boolean parameter.

	DECLARE_DYNAMIC_DELEGATE_OneParam(FOculusPlatformOnGroupPresenceSet, bool, Successful);

This delegate type can now be used by the blueprint-callable method _GroupPresenceSet_.

	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|GroupPresence", Meta = (AutoCreateRefTerm = "Callback"))
	void GroupPresenceSet(
		FString DestinationApiName,
		bool bIsJoinable,
		FString LobbyId,
		FString MatchId,
		const FOculusPlatformOnGroupPresenceSet& Callback);

This method is an adapter that makes the _ovr_GroupPresence_Set_ Oculus platform call, and stores the request id
along with the _Callback_ data.  When the corresponding response comes back, we execute the callback with the parameters
declared (_bool Successful_).  We will look at the actual implementation in the next section.

Notification handlers are created with macros of the form _DECLARE_DYNAMIC_MULTICAST_DELEGATE*_.  Multicast
delegates have a similar declaration as request response delegates, as you can see with 
_FOculusPlatformOnGroupJoinIntentReceived_.

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOculusPlatformOnGroupJoinIntentReceived,
		const FString&, DestinationApiName,
		const FString&, DeeplinkMessage,
		const FString&, LobbyId,
		const FString&, MatchId);

Multicast delegates allow you to attach multiple callback endpoints to them.  The way this is exposed is through
the declaration of a public variable on the subsystem, in this example _OnGroupJoinIntentReceived_.

	UPROPERTY(BlueprintAssignable, Category = "OculusPlatform|GroupPresence")
	FOculusPlatformOnGroupJoinIntentReceived OnGroupJoinIntentReceived;

In this specific case we use this multicast delegate to call back all registered handlers when the Oculus
platform delivers an _ovrMessage_Notification_GroupPresence_JoinIntentReceived_ to the application. 
This notification is generated in reaction to a number of different events, the most common one being
when the user accepts an invitation to join a destination.

### A3. From Oculus Platform API to Blueprint Node

Now let's look at the implementation of _UOculusPlatformSubsystem::GroupPresenceSet_ in
[OculusPlatformSubsystem.cpp](../Source/OculusPlatform/Private/OculusPlatformSubsystem.cpp)
as a typical example of all adapter methods that expose the Oculus platform C language calls to UE4 blueprints.

	void UOculusPlatformSubsystem::GroupPresenceSet(
		FString DestinationApiName,
		bool bIsJoinable,
		FString LobbyId,
		FString MatchId,
		const FOculusPlatformOnGroupPresenceSet& Callback)
	{
		[...]

		ovrGroupPresenceOptionsHandle GroupPresenceOptions = ovr_GroupPresenceOptions_Create();
		ovr_GroupPresenceOptions_SetDestinationApiName(GroupPresenceOptions, TCHAR_TO_UTF8(*DestinationApiName));
		ovr_GroupPresenceOptions_SetLobbySessionId(GroupPresenceOptions, TCHAR_TO_UTF8(*LobbyId));
		ovr_GroupPresenceOptions_SetMatchSessionId(GroupPresenceOptions, TCHAR_TO_UTF8(*MatchId));
		ovr_GroupPresenceOptions_SetIsJoinable(GroupPresenceOptions, bIsJoinable);

		AddRequestDelegate(ovr_GroupPresence_Set(GroupPresenceOptions),
			FOculusPlatformMessageOnComplete::CreateLambda(
			[this, DestinationApiName, bIsJoinable, LobbyId, MatchId, Callback](ovrMessageHandle Message, bool bIsError)
			{
				if (bIsError)
				{
					ovrErrorHandle Error = ovr_Message_GetError(Message);
					FString ErrorMessage(ovr_Error_GetMessage(Error));
					LogError(FString::Printf(TEXT("Error setting group presence: %s"), *ErrorMessage));
				}
				else
				{
					[...]
				}

				Callback.ExecuteIfBound(!bIsError);
			}));

		ovr_GroupPresenceOptions_Destroy(GroupPresenceOptions);
	}

The method first prepares the group presence options, with the UE4 parameters converted to the corresponding
Oculus C types.  _AddRequestDelegate_ is then called with two arguments: a request id generated by an api call,
and a_FOculusPlatformMessageOnComplete_ delegate generally created with a 
[lambda](https://docs.unrealengine.com/4.26/en-US/API/Runtime/Core/Delegates/TBaseDelegate/CreateLambda/).
The lambda captures the variables that it needs when the response comes back, including our _Callback_
variable.  The lambda that we define takes an _ovrMessageHandle_ and an error boolean.  In this specific case,
there is no payload expected so there is no need to extract data from the message handle (you can find examples
of that in other methods).

Finally _Callback.ExecuteIfBound()_ is called with the arguments declared for that delegate.

This can be directly called in C++, but in SharedSpaces this is done in the game instance blueprint as shown below.

<div style="text-align: center;  padding: 10pt;">
	<img src="./Media/group_presence_set_blueprint.png">
</div>

Of particular interest is how the callback is attached to the node: it is a custom event that will have the
same signature as the delegate declared for the method's callback parameter.

### A4. Blueprint Notification Handler

Binding a handler to a multicast delegate is done by binding to the corresponding variable on the subsystem.

<div style="text-align: center;  padding: 10pt;">
	<img src="./Media/group_join_intent_received_blueprint.png">
</div>

Here you can see how this is done in SharedSpaces' game instance as a one-time action when the subsystem
is ready.

### A5. Oculus Platform Types

Blueprint scripting also requires us to adapt the C types used by the Oculus apis.
The header file [OculusPlatformTypes.h](../Source/OculusPlatform/Private/OculusPlatformTypes.h) collects most
of those.

As a first example, the Oculus _uint64_t_ _ovrID_ that is used in particular to represent user ids, is of a type that
cannot be used directly in blueprints since Unreal
[only support signed integers](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Blueprints/UserGuide/Variables/).
We create a blueprint equivalent using the USTRUCT macro.

	USTRUCT(BlueprintType)
	struct OCULUSPLATFORM_API FOculusId
	{
		GENERATED_BODY()
		FOculusId(): Id(0) {}
		FOculusId(ovrID ID): Id(ID) {}
		FOculusId(const FString& StrId): Id(FCString::Strtoui64(*StrId, nullptr, 10)) {}
		operator ovrID() const { return Id; }
	private:
		ovrID Id;
	};

For C enums equivalents, we use the _UENUM_ macro.

	UENUM(BlueprintType)
	enum class ERoomJoinPolicy : uint8 {
		RoomJoinPolicy_None,
		RoomJoinPolicy_Everyone,
		RoomJoinPolicy_FriendsOfMembers,
		RoomJoinPolicy_FriendsOfOwner,
		RoomJoinPolicy_InvitedUsers,
		RoomJoinPolicy_Unknown,

		RoomJoinPolicy_Count UMETA(Hidden, DisplayName = "<INVALID>")
	};

When used as an input parameter to a blueprint node, the enumeration appears as a nicely readable drop-down menu.

<div style="text-align: center;  padding: 10pt;">
	<img src="./Media/enumeration_blueprint.png">
</div>

Conversion from an Oculus C-language enumeration to the Unreal equivalent has been implemented with explicit
functions.

	ERoomJoinPolicy UOculusPlatformSubsystem::ConvertJoinPolicy(ovrRoomJoinPolicy JoinPolicy) const
	{
		switch (JoinPolicy)
		{
			case ovrRoom_JoinPolicyNone:
				return ERoomJoinPolicy::RoomJoinPolicy_None;
			case ovrRoom_JoinPolicyEveryone:
				return ERoomJoinPolicy::RoomJoinPolicy_Everyone;
			case ovrRoom_JoinPolicyFriendsOfMembers:
				return ERoomJoinPolicy::RoomJoinPolicy_FriendsOfMembers;
			case ovrRoom_JoinPolicyFriendsOfOwner:
				return ERoomJoinPolicy::RoomJoinPolicy_FriendsOfOwner;
			case ovrRoom_JoinPolicyInvitedUsers:
				return ERoomJoinPolicy::RoomJoinPolicy_InvitedUsers;
			default:
				return ERoomJoinPolicy::RoomJoinPolicy_Unknown;
		}
	}

	ovrRoomJoinPolicy UOculusPlatformSubsystem::ConvertJoinPolicy(ERoomJoinPolicy JoinPolicy) const
	{
		switch (JoinPolicy)
		{
			case ERoomJoinPolicy::RoomJoinPolicy_None:
				return ovrRoom_JoinPolicyNone;
			case ERoomJoinPolicy::RoomJoinPolicy_Everyone:
				return ovrRoom_JoinPolicyEveryone;
			case ERoomJoinPolicy::RoomJoinPolicy_FriendsOfMembers:
				return ovrRoom_JoinPolicyFriendsOfMembers;
			case ERoomJoinPolicy::RoomJoinPolicy_FriendsOfOwner:
				return ovrRoom_JoinPolicyFriendsOfOwner;
			case ERoomJoinPolicy::RoomJoinPolicy_InvitedUsers:
				return ovrRoom_JoinPolicyInvitedUsers;
			default:
				return ovrRoom_JoinPolicyUnknown;
		}
	}

To be able to convert between different types in blueprints, we have also created a few
_Conv&lt;from-type&gt;To&lt;to-type&gt;_ methods available in the
[OculusPlatformFunctionLibrary](../Source/OculusPlatform/Private/OculusPlatformFunctionLibrary.h).

	UFUNCTION(BlueprintPure, meta=(DisplayName = "ToString (OculusId)", CompactNodeTitle = "->", BlueprintAutocast), Category="OculusPlatform|Utils")
	static FString Conv_OculusIdToString(FOculusId OculusId);

	UFUNCTION(BlueprintPure, meta=(DisplayName = "ToOculusId (Int64)", CompactNodeTitle = "->", BlueprintAutocast), Category="OculusPlatform|Utils")
	static FOculusId Conv_Int64ToOculusId(int64 Id);

To compare _FOculusIds_ in blueprint, that function library declares the following comparator function.

	UFUNCTION(BlueprintPure, meta=(DisplayName = "Equal OculusId", CompactNodeTitle = "==", Keywords = "== equal"), Category="OculusPlatform|Utils")
	static bool EqualEqual_OculusIdOculusId(const FOculusId& A, const FOculusId& B);

### A6. Logging

To make the SharedSpaces sample as educative as possible, we needed to have a way to display as much under-the-hood
information as possible in the application.  For that purpose we have added a few logging functions to the
subsystem so that we can persist log entries as we travel between levels.

	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Log")
	void ClearLog(int32 LineLength, int32 NumLines);

	UFUNCTION(BlueprintCallable, Category = "OculusPlatform|Log")
	void LogMessage(FString Message);

The _ClearLog_ method sets the maximum length per log line, and the number of log lines to remember.
Long log messages are split into separate log lines.

	UPROPERTY(BlueprintAssignable, Category = "OculusPlatform|Log")
	FOculusPlatformLogUpdated OnLogUpdated;

Whenever we add to the log, the _OnLogUpdated_ broadcasts to all listeners.  In SharedSpaces, this is
used to update the in-game log panel.

## B. Oculus Net Driver

When we first started work on this plugin for the SharedSpaces project, we used the Oculus networking transport
facilities, in particular for the Oculus room system.  We have since replaced this with Photon to satisfy our
developers demand for samples using that tranport sdk, as you can see in that project's DefaultEngine.ini.
You can uncomment the Oculus net driver if you want to use it.

	[/Script/Engine.GameEngine]
	#+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="/Script/OculusPlatform.NetDriverForOculus",DriverClassNameFallback="/Script/OnlineSubsystemUtils.IpNetDriver")
	+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="/Script/PhotonNetDriver.PhotonIpNetDriver", DriverClassNameFallback="/Script/OnlineSubsystemUtils.IpNetDriver")

These files were originally available in the Oculus Online SubSystem and have been copied here in our effort
to reduce the number of layers standing between the Oculus platform and the UE4 blueprints.

The key files that adapt the Oculus transport layer to the UE4 networking stack are

- [NetDriverForOculus.h](../Source/OculusPlatform/Private/NetDriverForOculus.h) and
  [.cpp](../Source/OculusPlatform/Private/NetDriverForOculus.cpp)
- [NetConnectionForOculus.h](../Source/OculusPlatform/Private/NetConnectionForOculus.h) and
  [.cpp](../Source/OculusPlatform/Private/NetConnectionForOculus.cpp)

Diving into the UE4 networking is beyond this plugin documentation.   To get started we highly recommend
Cedric Neukirchen's 
[Unreal Engine 4 Compendium](https://cedric-neukirchen.net/Downloads/Compendium/UE4_Network_Compendium_by_Cedric_eXi_Neukirchen.pdf).

<div style="text-align: right; padding: 10pt;">&#x25A0;</div>
