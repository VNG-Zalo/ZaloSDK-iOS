//
//  ZDKNetworkManager.h
//  ZaloSDKCoreKit
//
//  Created by Liem Vo on 10/25/17.
//  Copyright © 2017 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^ZDKNetworkManagerJSONCallBack)(NSDictionary* _Nullable data, NSURLResponse* _Nullable response, NSError* _Nullable connectionError);
typedef void (^ZDKNetworkManagerDataCallBack)(NSData* _Nullable data, NSURLResponse* _Nullable response, NSError* _Nullable connectionError);
@interface ZDKNetworkManager : NSObject
@property (nonatomic, strong, nonnull) NSURLSession *urlSession;
+ (instancetype _Nonnull) sharedInstance;

+ (id _Nullable) sendAsynchronousRequest:(NSURLRequest* _Nonnull) request
                       completionDataHandler:(ZDKNetworkManagerDataCallBack _Nullable) handler;
+ (id _Nullable) sendAsynchronousRequest:(NSURLRequest* _Nonnull) request
                                           completionJSONHandler:(ZDKNetworkManagerJSONCallBack _Nullable) handler;
+ (NSDictionary * _Nullable) sendSynchronousRequest:(NSURLRequest * _Nonnull)request
                            returningResponse:(__autoreleasing NSURLResponse *_Nullable* _Nullable)responsePtr
                                        error:(__autoreleasing NSError *_Nonnull* _Nullable)errorPtr;
+ (void)addDefaultHeaderIntoURLRequest:(NSMutableURLRequest *_Nonnull)request;
+ (NSInteger)convertZaloErrorCodeToZaloSDKErrorCode:(NSInteger)zaloErrorCode;
@end
