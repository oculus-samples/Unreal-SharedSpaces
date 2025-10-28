# Shared Spaces changelog

## 03 August 2025 Update

We updated the MetaXRPlatform plugin to SDK v77.

## 10 July 2025 Update

We fixed the hostmigration on branch `eos`.
We removed the deprecated `OculusAudio` plugin from the project.

## 13 February 2025 Update

We updated the project to UE5.5.

We updated the MetaXRPlatform plugin to SDK v72.

We fixed a crash when playing in editor with "Number of Players" > 1.

## 23 August 2024 Update - Shared Spaces EOS!

We have created a new branch `eos-5.x` which contains a [new version of Shared Spaces using Epic Online Services](https://github.com/oculus-samples/Unreal-SharedSpaces/tree/eos-5.x) as its network layer (instead of Photon). This version also includes updates to support the latest [Meta fork of Unreal Engine](https://github.com/Oculus-VR/UnrealEngine)  `5.4.3-v68`.

## 06 December 2023 Update

We updated the project to UE5.3.

We updated the MetaXRPlatform plugin to SDK v59.

## 30 August 2023 Update

We updated the settings for UE5.2.

We updated the OVRPlatform plugin to use the new MetaXRPlatform plugin found [here](https://developer.oculus.com/downloads/package/unreal-5-platform-sdk-plugin/). We updated to SDK v56.

We have added the the ability to handle [User Reporting](https://developer.oculus.com/resources/reporting-plugin/). This allow users to notify the developer about conduct within the application that does not adhere to the [Code of Conduct](https://developer.oculus.com/resources/vrc-content-3/) in Virtual Experiences.

## 08 March 2023 Update

We have added a demo for the [App to App Travel](https://developer.oculus.com/documentation/unreal/ps-app-to-app-travel/) platform feature.

For that purpose we added a door that will launch another of our showcase [_Ultimate Glove Ball_](https://github.com/oculus-samples/Unity-UltimateGloveBall) joining directly in an arena of the same session, making it so that every user in the same lobby can join the same arena.
Implementation details can be found [here](./Documentation/SharedSpaces.md#6-external-application-portal).

## 20 October 2022 Update

We have added a demo of the new Blocked Users flows presented at
[Connect 2022](https://metaconnect.com/en-us/program/fbc023/).

For that purpose, pulling the controller trigger no longer changes your robot color,
but instead starts the block/unblock flow with the character in front of you (if any).
You can still change your robot color by stepping on the paint shop plate in the lobby.

## 18 May 2022 Update

For the original SharedSpaces for UE4, we created a new plugin, *Plugin/OculusPlatform*, to expose the
new OVR Platform APIs that we needed, in particular the group presence ones.  Instead of using both
the old Oculus OSS and the new plugin, we just moved everything that we needed into the new plugin.

In this update, the plugin has been renamed *Plugin/OVRPlatform* and now covers all OVR Platform APIs.
A key feature of this plugin is that it is codegened, which means that it will be kept in sync with the
OVR Platform.  That was not possible with the older Oculus OSS, has it required manual adaptation of
UE4 OSS to Oculus VR Platform services.  We are planning on releasing it as an engine level plugin in
the near future.
