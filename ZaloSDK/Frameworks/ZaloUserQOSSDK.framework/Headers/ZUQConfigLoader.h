//
//  ZUQConfigLoader.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 3/31/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ZUQConfig;
@class ZUQTest;
@protocol ZUQConfigLoaderDelegate;
@interface ZUQConfigLoader : NSObject
@property (weak, nonatomic) id<ZUQConfigLoaderDelegate> delegate;
@property (strong, nonatomic) ZUQConfig *config;
@property (nonatomic, readonly) NSString *appId;
@property (nonatomic, strong) NSDictionary * params;
@property (nonatomic, strong) NSArray * testClasses;

- (instancetype) initWithAppId: (NSString *) appid;
- (BOOL) isConfigValid;
- (void) loadConfig;
- (void) loadConfigFromCache;
- (void) saveConfigToCache;
- (void) removeTest: (ZUQTest *) test;

@end


@protocol ZUQConfigLoaderDelegate<NSObject>
@optional
- (void) configLoader: (ZUQConfigLoader *) configLoader didLoadConfig: (ZUQConfig *) config;
- (void) configLoader: (ZUQConfigLoader *) configLoader didFailLoadWithError: (NSError *) error;
@end