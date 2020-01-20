//
//  ZUQConfig.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 3/31/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZUQConfig : NSObject<NSCoding>
@property (nonatomic, strong) NSArray * tests;
@property (nonatomic, strong) NSArray * appAllowCMDs;
@property (nonatomic, strong) NSString * checksum;
@property (nonatomic, strong) NSString * trackingLink;
@property (nonatomic) NSTimeInterval expireDate;
@end
