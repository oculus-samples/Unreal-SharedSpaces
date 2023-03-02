# Oculus Platform Plugin

The Oculus Platform plugin for the Unreal Engine offers full access to the Oculus Platform SDK to both blueprints and C++ code.

In the past, most of the Oculus Platform functionality was exposed through the Oculus Online SubSystem (OSS).
The Oculus OSS is an adaptation layer that is hard to maintain, an approximation of the available functionality
and not well suited for some of our newer APIs such as
[Group Presence](../../../../../Engine/Source/ThirdParty/Oculus/LibOVRPlatform/LibOVRPlatform/include/OVR_Requests_GroupPresence.h).
For those reasons, when we built the SharedSpaces sample, we decided not to use the OSS and hand-crafted instead
a new plugin with only the functionality that we needed.

This led to a follow-up project to offer that plugin with complete API coverage.

The Oculus Platform plugin is now automatically generated each time the platform APIs are updated.
It contains two modules that are kept in sync: the OVRPlatform module with our UE blueprint and C++
interface and the OVRPlatformSDK module containing the platform C++ include files and compiled libraries.

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

Let's dive into the header file [OVRPlatformSubsystem.h](../Source/OVRPlatform/Public/OVRPlatformSubsystem.h).

### A1. Message Pump

The subsystem implements
[FTickableGameObject](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Engine/FTickableGameObject/)
in order to be called every game tick to get a chance to process the messages received from the
Oculus platform (see _UOvrPlatformSubsystem::Tick(float DeltaTime)_).
The [ovr_PopMessage](../../../../../Engine/Source/ThirdParty/Oculus/LibOVRPlatform/LibOVRPlatform/include/OVR_Platform.h)
function dequeues the next message and checks if it is a response to a pending request.
If that's the case, the __request delegate__ is called back to further process the message and its payload.
Messages can also be system notifications that are not bound to a prior request, and in that case we broadcast
the message and its payload to all __notification delegates__ registered to handle it.

It is important to note that __the message pump is not automatically started__ when the subsystem starts.
There are system notifications that could be lost otherwise, such as *FOvrNotification_ApplicationLifecycle_LaunchIntentChanged*.
After authentication, the subsystem triggers the __OvrPlatformSubsystemStarted event__ on your game instance.

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/oculus_platform_started_event.png">
</div>

After a successful login, you first register your callbacks for the events that you are interested in.

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/application_lifecycle_event_registration.png">
</div>

Finally you start the message pump.

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/start_message_pump.png">
</div>

### A2. Multicast Notification Delegates

At the top of
[OVRPlatformSubsystem.h](../Source/OVRPlatform/Public/OVRPlatformSubsystem.h)
are a number of
[delegate](https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Delegates/)
declarations.  These represent callback signatures used to listen to Oculus platform notifications.
They are [dynamic](https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Delegates/Dynamic/)
which is required to use them in blueprints.  They are also multicast, which means that any number of listeners can be attached to it.

As an example, here's the declaration of *GroupPresence/JoinIntentReceived*.

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
        FOvrNotification_GroupPresence_JoinIntentReceived,
        const FOvrGroupPresenceJoinIntent&, JoinIntentReceived);

This notification carries a payload of type *FOvrGroupPresenceJoinIntent*.
(See the actual declaration in [OVRPlatformModels.h](../Source/OVRPlatform/Public/OVRPlatformModels.h).)

    struct OVRPLATFORM_API FOvrGroupPresenceJoinIntent
    {
        FString DeeplinkMessage;
        FString DestinationApiName;
        FString LobbySessionId;
        FString MatchSessionId;
    }

Your application will receive this notification in particular when you accept an invitation sent to you by one of your friends.
It is up to your application to handle this message and establish the proper communication channel to that destination,
and you should definitely look at SharedSpaces for a good example on how to do that.

### A3. C++ Request Delegates

