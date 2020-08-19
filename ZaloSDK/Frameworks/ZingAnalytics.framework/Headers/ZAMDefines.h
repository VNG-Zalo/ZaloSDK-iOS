//
//  ZDTDefines.h
//  DeviceTrackingSDK
//
//  Created by Liem Vo Uy on 12/22/14.
//  Copyright (c) 2014 VNG. All rights reserved.
//

#ifndef ZingAnalytics_ZDTDefines_h
#define ZingAnalytics_ZDTDefines_h

#define ZAM_HARDWARE_ID_URL @"/id/mobile/ios"
#define ZAM_HARDWARE_ID_4ADS_URL    @"/zaid/mobile/ios"
#define ZAM_SDK_ID_URL @"/sdk/mobile/ios"
#define ZAM_TRACKING_URL @"/apps/mobile/ios"
#define ZAM_APP_TRACKING_URL @"/apps/mobile/explore/ios"
#define ZAM_API_SECRET_KEY @"@#centralize#@"
#define ZAM_OAUTH_STATS @"/oauth/mobile/ios"

#define ZDTSDK_DEFAULT_MAX_EVENTS_STORED 500
#define ZDTSDK_DEFAULT_DISPATACH_EVENTS_INTERVAL 60
#define ZDTSDK_MIN_DISPATACH_EVENTS_INTERVAL 30
#define ZDTSDK_DEFAULT_STORE_EVENTS_INTERVAL 20
#define ZDTSDK_MIN_STORE_EVENTS_INTERVAL 10
#define ZDKSDK_DEFAULT_MAX_EVENT_LIFE_INTERVAL  259200 //seconds, 3 days
#define ZSDK_LOG_TAG @"[ZDK]"

#define kSdkIdKey @"zdtsdk_sdk_id"
#define kZDKSDKDidFinishGetSDKIDAndPrivateKeyNotification   @"kZDKSDKDidFinishGetSDKIDAndPrivateKeyNotification"
#define ZAMUserDefaults [NSUserDefaults standardUserDefaults]
#define kZDKSDKDidFinishGetDeviceIdWithCallbackKeyNotification  @"kZDKSDKDidFinishGetDeviceIdWithCallbackKeyNotification"


#endif
