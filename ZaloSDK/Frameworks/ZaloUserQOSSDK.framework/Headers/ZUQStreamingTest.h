//
//  ZUQStrreamingTest.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 4/21/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import "ZUQTest.h"

@interface ZUQStreamingTest : ZUQTest
@property (assign, nonatomic) NSUInteger start;
@property (assign, nonatomic) NSUInteger end;
@property (strong, nonatomic) NSArray *endTestStatusCodes;
@property (assign, nonatomic) NSUInteger expectedContentLength;
@property (assign, nonatomic) NSUInteger expectedTotalLength;
@property (assign, nonatomic) NSInteger expectedStatusCode;
@property (strong, nonatomic) NSString * url;
@end
