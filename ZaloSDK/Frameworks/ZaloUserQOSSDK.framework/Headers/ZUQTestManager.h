//
//  TestManager.h
//  ZingAnalytics
//
//  Created by Hoang Nguyen on 12/30/15.
//  Copyright © 2015 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZUQConfig;
@class ZUQConfigLoader;
@class ZUQLogWritter;

@interface ZUQTestManager : NSObject
@property (strong, nonatomic) ZUQConfig *config;
@property (strong, nonatomic, readonly) NSArray *logWritters;
@property (strong, nonatomic, readonly) NSArray *testClasses;
@property (strong, nonatomic, readonly) NSArray *testRunnerClasses;
@property (nonatomic, getter=isRunning, readonly) BOOL running;

//addition log data
@property (strong, nonatomic) NSString * deviceId; //~advertiser id
@property (strong, nonatomic) NSString * sdkId;
@property (strong, nonatomic) NSString * userId; // uid of logged in user
@property (strong, nonatomic) NSString * session; // zalo session of logged in user
@property (strong, nonatomic) NSString * user; // user name
@property (strong, nonatomic) NSString * oauthCode; // zalo oauth code
@property (nonatomic) double lat; // current user location
@property (nonatomic) double lng; // current user location


+ (instancetype)sharedInstance;

/**
 Init test manager with default config loader
 */
- (void) initWithAppId: (NSString *) appId;

/**
 Init test manager with a config loader
 */
- (void) initWithConfigLoader: (ZUQConfigLoader *) configLoader;

/**
 start & testing
 */
- (void) start;
- (void) stop;

/**
 add & remove custom log writter
 */
- (void) addLogWritter: (ZUQLogWritter *) logWritter;
- (void) removeLogWritter: (ZUQLogWritter *) logWritter;

/**
 Register new test runner classes
 */
- (void) registerTestRunnerClass: (Class) clss;
- (void) unregisterTestRunnerClass: (Class) clss;

/**
 Register new test classes
 */
- (void) registerTestClass: (Class) clss;
- (void) unregisterTestClass: (Class) clss;


@end
