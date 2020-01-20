//
//  ZUQLogWritter.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 3/31/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZUQLogWritter : NSObject
@property (strong, nonatomic) NSDictionary * params;
@property (strong, nonatomic, readonly) NSString * appId;
@property (strong, nonatomic) NSString * trackingUrl;
@property (nonatomic, readonly) BOOL isRunning;

- (instancetype) initWithAppId: (NSString *) appId;
- (void) writeLog: (NSDictionary *) log;
- (void) start;
- (void) stop;
@end
