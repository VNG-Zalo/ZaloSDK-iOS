//
//  ZDKServiceMapManager.h
//  ZaloSDKCoreKit
//
//  Created by Liem Vo  on 8/1/19.
//  Copyright © 2019 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define KEY_URL_OAUTH @"oauth_http_s"
#define KEY_URL_GRAPH @"graph_http_s"
#define KEY_URL_CENTRALIZED @"centralized_http_s"

#define ZDK_MAKE_URL(key, path) [[ZDKServiceMapManager sharedInstance] urlForKey:key withPath:path]
#define OAUTH_URL(path) ZDK_MAKE_URL(KEY_URL_OAUTH, path)
#define GRAPH_URL(path) ZDK_MAKE_URL(KEY_URL_GRAPH, path)
#define CENTRALIZED_URL(path) ZDK_MAKE_URL(KEY_URL_CENTRALIZED, path)

@interface ZDKServiceMapManager : NSObject
+ (instancetype) sharedInstance;
- (void) loadServiceMap;
- (NSString *) urlForKey: (NSString *) key withPath: (NSString *) path;
@end

NS_ASSUME_NONNULL_END
