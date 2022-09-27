//
// Created by ToanTM on 04/10/2021.
// Copyright (c) 2021 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ZDKRSA : NSObject

// return base64 encoded string
+ (NSString *)zdkEncryptString:(NSString *)str publicKey:(NSString *)pubKey;
// return raw data
+ (NSData *)zdkEncryptData:(NSData *)data publicKey:(NSString *)pubKey;
// return base64 encoded string
+ (NSString *)zdkEncryptString:(NSString *)str privateKey:(NSString *)privKey;
// return raw data
+ (NSData *)zdkEncryptData:(NSData *)data privateKey:(NSString *)privKey;

// decrypt base64 encoded string, convert result to string(not base64 encoded)
+ (NSString *)zdkDecryptString:(NSString *)str publicKey:(NSString *)pubKey;
+ (NSData *)zdkDecryptData:(NSData *)data publicKey:(NSString *)pubKey;
+ (NSString *)zdkDecryptString:(NSString *)str privateKey:(NSString *)privKey;
+ (NSData *)zdkDecryptData:(NSData *)data privateKey:(NSString *)privKey;

@end