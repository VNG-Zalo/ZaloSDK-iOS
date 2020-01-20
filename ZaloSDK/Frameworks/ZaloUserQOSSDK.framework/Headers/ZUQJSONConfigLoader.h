//
//  ZUQJSONConfigLoader.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 3/31/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import "ZUQConfigLoader.h"

@interface ZUQJSONConfigLoader : ZUQConfigLoader
/**
 Init with appid & config data
 Exmaple of data
 NSString * json = @"{\"errorCode\":0,\"ismodify\":true,\"checksum\":\"1\",\"expiredTime\":100000,\"trackingLink\":\"http://google.com\",\"data\":[{\"id\":3,\"loop\":4,\"period\":120,\"endDate\":100000000,\"cmd\":3,\"host\":\"8.8.8.8\",\"waitTime\":120}]}";
 NSDictionary *data = [NSJSONSerialization JSONObjectWithData:[json dataUsingEncoding:NSUTF8StringEncoding] options:0 error:nil];
 */
- (instancetype) initWithAppId:(NSString *)appid data: (NSDictionary *) data;
@end
