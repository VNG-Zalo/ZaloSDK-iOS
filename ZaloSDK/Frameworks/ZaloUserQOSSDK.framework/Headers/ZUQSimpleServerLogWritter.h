//
//  ZUQSimpleServerLogWritter.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 3/31/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import "ZUQLogWritter.h"
@class ZUQDeviceInfoCollector;
@class ZUQHttpClient;
@interface ZUQSimpleServerLogWritter : ZUQLogWritter
@property (nonatomic, strong) ZUQDeviceInfoCollector *deviceInfoCollector;
@property (nonatomic, strong) ZUQHttpClient *httpClient;
- (BOOL) submitLogToServer: (NSDictionary *) body;
@end
