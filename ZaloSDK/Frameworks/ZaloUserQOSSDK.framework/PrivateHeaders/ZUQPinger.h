//
//  ZUQPinger.h
//  ZaloUserQOSSDK
//
//  Created by Liem Vo Uy on 4/7/16.
//  Copyright © 2016 VNG. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_EMBEDDED || TARGET_IPHONE_SIMULATOR
#import <CFNetwork/CFNetwork.h>
#else
#import <CoreServices/CoreServices.h>
#endif

#include <AssertMacros.h>

#pragma mark * SimplePing

// The SimplePing class is a very simple class that lets you send and receive pings.

@protocol ZUQPingDelegate;

@interface ZUQPinger : NSObject

+ (ZUQPinger *)simplePingWithHostName:(NSString *)hostName;        // chooses first IPv4 address
+ (ZUQPinger *)simplePingWithHostAddress:(NSData *)hostAddress;    // contains (struct sockaddr)

@property (nonatomic, weak,   readwrite) id<ZUQPingDelegate> delegate;

@property (nonatomic, strong,   readonly ) NSString *             hostName;
@property (nonatomic, strong,   readonly ) NSData *               hostAddress;
@property (nonatomic, assign, readonly ) uint16_t               identifier;
@property (nonatomic, assign, readonly ) uint16_t               nextSequenceNumber;

- (void)start;
// Starts the pinger object pinging.  You should call this after
// you've setup the delegate and any ping parameters.

- (void)sendPingWithData:(NSData *)data;
- (void)sendPingWithData:(NSData *)data ttl: (int) ttl;
// Sends an actual ping.  Pass nil for data to use a standard 56 byte payload (resulting in a
// standard 64 byte ping).  Otherwise pass a non-nil value and it will be appended to the
// ICMP header.
//
// Do not try to send a ping before you receive the -simplePing:didStartWithAddress: delegate
// callback.

- (void)stop;
// Stops the pinger object.  You should call this when you're done
// pinging.

+ (const struct ZUQICMPHeader *)icmpInPacket:(NSData *)packet;
// Given a valid IP packet contains an ICMP , returns the address of the ICMP header that
// follows the IP header.  This doesn't do any significant validation of the packet.

@end

@protocol ZUQPingDelegate <NSObject>

@optional

- (void)simplePing:(ZUQPinger *)pinger didStartWithAddress:(NSData *)address;
// Called after the SimplePing has successfully started up.  After this callback, you
// can start sending pings via -sendPingWithData:

- (void)simplePing:(ZUQPinger *)pinger didFailWithError:(NSError *)error;
// If this is called, the SimplePing object has failed.  By the time this callback is
// called, the object has stopped (that is, you don't need to call -stop yourself).

// IMPORTANT: On the send side the packet does not include an IP header.
// On the receive side, it does.  In that case, use +[SimplePing icmpInPacket:]
// to find the ICMP header within the packet.

- (void)simplePing:(ZUQPinger *)pinger didSendPacket:(NSData *)packet;
// Called whenever the SimplePing object has successfully sent a ping packet.

- (void)simplePing:(ZUQPinger *)pinger didFailToSendPacket:(NSData *)packet error:(NSError *)error;
// Called whenever the SimplePing object tries and fails to send a ping packet.

- (void)simplePing:(ZUQPinger *)pinger didReceivePingResponsePacket:(NSData *)packet;
// Called whenever the SimplePing object receives an ICMP packet that looks like
// a response to one of our pings (that is, has a valid ICMP checksum, has
// an identifier that matches our identifier, and has a sequence number in
// the range of sequence numbers that we've sent out).

- (void)simplePing:(ZUQPinger *)pinger didReceiveUnexpectedPacket:(NSData *)packet;
// Called whenever the SimplePing object receives an ICMP packet that does not
// look like a response to one of our pings.

@end

#pragma mark * IP and ICMP On-The-Wire Format

// The following declarations specify the structure of ping packets on the wire.

// IP header structure:

struct ZUQIPHeader {
    uint8_t     versionAndHeaderLength;
    uint8_t     differentiatedServices;
    uint16_t    totalLength;
    uint16_t    identification;
    uint16_t    flagsAndFragmentOffset;
    uint8_t     timeToLive;
    uint8_t     protocol;
    uint16_t    headerChecksum;
    uint8_t     sourceAddress[4];
    uint8_t     destinationAddress[4];
    // options...
    // data...
};
typedef struct ZUQIPHeader ZUQIPHeader;

__Check_Compile_Time(sizeof(ZUQIPHeader) == 20);
__Check_Compile_Time(offsetof(ZUQIPHeader, versionAndHeaderLength) == 0);
__Check_Compile_Time(offsetof(ZUQIPHeader, differentiatedServices) == 1);
__Check_Compile_Time(offsetof(ZUQIPHeader, totalLength) == 2);
__Check_Compile_Time(offsetof(ZUQIPHeader, identification) == 4);
__Check_Compile_Time(offsetof(ZUQIPHeader, flagsAndFragmentOffset) == 6);
__Check_Compile_Time(offsetof(ZUQIPHeader, timeToLive) == 8);
__Check_Compile_Time(offsetof(ZUQIPHeader, protocol) == 9);
__Check_Compile_Time(offsetof(ZUQIPHeader, headerChecksum) == 10);
__Check_Compile_Time(offsetof(ZUQIPHeader, sourceAddress) == 12);
__Check_Compile_Time(offsetof(ZUQIPHeader, destinationAddress) == 16);

// ICMP type and code combinations:

enum {
    kICMPTypeEchoReply   = 0,           // code is always 0
    kICMPTypeEchoRequest = 8            // code is always 0
};

// ICMP header structure:

struct ZUQICMPHeader {
    uint8_t     type;
    uint8_t     code;
    uint16_t    checksum;
    uint16_t    identifier;
    uint16_t    sequenceNumber;
    // data...
};
typedef struct ZUQICMPHeader ZUQICMPHeader;

__Check_Compile_Time(sizeof(ZUQICMPHeader) == 8);
__Check_Compile_Time(offsetof(ZUQICMPHeader, type) == 0);
__Check_Compile_Time(offsetof(ZUQICMPHeader, code) == 1);
__Check_Compile_Time(offsetof(ZUQICMPHeader, checksum) == 2);
__Check_Compile_Time(offsetof(ZUQICMPHeader, identifier) == 4);
__Check_Compile_Time(offsetof(ZUQICMPHeader, sequenceNumber) == 6);
