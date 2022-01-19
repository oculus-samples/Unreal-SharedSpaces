# Shared Spaces

[![Shared Spaces video](http://img.youtube.com/vi/td8dQxZY9OI/maxresdefault.jpg)](http://www.youtube.com/watch?v=td8dQxZY9OI "Shared Spaces | Oculus Multiplayer Sample")

SharedSpaces was built by the VR Developer Tools team to demonstrate how you can quickly get people together in VR using the Oculus Social Platform APIs. This version was built for the Unreal Engine using the Photon SDK as the transport layer. Check out this [YouTube video](http://www.youtube.com/watch?v=td8dQxZY9OI "Shared Spaces | Oculus Multiplayer Sample") showing the demo.

## Documentation

To [visualize](./Documentation/Media/markdown_extension.png) markdown files in Visual Studio, we recommend installing a
[markdown extension](https://marketplace.visualstudio.com/search?term=markdown&target=VS&category=Tools&vsVersion=&subCategory=All&sortBy=Relevance).


1. [SharedSpaces project](./Documentation/SharedSpaces.md "SharedSpaces documentation")
2. [Oculus Platform plugin](./Plugins/OculusPlatform/Documentation/OculusPlatform.md)
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
3. This project requires the Oculus fork of the UE4.27 game engine that you can find [here](https://github.com/Oculus-VR/UnrealEngine/tree/4.27).<br/>*NOTE:* access to the Oculus fork requires [access to Epic's GitHub](https://www.unrealengine.com/ue4-on-github).
4. You need [Visual Studio](https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/DevelopmentSetup/VisualStudioSetup/) installed to build the engine and the project plugins.
5. Open a command prompt, change directory to your Unreal root (see step 3), then run this command:
```sh
.\GenerateProjectFiles.bat -Game SharedSpaces -Engine <full path to Unreal-SharedSpaces directory>\SharedSpaces.uproject
```
6. Open the `SharedSpaces.sln` file that has been generated in the `Unreal-SharedSpaces` directory.
7. Set `SharedSpaces` as the start-up project and `Development Editor` as the configuration.
8. Hit `F5` to build and debug the project (and the engine).

## License

Unreal-SharedSpaces is under the license found [here](LICENSE).<br/>
We distribute the Photon SDK under agreement with Photon.  You will find their license [here](./Source/ThirdParty/Photon/license.txt).

<div style="text-align: right; padding: 10pt;">&#x25A0;</div>
