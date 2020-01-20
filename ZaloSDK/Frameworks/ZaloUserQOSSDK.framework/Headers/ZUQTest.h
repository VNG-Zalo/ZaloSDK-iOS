//
//  Test.h
//  ZingAnalytics
//
//  Created by Hoang Nguyen on 12/30/15.
//  Copyright © 2015 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZUQTest : NSObject<NSCoding>
@property (nonatomic) long long identifier;
@property (nonatomic) NSUInteger loop;
@property (nonatomic) NSTimeInterval period;
@property (nonatomic) NSTimeInterval endDate;
@property (nonatomic) NSDictionary *param;

+ (NSUInteger) cmd;
- (instancetype) initWithJSONData: (NSDictionary *) json;
@end
