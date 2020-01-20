//
//  ZUQHttpClient.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 6/6/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZUQHttpClient : NSObject

@property (nonatomic, strong, readonly) NSString *rootUrl;

- (id) initWithRootUrl: (NSString * ) rootUrl;
- (id) doGetJSONWithPath: (NSString *) path params: (NSDictionary *) params error: (NSError **) error;
- (NSData *) sendSynchronousRequest:(NSURLRequest *)request
                  returningResponse:(__autoreleasing NSURLResponse **)responsePtr
                              error:(__autoreleasing NSError **)errorPtr;
@end
