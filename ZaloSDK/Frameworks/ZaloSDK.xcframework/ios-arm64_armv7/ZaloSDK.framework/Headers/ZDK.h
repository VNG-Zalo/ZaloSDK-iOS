//
//  ZaloApi.h
//  ZaloSDK
//
//  Created by smile on 8/1/13.
//  Copyright (c) 2013 com. All rights reserved.
//

@class ZOGraphResponseObject;
@class ZOOauthResponseObject;
@class ZORequestPermissionResponseObject;
@class ZOZingMeLoginView;
@class ZOLoginViewController;
@class ZOFeed;
@class ZOShareResponseObject;
@class ZDKConfig;
@class ZOTokenResponseObject;

@protocol ZOZaloApiDelegate;


/**
 A class that contains static functions that you
 can use to authenticate, get user profile, get friend list,
 send message, push feed, etc... in Zalo.
 */
@interface ZaloSDK : NSObject


//////////////////////////////////////
// General                          //
//////////////////////////////////////

/**
 Singleton object of SDK
 */
+ (instancetype) sharedInstance;
- (NSString *) appId;
- (NSString *) getVersion;

/**
 Initialize SDK with specific app id
 */
- (void) initializeWithAppId: (NSString *) appId;
- (void) setOauthDelegate:(id<ZOZaloApiDelegate>)delegate;

@property (nonatomic, strong, readonly) ZDKConfig *config;

//////////////////////////////////////
// Authenticate                     //
//////////////////////////////////////

- (void) authenticateZaloWithAuthenType:(enum ZAZaloSDKAuthenType) type
                       parentController:(UIViewController *)parentController
                          codeChallenge:(NSString*) codeChallenge
                                extInfo:(NSDictionary *)extInfo
                                handler:(void (^)(ZOOauthResponseObject* response))handler;

- (void) authenticateZaloWithAuthenType:(enum ZAZaloSDKAuthenType) type
                       parentController:(UIViewController *)parentController
                          isShowLoading:(BOOL) isShow
                          codeChallenge:(NSString*) codeChallenge
                                extInfo:(NSDictionary *)extInfo
                                handler:(void (^)(ZOOauthResponseObject* response))handler;
/**
 Register zalo accoun
 */
- (void) registZaloAccountWithParentController:(UIViewController *)parentController
                                 codeChallenge:(NSString *)codeChallenge
                                       extInfo:(NSDictionary *)extInfo
                                       handler:(void (^)(ZOOauthResponseObject *response)) handler;
/**
 Login Zalo with facebook account
 */
- (void) authenticateFacebookInController:(UIViewController *) controller
                            codeChallenge:(NSString *)codeChallenge
                                  extInfo:(NSDictionary *)extInfo
                    withCompletionHandler: (void (^)(ZOOauthResponseObject* response)) handler;

/**
Login Zalo with facebook access token
*/
- (void) authenticateWithFacebookAccessToken: (NSString *) accessToken
                               codeChallenge:(NSString *)codeChallenge
                                     extInfo:(NSDictionary *)extInfo
                       withCompletionHandler:(void (^)(ZOOauthResponseObject *))handler;
- (void) setFacebookAppId: (NSString *) appId;
- (void) setFacebookScopes: (NSArray<NSString *> *) scopes;
/**
 Default is NO
 **/
- (void) setAllowsSignInFacebookWithBrowser: (BOOL) yesOrNo;

/**
Login Zalo with Apple account
*/
- (void) authenticateAppleInController:(UIViewController *) controller
                         codeChallenge:(NSString *)codeChallenge
                               extInfo:(NSDictionary *)extInfo
                 withCompletionHandler: (void (^)(ZOOauthResponseObject* response)) handler;

/**
 Login Zalo with Google account
 */
- (void) authenticateGoogleInController:(UIViewController *)controller
                          codeChallenge:(NSString *)codeChallenge
                                extInfo:(NSDictionary *)extInfo
                                handler:(void (^)(ZOOauthResponseObject * response))handler;

/**
 Login Zalo with Guest account
 */
- (void) authenticateGuestWithCodeChallenge:(NSString *)codeChallenge
                               guestSession:(NSString *)guestSession
                                    extInfo:(NSDictionary *)extInfo
                          completionHandler:(void (^)(ZOOauthResponseObject * response))handler;

/**
 Create zing me login view
 @param frame frame of the login view. Height should be at least 114 pixel
 @return ZingMeLoginView
 */
- (ZOZingMeLoginView *) createZingMeLoginViewWithFrame: (CGRect) frame codeChallenge:(NSString *)codeChallenge extInfo:(NSDictionary *)extInfo;

- (void) authenticateZingMeWithUsername: (NSString *) username
                               password: (NSString *) password
                          codeChallenge:(NSString *)codeChallenge
                                extInfo:(NSDictionary *)extInfo
                      completionHandler: (void (^)(ZOOauthResponseObject* response)) handler;

- (void)getAccessTokenWithOAuthCode:(NSString *)oauthCode
                       codeVerifier:(NSString *)codeVerifier
                  completionHandler: (void (^)(ZOTokenResponseObject* response)) handler;
- (void)getAccessTokenWithOAuthCode:(NSString *)oauthCode
                       codeVerifier:(NSString *)codeVerifier
                            isGuest:(BOOL)isGuest
                  completionHandler:(void (^)(ZOTokenResponseObject *))handler;

