package com.bytebrew.unrealsdk;

import android.content.Context;
import android.app.Activity;

import com.bytebrew.bytebrewlibrary.ByteBrew;

import com.bytebrew.bytebrewlibrary.ByteBrewProgressionType;
import com.bytebrew.bytebrewlibrary.ByteBrewAdType;

import com.bytebrew.bytebrewlibrary.RemoteConfigListener;
import com.bytebrew.bytebrewlibrary.PurchaseResponseListener;
import com.bytebrew.bytebrewlibrary.ByteBrewPurchaseResult;

public class ByteBrewWrapper {

    public static void InitializeByteBrew(String gameKey, String secretKey, String engineVersion,
            final Context context) {
        if (context instanceof Activity) {
            ((Activity) context).runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    ByteBrew.InitializeByteBrew(gameKey, secretKey, engineVersion, context);
                }
            });
        }
    }

    public static boolean IsByteBrewInitialized() {
        return ByteBrew.IsByteBrewInitialized();
    }

    public static void StartPushNotifications(final Context context) {
        if (context instanceof Activity) {
            ((Activity) context).runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    ByteBrew.StartPushNotifications(context);
                }
            });
        }
    }

    public static void NewCustomEvent(String eventName) {
        ByteBrew.NewCustomEvent(eventName);
    }

    public static void NewCustomEvent(String eventName, String value) {
        ByteBrew.NewCustomEvent(eventName, value);
    }

    public static void NewCustomEvent(String eventName, float value) {
        ByteBrew.NewCustomEvent(eventName, value);
    }

    public static void SetCustomData(String key, String value) {
        ByteBrew.SetCustomData(key, value);
    }

    public static void SetCustomData(String key, double value) {
        ByteBrew.SetCustomData(key, value);
    }

    public static void SetCustomData(String key, int value) {
        ByteBrew.SetCustomData(key, value);
    }

    public static void SetCustomData(String key, boolean value) {
        ByteBrew.SetCustomData(key, value);
    }

    public static void NewProgressionEvent(String progressionStatus, String environment, String stage) {
        ByteBrewProgressionType status = ByteBrewProgressionType.valueOf(progressionStatus);
        ByteBrew.NewProgressionEvent(status, environment, stage);
    }

    public static void NewProgressionEvent(String progressionStatus, String environment, String stage, String value) {
        ByteBrewProgressionType status = ByteBrewProgressionType.valueOf(progressionStatus);
        ByteBrew.NewProgressionEvent(status, environment, stage, value);
    }

    public static void NewProgressionEvent(String progressionStatus, String environment, String stage, float value) {
        ByteBrewProgressionType status = ByteBrewProgressionType.valueOf(progressionStatus);
        ByteBrew.NewProgressionEvent(status, environment, stage, value);
    }

    public static void TrackAdEvent(String adType, String adLocation) {
        ByteBrewAdType type = ByteBrewAdType.valueOf(adType);
        ByteBrew.TrackAdEvent(type, adLocation);
    }

    public static void TrackAdEventWithAdID(String adType, String adLocation, String adID) {
        ByteBrewAdType type = ByteBrewAdType.valueOf(adType);
        ByteBrew.TrackAdEvent(type, adLocation, adID);
    }

    public static void TrackAdEventWithAdIDAndProvider(String adType, String adLocation, String adID,
            String adProvider) {
        ByteBrewAdType type = ByteBrewAdType.valueOf(adType);
        ByteBrew.TrackAdEvent(type, adLocation, adID, adProvider);
    }

    public static void TrackAdEventWithRevenue(String placementType, String adProvider, String adUnitName,
            double revenue) {
        ByteBrewAdType type = ByteBrewAdType.valueOf(placementType);
        ByteBrew.TrackAdEvent(type, adProvider, adUnitName, revenue);
    }

    public static void TrackAdEventWithAdLocationRevenue(String placementType, String adProvider, String adUnitName,
            String adLocation, double revenue) {
        ByteBrewAdType type = ByteBrewAdType.valueOf(placementType);
        ByteBrew.TrackAdEvent(type, adProvider, adUnitName, adLocation, revenue);
    }

    public static void TrackInAppPurchaseEvent(String store, String currency, float amount, String itemID,
            String category) {
        ByteBrew.TrackInAppPurchaseEvent(store, currency, amount, itemID, category);
    }

    public static void TrackGoogleInAppPurchaseEvent(String store, String currency, float amount, String itemID,
            String category, String receipt, String signature) {
        ByteBrew.TrackGoogleInAppPurchaseEvent(store, currency, amount, itemID, category, receipt, signature);
    }

    public static void ValidateGoogleInAppPurchaseEvent(String store, String currency, float amount, String itemID,
            String category, String receipt, String signature) {
        PurchaseResponseListener listener = new PurchaseResponseListener() {
            @Override
            public void purchaseValidated(ByteBrewPurchaseResult result) {
                //do stuff
            }
        };
        ByteBrew.ValidateGoogleInAppPurchaseEvent(store, currency, amount, itemID, category, receipt, signature,
                listener);
    }

    public static void LoadRemoteConfigs() {
        RemoteConfigListener configListener = new RemoteConfigListener() {
            @Override
            public void RetrievedConfigs(boolean status) {
                //do stuff
            }
        };
        ByteBrew.LoadRemoteConfigs(configListener);
    }

    public static boolean HasRemoteConfigsBeenSet() {
        return ByteBrew.HasRemoteConfigsBeenSet();
    }

    public static String RetrieveRemoteConfigValue(String key, String defaultValue) {
        return ByteBrew.RetrieveRemoteConfigValue(key, defaultValue);
    }

    public static void RestartTracking(final Context context) {
        if (context instanceof Activity) {
            ((Activity) context).runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    ByteBrew.RestartTracking(context);
                }
            });
        }
    }

    public static void StopTracking(final Context context) {
        if (context instanceof Activity) {
            ((Activity) context).runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    ByteBrew.StopTracking(context);
                }
            });
        }
    }

    public static String GetUserID() {
        return ByteBrew.GetUserID();
    }

}
