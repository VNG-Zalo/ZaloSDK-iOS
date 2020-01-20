//
//  ZUQDefaultConfigLoader.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 3/31/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import "ZUQConfigLoader.h"
@class ZUQHttpClient;
@class ZUQDeviceInfoCollector;

@interface ZUQDefaultConfigLoader : ZUQConfigLoader
@property (nonatomic, strong) ZUQHttpClient *httpClient;
@property (nonatomic, strong) ZUQDeviceInfoCollector *deviceInfoCollector;
@end
