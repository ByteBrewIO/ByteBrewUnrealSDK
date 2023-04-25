#include "ByteBrewSDKInterface.h"
#include "Misc/OutputDeviceDebug.h"

void UByteBrewSDKInterface::InitializeByteBrew(FString gameKey, FString secretKey, FString engineVersion, FString buildVersion)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jstring GameKey = Env->NewStringUTF(TCHAR_TO_UTF8(*gameKey));
        jstring SecretKey = Env->NewStringUTF(TCHAR_TO_UTF8(*secretKey));
        jstring EngineVersion = Env->NewStringUTF(TCHAR_TO_UTF8(*engineVersion));
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "InitializeByteBrew",
                                                          "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/content/Context;)V", false);
        jobject Activity = FJavaWrapper::GameActivityThis;
        Env->CallStaticVoidMethod(Class, Method, GameKey, SecretKey, EngineVersion, Activity);
        Env->DeleteLocalRef(GameKey);
        Env->DeleteLocalRef(SecretKey);
        Env->DeleteLocalRef(EngineVersion);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin InitializeWithSettings:gameKey.GetNSString()
                                          SecretKey:secretKey.GetNSString()
                                      EngineVersion:engineVersion.GetNSString()
                                       BuildVersion:buildVersion.GetNSString()];
#endif
}

bool UByteBrewSDKInterface::IsByteBrewInitialized()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "IsByteBrewInitialized", "()Z", false);
        bool Result = Env->CallStaticBooleanMethod(Class, Method);
        Env->DeleteLocalRef(Class);
        return Result;
    }
#elif PLATFORM_IOS
    return [ByteBrewNativeiOSPlugin IsByteBrewInitialized];
#endif
    return false;
}

void UByteBrewSDKInterface::StartPushNotifications()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "StartPushNotifications", "(Landroid/content/Context;)V", false);
        jobject Activity = FJavaWrapper::GameActivityThis;
        Env->CallStaticVoidMethod(Class, Method, Activity);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin StartPushNotification];
#endif
}

void UByteBrewSDKInterface::NewCustomEvent(FString eventName)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "NewCustomEvent", "(Ljava/lang/String;)V", false);
        jstring EventName = Env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
        Env->CallStaticVoidMethod(Class, Method, EventName);
        Env->DeleteLocalRef(EventName);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddNewCustomEvent:eventName.GetNSString()];
#endif
}

void UByteBrewSDKInterface::NewCustomEventWithStringValue(FString eventName, FString value)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "NewCustomEvent", "(Ljava/lang/String;Ljava/lang/String;)V", false);
        jstring EventName = Env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
        jstring Value = Env->NewStringUTF(TCHAR_TO_UTF8(*value));
        Env->CallStaticVoidMethod(Class, Method, EventName, Value);
        Env->DeleteLocalRef(EventName);
        Env->DeleteLocalRef(Value);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddNewCustomEventWithStringValue:eventName.GetNSString()
                                                        Value:value.GetNSString()];
#endif
}

void UByteBrewSDKInterface::NewCustomEventWithFloatValue(FString eventName, float value)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "NewCustomEvent", "(Ljava/lang/String;F)V", false);
        jstring EventName = Env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
        jfloat Value = static_cast<jfloat>(value);
        Env->CallStaticVoidMethod(Class, Method, EventName, Value);
        Env->DeleteLocalRef(EventName);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddNewCustomEventWithNumericValue:eventName.GetNSString()
                                                         Value:value];
#endif
}

void UByteBrewSDKInterface::SetCustomData(FString key, FString value)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "SetCustomData", "(Ljava/lang/String;Ljava/lang/String;)V", false);
        jstring Key = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
        jstring Value = Env->NewStringUTF(TCHAR_TO_UTF8(*value));
        Env->CallStaticVoidMethod(Class, Method, Key, Value);
        Env->DeleteLocalRef(Key);
        Env->DeleteLocalRef(Value);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddCustomDataAttributeWithStringValue:key.GetNSString()
                                                             Value:value.GetNSString()];
#endif
}

