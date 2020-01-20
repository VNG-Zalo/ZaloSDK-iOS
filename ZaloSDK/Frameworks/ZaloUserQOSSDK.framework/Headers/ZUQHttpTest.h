//
//  HttpTest.h
//  ZingAnalytics
//
//  Created by Hoang Nguyen on 12/30/15.
//  Copyright © 2015 VNG. All rights reserved.
//

#import "ZUQTest.h"

@interface ZUQHttpTest : ZUQTest

@property (strong, nonatomic) NSArray *endTestStatusCodes;
@property (assign, nonatomic) NSUInteger expectedContentLength;
@property (assign, nonatomic) NSInteger expectedStatusCode;
@property (strong, nonatomic) NSString * method;
@property (strong, nonatomic) NSString * url;

@end
