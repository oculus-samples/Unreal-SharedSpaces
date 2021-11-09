# Photon NetDriver

Unreal engine provides the NetDriver interface so you can build a generic transport layer for network data. This means you don’t need to worry about what data to send, or how to handle each type of data. You are simply providing a general pipe for data, and the engine will take care of sending and receiving necessary replication data.

For SharedSpaces we built a Photon NetDriver. It handles the following:
- Connect to the Photon master server.
- Create a room if it doesn’t exist. Otherwise, join the existing room.
- Establish a connection between the master client and each peer.
- Send and receive packets.

The NetDriver is so general it only utilizes two event types.
- Connect - Establishes a connection to a peer in the room.
- Packet - Send data to specified peer.

## Photon AppID

To get the sample working, you will need to configure the NetDriver with your own Photon account. Their base plan is free.
- Visit [photonengine.com](https://www.photonengine.com/en-US/Photon) and [create an account](https://doc.photonengine.com/en-us/realtime/current/getting-started/obtain-your-app-id).
- From your Photon dashboard, click “Create A New App”
- Fill out the form making sure to set type to “Photon Realtime”. Then click Create.
<div style="text-align: center; padding: 10pt;">
	<img src="./Media/photondoc1.png"  width="800">
</div>

- Your new app will now show on your Photon dashboard. Click the App ID to reveal the full string and copy the value.
- Paste your AppID in PhotonLBClient.h
<div style="text-align: center; padding: 10pt;">
	<img src="./Media/photondoc2.png"  width="800">
</div>

The Photon NetDriver should function now. You can check the dashboard in your Photon account to verify there is network traffic.

## Portability

The NetDriver plugin and Photon Realtime module can easily be transferred to another UE4 project in a few easy steps.

- Copy the SharedSpaces/Plugins/PhotonNetDriver folder to \<Project>/Plugins/
- Make sure the plugin is enabled in UE4 Settings > Plugins.
<div style="text-align: center; padding: 10pt;">
	<img src="./Media/photondoc3.png"  width="800">
</div>

- Copy the SharedSpaces/Source/ThirdParty/Photon folder to somewhere in \<Project>/Source/. The Photon.build.cs file will be detected by the UnrealBuildTool.
- Open Config\DefaultEngine.ini and set the following:

		[/Script/Engine.GameEngine]
		+NetDriverDefinitions=(DefName="GameNetDriver",DriverClassName="/Script/PhotonNetDriver.PhotonIpNetDriver", DriverClassNameFallback="/Script/OnlineSubsystemUtils.IpNetDriver")

		[/Script/Engine.NetDriver]
		AllowPeerConnections=False
		AllowPeerVoice=False
		ConnectionTimeout=60.0
		InitialConnectTimeout=60.0
		KeepAliveTime=0.2
		MaxClientRate=15000
		MaxInternetClientRate=10000
		RelevantTimeout=5.0
		SpawnPrioritySeconds=1.0
		ServerTravelPause=4.0
		NetServerMaxTickRate=30
		MaxPortCountToTry=512

- Copy the game instance blueprint in SharedSpaces/Content/SharedSpaces/Blueprints/SharedSpacesGameInstance.uasset. It contains all the logic around connecting to the master server, creating and joining rooms, host migration, leaving rooms, and rejoining rooms. Additionally it handles Oculus Platform login and Group Presence.


<div style="text-align: right; padding: 10pt;">&#x25A0;</div>