void UByteBrewSDKInterface::SetCustomDataFloat(FString key, float value)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "SetCustomData", "(Ljava/lang/String;D)V", false);
        jstring Key = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
        jdouble Value = static_cast<jdouble>(value);
        Env->CallStaticVoidMethod(Class, Method, Key, Value);
        Env->DeleteLocalRef(Key);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddCustomDataAttributeWithDoubleValue:key.GetNSString()
                                                             Value:value];
#endif
}

void UByteBrewSDKInterface::SetCustomDataInt(FString key, int32 value)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "SetCustomData", "(Ljava/lang/String;I)V", false);
        jstring Key = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
        jint Value = static_cast<jint>(value);
        Env->CallStaticVoidMethod(Class, Method, Key, Value);
        Env->DeleteLocalRef(Key);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddCustomDataAttributeWithIntegerValue:key.GetNSString()
                                                              Value:value];
#endif
}

void UByteBrewSDKInterface::SetCustomDataBool(FString key, bool value)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "SetCustomData", "(Ljava/lang/String;Z)V", false);
        jstring Key = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
        jboolean Value = static_cast<jboolean>(value);
        Env->CallStaticVoidMethod(Class, Method, Key, Value);
        Env->DeleteLocalRef(Key);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddCustomDataAttributeWithBooleanValue:key.GetNSString()
                                                              Value:value];
#endif
}

FString UByteBrewSDKInterface::GetProgressionTypeAsString(EByteBrewProgressionType progressionType)
{
    FString enumAsString = UEnum::GetValueAsString(progressionType);
    FString stringPrefix = "EByteBrewProgressionType::";
    return enumAsString.Replace(*stringPrefix, TEXT(""));
}

void UByteBrewSDKInterface::NewProgressionEvent(EByteBrewProgressionType progressionStatus, FString environment, FString stage)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "NewProgressionEvent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
        jstring ProgressionStatus = Env->NewStringUTF(TCHAR_TO_UTF8(*GetProgressionTypeAsString(progressionStatus)));
        jstring Environment = Env->NewStringUTF(TCHAR_TO_UTF8(*environment));
        jstring Stage = Env->NewStringUTF(TCHAR_TO_UTF8(*stage));
        Env->CallStaticVoidMethod(Class, Method, ProgressionStatus, Environment, Stage);
        Env->DeleteLocalRef(ProgressionStatus);
        Env->DeleteLocalRef(Environment);
        Env->DeleteLocalRef(Stage);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddProgressionEvent:(ByteBrewProgressionType)progressionStatus
                                     Environment:environment.GetNSString()
                                           Stage:stage.GetNSString()];
#endif
}

void UByteBrewSDKInterface::NewProgressionEventWithStringValue(EByteBrewProgressionType progressionStatus, FString environment, FString stage, FString value)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "NewProgressionEvent",
                                                          "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
        jstring ProgressionStatus = Env->NewStringUTF(TCHAR_TO_UTF8(*GetProgressionTypeAsString(progressionStatus)));
        jstring Environment = Env->NewStringUTF(TCHAR_TO_UTF8(*environment));
        jstring Stage = Env->NewStringUTF(TCHAR_TO_UTF8(*stage));
        jstring Value = Env->NewStringUTF(TCHAR_TO_UTF8(*value));
        Env->CallStaticVoidMethod(Class, Method, ProgressionStatus, Environment, Stage, Value);
        Env->DeleteLocalRef(ProgressionStatus);
        Env->DeleteLocalRef(Environment);
        Env->DeleteLocalRef(Stage);
        Env->DeleteLocalRef(Value);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddProgressionEventWithStringValue:(ByteBrewProgressionType)progressionStatus
                                                    Environment:environment.GetNSString()
                                                          Stage:stage.GetNSString()
                                                          Value:value.GetNSString()];
#endif
}

