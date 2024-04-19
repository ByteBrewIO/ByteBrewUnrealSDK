// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class ByteBrewSDK : ModuleRules
{
    public ByteBrewSDK(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
			}
        );


        PrivateIncludePaths.AddRange(
            new string[] {
				// ... add other private include paths required here ...
			}
        );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine"
				// ... add other public dependencies that you statically link with here ...
			}
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Slate",
                "SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
        );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
        );


        PrivateIncludePathModuleNames.AddRange(
              new string[] {
                "Settings",
                "Launch",
              }
        );


        // Read this related thread: https://forums.unrealengine.com/development-discussion/android-development/76381-how-do-i-include-native-libraries-from-a-plugin

        if (Target.Platform == UnrealTargetPlatform.Android)
        {

            string aarDir = Path.Combine(ModuleDirectory, "Source/../../ThirdParty/Android");
            string pluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);

#if UE_5_0_OR_LATER
            PublicSystemLibraryPaths.Add(aarDir);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(pluginPath, "ByteBrewSDK_UPL.xml"));
#else
            PublicLibraryPaths.Add(aarDir);
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(pluginPath, "ByteBrewSDK_UPL.xml")));
#endif

        }
        else if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            
            string iosPath = Path.Combine(ModuleDirectory, "Source/../../ThirdParty/IOS");
            PublicAdditionalFrameworks.Add(new Framework("ByteBrewNativeiOSPlugin", Path.Combine(iosPath, "ByteBrewNativeiOSPlugin.embeddedframework.zip")));

        }


    }

}
