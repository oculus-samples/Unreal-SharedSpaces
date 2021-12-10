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
D. <a href="#D">Oculus Application Configuration</a><br/>
&nbsp;&nbsp;&nbsp;1. <a href="#D1">Application Identifier</a><br/>
&nbsp;&nbsp;&nbsp;2. <a href="#D2">Destinations</a><br/>
&nbsp;&nbsp;&nbsp;3. <a href="#D3">Data Use Checkup</a><br/>
&nbsp;&nbsp;&nbsp;4. <a href="#D4">Photon Configuration</a><br/>
</td>
</tr>
</table>
</div>


# A. <a id="A">Overview of SharedSpaces</a>
SharedSpaces was built by the VR Developer Tools team to demonstrate how you can quickly get people together
in VR using the Oculus Social Platform APIs.  This version was built for the Unreal Engine using the Photon SDK as
the transport layer.  Other versions are available, in particular one built for the Unity game engine.

<div style="margin: auto; width: 60%; padding: 10pt;">
<table>
<tr style="background-color:#FFEEEE;">
	<td style="border:0px;"><b>Oculus</b></td>
	<td style="border:0px;">Group presence with <i>destination</i>, <i>lobby</i> and <i>match</i> ids.</td>
</tr>
<tr style="background-color:#EEFFEE;">
	<td style="border:0px;"><b>Photon</b></td>
	<td style="border:0px;">Transport via a <i>room</i> named after the <i>lobby</i> or <i>match</i> id.</td>
</tr>
<tr style="background-color:#EEEEFF;">
	<td style="border:0px;"><b>UE4</b></td>
	<td style="border:0px;">Replication between <i>room members</i> with <i>the master client</i> as host.</td>
</tr>
</table>
</div>

SharedSpaces networking is divided into three layers.  The Oculus layer provides presence information needed
to find and connect with friends.  The Photon layer provides the transport layer for sending messages to other
players.  And the UE4 layer handles the replication of game objects.

In this overview we will explore each of these layers and show how we connected them together to make a
simple multiplayer application which allows people to connect and play together, without the need for a
dedicated server.

## *A Private Lobby Connected to Rooms*
<div style="text-align: center; padding: 10pt;"><img src="./Media/layout.png" align="middle" width="600"></div>

SharedSpaces is made of a few connected levels, known as destinations.  In the center is your personal lobby 
with doors leading to the surrounding matches.  The matches on the left are private and are reachable from your
own lobby only.  The match on the right is public, reachable from any lobby.

## *Social Layer - Destination, Lobby & Match Session IDs*

<div style="text-align: center; padding: 10pt;"><img src="./Media/presence.png" align="middle" width="750"></div>

We use this layout as a direct representation of the new group presence apis.  To get you to a SharedSpaces
destination, we first set your destination and a pair of session identifiers in your group presence:
one for your lobby session id, which should not change very often, and one for your match session id,
only set when you join a match.

