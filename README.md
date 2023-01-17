# Shared Spaces

[![Shared Spaces video](http://img.youtube.com/vi/td8dQxZY9OI/maxresdefault.jpg)](http://www.youtube.com/watch?v=td8dQxZY9OI "Shared Spaces | Oculus Multiplayer Sample")

SharedSpaces was built by the VR Developer Tools team to demonstrate how you can quickly get people together in VR using the Oculus Social Platform APIs. This version was built for the Unreal Engine using the Photon SDK as the transport layer. Check out this [YouTube video](http://www.youtube.com/watch?v=td8dQxZY9OI "Shared Spaces | Oculus Multiplayer Sample") showing the demo.

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

SharedSpaces is available on the [Quest AppLab](https://www.oculus.com/experiences/quest/4540942155998634).

## Documentation

To [visualize](./Documentation/Media/markdown_extension.png) markdown files in Visual Studio, we recommend installing a
[markdown extension](https://marketplace.visualstudio.com/search?term=markdown&target=VS&category=Tools&vsVersion=&subCategory=All&sortBy=Relevance).


1. [SharedSpaces project](./Documentation/SharedSpaces.md "SharedSpaces documentation")
2. [OVRPlatform plugin](./Plugins/OVRPlatform/Documentation/OVRPlatform.md)
3. [Photon plugin](./Plugins/PhotonNetDriver/Documentation/PhotonNetDriver.md)

Details on how to setup the project can be found under [Oculus Application Configuration](./Documentation/SharedSpaces.md#d-oculus-application-configuration).

## Build Instructions

1. Git LFS is required to access the assets of the project, such as blueprints and materials.  Make sure that you have Git LFS installed using the following command.
```sh
git lfs install
```
2. Clone this repo using the "Code" button above, or this command:
```sh
git clone https://github.com/oculus-samples/Unreal-SharedSpaces.git
```
3. [Link your Github and Epic accounts](https://www.unrealengine.com/ue4-on-github) to gain access to the Oculus fork.
4. Clone the [Oculus fork of UE4.27](https://github.com/Oculus-VR/UnrealEngine/tree/4.27). SharedSpaces depends on this version of the engine.<br/>
5. You need [Visual Studio](https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/DevelopmentSetup/VisualStudioSetup/) installed to build the engine and the project plugins.
6. Open a command prompt, change directory to your Unreal root (see step 3), then run this command:
```sh
.\GenerateProjectFiles.bat -Game SharedSpaces -Engine <full path to Unreal-SharedSpaces directory>\SharedSpaces.uproject
```
7. Open the `SharedSpaces.sln` file that has been generated in the `Unreal-SharedSpaces` directory.
8. Set `SharedSpaces` as the start-up project and `Development Editor` as the configuration.
9. Hit `F5` to build and debug the project (and the engine).

## License

Unreal-SharedSpaces is under the license found [here](LICENSE).<br/>
The Oculus License applies to the SDK and supporting material.<br/>
The MIT license applies to only certain, clearly marked documents. If an individual file does not indicate which license it is subject to, then the Oculus License applies.<br/>
We distribute the Photon SDK under agreement with Photon.  You will find their license [here](./Source/ThirdParty/Photon/license.txt).

<div style="text-align: right; padding: 10pt;">&#x25A0;</div>
