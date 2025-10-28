# Shared Spaces

[![Shared Spaces video](http://img.youtube.com/vi/td8dQxZY9OI/maxresdefault.jpg)](http://www.youtube.com/watch?v=td8dQxZY9OI "Shared Spaces | Oculus Multiplayer Sample")

# Project Overview

The VR Developer Tools team built SharedSpaces to show how to quickly connect people in VR using the Oculus Social Platform APIs. This version uses Unreal Engine with the Unreal EOS plugin as the transport layer. Watch this [YouTube video](http://www.youtube.com/watch?v=td8dQxZY9OI "Shared Spaces | Oculus Multiplayer Sample") to see the demo.

**NOTE:** The EOS version of Shared Spaces works only with the Meta Quest fork of Unreal Engine. See <a href="#build-instructions">Build Instructions</a> for details.

You can find SharedSpaces on the [Meta Horizon Store](https://www.meta.com/experiences/oculus-sharedspaces-for-unreal/4540942155998634/).

## Documentation

To view markdown files in Visual Studio, install a [markdown extension](https://marketplace.visualstudio.com/search?term=markdown&target=VS&category=Tools&vsVersion=&subCategory=All&sortBy=Relevance).

1. [SharedSpaces project](./Documentation/SharedSpaces.md "SharedSpaces documentation")
2. [OVRPlatform plugin](./Documentation/SharedSpaces.md#D)
3. [EOS configuration](./Documentation/EOSConfiguration.md)

Find setup details under [Oculus Application Configuration](./Documentation/SharedSpaces.md#d-oculus-application-configuration).

## Build Instructions

1. Install Git LFS to access project assets like blueprints and materials:
```sh
git lfs install
```
2. Clone this repo using the "Code" button or this command:
```sh
git clone https://github.com/oculus-samples/Unreal-SharedSpaces.git
```
3. Get access to the Unreal source code [here](https://www.unrealengine.com/en-US/ue-on-github).
4. Clone the `oculus-5.5` branch of the Oculus fork [here](https://github.com/Oculus-VR/UnrealEngine/tree/oculus-5.5).
5. Install [Visual Studio](https://dev.epicgames.com/documentation/en-us/unreal-engine/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine?application_version=5.4) to build the engine and plugins.
6. Open a command prompt, navigate to your Unreal root (step 3), and run:
```sh
.\GenerateProjectFiles.bat -Game SharedSpaces -Engine <full path to Unreal-SharedSpaces directory>\SharedSpaces.uproject
```
7. Open the generated `SharedSpaces.sln` file in the `Unreal-SharedSpaces` directory.
8. Set `SharedSpaces` as the start-up project and `Development Editor` as the configuration.
9. Press `F5` to build and debug the project and engine.

## License

Unreal-SharedSpaces is under the license found [here](LICENSE).<br/>
The Oculus License applies to the SDK and supporting material.<br/>
The MIT license applies to only certain, clearly marked documents. If an individual file does not indicate which license it is subject to, then the Oculus License applies.<br/>

## Contribution

See the [CONTRIBUTING](./CONTRIBUTING.md) file for information on how to contribute.

<div style="text-align: right; padding: 10pt;">&#x25A0;</div>
