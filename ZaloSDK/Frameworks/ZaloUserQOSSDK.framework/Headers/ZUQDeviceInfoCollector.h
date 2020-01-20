//
//  ZUQDeviceHelper.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 4/5/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZUQDeviceInfoCollector : NSObject
+ (instancetype) sharedInstance;
- (NSString *) deviceId;
- (NSString *) platform;
- (NSString *) deviceModel;
- (NSString *) connectionType;
- (NSString *) mobileNetworkCode;
- (NSString *) osVersion;
- (int) errorCategoryFromNSURLErrorCode: (NSInteger) code;
- (NSString *) displayAddressForAddress: (NSData *) address;
- (NSArray *)hostnamesForAddress:(NSString *)address;
@end