- (void)getAccessTokenWithRefreshToken:(NSString *)refreshToken
                     completionHandler: (void (^)(ZOTokenResponseObject* response)) handler;
- (void)getAccessTokenWithRefreshToken:(NSString *)refreshToken
                               isGuest:(BOOL)isGuest
                     completionHandler: (void (^)(ZOTokenResponseObject* response)) handler;

- (void)validateRefreshToken:(NSString *)refreshToken
                     extInfo:(NSDictionary *)extInfo
           completionHandler: (void (^)(ZOOauthResponseObject* response)) handler;

- (void)validateGuestSession:(NSString * _Nonnull)guestSession
                     extInfo:(NSDictionary * _Nullable)extInfo
           completionHandler: (void (^ _Nullable)(ZOOauthResponseObject* _Nonnull response)) handler;

- (ZOLoginType) lastLoginType;

- (void)unauthenticate;

/**
 Call this method in applicationDidBecomeActive:
 */
- (void) handleDidBecomeActive;



//////////////////////////////////////
// Open APIs                        //
//////////////////////////////////////
typedef void (^ZOGraphCallback)(ZOGraphResponseObject* _Nullable response);

/**
 Get Zalo user profile
 */
- (void) getZaloUserProfileWithAccessToken:(NSString*) accessToken callback:(ZOGraphCallback) callback;

/**
 Get Zalo user friend list by offset and count
 */
- (void) getUserFriendListAtOffset:(NSUInteger) offset count:(NSUInteger) count accessToken:(NSString*) accessToken callback:(ZOGraphCallback) callback;

/**
 Get invitable Zalo user friend list
 */
- (void) getUserInvitableFriendListAtOffset:(NSUInteger) offset count:(NSUInteger) count accessToken:(NSString*) accessToken callback:(ZOGraphCallback) callback;

/**
 Post feed
 */
- (void) postFeedWithMessage:(NSString *) message link:(NSString *) link accessToken:(NSString*) accessToken callback:(ZOGraphCallback) callback;

/**
 Invite other user to use app
 */
- (void) sendAppRequestTo:(NSString *) friendId message:(NSString *) message accessToken:(NSString*) accessToken callback:(ZOGraphCallback) callback;

/**
 Send message to a friend
 */
- (void) sendMessageTo: (NSString *) friendId message:(NSString *) message link:(NSString *) link accessToken:(NSString*) accessToken callback:(ZOGraphCallback) callback;

/**
 Send message onbehave of offical account
 */
- (void) sendOfficalAccountMessageWith: (NSString *) templateName templateData:(NSDictionary *) templateData accessToken:(NSString*) accessToken callback:(ZOGraphCallback) callback;

/**
 Send graph api request with specific path and param
 Path: graph path ie: /me
 Param: url query param
 Method: HttpMethod: GET / POST
 */
- (void) userGraphWithPath:(NSString *) path
                    params:(NSDictionary *) data
                    method:(NSString *) method
               accessToken:(NSString*) accessToken
                  callback:(ZOGraphCallback) callback;



/*!
 Share Feed Link, Image, ...
 */
- (void)shareFeed:(ZOFeed *)feed
     inController:(UIViewController *)controller
         callback:(void(^)(ZOShareResponseObject * response))callback;

- (void)sendMessage:(ZOFeed *)message
       inController:(UIViewController *)controller
           callback:(void(^)(ZOShareResponseObject * response))callback;


- (void)shareFeedOrSendMessage:(ZOFeed *)feedOrMessage
                  inController:(UIViewController *)controller
                      callback:(void(^)(ZOShareResponseObject * response))callback;


//This method is used to config sharing zalo using app or web
//Default is ZOShareViaTypeAppOrWeb
//- (void)shareZaloUsing:(ZOShareViaType)type;

// Disable option to post to user's wall when sharing with zalo app
// Default is NO
- (void)setShareZaloChatOnly: (BOOL) yesOrNo;

////////////////////////////////////////
//// Login Form                       //
////////////////////////////////////////

- (ZOLoginViewController *)createLoginViewController;

////////////////////////////////////////
//// Protect Account Form                       //
////////////////////////////////////////

- (ZOLoginViewController *)createAccountProtectionViewController;

- (void) setDeviceIdFromZalo:(NSString *)deviceIdFromZalo;


@end



@interface ZaloSDK(Deprecated)


- (void) authenticateZaloWithCodeChallenge:(NSString*) codeChallenge
                                   extInfo:(NSDictionary *)extInfo
                         completionHandler: (void (^)(ZOOauthResponseObject* response)) handler __deprecated_msg("use method authenticateZaloWithAuthenType:parentController:handler instead.");

- (void) authenticateZaloWithAuthenType:(enum ZAZaloSDKAuthenType) type
                          codeChallenge:(NSString*) codeChallenge
                                extInfo:(NSDictionary *)extInfo
                      completionHandler: (void (^)(ZOOauthResponseObject* response)) handler __deprecated_msg("use method authenticateZaloWithAuthenType:parentController:handler instead.");

- (void) authenticateFacebookWithCodeChallenge:(NSString*) codeChallenge
                                       extInfo:(NSDictionary *)extInfo
                             completionHandler: (void (^)(ZOOauthResponseObject* response)) handler __deprecated_msg("use method authenticateFacebookInController:withCompletionHandler: instead.");
@end
