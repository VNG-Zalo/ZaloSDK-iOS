//
//  ZDKApplication.h
//  ZaloSDKCoreKit
//
//  Created by Liem Vo on 12/7/17.
//  Copyright © 2017 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ZDKApplication : NSObject
+ (instancetype)sharedApplication;

- (BOOL)canOpenURL:(NSURL *)url;

- (void)openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenExternalURLOptionsKey, id> *_Nonnull)options completionHandler:(void (^ __nullable)(BOOL success))completion;
@end
