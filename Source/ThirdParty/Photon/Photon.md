# Photon Module
Files in this module are based on Photon SDK v4-1-16-5

## Updating the module to a new Photon SDK
[Download Photon-Windows-Sdk](https://www.photonengine.com/en-US/sdks#windows-sdkrealtimewindows)
[Download Photon-Windows-Sdk](https://dashboard.photonengine.com/en-US/download/photon-windows-sdk_v4-1-16-5.zip)

```bat
copy Common-cpp\inc\*.h Include\Common-cpp\inc
copy Common-cpp\lib\*_md_Win32.lib Lib\Windows\Win32
copy Common-cpp\lib\*_md_x64.lib Lib\Windows\x64
copy LoadBalancing-cpp\inc\*.h Include\LoadBalancing-cpp\inc
copy LoadBalancing-cpp\lib\*_md_Win32.lib Lib\Windows\Win32
copy LoadBalancing-cpp\lib\*_md_x64.lib Lib\Windows\x64
copy Photon-cpp\inc\*.h Include\Photon-cpp\inc
copy Photon-cpp\lib\*_md_Win32.lib Lib\Windows\Win32
copy Photon-cpp\lib\*_md_x64.lib Lib\Windows\x64
```

[Download Photon-AndroidNDK-Sdk](https://www.photonengine.com/en-US/sdks#realtime-android-sdkrealtimeandroid)
[Download Photon-AndroidNDK-Sdk](https://dashboard.photonengine.com/en-US/download/photon-androidndk-sdk_v4-1-16-5.zip)

```bat
copy Common-cpp\lib\common-cpp-prebuilt\*armeabi-v7a_no-rtti.a Lib\Android\armeabi-v7a
copy Common-cpp\lib\common-cpp-prebuilt\*arm64-v8a_no-rtti.a Lib\Android\arm64-v8a
copy LoadBalancing-cpp\lib\loadbalancing-cpp-prebuilt\*armeabi-v7a_no-rtti.a Lib\Android\armeabi-v7a
copy LoadBalancing-cpp\lib\loadbalancing-cpp-prebuilt\*arm64-v8a_no-rtti.a Lib\Android\arm64-v8a
copy Photon-cpp\lib\photon-cpp-prebuilt\*armeabi-v7a_no-rtti.a Lib\Android\armeabi-v7a
copy Photon-cpp\lib\photon-cpp-prebuilt\*arm64-v8a_no-rtti.a Lib\Android\arm64-v8a
```

## Using the Photon module
Add the Photon module as a dependency in your project's `.build.cs` file:
```cs
PublicDependencyModuleNames.Add("Photon");
```
Include the Photon header from your code:
```cpp
#include "Photon.h"
```
That's it!


## Notes
Instructions based on [this original document](https://doc.photonengine.com/en/realtime/current/getting-started/unreal-engine)
