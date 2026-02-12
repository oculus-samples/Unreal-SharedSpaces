![Showcase Banner](./Media/banner.png "SharedSpaces")

<div style="width: 60%; padding: 10pt;">
<table>
<tr style="background-color:#EEEEEE;">
<td>
A. <a href="#A">Overview of SharedSpaces</a><br/>
B. <a href="#B">SharedSpaces in Action</a><br/>
C. <a href="#C">SharedSpaces Implementation</a><br/>
&nbsp;&nbsp;&nbsp;1. <a href="#C1">SharedSpaces Game Instance</a><br/>
&nbsp;&nbsp;&nbsp;2. <a href="#C2">Roster and Invite Panels</a><br/>
&nbsp;&nbsp;&nbsp;3. <a href="#C3">Portals</a><br/>
&nbsp;&nbsp;&nbsp;4. <a href="#C4">SharedSpaces Character</a><br/>
&nbsp;&nbsp;&nbsp;5. <a href="#C5">In-Game Log</a><br/>
&nbsp;&nbsp;&nbsp;6. <a href="#C6">External Application Portal</a><br/>
&nbsp;&nbsp;&nbsp;7. <a href="#C7">User Reporting</a><br/>
D. <a href="#D">Oculus Application Configuration</a><br/>
&nbsp;&nbsp;&nbsp;1. <a href="#D1">Application Identifier</a><br/>
&nbsp;&nbsp;&nbsp;2. <a href="#D2">Destinations</a><br/>
&nbsp;&nbsp;&nbsp;3. <a href="#D3">Data Use Checkup</a><br/>
&nbsp;&nbsp;&nbsp;4. <a href="#D4">Upload to Release Channel</a><br/>
&nbsp;&nbsp;&nbsp;5. <a href="#D5">EOS Configuration</a><br/>
</td>
</tr>
</table>
</div>


<a id="A"></a>
# A. Overview of SharedSpaces

The VR Developer Tools team built SharedSpaces to show how to quickly gather people in VR using Oculus Social Platform APIs. This version uses Unreal Engine with the Unreal EOS plugin as the transport layer. Other versions exist, including one for Unity.

<div style="margin: auto; width: 60%; padding: 10pt;">
<table>
<tr style="background-color:#FFEEEE;">
	<td style="border:0px;"><b>Oculus</b></td>
	<td style="border:0px;">Group presence with <i>destination</i>, <i>lobby</i>, and <i>match</i> IDs.</td>
</tr>
<tr style="background-color:#EEFFEE;">
	<td style="border:0px;"><b>EOS</b></td>
	<td style="border:0px;">Transport via a <i>room</i> named after the <i>lobby</i> or <i>match</i> ID.</td>
</tr>
<tr style="background-color:#EEEEFF;">
	<td style="border:0px;"><b>UE4</b></td>
	<td style="border:0px;">Replication between <i>room members</i> with <i>the master client</i> as host.</td>
</tr>
</table>
</div>

SharedSpaces networking has three layers. The Oculus layer provides presence info to find and connect with friends. The EOS layer transports messages between players. The UE4 layer replicates game objects.

This overview explains each layer and how they connect to create a simple multiplayer app. It lets people connect and play together without a dedicated server.

## *A Private Lobby Connected to Rooms*

<div style="text-align: center; padding: 10pt;"><img src="./Media/layout.png" align="middle" width="600"></div>

SharedSpaces consists of connected levels called destinations. Your personal lobby sits at the center, with doors leading to surrounding matches. Matches on the left are private and accessible only from your lobby. The match on the right is public and reachable from any lobby.

## *Social Layer - Destination, Lobby & Match Session IDs*

<div style="text-align: center; padding: 10pt;"><img src="./Media/presence.png" align="middle" width="750"></div>

This layout directly represents the new group presence APIs. To send you to a SharedSpaces destination, we set your destination and two session IDs in your group presence: a lobby session ID, which rarely changes, and a match session ID, set only when you join a match.

