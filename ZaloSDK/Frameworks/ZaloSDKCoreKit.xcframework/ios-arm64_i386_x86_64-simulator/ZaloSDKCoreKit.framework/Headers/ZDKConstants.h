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

static NSString *const ZDK_CORE_VERSION_NAME = @"4.1.0120";
static NSString *const ZDK_CORE_VERSION_CODE = @"410120";

static NSString *const kZDKSDKDidFinishGetSDKIDAndPrivateKeyNotification = @"kZDKSDKDidFinishGetSDKIDAndPrivateKeyNotification";
static NSString *const kZDKSDKDidFinishGetDeviceIdWithCallbackKeyNotification = @"kZDKSDKDidFinishGetDeviceIdWithCallbackKeyNotification";
static NSString *const kZDKSDKDidChangedLanguageTypeKeyNotification = @"kZDKSDKDidChangedLanguageTypeKeyNotification";
static NSString *const kZDKSDKDidUnAuthenticatedTypeKeyNotification = @"kZDKSDKDidUnAuthenticatedTypeKeyNotification";
static NSString *const kZDKSDKDidAuthenticatedTypeKeyNotification = @"kZDKSDKDidAuthenticatedTypeKeyNotification";
static NSString *const kZDKSDKDebugEventKeyNotification = @"kZDKSDKDebugEventKeyNotification";

static NSString *const ZDK_KEYCHAIN_ZALO_SERVICE_NAME = @"vn.vng.zalo.keychain.service";
static NSString *const ZDK_KEYCHAIN_ZALO_GLOBAL_IDENTIFIER = @"zgid";

typedef NS_ENUM(NSInteger, ZAMEventActionType) {
    ZAMEventActionTypeUnknown = -1,
    ZAMEventActionTypeOpenApp = 1,
    ZAMEventActionTypeDeepLinking = 2,
    ZAMEventActionTypeShare = 3,
    ZAMEventActionTypeOpenAppByNotification = 4,
    ZAMEventActionTypeReceiveNotification = 5,
    ZAMEventActionTypePostFeed = 6,
    ZAMEventActionTypeSendAppRequest = 7,
    ZAMEventActionTypeSendMsg = 8,
    ZAMEventActionTypeSendOaMsg = 9,
    ZAMEventActionTypeGetFriend = 10,
    ZAMEventActionTypeGetInvitableFriend = 11,
    ZAMEventActionTypeGetProfile = 12,
    ZAMEventActionTypeAuthen = 13,
    ZAMEventActionTypeRecovery = 14,
    ZAMEventActionTypeProtectAcc = 15,
    ZAMEventActionTypeStartScreen = 16,
    ZAMEventActionTypeEndScreen = 17,
    ZAMEventActionTypeCrashLog = 18
};

static NSInteger const ZAMEventSubActionTypeAuthenViaZaloApp = 1;
static NSInteger const ZAMEventSubActionTypeAuthenViaZaloWeb = 2;
static NSInteger const ZAMEventSubActionTypeAuthenViaGooglePlus = 3;
static NSInteger const ZAMEventSubActionTypeAuthenViaZingMe = 4;
static NSInteger const ZAMEventSubActionTypeAuthenViaFacebook = 5;
static NSInteger const ZAMEventSubActionTypeAuthenViaGuest = 6;
static NSInteger const ZAMEventSubActionTypeAuthenViaApple = 7;
static NSInteger const ZAMEventSubActionTypeRecoveryPassMail = 1;// API Path: forgot-passwd-guest
static NSInteger const ZAMEventSubActionTypeRecoveryGuestAcc = 2;// API Path: recover-guest
static NSInteger const ZAMEventSubActionTypeProtectAccMail = 1;
static NSInteger const ZAMEventSubActionTypeProtectAccCMND = 2;