The destinations are specific areas of your application that are defined on the
[Oculus dashboard](https://developer.oculus.com/manage) under **Platform Services > Destinations**.
The lobby session id represents a tight group of people that want to stay together between games and
possibly play as part of the same team during matches.  The match session id is shared by people currently
playing a match together, whether they are on the same team or not.

<div style="text-align: center; padding: 10pt;"><img src="./Media/invitation_to_lobby.png" align="middle" width="600"></div>

When you first launch SharedSpaces, you start in your own private lobby for which we create a unique id.
To form a group to be with before and after matches, you invite people to share your lobby.  If they accept
the invitation, their lobby session id will be updated to be the same as yours, and whenever you will be in 
the lobby at the same time, you will be together in the same space.

You can think of the lobby as the base camp for your group.  Different groups always go back to their respective
lobbies after matches.

<div style="text-align: center; padding: 10pt;"><img src="./Media/private_room.png" align="middle" width="700"></div>

Members of your group are free to travel at any time between your lobby and their private matches.
This only affects the match session ids of their group presence.

<div style="text-align: center; padding: 10pt;"><img src="./Media/invitation_to_match.png" align="middle" width="700"></div>

You can also grant access to your private match to anyone.  You invite them from that match, and they join you
when they accept the invitation.  In SharedSpaces, accepting an invitation to a match only affects your match
session id, not your lobby session id.  

<div style="text-align: center; padding: 10pt;"><img src="./Media/respective_lobbies.png" align="middle" width="650"></div>

As a consequence, when they leave the match through the lobby door, users effectively go back to
their separate lobbies if they are not members of the same group.

<div style="text-align: center; padding: 10pt;"><img src="./Media/public_room.png" align="middle" width="650"></div>

SharedSpaces also has the purple room to represent a public match that is reachable from all lobbies.
Again, anybody is free to go from their lobby to the purple room at any time, and it only affects
their match session id.  It is a space where you can meet people from outside your group without a prior
invitation.

## *Transport Layer - Photon Rooms*

To connect users, Photon has the concept of room.  People in the same match or lobby instance will be in the same 
Photon room in order for data to flow between them.  The transport layer is responsible for routing packets
between your users who are most likely behind network firewalls.

<div style="text-align: center; padding: 10pt;"><img src="./Media/session_to_room.png" align="middle" width="650"></div>

Photon rooms have *unique names*.  The name of the room that we will use comes directly from the social layer:
we either use your match session id, if you have one, or your lobby session id, otherwise.

A key feature of the Photon room system is that it keeps track of the oldest member in the room, called
the “master client”, here identified with stars.

<div style="text-align: center; padding: 10pt;"><img src="./Media/photon_join_or_create.png" align="middle" width="650"></div>

Let’s look at Alice, Bob and Charlie entering the Purple room.  Charlie is first to join, so the room is
created for him and he is marked as its **master client**.  Alice and Bob join shortly after and they are
added as **normal clients**.

<div style="text-align: center; padding: 10pt;"><img src="./Media/photon_notification.png" align="middle" width="650"></div>

If Charlie, as the master client, leaves the room, a new master client is selected and all remaining clients
are notified of that change.  This is a key feature for the next networking layer.

## *Game Replication Layer - Unreal Engine Clients and Listen-Server*

<div style="text-align: center; padding: 10pt;"><img src="./Media/ue4_dedicated_server.png" align="middle" width="650"></div>

UE4 has a client-server architecture.  Clients connect to the server and rely on it to enforce the rules of the
application and to replicate the objects that are relevant to each of them.

For applications that require a trusted authority, or powerful hardware, the server is typically running in a
data center as a dedicated server.  In this configuration, each UE4 client runs on its own headset and connects to that dedicated server.

<div style="text-align: center; padding: 10pt;"><img src="./Media/ue4_listen_server.png" align="middle" width="650"></div>

For some applications, like SharedSpaces, we can instead host the server on one of the headsets as a
listen-server.  In that mode, Unreal Engine acts both as a server and as its first connected client.  It
will accept connections from the other players.

<div style="text-align: center; padding: 10pt;"><img src="./Media/ue4_open.png" align="middle" width="650"></div>

So for each room, we need to select one of the users to be the UE4 listen-server.  This decision comes from
the transport layer: the **master client** of the corresponding Photon room will be our host.  In UE4 terms,
the host opens a map with the ‘listen’ option while the clients connect to the master client using an address
that is understood by our Photon Net Driver.


<div style="text-align: center; padding: 10pt;"><img src="./Media/photon_to_ue4_1.png" align="middle" width="650"></div>

When the player hosting leaves, we perform a host migration.  Here we can see that Alice is leaving the purple
room.  Photon picks Bob as the new master client. The remaining members of the room are notified and they
reestablish their UE4 connections.

<div style="text-align: center; padding: 10pt;"><img src="./Media/photon_to_ue4_2.png" align="middle" width="650"></div>

We end up with two Photon rooms, the Purple room is now hosted by Bob, with Charlie and Donna connected to him.
Alice just left the room through the door to her lobby, but since she is the only one there, she becomes both
the master client and host of her group lobby.


# B. <a id="B">SharedSpaces in Action</a>

Let’s have a look at SharedSpaces in action.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/1a.jpg" width="250">
	<img src="./Media/screenshots/1b.jpg" width="250">
</div>

When Alice starts SharedSpaces, she starts alone in her private lobby.  She is the master client and host of
the lobby, as indicated by the star next to her name.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/2a.jpg" width="250">
	<img src="./Media/screenshots/2b_id.jpg" width="250">
	<img src="./Media/screenshots/2c.jpg" width="250">
	<img src="./Media/screenshots/2d.jpg" width="250">
</div>

Alice wants Bob to form a group with her so that they can be together between matches.
To do that, she steps on the invite panel switch and she sends him an invitation from her lobby.
By accepting, SharedSpaces starts on Bob’s headset with a deeplink message that will let him join Alice in game. 
From now on, Bob will have the same lobby session id as Alice and they will share the same lobby.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/3a.jpg" width="250">
	<img src="./Media/screenshots/3b.jpg" width="250">
	<img src="./Media/screenshots/3c.jpg" width="250">
	<img src="./Media/screenshots/3d.jpg" width="250">
</div>

Bob goes through the blue door to start a private match, followed by Alice.
They end up in the same Blue Room and they now have the same match session id that corresponds
to their private room.  Since Bob was there first, he is the one hosting the room and Alice is
connected to him.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/4a_id.jpg" width="250">
	<img src="./Media/screenshots/4b_id.jpg" width="250">
	<img src="./Media/screenshots/4c.jpg" width="250">
	<img src="./Media/screenshots/4d.jpg" width="250">
</div>

Alice decides to invite her friend Charlie to join their match, and he happens to be in his own
lobby when he accepts the invitation.  Charlie has his match session id updated with the private match id,
but on the other hand he still retains his own lobby session id.  He is still part of a different group.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/5a.jpg" width="250">
	<img src="./Media/screenshots/5b.jpg" width="250">
	<img src="./Media/screenshots/5c.jpg" width="250">
</div>

When Bob leaves the blue room, Photon notifies Alice and Charlie that the master client has changed.
A host migration is needed: Alice opens a new UE4 listen-server, since she is the new master client
of the blue room, and Charlie connects to her.

As for Bob, he started hosting his group lobby.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/6a.jpg" width="250">
	<img src="./Media/screenshots/6b.jpg" width="250">
</div>
<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/6c_id.jpg" width="250">
	<img src="./Media/screenshots/6d_id.jpg" width="250">
	<img src="./Media/screenshots/6e_id.jpg" width="250">
</div>

Now when Charlie leaves the blue room, he does not join Bob.
They are not part of the same group since they do have different lobby session ids.
Instead, he goes back to his own separate lobby.  This can be checked by stepping on the roster panel switch
and you will see your different groups explicitly listed.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/7a.jpg" width="250">
	<img src="./Media/screenshots/7b.jpg" width="250">
</div>

In the case of Alice, therefore, going back to lobby means that she will rejoin Bob who is waiting for her.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/8a_id.jpg" width="250">
	<img src="./Media/screenshots/8b_id.jpg" width="250">
	<img src="./Media/screenshots/8c.jpg" width="250">
	<img src="./Media/screenshots/8d.jpg" width="250">
</div>

To have Charlie join their group, Alice or Bob simply need to send him an invitation from their lobby.
Again, by accepting an invitation to lobby, you also accept to join a group.
Charlie’s lobby session id is updated and the three of them will now share the same lobby between matches.


# C. <a id="C">SharedSpaces Implementation</a>

SharedSpaces uses the Oculus Platform and the Photon SDK.  For each of these we have created a
[game instance subsystem](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Subsystems/)
deployed in its own separate plugin.  This makes them easy to reuse in your own projects.

The plugins have their own documentation available here that you can access for details:
- [Oculus Platform](../Plugins/OculusPlatform/Documentation/OculusPlatform.md)
- [Photon Net Driver](../Plugins/PhotonNetDriver/Documentation/PhotonNetDriver.md)

Let's dive into how these are used at the project level.

## <a id="C1">1. SharedSpaces Game Instance</a>

The most important piece of logic at the project level is the SharedSpaces Game Instance blueprint.
In the Unreal Engine, the game instance is a persistent singleton object that exists for the duration
of the process.  It survives map loads, in particular.

You can see below its overall layout.

<div style="text-align: center;  padding: 10pt;">
	<img src="./Media/game_instance_overview.png" width="400">
</div>

We can logically split it into an initialization with our subsystems and the use of those subsystems
to establish communication between the players through a cascade of social, transport and application
networking.

### 1a. Registering Subsystem Callbacks

At the top we have the regions of the blueprint that take care of registering our event handlers with
both major subsystems.

+ Oculus Platform Subsystem
	+ On Login Complete: we need to wait to be fully logged in with Oculus before we identify ourself
		with the Photon system, since we reuse the same identifiers.  Note that those identifiers are
		unique per user and per application, so this is not revealing any personal information.
    + On Launch Intent Changed: this event is generated when the application is started.  We only
		care about the case where the application was launched manually by the user (i.e. "normal" launch)
		so that we can start in the default destination.
    + On Group Launch Intent Received: this event is triggered when the application receives an
		Oculus group presence launch intent.  These are all the cases where the application is asked
		to join a specific destination with lobby and match identifiers, along with a deeplink message.
		Typically it will generated when the user explicitly accepts an invitation to join someone in game.
+ Photon Subsystem
	+ On Master Server Disconnected: there are many situations that will cause a user to disconnect from
		the Photon servers.  A typical one is when the headset is removed and goes dormant: we need to
		immediately notify all users that share that room that this user is gone, especially when he is
		the one hosting the UE4 server for the current shared space.
	+ On Room Joined or Created: event received in response to joining a room, potentially creating it
		first if it doesn't yet exist.  This triggers a UE4 client/server connection optionally with a
		start position if we are rejoining the room.
	+ On Master Client Changed: this is an important event for ensuring host migration.  The Photon
		master client is responsible for hosting the UE4 server, so when he leaves the room, all
		remaining users are notified of that change so that they can reestablish connection: the new
		master client starts a listen-server and the other users connect to him.
	+ On Application Enters Foreground: most often this is caused by the user removing his headset and
		putting it back on a bit later.  Here we rejoin the room that we were in.
	+ On Leave Room: Photon requires you to be in only one room at a time.  We explicitly leave the
		current room when we are about to join a new one.  This event leads us to join this new room.
	+ On Master Server Connected: we mostly care about the case where we fail to reconnect, in which
		case we wait a moment before trying again.

These game instance subsystems benefit from the same lifecycle guarantees as the game instance: they
are singletons that live as long as the application.  The only issue that we need to be careful of
is the timing dependencies between the subsystems and the game instance itself.  There are many ways
to control the ordering of actions and here we have opted for the Oculus Platform Subsystem to notify
the game instance by calling OculusPlatformSubsystemStarted event.  No prior bindings are required
as this is called by name in code.

### 1b. Social Networking: Setting your Group Presence

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/network_launch.png" width="200">
</div>

The rest of the blueprint is concerned with the *Network Launch* sequence that is initiated with a
user's social platform group presence which includes a destination and his lobby and match identifiers.
Let's review the information required for connecting the players together:

+ __Destination Api Name__: you can define a list of destinations for your application on the
	[Oculus application dashboard](https://developer.oculus.com/manage).  These can be deep linked
	for seamless navigation to your application.  In the case of SharedSpaces, we have created one
	destination for the lobby, and one for each of the colored rooms.
	<div style="text-align: center; padding: 10pt;">
		<img src="./Media/dashboard_destinations.png" width="1200">
	</div>

+ __Level Name__: in SharedSpaces, each destination is associated with a distinct level.  This is a design
	choice &mdash; not a requirement &mdash; that helps us illustrate destinations with simple
	spaces of different colors.  Which level to load for a given destination is stored in the
	configuration of that destination on the dashboard.
	<div style="text-align: center; padding: 10pt;">
		<img src="./Media/destination_config.png" width="400">
	</div>
	The <i>deeplink message</i> is an optional application-specific string.  In the case of
    SharedSpaces, we have opted for a simple JSON format to store key-value pairs and every
	destination comes with a "map" key as shown here for the Red Room.

+ __Lobby Id__: the Oculus group presence has a couple of identifiers to be more specific about your
	location.  The first one is the *lobby session id*.  People sharing a lobby session id are
	meant to stick together beyond a single match.  When you open the roster panel (see below),
	people sharing the same lobby id appear grouped.  What you decide to do with that grouping
	is more or less left for your application to decide, but there is a general expectation that
	people from the same lobby will still be together between matches and that when they participate
	to the same match, if applicable and possible, that they will be part of the same team.

	In SharedSpaces, a unique lobby id is given to you when you start the application.  As
	shown earlier in this document, you share your lobby id by inviting others to join you
	in the Lobby destination.  If they accept the invitation to lobby, they join your team.

	When at the Lobby destination, you join the Photon room named after your lobby id.

+ __Match Id__: the other identifier linked to your group presence is the *match session id*.
	You can think of it as the unique identifier of your current destination when you are not
	in your team lobby.

	For the private matches (the Red, Green and Blue rooms), these
	match session ids are uniquely linked to your lobby (e.g. "RedRoom_for_Lobby123").
	For public matches (the Purple room), these get a unique common shared name that is not
	linked to your lobby (e.g. "ThePurpleRoom").  There is currently only one purple room,
	which is a scheme that doesn't scale in real life.  Public rooms should be handled
	using a matchmaking system to distribute players into separate instances for load
	balancing, taking your lobby session id into consideration to try to keep your team
	together.  We have plans on expanding in that direction in a future version of the showcase.

	When at a colored room destination, you join the Photon room named after your match id.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/query_destination.png" width="1000">
</div>

The group presence is set quite differently whether we are joining a lobby or a match.
Similar to the level name, the destination type is also stored in the destination deeplink
on the application dashboard.  We query the destination by name and extract this information
using the *Get Is Lobby* node from the deeplink.  Since this way of storing data in the deeplink
is application specific, that node is implemented in a project blueprint library
(see [SharedSpacesFunctionLibrary.h](../Source/SharedSpaces/Public/SharedSpacesFunctionLibrary.h)).

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/lobby_match_split.png" width="1000">
</div>

When joining a lobby, we set the user's presence to the lobby session id parameter passed to
*Network Launch*.  In the case of an invitation, this is the lobby id of the user who sent it
which means that we join their team and their lobby.  Note that when you join a lobby, your
match session id is always cleared.

There are two ways to join a match: by going through a portal or by accepting an invitation.
In the first case, we derive the match id based on the lobby of origin (e.g. "RedRoom_for_Lobby123").
Since all people present in a specific lobby instance have by definition the same lobby session id,
they are guaranteed to join the same match by going through a given portal.

When accepting an invitation to a match, a user keeps his current *presence lobby id* and uses
the match id passed to *Network Launch* as his presence lobby id.

Finally, in the case of a public match, we override the match id with that room's
public name, as discussed earlier.

### 1c. Transport Layer: Joining or Rejoining a Photon Room

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/room_name.png" width="600">
</div>

The name of the Photon room that we join is trivially based on the user's group presence
set in the previous section: we use the match id if we have one, and the lobby id otherwise.

After ensuring that we have a connection to the Photon Master Server, we also ensure that
we are not currently in a different Photon room.  If we are, we first call the *Leave*
blueprint node and during the callback we call *Photon Join or Create Room* again.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/join_or_create_room.png" width="600">
</div>

When all this is done, we call the *Join or Create Room* blueprint node on our Photon subsystem.
If the room exists, we join it as a normal client, otherwise we create it and become its initial
master client.


<div style="text-align: center; padding: 10pt;">
	<img src="./Media/application_enter_foreground.png" width="600">
</div>

There are a few situations that require us to rejoin the current Photon room: when we lose
connection to the Photon Master Server, which should be rare, and when our application goes back
to foreground, which is much more frequent.  You can find how we handle those events in the
Photon initialization region of the blueprint.

### 1d. Application Replication: Establishing UE4 Client-Server Connections


<div style="text-align: center; padding: 10pt;">
	<img src="./Media/join_or_create_handler.png" width="1200">
</div>

UE4 network connections are mainly established after joining (or rejoining) a Photon room.
The key information that we need is our Photon room master client status, the host address
associated with the current master client of the space that we are connecting to, and an 
optional start location.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/host_migration.png" width="1200">
</div>

When there is a change of master client, we are forced to perform a host migration which is
basically just a question of reestablishing our UE4 network connections.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/ue4_open_level.png" width="1200">
</div>

We create our UE4 connection using the __open__ console command.  That command takes a parameter
that looks like an HTTP URL.  It takes two different forms depending on whether or not
we need to host the level or join an existing server.

+  __Master Client__: open &lt;level&gt; # &lt;startpos&gt; ? listen
+  __Normal Client__:  open &lt;address&gt; # &lt;startpos&gt;

The Photon room master client opens up a level by name and uses the "?listen" parameter to
indicate that we will also accept client connections.  This is known as the __listen-server__ 
mode.  Everybody else simply opens a connection to that server using the address provided.
In the case of SharedSpaces, that address is the application-specific user id of the host
followed by ".oculus".

The start position takes two forms:

+  __Joining__: the destination of origin
+  __Rejoining__: the location and rotation in string form

As we have shown earlier, there are a number of different situations that cause users to
join or rejoin a server, and we attempt to give the user a sensible start position.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/start_positions.png" width="600">
</div>

The way it works is through the placement of a number of player start objects in the level.
These look like console controllers with a flag.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/player_start_tag.png" width="300">
</div>

Each player start has an optional *Player Start Tag*.  In SharedSpaces, we have placed one
default player start without any tag that is used when you start the game the first time.
We have also placed player starts in front of all the portals with a tag that matches the
corresponding destination.  When you travel between spaces, we spawn you near the door that
leads to your space of origin.

In the cases where you rejoin a space, let's say during a host migration, we instead use
your current location and orientation to respawn you.  To do that, we actually create a new
player start for you at that location, and use it during the player spawn process.

## 2. <a id="C2">Roster and Invite Panels</a>

The roster panel is an important part of the Oculus group presence system.  It is a system
panel that appears in 3D in your field of view, on top of any other game content that may be
currently displayed.  You can see who you are currently playing with, and who you have invited
to join you.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/roster_panel.jpg" width="400">
</div>

In SharedSpaces, opening up the roster panel is done by moving your character on top of the
corresponding pressure plate.  The essence of the RosterPanelLaunchTrigger blueprint is to
ask the Oculus Platform Subsystem to launch it.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/launch_roster_panel.png" width="400">
</div>

An important caveat when opening a system panel is that VROS absorbs all controller input
until the panel is closed again.  In UE4 a consequence is that if your player triggers the
panel while moving, he will continue moving even if you release the controller thumbstick.
To prevent that, the blueprint waits for you character to stop moving and then does a final
check that you are still on the pressure plate before opening the roster panel.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/4b_id.jpg" width="400">
</div>

The invite panel can be opened directly from the roster panel (lower left button).  It can
also be opened directly with a separate call to the Oculus Platform Subsystem.

## 3. <a id="C3">Portals</a>

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/purple_portal.png" width="400">
</div>

The _Portal_ is a simple blueprint that issues a _Network Launch_ on the SharedSpaces Game
Instance for the player who enters its collision volume.  After placing it in the level,
either as is with it's built-in geometry made visible or right next to some existing object
that represents a door, you must set its __destination__ parameter.  This is literally the name
of a destination as you have defined them on the dashboard.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/portal_network_launch.png" width="1200">
</div>

When the user enters the portal, we find his current lobby id and we query the name of the
level from the destination's record.  We perform a network launch with those values and with
the match id empty in all cases, even when we travel to a match.  This is allowed since match
ids are derived from lobby session ids when we go through portals, as explained earlier. 

## 4. <a id="C4">SharedSpaces Character</a>

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/shared_spaces_character.png" width="800">
</div>

The SharedSpaces Character is the classic UE4 mannequin with a few modifications.

### 4a. Character Attributes

In SharedSpaces, users are distinguished by their name, color, master client status and
current destination.  You can set a new random color on your character by pressing the trigger.  You can even
hide your character name (which is by default your Oculus name) by pressing the thumbstick
down and choose between "Alice", "Bob" and "Charlie".  This is a somewhat hidden feature
that we have added to create our screenshots and videos.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/local_character_on_game_instance.png">
</div>

Most objects are lost between level loads, including the player character.  For that reason,
we have opted for a trivial persistence mechanism: we simply copy these values to the corresponding
variables on the SharedSpaces Game Instance.  If you scroll back to the implementation diagram
for __UE4 Open Level__, you will see where we use the current destination, for example.

Now let's talk about the replication of a user's name, color and master client status.  These
values need to be propagated to all players in order for them to see who's who, hopefully with a 
distinctive color and with a star above your head when you are the current master client.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/body_color_rep.png">
</div>

Let's take the character color as an example.  We have a linear color variable on the character
used for replication called __BodyColor__.  It's replication is set to _RepNotify_.  This means
that when the value is set on the server, it will be replicated down to all clients and that the
corresponding notification function (in this case __OnRep_BodyColor__) will be called.


<div style="text-align: center; padding: 10pt;">
	<img src="./Media/set_body_color.png" width="1200">
</div>

When a character calls __SetBodyColor__ it does not directly set the __BodyColor__ locally.
Instead it sends a message to the server to set it there in order for the value to be replicated
down to everybody, including itself.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/notify_server_of_body_color_cfg.png">
	<img src="./Media/notify_server_of_body_color.png">
</div>

__NotifyServerOfBodyColor__ is an event meant to run on the server.  It is set as reliable which
means that it will eventually get there.  The implementation of that event is simple, it simply
sets the value of __BodyColor__ on the server and replicates it to all with notification.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/on_rep_body_color.png" width="1200">
</div>

When a client receives the replicated value, __OnRepBodyColor__ is called, and this is what
actually changes the material parameter on the character.  This is done for all clients,
including the one that owns this character.

### 4b. Camera Behavior

The [camera components](https://docs.unrealengine.com/4.27/en-US/Basics/Components/Camera/)
are highly configurable, but we wanted to experiment with a different behavior for this
showcase that required some blueprint coding: the camera location would not change while
the character moves as this is not comfortable for some people.  When the character stops,
and after some delay, the camera would reset behind the character with an orientation
based on the character rotation.  At all times, of course, the camera would rotate in sync
with the headset when the user is looking in different directions.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/character_params.png">
</div>

To control this, we have two parameters on the SharedSpaces Character under
*Camera Logic*: the time that we must wait after the character stops moving before we reset
the camera behind him, and a minimum travel distance required between resets.  Both
parameters are intended to minimize the number of camera resets for comfort.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/character_is_stationary.png">
</div>

Every tick, on the local character, we perform a movement check.  This gives us whether or
not the character has moved (*IsStationary*) and the last time and location with movement
(*LastTimeWithMovement* and *LastLocationWithMovement*).

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/camera_behavior_1.png">
</div>

After checking that we are using a VR headset, there are two gates that we need to go through
before we allow the camera to reset.  The first one checks that the character is stationary.
The second one checks that we have moved enough since our last camera reset and waited enough
since we stopped moving.  

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/manual_reset.png">
</div>

These two gates will automatically go through when a manual reset is requested by the user.
In the sample, this is done by pressing the __A__ or __X__ buttons.


<div style="text-align: center; padding: 10pt;">
	<img src="./Media/camera_behavior_2.png">
</div>

Finally, we play with the *camera lag speed* to indirectly freeze and reset the camera location.
The *camera boom* (a Spring Arm Component) can be configured to follow the player at some distance
and to slide smoothly to the correct location.   In our case, we go to the extremes: very close to
zero speed when we want the camera to stay in place, and a high speed when we want to reset it
instantly.

## 5. <a id="C5">In-Game Log</a>

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/screenshots/log.jpg"  width="800">
</div>

The grip button toggles the in-game log panel.  For this technical showcase, most of the important
events happen under the hood.  This log panel is hooked to the persistent log that we have added
to the Oculus Platform Subsystem.   This ensures that the log persists between level loads.

# D. <a id="D">Oculus Application Configuration</a>

To build and run your own copy of SharedSpaces, you will need to create an application for it
on the [Oculus developer dashboard](https://developer.oculus.com/).

## 1. <a id="D1">Application Identifier</a>

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/dashboard/dashboard_app.png"  width="800">
</div>

You Oculus application identfier must be placed in _SharedSpaces/Config/DefaultEngine.ini_ like so.

	[OnlineSubsystemOculus]
	bEnabled=false
	MobileAppId=123xxxxxxxxxx321

Note that SharedSpaces does not use the Oculus Online Subsystem (OSS), but the identifer is still needed and is
found in that configuration section.

The identifier (__App ID__) can be found in the _API_ section.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/dashboard/dashboard_api.png"  width="800">
</div>

## 2. <a id="D2">Destinations</a>

You need to recreate the SharedSpaces destinations in your own application.  Destinations can be found
under __Platform Services__.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/dashboard/dashboard_platform_services.png"  width="800">
</div>

You need to recreate the SharedSpaces destinations in your own application.  Destinations can be found
under __Platform Services__.

<div style="text-align: center; padding: 10pt;">
	<img src="./Media/dashboard/dashboard_destinations.png"  width="800">
</div>

SharedSpaces has four destinations: a Lobby, three private rooms (the red, green and blue rooms) and one
public room (the purple room).  Here are the settings for each of them.

| API Name | Deeplink Message | Display Name | Description |
| :--- | :--- | :--- | :--- |
| [Lobby](./Media/dashboard/dashboard_destination_lobby.png) | {"is_lobby":"true","map":"Lobby"} | Lobby | The Lobby |
| [RedRoom](./Media/dashboard/dashboard_destination_redroom.png) | {"map":"RedRoom"} | Red Room | The Red Room |
| [GreenRoom](./Media/dashboard/dashboard_destination_greenroom.png) | {"map":"GreenRoom"} | Green Room | The Green Room |
| [BlueRoom](./Media/dashboard/dashboard_destination_blueroom.png) | {"map":"BlueRoom"} | Blue Room | The Blue Room |
| [PurpleRoom](./Media/dashboard/dashboard_destination_purpleroom.png) | {"map":"PurpleRoom","public_room_name":"ThePurpleRoom"} | Purple Room | The Purple room |

In addition to these settings, you need to set __Deeplink Type__ to __Enabled__ and add an image for your
destination.  In the case of SharedSpaces, the destination is __Audience__ is set to __Everyone__.

## 3. <a id="D3">Data Use Checkup</a>

You will need to request access to platform data needed by SharedSpaces. Under __Data Use Checkup__, add the following items and submit for certification.

+  User ID
+  User Profile
+  Deep Linking
+  Friends
+  Invites

## 4. <a id="D4">Photon Configuration</a>

You will also need to create a Photon AppID and configure the app to use it. Find instructions for this [here](../Plugins/PhotonNetDriver/Documentation/PhotonNetDriver.md#photon-appid).

<div style="text-align: right; padding: 10pt;">&#x25A0;</div>
