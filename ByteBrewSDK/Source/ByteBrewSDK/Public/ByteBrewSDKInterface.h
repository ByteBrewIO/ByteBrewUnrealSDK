#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#elif PLATFORM_IOS
#import <ByteBrewNativeiOSPlugin/ByteBrewNativeiOSPlugin.h>
#endif
#include "ByteBrewSDKInterface.generated.h"

UENUM(BlueprintType)
enum class EByteBrewProgressionType : uint8
{
    Started UMETA(DisplayName = "Started"),
    Completed UMETA(DisplayName = "Completed"),
    Failed UMETA(DisplayName = "Failed")
};

UENUM(BlueprintType)
enum class EByteBrewAdType : uint8
{
    Interstitial UMETA(DisplayName = "Interstitial"),
    Reward UMETA(DisplayName = "Reward"),
    Banner UMETA(DisplayName = "Banner")
};

UCLASS()
class BYTEBREWSDK_API UByteBrewSDKInterface : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void InitializeByteBrew(FString gameKey, FString secretKey, FString engineVersion, FString buildVersion);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static bool IsByteBrewInitialized();

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void StartPushNotifications();

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void NewCustomEvent(FString eventName);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void NewCustomEventWithStringValue(FString eventName, FString value);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void NewCustomEventWithFloatValue(FString eventName, float value);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void SetCustomData(FString key, FString value);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void SetCustomDataFloat(FString key, float value);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void SetCustomDataInt(FString key, int32 value);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void SetCustomDataBool(FString key, bool value);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void NewProgressionEvent(EByteBrewProgressionType progressionStatus, FString environment, FString stage);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void NewProgressionEventWithStringValue(EByteBrewProgressionType progressionStatus, FString environment, FString stage, FString value);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void NewProgressionEventWithFloatValue(EByteBrewProgressionType progressionStatus, FString environment, FString stage, float value);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void TrackAdEvent(EByteBrewAdType adType, FString adLocation);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void TrackAdEventWithAdID(EByteBrewAdType adType, FString adLocation, FString adID);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void TrackAdEventWithAdIDAndProvider(EByteBrewAdType adType, FString adLocation, FString adID, FString adProvider);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void TrackAdEventWithRevenue(EByteBrewAdType adType, FString adProvider, FString adUnitName, float revenue);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void TrackAdEventWithAdLocationRevenue(EByteBrewAdType adType, FString adProvider, FString adUnitName, FString adLocation, float revenue);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void TrackInAppPurchaseEvent(FString store, FString currency, float amount, FString itemID, FString category);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void TrackGoogleInAppPurchaseEvent(FString store, FString currency, float amount, FString itemID, FString category, FString receipt, FString signature);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void TrackAppleInAppPurchaseEvent(FString store, FString currency, float amount, FString itemID, FString category, FString receipt);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static bool HasRemoteConfigsBeenSet();

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static FString RetrieveRemoteConfigValue(FString key, FString defaultValue);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void RestartTracking();

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void StopTracking();

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static FString GetUserID();

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void ValidateGoogleInAppPurchaseEvent(FString store, FString currency, float amount, FString itemID, FString category, FString receipt, FString signature);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void ValidateAppleInAppPurchaseEvent(FString store, FString currency, float amount, FString itemID, FString category, FString receipt);

    UFUNCTION(BlueprintCallable, Category = "ByteBrew")
    static void LoadRemoteConfigs();

private:
    static FString GetProgressionTypeAsString(EByteBrewProgressionType progressionType);
    static FString GetAdTypeAsString(EByteBrewAdType adType);
};
