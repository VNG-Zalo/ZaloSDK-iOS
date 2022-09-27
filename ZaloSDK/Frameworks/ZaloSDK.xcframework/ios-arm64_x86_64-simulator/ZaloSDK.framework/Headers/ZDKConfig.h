//
//  ZDKConfig.h
//  ZaloSDK
//
//  Created by Liem Vo on 7/31/17.
//  Copyright © 2017 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZaloSDKCoreKit/ZaloSDKCoreKit.h>

@interface ZDKConfig : NSObject

+ (instancetype)defaultConfig;

- (NSString *)getPreferedLanguageCode;

- (void)setPreferedLanguageType:(ZDKLanguageType)languageType;

@end

