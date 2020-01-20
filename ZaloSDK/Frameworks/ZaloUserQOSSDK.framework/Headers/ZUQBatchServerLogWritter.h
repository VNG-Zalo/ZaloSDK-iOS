//
//  ZUQBatchServerLogWritter.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 3/31/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import "ZUQSimpleServerLogWritter.h"

@interface ZUQBatchServerLogWritter : ZUQSimpleServerLogWritter
- (void) setDispatchInterval: (NSTimeInterval) interval;
- (void) setMaxLogStored: (NSUInteger) max;
@end