Now if you open [OVRPlatformCppRequests.h](../Source/OVRPlatform/Public/OVRPlatformCppRequests.h) you will find
many request declarations suitable to be called from C++.  These generally produce a network message that is sent
to the Oculus platform for processing, and a reponse comes back a bit later.  To handle the response, you supply
a delegate that follows the _DECLARE_DELEGATE*_ signature defined right before.  As an example, the method to set
your group presence looks like this:

    DECLARE_DELEGATE_TwoParams(
        OvrPlatform_GroupPresence_Set_Delegate,
        bool,
        FString);

    void OvrPlatform_GroupPresence_Set(
        UGameInstance* GameInstance,
        FOvrGroupPresenceOptions GroupPresenceOptions,
        OvrPlatform_GroupPresence_Set_Delegate&& Delegate);

For reference, the group presence options look like this.

    struct FOvrGroupPresenceOptions
    {
        FString DeeplinkMessageOverride;
        FString DestinationApiName;
        bool IsJoinable;
        FString LobbySessionId;
        FString MatchSessionId;
    };

The C++ requests will use the _UGameInstance_ (to get access to the _UOvrPlatformSubsystem_), parameters in the options
structure, and a minimal delegate.   All C++ request delegates have at bool to indicate if the request
succeeded, and an error string to provide an explanation when it doesn't.

