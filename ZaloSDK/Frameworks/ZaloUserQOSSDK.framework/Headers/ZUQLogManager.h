//
//  Logger.h
//  123ClickAdsSDK
//
//  Created by Liem Vo Uy on 9/19/13.
//  Copyright (c) 2013 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 SDK Log level
 */
typedef NS_ENUM(NSUInteger, ZUQLogLevel) {
    /**
     No log at all
     */
    ZUQLogNone = 0,
    /**
     Log all messages
     */
    ZUQLogVerbose = 1,
    /**
     Log debug, info, warn and error messages
     */
    ZUQLogDebug = 2,
    /**
     Log info, warn and error messages
     */
    ZUQLogInfo = 3,
    /**
     Log warn and error messages
     */
    ZUQLogWarn = 4,
    /**
     Only log error messages
     */
    ZUQLogError = 5,
};


@interface ZUQLogManager : NSObject
+ (ZUQLogLevel) logLevel;
+ (void) setZUQLogLevel: (ZUQLogLevel) logLevel;
@end


extern void ZUQLog(NSString * format,...);
extern void ZUQLoge(NSString * format,...);
extern void ZUQLogw(NSString * format,...);
extern void ZUQLogi(NSString * format,...);
extern void ZUQLogd(NSString * format,...);
extern void ZUQLogv(NSString * format,...);

