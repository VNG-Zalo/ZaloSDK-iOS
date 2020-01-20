//
//  HttpTestRunner.h
//  ZingAnalytics
//
//  Created by Hoang Nguyen on 12/30/15.
//  Copyright © 2015 VNG. All rights reserved.
//

#import "ZUQTestRunner.h"

@class ZUQHttpClient;
@interface ZUQHttpTestRunner : ZUQTestRunner
@property (strong) ZUQHttpClient *httpClient;
@end