There are many ways to attach code to handle the response
(see [TBaseDelegate](https://docs.unrealengine.com/4.26/en-US/API/Runtime/Core/Delegates/TBaseDelegate/)).
One of them is by using a typical lambda expression like this:

    OvrPlatform_GroupPresence_Set(
        GameInstance,
        GroupPresenceOptions,
        OvrPlatform_GroupPresence_Set_Delegate::CreateLambda(
            [GameInstance](bool bIsError, FString ErrorMsg)
            {
                // handle response
            }));

### A4. From Oculus Platform API to Blueprint Node

Probably the most exciting feature of the Oculus Platform plugin is how it exposes requests to blueprints.
Unlike the previous version that required attaching a callback object to the request node, we now use
the Unreal Engine's latent action system and the ability of nodes to have multiple input and output
execution pins.  While it makes the system much more complex on our end,
it greatly simplifies the lives of blueprint developers.

Now let's look at the implementation of _UOvrPlatformSubsystem::GroupPresence_Set_ in
[OVRPlatformRequests.cpp](../Source/OVRPlatform/Private/OVRPlatformRequests.cpp)
as a typical example of all adapter methods that expose the Oculus platform C calls to UE4 blueprints.

    void UOvrRequestsBlueprintLibrary::GroupPresence_Set(
        // Context
        UObject* WorldContextObject,
        EOvrRequestOutputPins& OutExecs,
        FLatentActionInfo LatentInfo,
        // Input
        FOvrGroupPresenceOptions GroupPresenceOptions,
        // Output
        FString& ErrorMsg)
    {
        if (auto World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
        {
            OvrPlatformAddNewActionWithPreemption(
                World,
                LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FOvrRequestLatentAction(LatentInfo, OutExecs, ErrorMsg,
                    // Request Generator
                    [GroupPresenceOptions]()->ovrRequest
                    {
                        ovrRequest RequestID = ovr_GroupPresence_Set(FOvrGroupPresenceOptionsConverter(GroupPresenceOptions));

                        return RequestID;
                    },
                    // Response Processor
                    [](TOvrMessageHandlePtr MessagePtr, bool bIsError)->void
                    {
                        // No payload in response
                    }));
        }
    }

We create a latent action with a __request generator__ (a lambda that actually calls the Oculus Platform C API) and a __response processor__
(a lambda that captures, as needed, the output pins that will carry the response payload).  This latent action is associated with
a specific node instance, which allows us to preempt it with a new latent action by reentering the node.

Each game tick, the latent action gets an opportunity to update.  Most of the complexity is hidden in
[OVRPlatformRequestsSupport.cpp](../Source/OVRPlatform/Private/OVRPlatformRequestsSupport.cpp).
During one of those updates, the request generator will be called and another callback is attached to
the _UOvrPlatformSubsystem_ messaging system.  This callback will process the response, which in turn is passed
back to the response processor, and the response processor will update the blueprint node pins with the
proper information.

A lot happens under the hood, but at the blueprint level things are simple:

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/group_presence_set_blueprint.png">
</div>

The clock icon at the top right identifies the node as being asynchronous.  Options are packaged as structures
that can be split in the editor for directly setting them in the request node.

The following sequence of actions is guaranteed:

  1. Every time a latent node is entered, execution continues using the "then" pin (the unnamed top right exec pin).
  2. The corresponding request (a C++ function call) is always executed.
  3. When the response comes back, the node will exit either by the success pin or the failure pin.
  4. If you reenter the node again before the previous request returns, it is __preempted__: the response to the
     previous request will be ignored and it will not trigger any exits from the success or failure pin.
     Only the last request is allowed to exit with results.

There are a few ways to supply input to composite input pins like _Group Presence Options_ above.  One is to
simply right-click on the pin and select *split struct* from the context menu.  This opens up the pin right there
in the node.

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/group_presence_set_blueprint_2.png">
</div>

Another option is to drag the pin out to an empty space on the blueprint to create a new options structure.

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/group_presence_set_blueprint_3.png">
</div>

### A5. Blueprint Notification Handler

Binding a handler to a multicast delegate is done by binding to the corresponding variable on the subsystem.
This is very similar to how things were in the previous subsystem, except that here we have generated
structures instead of flattening the response.  You can always flatten by splitting structs, as shown in this
screenshot.

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/group_join_intent_received_blueprint.png">
</div>

### A6. Oculus Platform Types

Blueprint scripting also requires us to adapt the C types used by the Oculus APIs.
The header file [OVRPlatformTypes.h](../Source/OVRPlatform/Public/OVRPlatformTypes.h) has the custom ones, such
as *FOvrId*.

The Oculus _uint64_t_ _ovrID_ that is used in particular to represent user ids, is of a type that
cannot be used directly in blueprints since Unreal
[only support signed integers](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Blueprints/UserGuide/Variables/).
We create a blueprint equivalent using the _USTRUCT_ macro.

    USTRUCT(BlueprintType, Category = "OvrPlatform|CustomModels|ID")
    struct OVRPLATFORM_API FOvrId
    {
        GENERATED_USTRUCT_BODY()

        FOvrId() : Id(0) {}
        FOvrId(ovrID ID) : Id(ID) {}
        FOvrId(const FString& StrId) : Id(FCString::Strtoui64(*StrId, nullptr, 10)) {}

        operator ovrID() const
        {
            return Id;
        }

    private:

        UPROPERTY()
        uint64 Id;
    };

For C enums equivalents, we use the _UENUM_ macro.  See [OVRPlatformEnums.h](../Source/OVRPlatform/Public/OVRPlatformEnums.h).
Each of them comes with C to/from UE converters.

    UENUM(BlueprintType)
    enum class EOvrLaunchResult : uint8
    {
        Unknown,
        Success,
        FailedRoomFull,
        FailedGameAlreadyStarted,
        FailedRoomNotFound,
        FailedUserDeclined,
        FailedOtherReason,
    };

    ovrLaunchResult ConvertLaunchResult(EOvrLaunchResult Value);
    EOvrLaunchResult ConvertLaunchResult(ovrLaunchResult Value);


When used as an input parameter to a blueprint node, the enumeration appears as a nicely readable drop-down menu.

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/enumeration_blueprint.png">
</div>

We also have _USTRUCT_ equivalents for all public models exposed by the Oculus platform.
You can see them in [OVRPlatformModels.h](../Source/OVRPlatform/Public/OVRPlatformModels.h).

    USTRUCT(BlueprintType, Category = "OvrPlatform|Models|AchievementDefinition")
    struct OVRPLATFORM_API FOvrAchievementDefinition
    {
        GENERATED_USTRUCT_BODY()

        UPROPERTY(BlueprintReadOnly)
        EOvrAchievementType AchievementType;

        /** The name of the achievement. */
        UPROPERTY(BlueprintReadOnly)
        FString ApiName;

        UPROPERTY(BlueprintReadOnly)
        int32 BitfieldLength;

        UPROPERTY(BlueprintReadOnly)
        int64 Target;

        // Default ctor.
        FOvrAchievementDefinition();

        // Copying values from an OVR handle.
        FOvrAchievementDefinition(ovrAchievementDefinitionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);

        // Setting all values to their defaults.
        void Clear();

        // Updating with values from an OVR handle.
        void Update(ovrAchievementDefinitionHandle OvrHandle, TOvrMessageHandlePtr MessageHandlePtr);
    };

The FOvrAchievementDefinition structure comes with a constructor that can populate itself using the
C API handle _ovrAchievementDefinitionHandle_.

### A7. Arrays

For large collections of objects, such as leaderboard entries, the Oculus platform uses paged arrays, which is
basically a list of sub-arrays that can be fetched one at a time.  Some of those collections are forward-only,
which means that you can fetch the next page only.   Others are bidirectional and allow you to fetch forward and
backward.

Here is an example for fetching your logged in friends.

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/user_get_logged_in_user_friends_blueprint.png">
</div>

When successful, the request returns a first page.  When you enter *FetchUserPage* by the unnamed pin, you get
the usual first exit by the unnamed "then" pin, followed by an exit by *PageReady*, at which point you can process
a traditional TArray of reponses using *ForEachLoop*, as an example.  Here the array element has been split in
place to expose all user fields.  When the loop reaches the end, we reenter *FetchUserPage* using the *NextPage* pin.
As long as there are pages, *PageReady* will fire, and eventually we will exit by *NoMorePages*.

Note that the same semantics are guaranteed as for other request nodes: if you reenter the node before processing
the previous response, the previous request will be preempted.   You are also guaranteed that you will always
have the execution exit the "then" unnamed pin every single time you enter the fetching node, regardless of how you
enter it.

Finally, another example with a bidirectional paged array.

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/challenges_get_entries_after_rank_blueprint.png">
</div>

This example uses 3 custom events for fetching pages (an initial fetch around a rank and next/previous page fetches) and
another custom event to display a full page on an in-game leaderboard.  The events for fetching more pages could be
linked to next/previous page buttons on the leaderboard UI.

### A8. Functions

For completion, let's also note that we have a number of functions available in
[OVRPlatformFunctions.h](../Source/OVRPlatform/Public/OVRPlatformFunctions.h) for local calls,
in particular for retrieving the current launch details or the ID of the current user.

<div style="text-align: center;  padding: 10pt;">
    <img src="./Media/platform_get_logged_in_user_id.png">
</div>

These functions are not latent and immediately return a response.

As a side note, we should contrast three ways that we have to retrieve information about the currently
logged in user.  _Platform_GetLoggedInUserID_ immediately returns the __ID__ of the user, and nothing else.
_User_GetLoggedInUser_ is a request that actually doesn't call the server and returns on the next tick
a partially filled response with the __ID__, the __Oculus ID__ (account name), and the normal and small
__Image Urls__.  To get all of the available information about a user, use _User_GetUser_ with the __ID__
returned by one of the other functions: this will issue a server request.

## B. Oculus Net Driver

When we first started work on this plugin for the SharedSpaces project, we used the Oculus networking transport
facilities, in particular for the Oculus room system.  We have since replaced this with Photon to satisfy our
developers demand for samples using that tranport sdk, as you can see in that project's DefaultEngine.ini.
You can uncomment the Oculus net driver if you want to use it.

    [/Script/Engine.GameEngine]
    #+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="/Script/OVRPlatform.NetDriverForOculus",DriverClassNameFallback="/Script/OnlineSubsystemUtils.IpNetDriver")
    +NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="/Script/PhotonNetDriver.PhotonIpNetDriver", DriverClassNameFallback="/Script/OnlineSubsystemUtils.IpNetDriver")

These files were originally available in the Oculus Online SubSystem and have been copied here in our effort
to reduce the number of layers standing between the Oculus platform and the UE4 blueprints.

The key files that adapt the Oculus transport layer to the UE4 networking stack are

- [OVRNetDriver.h](../Source/OVRPlatform/Private/OVRNetDriver.h) and
  [.cpp](../Source/OVRPlatform/Private/OVRNetDriver.cpp)
- [OVRNetConnection.h](../Source/OVRPlatform/Private/OVRNetConnection.h) and
  [.cpp](../Source/OVRPlatform/Private/OVRNetConnection.cpp)

Diving into the UE4 networking is beyond this plugin documentation.   To get started we highly recommend
Cedric Neukirchen's
[Unreal Engine 4 Compendium](https://cedric-neukirchen.net/Downloads/Compendium/UE4_Network_Compendium_by_Cedric_eXi_Neukirchen.pdf).

<div style="text-align: right; padding: 10pt;">&#x25A0;</div>
