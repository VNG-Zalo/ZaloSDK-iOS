//
//  ZPTracking.h
//  ZPixelTracking
//
//  Created by Liem Vo  on 10/21/19.
//  Copyright © 2019 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZPTracker : NSObject

/**
 Create new tracker instance with specific pixel id
 */
+ (ZPTracker *_Nonnull) newInstanceWithPixelId: (long long) pixelId;
+ (void) releaseInstance: (ZPTracker *_Nonnull) tracker;

/**
Set Zalo App id
*/
- (void) setAppId: (NSString * _Nonnull) appId;

/**
 Set Addition user info
 userInfo: @{
   @"uid": "",
   @"account_created_time": @0, //NSNumber long unix ts,
   @"city": "",
   @"country": "",
   @"currency": "VND", //ISO 4217 currency code
   @"gender": "", //m: male, f: female, o: others,
   @"install_source": "..",
   @"language": "VN", //ISO 639-1 codes,
   @"user_type": "",
   ...
 }
 */
- (void) setUserInfo: (NSDictionary * _Nullable) userInfo;

/**
Track event with name
*/
- (void) trackEventWithName: (NSString * _Nonnull) name;

/**
 Track event with name & params
 */
- (void) trackEventWithName: (NSString * _Nonnull) name params: (NSDictionary * _Nullable) params;


/**
 Set Event dispatched interval in second.
 Default 30s
 */
- (void) setDispatchInterval: (NSTimeInterval) interval;

/**
 Set max number of stored events
 Default 500
*/
- (void) setMaxNumberEvents: (NSInteger) numberOfEvents;

/**
 Set Event stored interval
 Default 60s
*/
- (void) setStoreInterval: (NSTimeInterval) interval;

/**
 SDK Version
 */
+ (NSString * _Nonnull) sdkVersion;
@end
