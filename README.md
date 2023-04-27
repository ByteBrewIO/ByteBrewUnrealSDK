# ByteBrewUnrealSDK
ByteBrew Unreal Engine SDK

## Getting Started

1. Download the repository as a zip.
2. Extract the ByteBrewSDK folder and copy it to your project's Plugins folder.
3. Restart your Unreal project to rebuild the plugin.
4. Go to Edit > Plugins and make sure Other > ByteBrewSDK is enabled.

<details>
  <summary>Extra steps for enabling push notifications on iOS</summary>
  ### If your Unreal Engine is built from the Github source:
  1. Open project settings (Edit > Project Settings)
  2. Under Platforms > iOS, under the "Online" section, enable "Enable Remote Notifications Support".
  ### If your Unreal Engine is NOT built from the Github source:
  1. Close the Unreal editor if it's open.
  2. Open your DefaultEngine.ini config file located at project_root/Config/DefaultEngine.ini
  3. Find the section with the heading 
  ```[/Script/IOSRuntimeSettings.IOSRuntimeSettings]```
  4. Add this line:
  ```bEnableRemoteNotificationsSupport=True```
</details>

## How to Use

You should now be able to access the ByteBrew category when creating blueprints.

You can Initialize ByteBrew like so:

<img width="971" alt="image" src="https://user-images.githubusercontent.com/29225093/234193268-bedd085c-cc02-47b4-817c-578696fa4041.png">

Here's a list of available blueprint functions and implementation examples:

<img width="397" alt="image" src="https://user-images.githubusercontent.com/29225093/234193535-e7f016d7-cf1e-4cda-b7c2-d843029dcf66.png">
<img width="432" alt="image" src="https://user-images.githubusercontent.com/29225093/234193575-22bfa572-0ce7-4118-9a84-7757e1c4383e.png">
<img width="536" alt="image" src="https://user-images.githubusercontent.com/29225093/234193852-0887fd2f-a2ef-4d69-b367-d7a8cc6e4f74.png">
<img width="425" alt="image" src="https://user-images.githubusercontent.com/29225093/234193897-2c51bf23-c865-49ad-8fa6-7c07c33fcc78.png">
<img width="502" alt="image" src="https://user-images.githubusercontent.com/29225093/234193926-34d6692d-ef37-4285-a142-0a25bafedbb4.png">
<img width="506" alt="image" src="https://user-images.githubusercontent.com/29225093/234193971-872bb82b-009e-46e6-8434-3c32f704e5b6.png">
<img width="488" alt="image" src="https://user-images.githubusercontent.com/29225093/234194037-797226d7-4973-45b3-b74f-c35a7ffc0a83.png">
<img width="596" alt="image" src="https://user-images.githubusercontent.com/29225093/234194076-c46c8f5f-c5c4-42bf-b3e3-04305ae75d05.png">
<img width="497" alt="image" src="https://user-images.githubusercontent.com/29225093/234194152-5f846e69-045e-49fb-883b-70abfd2e14c4.png">
<img width="455" alt="image" src="https://user-images.githubusercontent.com/29225093/234194196-c2b3cc14-37f1-4e6f-b63b-c09308bb4950.png">
<img width="403" alt="image" src="https://user-images.githubusercontent.com/29225093/234194218-0b921c69-0a66-41e8-a2ab-0d433effe60f.png">
<img width="397" alt="image" src="https://user-images.githubusercontent.com/29225093/234194236-7ab82db0-ff9d-45dc-9470-8dc07e0279c0.png">

