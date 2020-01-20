//
//  ZDTSDK.h
//  Zing Analytics
//
//  Created by Liem Vo Uy on 2/6/15.
//  Copyright (c) 2015 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZaloSDKCoreKit/ZaloSDKCoreKit.h>
#import "ZAMDefines.h"


@class ZDKSharedStorage;
@interface ZingAnalytics : NSObject

+ (instancetype) sharedInstance;
+ (void) setCrashReportEnabled: (BOOL) enabled;
- (void) initWithAppId:(NSString *)appId;

@property (readonly, nonatomic) ZDKSharedStorage * storage;
@property (readonly, nonatomic) NSString * appUser;
@property (readonly, nonatomic) NSString * distributionSource;
@property (readonly, nonatomic) NSString * utmSource;
@property (readonly, nonatomic) ZOLoginType loginChannel;

@property (readonly, nonatomic) NSString * customDeviceId;
@property (readonly, nonatomic) NSString * centralizedDeviceId; //zdkid
@property (readonly, nonatomic) NSString * deviceId; //zdkid
@property (readonly, nonatomic) NSString * sdkId;
@property (readonly, nonatomic) NSString * deviceId4Ads;
/*!
 By default device tracker will use idfa. If your app doesn't display ad, 
 this option must be set to NO. Default is YES
 */
@property (assign, nonatomic) BOOL usingIDFAEnabled;


/**
 Get device id async
 */
- (void) deviceIdWithCallback: (void(^)(NSString * deviceId)) callback;

/**************
 Screen View tracking
 **************/
- (void) viewWillAppear:(UIViewController *)controller screenName:(NSString *)screenName;


/**
 Manual send events
 */
- (void) dispatchEvents;

/**
 Manual store events
 */
- (void) storeEvents;

/**************
 Configuration
 **************/

/**
 Set the max events to be stored. Default value is 1000 ~ 80kb
 */
- (void) setMaxEventsStored: (NSInteger) maxEventsStored;

/**
 Set the dispatch events to server interval. Default value is 60, min 30
 Set to a nagative value to disable dispatch events automatically. App must dispatch events manually
 */
- (void) setDisptachEventsInterval: (NSTimeInterval) sec;

/**
 Set the write events to disk interval. Default value is 20, min 10
 Set to a nagative value to disable store events automatically. App must store events manually
 */
- (void) setStoreEventsInterval: (NSTimeInterval) sec;

/**
 Add custom actioin event
 */
- (void) addEventWithAction: (NSString *) action params: (NSDictionary *) params;

- (void) addException:(NSString *)name
               mesage:(NSString *)message
               reason:(NSString *)reason
           stacktrace:(NSString *)stacktrace;

- (void) addEventWithAction:(NSString *)action
                   category: (NSString *) category
                      label: (NSString *) label
                      value: (NSNumber *) value;

@end
