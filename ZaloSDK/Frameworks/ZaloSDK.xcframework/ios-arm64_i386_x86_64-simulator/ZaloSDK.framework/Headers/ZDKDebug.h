//
// Created by ToanTM on 29/08/2021.
// Copyright (c) 2021 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZOOauthResponseObject.h"

typedef NS_ENUM(NSInteger, ZDKDebugEventType) {
    kZDKDebugEventTypeDidAuthenticatonViaWebView,
    kZDKDebugEventTypeDidAuthenticatonViaZaloApp,
    kZDKDebugEventTypeDidAuthenticatonViaGoogle,
    kZDKDebugEventTypeDidAuthenticatonViaZingMe,
    kZDKDebugEventTypeDidAuthenticatonViaApple,
    kZDKDebugEventTypeDidAuthenticatonViaFacebook,
    kZDKDebugEventTypeDidAuthenticatonViaGuest,
    kZDKDebugEventTypeGuestForgotPassword,
    kZDKDebugEventTypeGuestProtectAccountWithEmail,
    kZDKDebugEventTypeGuestRecoverAccountWithEmail,
    kZDKDebugEventTypeGuestProtectAccountWithCMND,
    kZDKDebugEventTypeDidGetAccessToken,
    kZDKDebugEventTypeDidValidatedRefreshToken,
    kZDKDebugEventTypeDidValidatedGuestSession
};
@interface ZDKDebug : NSObject
+ (instancetype) sharedInstance;
@property (nonatomic, assign) BOOL enable;
-(void)sendDebugMessageWithType:(ZDKDebugEventType) type data:(NSDictionary *)data;

- (void)sendErrorDebugMessageWithType:(enum ZDKDebugEventType)type data:(ZOOauthResponseObject *)oauthResponse;
@end