Destinations are specific app areas defined on the [Developer Dashboard](https://developers.meta.com/horizon/manage/) under **Platform Services > Destinations**. The lobby session ID identifies a close group that stays together between games and may play as a team. The match session ID identifies players currently in a match, regardless of team.

<div style="text-align: center; padding: 10pt;"><img src="./Media/invitation_to_lobby.png" align="middle" width="600"></div>

When you launch SharedSpaces, you start in your private lobby with a unique ID. To form a group before and after matches, you invite others to share your lobby. If they accept, their lobby session ID matches yours. When you are in the lobby simultaneously, you share the same space.

Think of the lobby as your group's base camp. Different groups return to their own lobbies after matches.

<div style="text-align: center; padding: 10pt;"><img src="./Media/private_room.png" align="middle" width="700"></div>

Group members can move anytime between their lobby and private matches. This only changes their match session IDs.

<div style="text-align: center; padding: 10pt;"><img src="./Media/invitation_to_match.png" align="middle" width="700"></div>

You can invite anyone to your private match. When they accept, they join you and their match session ID updates. Accepting a match invitation does not change the lobby session ID.

<div style="text-align: center; padding: 10pt;"><img src="./Media/respective_lobbies.png" align="middle" width="650"></div>

When players leave a match through the lobby door, they return to their own lobbies if they are not in the same group.

<div style="text-align: center; padding: 10pt;"><img src="./Media/public_room.png" align="middle" width="650"></div>

SharedSpaces also includes a purple room representing a public match accessible from all lobbies. Anyone can enter from their lobby at any time. This room lets you meet people outside your group without invitations.

## *Transport Layer - EOS Lobbies*

EOS uses lobbies to connect users. Players in the same match or lobby share an EOS lobby, allowing data to flow between them. The transport layer routes packets between users, often behind firewalls.

<div style="text-align: center; padding: 10pt;"><img src="./Media/session_to_room.png" align="middle" width="650"></div>

EOS lobbies have *unique names*. We name rooms using the social layer’s session IDs: either the match session ID if set, or the lobby session ID otherwise.

A key EOS feature is tracking the oldest member, called the “master client,” marked with stars.

<div style="text-align: center; padding: 10pt;"><img src="./Media/eos_join_or_create.png" align="middle" width="650"></div>

For example, when Alice, Bob, and Charlie enter the Purple room, Charlie joins first, creating the room and becoming the **master client**. Alice and Bob join later as **normal clients**.

<div style="text-align: center; padding: 10pt;"><img src="./Media/eos_notification.png" align="middle" width="650"></div>

If Charlie leaves, EOS selects a new master client and notifies all clients. This feature supports the next networking layer.

## *Game Replication Layer - Unreal Engine Clients and Listen-Server*

<div style="text-align: center; padding: 10pt;"><img src="./Media/ue4_dedicated_server.png" align="middle" width="650"></div>

UE4 uses a client-server model. Clients connect to a server that enforces rules and replicates relevant objects.

For trusted authority or powerful hardware, the server runs as a dedicated server in a data center. Each UE4 client runs on its own headset and connects to this server.

<div style="text-align: center; padding: 10pt;"><img src="./Media/ue4_listen_server.png" align="middle" width="650"></div>

SharedSpaces hosts the server on one headset as a listen-server. Here, Unreal Engine acts as both server and first client, accepting connections from others.

<div style="text-align: center; padding: 10pt;"><img src="./Media/ue4_open.png" align="middle" width="650"></div>

For each room, the transport layer selects the UE4 listen-server host. The **master client** of the EOS room becomes the host. The host opens a map with the ‘listen’ option. Clients connect to the host using an EOS Net Driver address.

<div style="text-align: center; padding: 10pt;"><img src="./Media/eos_to_ue4_1.png" align="middle" width="650"></div>

When the host leaves, host migration occurs. For example, Alice leaves the purple room. EOS selects Bob as the new master client. Remaining members are notified and reconnect to Bob.

<div style="text-align: center; padding: 10pt;"><img src="./Media/eos_to_ue4_2.png" align="middle" width="650"></div>

Now, two EOS rooms exist. The Purple room is hosted by Bob, with Charlie and Donna connected. Alice left through the door to her lobby. Since she is alone there, she becomes the master client and host of her group lobby.


<a id="B"></a>
# B. SharedSpaces in Action

Let's see how SharedSpaces works.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/1a.jpg" width="250">
	<img src="./Media/screenshots/1b.jpg" width="250">
</div>

Alice starts SharedSpaces alone in her private lobby. She is the master client and host, shown by the star next to her name.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/2a.jpg" width="250">
	<img src="./Media/screenshots/2b_id.jpg" width="250">
	<img src="./Media/screenshots/2c.jpg" width="250">
	<img src="./Media/screenshots/2d.jpg" width="250">
</div>

Alice wants Bob to join her group so they can stay together between matches. She steps on the invite panel switch and sends him an invitation from her lobby. When Bob accepts, SharedSpaces launches on his headset with a deeplink message that lets him join Alice in-game. Bob’s lobby session ID updates to match Alice’s, so they share the same lobby.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/3a.jpg" width="250">
	<img src="./Media/screenshots/3b.jpg" width="250">
	<img src="./Media/screenshots/3c.jpg" width="250">
	<img src="./Media/screenshots/3d.jpg" width="250">
</div>

Bob enters the blue door to start a private match, followed by Alice. They arrive in the same Blue Room with a shared match session ID for their private room. Since Bob arrived first, he hosts the room, and Alice connects to him.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/4a_id.jpg" width="250">
	<img src="./Media/screenshots/4b_id.jpg" width="250">
	<img src="./Media/screenshots/4c.jpg" width="250">
	<img src="./Media/screenshots/4d.jpg" width="250">
</div>

Alice invites her friend Charlie to join their match. Charlie accepts while in his own lobby. His match session ID updates to the private match ID, but he keeps his original lobby session ID. This means he remains in a different group.

<div style="text-align: center; padding="10pt;">
	<img src="./Media/screenshots/5a.jpg" width="250">
	<img src="./Media/screenshots/5b.jpg" width="250">
	<img src="./Media/screenshots/5c.jpg" width="250">
</div>

When Bob leaves the blue room, EOS notifies Alice and Charlie that the master client changed. Alice becomes the new master client and opens a UE4 listen-server. Charlie connects to her. Meanwhile, Bob starts hosting his own group lobby.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/6a.jpg" width="250">
	<img src="./Media/screenshots/6b.jpg" width="250">
</div>
<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/6c_id.jpg" width="250">
	<img src="./Media/screenshots/6d_id.jpg" width="250">
	<img src="./Media/screenshots/6e_id.jpg" width="250">
</div>

When Charlie leaves the blue room, he does not join Bob because they have different lobby session IDs. Instead, Charlie returns to his separate lobby. You can verify this by stepping on the roster panel switch, which lists your different groups.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/7a.jpg" width="250">
	<img src="./Media/screenshots/7b.jpg" width="250">
</div>

For Alice, returning to the lobby means rejoining Bob, who is waiting for her.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/8a_id.jpg" width="250">
	<img src="./Media/screenshots/8b_id.jpg" width="250">
	<img src="./Media/screenshots/8c.jpg" width="250">
	<img src="./Media/screenshots/8d.jpg" width="250">
</div>

To add Charlie to their group, Alice or Bob simply send him an invitation from their lobby. When Charlie accepts, his lobby session ID updates, and all three share the same lobby between matches.


<a id="C"></a>
# C. SharedSpaces Implementation

SharedSpaces uses the Oculus Platform and Unreal EOS plugin. Each has a [game instance subsystem](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Subsystems/) implemented in its own plugin. This design makes them easy to reuse in your projects.

You can find detailed documentation for these plugins here:
- [Oculus Platform](../Plugins/OculusPlatform/Documentation/OculusPlatform.md)

Next, we explain how these subsystems integrate at the project level.

<a id="C1"></a>
## 1. SharedSpaces Game Instance

The core logic at the project level is the SharedSpaces Game Instance blueprint. In Unreal Engine, the game instance is a persistent singleton object that lasts for the entire process, surviving map loads.

Below is its overall layout.

<div style="text-align: center;  padding: 10pt;">
	<img src="./Media/game_instance_overview.png" width="400">
</div>

We can divide it into two parts: initializing subsystems and using them to enable player communication through social, transport, and application networking.

### 1a. Registering Subsystem Callbacks

At the top, the blueprint registers event handlers for both major subsystems.

+ **Oculus Platform Subsystem**
	+ **On Login Complete:** Wait until Oculus login finishes before identifying with EOS, since both use the same unique user and application identifiers. These identifiers do not reveal personal information.
	+ **On Launch Intent Changed:** Triggered when the app starts. We only handle manual launches to start at the default destination.
	+ **On Group Launch Intent Received:** Triggered when the app receives an Oculus group presence launch intent. This happens when joining a specific destination with lobby and match IDs plus a deeplink message, usually after accepting an invitation.

+ **EOS Subsystem**
	+ **On Log Entry:** Enables logging of EOS info, warnings, and errors.
	+ **On Login:** Fires when the user attempts EOS login. EOS login must succeed before continuing initialization.
	+ **On Room Created:** Fires when creating an EOS lobby, triggering a UE4 client/server connection.
	+ **On Room Found:** Fires after searching for an EOS lobby. If found, the user joins it; otherwise, they create a new lobby.
	+ **On Room Joined:** Fires when joining a lobby, triggering a UE4 client/server connection.
	+ **On Master Client Changed:** Handles host migration. When the EOS master client leaves, remaining users are notified. The new master client starts a listen-server, and others connect to it.
	+ **On Room Destroyed:** Fires when a user leaves a lobby. If the user was alone, the lobby is destroyed.
	+ **On Player Joined:** Notifies the master client when a player joins.
	+ **On Player Left:** Notifies the master client when a player leaves.
	+ **On App Enters Foreground:** Usually triggered when the user removes and replaces their headset. The app rejoins the previous lobby.

These subsystems share the game instance’s lifecycle: they are singletons that live as long as the app. The main challenge is managing timing dependencies between subsystems and the game instance. Here, the Oculus Platform and EOS subsystems notify the game instance by calling `OculusPlatformSubsystemStarted` and `EOSInitialized` events. These calls happen by name in code, so no prior bindings are needed.

### 1b. Social Networking: Setting Your Group Presence

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/network_launch.png" width="200">
</div>

The rest of the blueprint handles the *Network Launch* sequence, which starts with a user's social platform group presence. This presence includes a destination and lobby and match IDs. Here is the information needed to connect players:

+ **Destination Api Name:** Define destinations for your app on the [Oculus application dashboard](https://developers.meta.com/horizon/manage/). These destinations support deep linking for seamless navigation. SharedSpaces defines one destination for the lobby and one for each colored room.
	<div style="text-align: center; padding: 10pt;">
		<img src="./Media/dashboard_destinations.png" width="1200">
	</div>

+ **Level Name:** Each destination links to a distinct level in SharedSpaces. This design choice helps illustrate destinations as simple, colored spaces. The level to load is stored in the destination’s dashboard configuration.
	<div style="text-align: center; padding: 10pt;">
		<img src="./Media/destination_config.png" width="400">
	</div>
	The *deeplink message* is an optional app-specific string. SharedSpaces uses a simple JSON format with key-value pairs. Every destination includes a "map" key, as shown for the Red Room.

+ **Lobby Id:** Oculus group presence includes identifiers to specify location. The *lobby session id* groups users who stay together beyond a single match. In the roster panel, users sharing a lobby id appear grouped. Your app decides how to use this grouping, but generally, users in the same lobby stay together between matches and, if possible, on the same team.

	In SharedSpaces, you receive a unique lobby id when starting the app. You share your lobby id by inviting others to join your Lobby destination. Accepting the invitation adds them to your team.

	At the Lobby destination, you join the EOS room named after your lobby id.

+ **Match Id:** The *match session id* identifies your current destination when not in the team lobby.

	For private matches (Red, Green, Blue rooms), match ids link uniquely to your lobby (e.g., "RedRoom_for_Lobby123"). For public matches (Purple room), match ids use a shared public name (e.g., "ThePurpleRoom"). Currently, only one purple room exists, which does not scale. Public rooms should use matchmaking to distribute players across instances, considering lobby ids to keep teams together. We plan to add this in a future version.

	At a colored room destination, you join the EOS room named after your match id.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/query_destination.png" width="1000">
</div>

Group presence setup differs when joining a lobby versus a match. The destination type is stored in the destination deeplink on the dashboard. We query the destination by name and extract this info using the *Get Is Lobby* node from the deeplink. Since this data format is app-specific, the node is implemented in a project blueprint library (see [SharedSpacesFunctionLibrary.h](../Source/SharedSpaces/Public/SharedSpacesFunctionLibrary.h)).

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/lobby_match_split.png" width="1000">
</div>

When joining a lobby, we set the user's presence to the lobby session id passed to *Network Launch*. For invitations, this is the sender’s lobby id, so you join their team and lobby. Joining a lobby always clears your match session id.

You can join a match in two ways: through a portal or by accepting an invitation. When using a portal, we derive the match id from the origin lobby (e.g., "RedRoom_for_Lobby123"). Since all users in a lobby share the same lobby id, they join the same match via the portal.

When accepting a match invitation, a user keeps their current presence lobby id but uses the match id passed to *Network Launch* as their presence match id.

For public matches, we override the match id with the room’s public name, as explained earlier.

### 1c. Transport Layer: Joining or Rejoining an EOS Lobby

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/FindSession.png" width="600">
</div>

We join an EOS Lobby based on the user's group presence set earlier: we use the match ID if available, otherwise the lobby ID.

We locate the lobby using *Find Session*.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/FindSessionDelegate.png" width="600">
</div>

After *Find Session* completes, a callback runs. If the lobby is found, the user attempts to join it by calling *Join Session*. If not, the lobby is created with *Create Session*, and the user becomes the initial master client.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/OnAppEntersForeground.png" width="600">
</div>

We must rejoin the current EOS room in two cases: when the connection to the EOS lobby is lost (rare) and when the application returns to the foreground (common). The EOS setup region of the blueprint handles these events.

### 1d. Application Replication: Establishing UE4 Client-Server Connections

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/LobbyCreation.png" width="1200">
</div>

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/JoinLobby.png" width="1200">
</div>

UE4 network connections are established after joining or rejoining an EOS lobby. We need three key pieces of information: the EOS room master client status, the host address of the current master client, and an optional start location.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/host_migration.png" width="1200">
</div>

When the master client changes, we perform a host migration by reestablishing UE4 network connections.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/ue4_open_level.png" width="1200">
</div>

We create the UE4 connection using the __open__ console command. This command takes a parameter resembling an HTTP URL and has two forms depending on whether we host the level or join an existing server:

+  __Master Client__: open &lt;level&gt; # &lt;startpos&gt; ? listen
+  __Normal Client__:  open &lt;address&gt; # &lt;startpos&gt;

The EOS room master client opens the level by name and adds "?listen" to accept client connections, enabling __listen-server__ mode. Other clients connect using the host address, which in SharedSpaces is the host's application-specific user ID followed by ".oculus".

The start position has two forms:

+  __Joining__: the destination origin
+  __Rejoining__: the current location and rotation as a string

We provide a sensible start position depending on whether the user is joining or rejoining.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/start_positions.png" width="600">
</div>

We place several player start objects in the level, which look like console controllers with flags.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/player_start_tag.png" width="300">
</div>

Each player start can have an optional *Player Start Tag*. SharedSpaces includes one default player start without a tag for first-time game starts. We also place tagged player starts in front of portals matching their destinations. When traveling between spaces, players spawn near the door leading to their origin.

When rejoining a space, such as during host migration, we respawn the player at their current location and orientation. We create a new player start at that location and use it during spawning.

<a id="C2"></a>
## 2. Roster and Invite Panels

The roster panel is a key part of the Oculus group presence system. It appears as a 3D system panel in your field of view, overlaying any game content. It shows who you are playing with and who you have invited.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/roster_panel.jpg" width="400">
</div>

In SharedSpaces, you open the roster panel by moving your character onto a pressure plate. The *RosterPanelLaunchTrigger* blueprint calls the Oculus Platform Subsystem to launch the panel.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/launch_roster_panel.png" width="400">
</div>

When the system panel opens, VROS absorbs all controller input until the panel closes. In UE4, this means if your player triggers the panel while moving, they will keep moving even after releasing the thumbstick. To prevent this, the blueprint waits for the character to stop moving and confirms the character is still on the pressure plate before opening the panel.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/4b_id.jpg" width="400">
</div>

You can open the invite panel from the roster panel (lower left button) or directly via a separate call to the Oculus Platform Subsystem.

<a id="C3"></a>
## 3. Portals

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/purple_portal.png" width="400">
</div>

The _Portal_ blueprint triggers a _Network Launch_ on the SharedSpaces Game Instance for any player entering its collision volume. You can place it in the level with its built-in visible geometry or next to an existing door object. You must set its __destination__ parameter, which matches a destination name defined on the dashboard.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/portal_network_launch.png" width="1200">
</div>

When a user enters the portal, we retrieve their current lobby ID and query the destination's level name. We perform a network launch with these values and leave the match ID empty, even when traveling to a match. This works because match IDs derive from lobby session IDs when traveling through portals, as explained earlier.

<a id="C4"></a>
## 4. SharedSpaces Character

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/shared_spaces_character.png" width="800">
</div>

The SharedSpaces Character is a classic UE4 mannequin with some modifications.

### 4a. Character Attributes

In SharedSpaces, users differ by name, color, master client status, and current destination. Pressing the trigger sets a new random color. Pressing the thumbstick down hides your character name (default is your Oculus name) and lets you choose between "Alice," "Bob," and "Charlie." This hidden feature helps create screenshots and videos.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/local_character_on_game_instance.png">
</div>

Most objects, including the player character, are lost between level loads. To persist data, we copy these values to variables on the SharedSpaces Game Instance. For example, the current destination is used during the __UE4 Open Level__ process.

We replicate the user's name, color, and master client status so all players can identify each other, with distinctive colors and a star above the master client.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/body_color_rep.png">
</div>

For example, the character color uses a linear color variable called __BodyColor__ with _RepNotify_ replication. When the server sets this value, it replicates to all clients and triggers the notification function __OnRep_BodyColor__.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/set_body_color.png" width="1200">
</div>

Calling __SetBodyColor__ does not set __BodyColor__ locally. Instead, it sends a message to the server to set the value, ensuring replication to all clients, including the caller.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/notify_server_of_body_color_cfg.png">
	<img src="./Media/notify_server_of_body_color.png">
</div>

__NotifyServerOfBodyColor__ is a reliable server event that sets __BodyColor__ on the server and replicates it with notification.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/on_rep_body_color.png" width="1200">
</div>

When clients receive the replicated value, __OnRepBodyColor__ runs and updates the character's material parameter. This happens on all clients, including the owner.

### 4b. Camera Behavior

The [camera components](https://docs.unrealengine.com/4.27/en-US/Basics/Components/Camera/) are highly configurable. For this showcase, we implemented a custom behavior via blueprint: the camera location does not move with the character to improve comfort. After the character stops moving and a delay passes, the camera resets behind the character, oriented by the character's rotation. The camera still rotates with the headset as the user looks around.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/character_params.png">
</div>

Two parameters under *Camera Logic* control this: the wait time after stopping before resetting the camera, and the minimum travel distance between resets. These reduce the number of camera resets for comfort.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/character_is_stationary.png">
</div>

Each tick, the local character checks movement status, providing *IsStationary*, *LastTimeWithMovement*, and *LastLocationWithMovement*.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/camera_behavior_1.png">
</div>

After confirming VR headset use, two conditions must be met before resetting the camera: the character must be stationary, and enough time and distance must have passed since the last reset.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/manual_reset.png">
</div>

These conditions are bypassed when the user manually requests a reset by pressing the __A__ or __X__ buttons.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/camera_behavior_2.png">
</div>

We adjust the *camera lag speed* to freeze or reset the camera location. The *camera boom* (Spring Arm Component) follows the player smoothly. We set lag speed near zero to hold the camera in place and high speed to reset it instantly.

<a id="C5"></a>
## 5. In-Game Log

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/log.jpg" width="800">
</div>

Pressing the grip button toggles the in-game log panel. Most important events happen behind the scenes in this technical showcase. The log panel connects to the persistent log added to the Oculus Platform Subsystem, ensuring the log remains between level loads.

<a id="C6"></a>
## 6. External Application Portal

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/external_application_portal.png" width="400">
</div>

These portals work like the standard Portals. Place the _ExternalAppPortal_ blueprint, then set the Application App ID and destination name. When a player enters its collision volume, the portal calls _Launch External App_ on the SharedSpaces Game Instance. The Game Instance validates inputs and calls the Platform function _Application Launch Other App_.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/external_app_launch.png" width="1200">
</div>

This implements the [App to App Travel](https://developers.meta.com/horizon/documentation/unreal/ps-app-to-app-travel/) platform feature.

## 7. <a id="C7">User Reporting</a>

When users press the Oculus button and select _Report_, your application must notify the system how it will handle the report. You can provide your own in-app reporting flow or defer to the system by selecting _Unhandled_.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/user_reporting.png" width="1200">
</div>

This implements the [User Reporting](https://developers.meta.com/horizon/resources/reporting-plugin/) platform feature.


<a id="D"></a>
# D. Oculus Application Configuration

To build and run your own copy of SharedSpaces, create an application on the [Developer Dashboard](https://developers.meta.com/horizon/).

<a id="D1"></a>
## 1. Application Identifier

Place your Oculus application identifier in _SharedSpaces/Config/DefaultEngine.ini_ as follows:

	[OnlineSubsystemOculus]
	bEnabled=false
	RiftAppId=123xxxxxxxxxx321
	MobileAppId=123xxxxxxxxxx321

Although SharedSpaces does not use the Oculus Online Subsystem (OSS), the identifier is still required in this section.

Find the identifier (__App ID__) in the _API_ section.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/dashboard/dashboard_api.png" width="800">
</div>

You need a `MobileAppId` for Quest builds and a `RiftAppId` for Quest Link.

<a id="D2"></a>
## 2. Destinations

Recreate the SharedSpaces destinations in your application. Find Destinations under __Engagement__.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/dashboard/dashboard_platform_services.png" width="800">
</div>

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/dashboard/dashboard_destinations.png" width="800">
</div>

SharedSpaces has four destinations: a Lobby, three private rooms (Red, Green, Blue), and one public room (Purple). Their settings are:

| API Name | Deeplink Message | Display Name | Description |
| :--- | :--- | :--- | :--- |
| [Lobby](./Media/dashboard/dashboard_destination_lobby.png) | {"is_lobby":"true","map":"Lobby"} | Lobby | The Lobby |
| [RedRoom](./Media/dashboard/dashboard_destination_redroom.png) | {"map":"RedRoom"} | Red Room | The Red Room |
| [GreenRoom](./Media/dashboard/dashboard_destination_greenroom.png) | {"map":"GreenRoom"} | Green Room | The Green Room |
| [BlueRoom](./Media/dashboard/dashboard_destination_blueroom.png) | {"map":"BlueRoom"} | Blue Room | The Blue Room |
| [PurpleRoom](./Media/dashboard/dashboard_destination_purpleroom.png) | {"map":"PurpleRoom","public_room_name":"ThePurpleRoom"} | Purple Room | The Purple Room |

Set __Deeplink Type__ to __Enabled__ and add an image for each destination. SharedSpaces sets the destination __Audience__ to __Everyone__. Also, set the max group launch capacity for each destination to enable the group launch feature.

<a id="D3"></a>
## 3. Data Use Checkup

Request access to platform data required by SharedSpaces. Under __Data Use Checkup__, add and submit these items for certification:

+ User ID
+ User Profile
+ Deep Linking
+ Friends
+ Invites

<a id="D4"></a>
## 4. Upload to Release Channel

Upload an initial build to a release channel to use platform features. Follow the instructions at [Unreal Sign Project for Release](https://dev.epicgames.com/documentation/en-us/unreal-engine/signing-android-projects-for-release-on-the-google-play-store-with-unreal-engine).

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/Developerhub.png" width="800">
</div>

After packaging your project, open the Meta Developer Hub app, go to App Distribution, find your app, select a Release Channel, and press Upload.

Once uploaded, the build appears on the Oculus Developer Dashboard under Distribution -> Release Channels.

After passing all tests, go to Distribution -> Release Channels, select your release channel, then go to Users and click Email Invite Users. Invite all users who need access.

Use emails linked to Quest devices; otherwise, the Oculus platform will not work correctly.

If done correctly, the app appears in your Quest library, ready to download and install. After this, you can upload development or shipping builds directly, and the entitlement check will always pass.

Each time you upload a new build, delete the app data on your Quest device before launching. Go to Settings -> Storage, find your app, and select Delete App Data.

To test with other users, add them to the channel. See [Add Users to Release Channel](https://developers.meta.com/horizon/resources/publish-release-channels-add-users/) for details.

Once the initial build is uploaded, you can test local changes with any development build using the same application ID without uploading every build.

<a id="D5"></a>
## 5. EOS Configuration

Configure EOS by following the instructions [here](EOSConfiguration.md).

<div style="text-align: right; padding: 10pt;">&#x25A0;</div>