void UByteBrewSDKInterface::NewProgressionEventWithFloatValue(EByteBrewProgressionType progressionStatus, FString environment, FString stage, float value)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "NewProgressionEvent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;F)V", false);
        jstring ProgressionStatus = Env->NewStringUTF(TCHAR_TO_UTF8(*GetProgressionTypeAsString(progressionStatus)));
        jstring Environment = Env->NewStringUTF(TCHAR_TO_UTF8(*environment));
        jstring Stage = Env->NewStringUTF(TCHAR_TO_UTF8(*stage));
        jfloat Value = static_cast<jfloat>(value);
        Env->CallStaticVoidMethod(Class, Method, ProgressionStatus, Environment, Stage, Value);
        Env->DeleteLocalRef(ProgressionStatus);
        Env->DeleteLocalRef(Environment);
        Env->DeleteLocalRef(Stage);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddProgressionEventWithNumericValue:(ByteBrewProgressionType)progressionStatus
                                                     Environment:environment.GetNSString()
                                                           Stage:stage.GetNSString()
                                                           Value:value];
#endif
}

FString UByteBrewSDKInterface::GetAdTypeAsString(EByteBrewAdType adType)
{
    FString enumAsString = UEnum::GetValueAsString(adType);
    FString stringPrefix = "EByteBrewAdType::";
    return enumAsString.Replace(*stringPrefix, TEXT(""));
}

void UByteBrewSDKInterface::TrackAdEvent(EByteBrewAdType adType, FString adLocation)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "TrackAdEvent", "(Ljava/lang/String;Ljava/lang/String;)V", false);
        jstring AdType = Env->NewStringUTF(TCHAR_TO_UTF8(*GetAdTypeAsString(adType)));
        jstring AdLocation = Env->NewStringUTF(TCHAR_TO_UTF8(*adLocation));
        Env->CallStaticVoidMethod(Class, Method, AdType, AdLocation);
        Env->DeleteLocalRef(AdType);
        Env->DeleteLocalRef(AdLocation);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin NewTrackedAdEvent:GetAdTypeAsString(adType).GetNSString()
                                    AdLocation:adLocation.GetNSString()];
#endif
}

void UByteBrewSDKInterface::TrackAdEventWithAdID(EByteBrewAdType adType, FString adLocation, FString adID)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "TrackAdEventWithAdID", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
        jstring AdType = Env->NewStringUTF(TCHAR_TO_UTF8(*GetAdTypeAsString(adType)));
        jstring AdLocation = Env->NewStringUTF(TCHAR_TO_UTF8(*adLocation));
        jstring AdID = Env->NewStringUTF(TCHAR_TO_UTF8(*adID));
        Env->CallStaticVoidMethod(Class, Method, AdType, AdLocation, AdID);
        Env->DeleteLocalRef(AdType);
        Env->DeleteLocalRef(AdLocation);
        Env->DeleteLocalRef(AdID);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin NewTrackedAdEvent:GetAdTypeAsString(adType).GetNSString()
                                    AdLocation:adLocation.GetNSString()
                                          AdID:adID.GetNSString()];
#endif
}

void UByteBrewSDKInterface::TrackAdEventWithAdIDAndProvider(EByteBrewAdType adType, FString adLocation, FString adID, FString adProvider)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "TrackAdEventWithAdIDAndProvider",
                                                          "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
        jstring AdType = Env->NewStringUTF(TCHAR_TO_UTF8(*GetAdTypeAsString(adType)));
        jstring AdLocation = Env->NewStringUTF(TCHAR_TO_UTF8(*adLocation));
        jstring AdID = Env->NewStringUTF(TCHAR_TO_UTF8(*adID));
        jstring AdProvider = Env->NewStringUTF(TCHAR_TO_UTF8(*adProvider));
        Env->CallStaticVoidMethod(Class, Method, AdType, AdLocation, AdID, AdProvider);
        Env->DeleteLocalRef(AdType);
        Env->DeleteLocalRef(AdLocation);
        Env->DeleteLocalRef(AdID);
        Env->DeleteLocalRef(AdProvider);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin NewTrackedAdEvent:GetAdTypeAsString(adType).GetNSString()
                                    AdLocation:adLocation.GetNSString()
                                          AdID:adID.GetNSString()
                                    AdProvider:adProvider.GetNSString()];
#endif
}

