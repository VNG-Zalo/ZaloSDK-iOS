//
//  ZDKSettingManager.h
//  ZaloSDKCoreKit
//
//  Created by Liem Vo  on 7/5/19.
//  Copyright © 2019 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define ZDK_SETTINGS_LOADED @"ZDK_SETTINGS_LOADED"
@interface ZDKSettingManager : NSObject

//Use web view if zalo app does not login
@property (nonatomic, readonly) BOOL loginZaloAppWebViewEnabled;

//login with browser instead of webview
@property (nonatomic, readonly) BOOL loginBrowser;
@property (nonatomic) NSTimeInterval expireTime;

//user qos enabled
@property (nonatomic, readonly) BOOL userQOSEnabled;

+ (instancetype) sharedInstance;
- (void) loadSettings;
- (void) reset;
@end

NS_ASSUME_NONNULL_END
