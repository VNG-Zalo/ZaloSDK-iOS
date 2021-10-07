//
//  ZDKConstants.h
//  ZaloSDK.CoreKit
//
//  Created by Hoang Nguyen on 9/22/15.
//  Copyright © 2015 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ZOLoginType) {
    ZOLoginTypeUnknown = 0,
    ZOLoginTypeFacebook = 1,
    ZOLoginTypeZalo = 2,
    ZOLoginTypeGooglePlus = 3,
    ZOLoginTypeZingMe = 4,
    ZOLoginTypeGuest = 5,
    ZOLoginTypeApple = 7,
};


typedef NS_ENUM(NSInteger, ZDKErrorCode) {
    ZDKNoneErrorCode,
    ZDKUnknownErrorCode,
    ZDKInvalidErrorCode,
    ZDKTimeoutErrorCode,
    ZDKNetworkErrorCode,
    ZDKEncryptionErrorCode,
    ZDKInvalidParamsErrorCode
};

typedef NS_ENUM(NSInteger, ZDKNetworkType) {
    ZDKNetworkTypeUnknown = -1,
    ZDKNetworkTypeOffline = 0,
    ZDKNetworkType3G = 1,
    ZDKNetworkTypeWifi = 2
};

typedef NS_ENUM(NSInteger, ZDKLanguageType) {
    ZDKLanguageTypeVietnamese = 1,
    ZDKLanguageTypeEnglish = 2,
    ZDKLanguageTypeMyanmar = 3
};

@interface ZDKConstants : NSObject

@end

static NSString *const ZDK_FROMSOURCE_SDK     = @"1";
static NSString *const ZDK_FROMSOURCE_ZALOAPP = @"2";

static NSString *const ZDK_OS_iOS = @"2";

static NSString *const ZDK_CORE_VERSION_NAME = @"2.6.1007";
static NSString *const ZDK_CORE_VERSION_CODE = @"261007";

static NSString *const kZDKSDKDidFinishGetSDKIDAndPrivateKeyNotification = @"kZDKSDKDidFinishGetSDKIDAndPrivateKeyNotification";
static NSString *const kZDKSDKDidFinishGetDeviceIdWithCallbackKeyNotification = @"kZDKSDKDidFinishGetDeviceIdWithCallbackKeyNotification";
static NSString *const kZDKSDKDidChangedLanguageTypeKeyNotification = @"kZDKSDKDidChangedLanguageTypeKeyNotification";
static NSString *const kZDKSDKDidUnAuthenticatedTypeKeyNotification = @"kZDKSDKDidUnAuthenticatedTypeKeyNotification";
static NSString *const kZDKSDKDidAuthenticatedTypeKeyNotification = @"kZDKSDKDidAuthenticatedTypeKeyNotification";
static NSString *const kZDKSDKDebugEventKeyNotification = @"kZDKSDKDebugEventKeyNotification";

static NSString *const ZDK_KEYCHAIN_ZALO_SERVICE_NAME = @"vn.vng.zalo.keychain.service";
static NSString *const ZDK_KEYCHAIN_ZALO_GLOBAL_IDENTIFIER = @"zgid";