void UByteBrewSDKInterface::TrackInAppPurchaseEvent(FString store, FString currency, float amount, FString itemID, FString category)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "TrackInAppPurchaseEvent",
                                                          "(Ljava/lang/String;Ljava/lang/String;FLjava/lang/String;Ljava/lang/String;)V", false);
        jstring Store = Env->NewStringUTF(TCHAR_TO_UTF8(*store));
        jstring Currency = Env->NewStringUTF(TCHAR_TO_UTF8(*currency));
        jfloat Amount = static_cast<jfloat>(amount);
        jstring ItemID = Env->NewStringUTF(TCHAR_TO_UTF8(*itemID));
        jstring Category = Env->NewStringUTF(TCHAR_TO_UTF8(*category));
        Env->CallStaticVoidMethod(Class, Method, Store, Currency, Amount, ItemID, Category);
        Env->DeleteLocalRef(Store);
        Env->DeleteLocalRef(Currency);
        Env->DeleteLocalRef(ItemID);
        Env->DeleteLocalRef(Category);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddTrackedInAppPurchaseEvent:store.GetNSString()
                                                 Currency:currency.GetNSString()
                                                   Amount:amount
                                                   ItemID:itemID.GetNSString()
                                                 Category:category.GetNSString()];
#endif
}

void UByteBrewSDKInterface::TrackGoogleInAppPurchaseEvent(FString store, FString currency, float amount, FString itemID, FString category, FString receipt, FString signature)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "TrackGoogleInAppPurchaseEvent",
                                                          "(Ljava/lang/String;Ljava/lang/String;FLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
        jstring Store = Env->NewStringUTF(TCHAR_TO_UTF8(*store));
        jstring Currency = Env->NewStringUTF(TCHAR_TO_UTF8(*currency));
        jfloat Amount = static_cast<jfloat>(amount);
        jstring ItemID = Env->NewStringUTF(TCHAR_TO_UTF8(*itemID));
        jstring Category = Env->NewStringUTF(TCHAR_TO_UTF8(*category));
        jstring Receipt = Env->NewStringUTF(TCHAR_TO_UTF8(*receipt));
        jstring Signature = Env->NewStringUTF(TCHAR_TO_UTF8(*signature));
        Env->CallStaticVoidMethod(Class, Method, Store, Currency, Amount, ItemID, Category, Receipt, Signature);
        Env->DeleteLocalRef(Store);
        Env->DeleteLocalRef(Currency);
        Env->DeleteLocalRef(ItemID);
        Env->DeleteLocalRef(Category);
        Env->DeleteLocalRef(Receipt);
        Env->DeleteLocalRef(Signature);
        Env->DeleteLocalRef(Class);
    }
#endif
}

void UByteBrewSDKInterface::TrackAppleInAppPurchaseEvent(FString store, FString currency, float amount, FString itemID, FString category, FString receipt)
{
#if PLATFORM_IOS
    [ByteBrewNativeiOSPlugin AddTrackediOSInAppPurchaseEvent:store.GetNSString()
                                                    Currency:currency.GetNSString()
                                                      Amount:amount
                                                      ItemID:itemID.GetNSString()
                                                    Category:category.GetNSString()
                                                     Receipt:receipt.GetNSString()];
#endif
}

bool UByteBrewSDKInterface::HasRemoteConfigsBeenSet()
{
    bool bResult = false;
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "HasRemoteConfigsBeenSet", "()Z", false);
        bResult = static_cast<bool>(Env->CallStaticBooleanMethod(Class, Method));
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    bResult = [ByteBrewNativeiOSPlugin HasRemoteConfigs];
#endif
    return bResult;
}

FString UByteBrewSDKInterface::RetrieveRemoteConfigValue(FString key, FString defaultValue)
{
    FString Result = defaultValue;
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "RetrieveRemoteConfigValue", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", false);
        jstring Key = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
        jstring DefaultValue = Env->NewStringUTF(TCHAR_TO_UTF8(*defaultValue));
        jstring JavaResult = static_cast<jstring>(Env->CallStaticObjectMethod(Class, Method, Key, DefaultValue));
        const char *nativeResult = Env->GetStringUTFChars(JavaResult, 0);
        Result = FString(nativeResult);
        Env->ReleaseStringUTFChars(JavaResult, nativeResult);
        Env->DeleteLocalRef(Key);
        Env->DeleteLocalRef(DefaultValue);
        Env->DeleteLocalRef(JavaResult);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    NSString *nsString = [ByteBrewNativeiOSPlugin RetrieveRemoteConfigs:key.GetNSString() DefaultValue:defaultValue.GetNSString()];
    Result = FString(nsString.UTF8String);
#endif
    return Result;
}

