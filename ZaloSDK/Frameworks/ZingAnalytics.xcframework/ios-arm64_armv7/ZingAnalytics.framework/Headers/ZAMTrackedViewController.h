//
//  ZAMTrackedViewController.h
//  ZingAnalytics
//
//  Created by Hoang Nguyen on 9/30/15.
//  Copyright © 2015 VNG. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZAMTrackedViewController : UIViewController

/*!
 The screen name, for purposes of Zing Analytics tracking. If this is `nil`,
 no tracking calls will be made.
 */
@property (nonatomic, copy)  NSString * screenName;

@end
