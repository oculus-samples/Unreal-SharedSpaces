# Shared Spaces

<iframe width="560" height="315" src="https://www.youtube.com/embed/td8dQxZY9OI" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


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

## Engine

To build this project you must use the Oculus fork of Unreal 4.27 found [here](https://github.com/Oculus-VR/UnrealEngine).<br>
Access to the Oculus fork is dependent on access to Epic's github as described [here](https://www.unrealengine.com/ue4-on-github).

## Documentation

To [visualize](./Documentation/media/markdown_extension.png) markdown files in Visual Studio, we recommend installing a
[markdown extension](https://marketplace.visualstudio.com/search?term=markdown&target=VS&category=Tools&vsVersion=&subCategory=All&sortBy=Relevance).


1. [SharedSpaces project](./Documentation/SharedSpaces.md "SharedSpaces documentation")
2. [OVRPlatform plugin](./Plugins/OVRPlatform/Documentation/OVRPlatform.md)
3. [Photon plugin](./Plugins/PhotonNetDriver/Documentation/PhotonNetDriver.md)

## License

SharedSpaces is under the license found [here](LICENSE).

<div style="text-align: right; padding: 10pt;">&#x25A0;</div>
