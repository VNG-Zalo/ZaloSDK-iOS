//
//  TestRunner.h
//  ZingAnalytics
//
//  Created by Hoang Nguyen on 12/30/15.
//  Copyright © 2015 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ZUQTest;
@protocol ZUQTestRunnerDelegate;

@interface ZUQTestRunner : NSObject
@property (weak, nonatomic) id<ZUQTestRunnerDelegate> delegate;
@property (strong, nonatomic, readonly) ZUQTest * test;
@property (nonatomic) BOOL cancel;

+ (BOOL) canRunTest:(ZUQTest *) test;
- (instancetype)initWithTest:(ZUQTest *)test;
- (void)execute;

- (void) notifiyDelegateSuccessWithResult: (NSDictionary *) result;
- (void) notifyDelegateFailureWithError: (NSError *) error;
@end


@protocol ZUQTestRunnerDelegate<NSObject>
@optional
- (void) testRunner: (ZUQTestRunner *) testRunner didCompleteTest:(ZUQTest *) test result: (NSDictionary *) result;
- (void) testRunner: (ZUQTestRunner *) testRunner didFailToRunTest:(ZUQTest *) test error: (NSError *) error;
@end