void UByteBrewSDKInterface::RestartTracking()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "RestartTracking", "(Landroid/content/Context;)V", false);
        jobject Activity = FJavaWrapper::GameActivityThis;
        Env->CallStaticVoidMethod(Class, Method, Activity);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin RestartTracking];
#endif
}

void UByteBrewSDKInterface::StopTracking()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "StopTracking", "(Landroid/content/Context;)V", false);
        jobject Activity = FJavaWrapper::GameActivityThis;
        Env->CallStaticVoidMethod(Class, Method, Activity);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin StopTracking];
#endif
}

FString UByteBrewSDKInterface::GetUserID()
{
    FString Result;
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "GetUserID", "()Ljava/lang/String;", false);
        jstring JavaResult = static_cast<jstring>(Env->CallStaticObjectMethod(Class, Method));
        const char *nativeResult = Env->GetStringUTFChars(JavaResult, 0);
        Result = FString(nativeResult);
        Env->ReleaseStringUTFChars(JavaResult, nativeResult);
        Env->DeleteLocalRef(JavaResult);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    NSString *nsString = [ByteBrewNativeiOSPlugin GetUserID];
    Result = FString(nsString.UTF8String);
#endif
    return Result;
}

void UByteBrewSDKInterface::ValidateGoogleInAppPurchaseEvent(FString store, FString currency, float amount, FString itemID, FString category, FString receipt,
                                                             FString signature)
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "ValidateGoogleInAppPurchaseEvent",
                                                          "(Ljava/lang/String;Ljava/lang/String;FLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
        jstring Store = Env->NewStringUTF(TCHAR_TO_UTF8(*store));
        jstring Currency = Env->NewStringUTF(TCHAR_TO_UTF8(*currency));
        jfloat Amount = static_cast<jfloat>(amount);
        jstring ItemID = Env->NewStringUTF(TCHAR_TO_UTF8(*itemID));
        jstring Category = Env->NewStringUTF(TCHAR_TO_UTF8(*category));
        jstring Receipt = Env->NewStringUTF(TCHAR_TO_UTF8(*receipt));
        jstring Signature = Env->NewStringUTF(TCHAR_TO_UTF8(*signature));
        Env->CallStaticVoidMethod(Class, Method, Store, Currency, Amount, ItemID, Category, Receipt, Signature);
        Env->DeleteLocalRef(Store);
        Env->DeleteLocalRef(Currency);
        Env->DeleteLocalRef(ItemID);
        Env->DeleteLocalRef(Category);
        Env->DeleteLocalRef(Receipt);
        Env->DeleteLocalRef(Signature);
        Env->DeleteLocalRef(Class);
    }
#endif
}

void UByteBrewSDKInterface::ValidateAppleInAppPurchaseEvent(FString store, FString currency, float amount, FString itemID, FString category, FString receipt)
{
#if PLATFORM_IOS
    [ByteBrewNativeiOSPlugin ValidateiOSInAppPurchaseEvent:store.GetNSString()
                                                  Currency:currency.GetNSString()
                                                    Amount:amount
                                                    ItemID:itemID.GetNSString()
                                                  Category:category.GetNSString()
                                                   Receipt:receipt.GetNSString()
                                  finishedValidationResult:^(NSMutableDictionary *purchaseResult){
                                      // Handle the purchase result here
                                  }];
#endif
}

void UByteBrewSDKInterface::LoadRemoteConfigs()
{
#if PLATFORM_ANDROID
    if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
    {
        jclass Class = FAndroidApplication::FindJavaClass("com/bytebrew/unrealsdk/ByteBrewWrapper");
        jmethodID Method = FJavaWrapper::FindStaticMethod(Env, Class, "LoadRemoteConfigs", "()V", false);
        Env->CallStaticVoidMethod(Class, Method);
        Env->DeleteLocalRef(Class);
    }
#elif PLATFORM_IOS
    [ByteBrewNativeiOSPlugin LoadRemoteConfigs:^(BOOL status){
        // Handle the remote config status here
    }];
#endif
}
