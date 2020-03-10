//
//  ZDKConstants.h
//  ZaloSDK.CoreKit
//
//  Created by Hoang Nguyen on 9/22/15.
//  Copyright © 2015 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ZOLoginType){
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


@interface ZDKConstants : NSObject

@end

#define ZDK_CORE_VERSION @"2.5.0310"
#define kZDKSDKDidFinishGetSDKIDAndPrivateKeyNotification   @"kZDKSDKDidFinishGetSDKIDAndPrivateKeyNotification"
