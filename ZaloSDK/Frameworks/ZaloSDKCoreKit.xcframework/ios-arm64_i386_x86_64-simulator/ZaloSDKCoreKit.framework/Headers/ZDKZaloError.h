//
//  ZaloError.h
//  ZaloSDK
//
//  Created by smile on 8/9/13.
//  Copyright (c) 2013 com. All rights reserved.
//



#import <Foundation/Foundation.h>
/**
 enum define error code when using function +(void)authenticateWithAppId : (NSString*) appId  andDelegate:(id<ZAZaloApiDelegate>) delegate andCompletionHandler: (void (^)(ZAOauthResponseObject* response)) handler; of @class ZAZaloApi
 */
#ifndef ZALO_SDK_ERROR_H
#define ZALO_SDK_ERROR_H

typedef NS_ENUM(NSInteger, ZaloSDKErrorCode) {

    kZaloSDKErrorCodeNoneError = 0,

    // The account wasn't saved because it is missing a required login.
    // kZaloSDKErrorCodeRequiredLogin = -5001, =>Deprecated!

    /**
    The account wasn't saved because authentication of the supplied credential failed.
    */
    kZaloSDKErrorCodeAuthenticationFailed = -7014,
    /**
    force call service too more times.
    */
    kZaloSDKErrorCodeAuthenticationExceeded = -7015,

    // Invalid code type.
    kZaloSDKErrorCodeAppIdInvalid = -5000,
    /**
    account invalid. please check your app id.
    */
    kZaloSDKErrorCodeAccountInvalid = -7016,
    /**
    invalid request.
    */
    kZaloSDKErrorCodeRequestInvalid = -7017,

    /**
    The account wasn't deleted because it doesn't exist
    */
    kZaloSDKErrorCodeAccountNotFound = -7018,
    /**
    Get data from Zalo application fail.
    */
    kZaloSDKErrorCodeDataNotFound = -7019,

    // The operation didn't complete because the user denied permission.
    kZaloSDKErrorCodePermissionDenied = -7020,

    // Cancel request
    kZaloSDKErrorCodeRequestCanceled = -7021,

    // Compatible version
    // For example; You're using SDK version lager/lower than supported Zalo version
    // If you get the error code, you should be notify to user to upgrade latest Zalo version
    kZaloSDKErrorCodeUnSupportVersion = -7022,
    /**
    Invalid secret key.
    */
    kZaloSDKErrorCodeInvalidSecretKey = -5002,
    /**
    can't create oauth code.
    */
    kZaloSDKErrorCodeCreateOauthCodeFail = -7002,
    /**
    Can't create access token when authenticate to get oauth code
    */
    kZaloSDKErrorCodeCreateAccessTokenFail = -7001,
    /**
    oauth code's invalid when you use oauth code with Zalo Api
    */
    kZaloSDKErrorCodeInvalidOauthCode = -5003,

    kZaloSDKErrorCodeUserConsentFail = -6003,
    /**
    your session id @ Zalo application expired or invalid.
    */
    kZaloSDKErrorCodeInvalidSessionId = -5007,
    /**
    request has invalid parameter.
    */
    kZaloSDKErrorCodeInvalidParameter = -5014,
    /**
    zalo was not installed.
    */
    kZaloSDKErrorCodeRequiredZaloInstalled = -7023,
    kZaloSDKErrorCodeServerConnection = -7024,
    kZaloSDKErrorCodeTimeOutRequest = -7025,

    kZaloSDKErrorCodeDidNotLogin = -6002,

    kZaloSDKErrorCodeInvalidAccessToken = -5004,
    kZaloErrorCodeInvalidState = -5018,
    kZaloErrorCodeRefreshTokenIsNotGuestRefreshToken = -5019,

    /**
    Could not login to facebook
    */
    kZaloSDKErrorCouldNotLoginToFacebook = -7012,

    /**
    Could not login to G+
    */
    kZaloSDKErrorCouldNotLoginToGooglePlus = -7011,

    /**
    Could not login Zing Me
    */
    kZaloSDKErrorCouldNotLoginToZingMe = -7013,

    /**
    Guest Login - Account Protection Send Email failed
    */
    kZaloSDKErrorGuestProtectionFailed = -7026,
    kZaloSDKErrorGuestProtectionSuccess = -7027,
    kZaloSDKErrorGuestProtectionEmailPasswordMissing = -7028,

    kZaloSDKErrorGuestRecoveryFailed = -7005,
    kZaloSDKErrorGuestRecoverySuccess = -7029,
    kZaloSDKErrorGuestRecoveryEmailPasswordMissing = -7030,

    /**
    Enter CMND
    */
    kZaloSDKErrorMissingCMND = -7031,
    kZaloSDKErrorRegisterCMNDSuccess = -7032,

    /**
    Login apple
    */
    kZaloSDKErrorAppleIOSNotSupported = -7033,
    kZaloSDKErrorAppleIOSLoginError = -7034,

    /**
    Unknown exception
    */
    kZaloSDKErrorCodeUnknownException = -8000,
    kZaloSDKErrorCodeUserCancel = -7035,

    kZaloSDKErrorCodeInvalidCallbackURL = -5001,
    kZaloSDKErrorCodeInvalidIOSBundleID = -5005,
    kZaloSDKErrorCodeInvalidAndroidPackageName = -5006,
    kZaloSDKErrorCodeInvalidAndroidSignKey = -5008,
    kZaloSDKErrorCodeInvalidCodeChallenge = -5009,
    kZaloSDKErrorCodeInvalidCodeVerfifier = -5010,
    kZaloSDKErrorCodeInvalidRefreshToken = -5011,
    kZaloSDKErrorCodeInvalidOAID = -5012,
    kZaloSDKErrorCodeInvalidBodyData = -5013,
    kZaloSDKErrorCodeInvalidGrantType = -5015,
    kZaloSDKErrorCodeAuthorizedCodeExpired = -5016,
    kZaloSDKErrorCodeRefreshTokenExpired = -5017,
    kZaloSDKErrorCodeUserIsInvalid = -6000,
    kZaloSDKErrorCodeInvalidPermission = -6001,
    kZaloSDKErrorCodeUserNotOwnOa = -6004,
    kZaloSDKErrorCodeUserBanned = -6005,
    kZaloSDKErrorCodeInvalidCsrfToken = -7000,
    kZaloSDKErrorCodeHadAnErrorWhenVerifySessionUser = -7003,
    kZaloSDKErrorCodeYourApplicationMightBeNotApproveOrDisableByAdmin = -7004,
    kZaloSDKErrorCodeBuildRedirectUriFailed = -7006,

    // Graph API Error
    kZaloSDKErrorCodeGraphAPIInvalidParameter = -9000,
    kZaloSDKErrorCodeGraphAPIInvalidUserId = -9001,
    kZaloSDKErrorCodeGraphAPICantResolveToAValidUserId = -9002,
    kZaloSDKErrorCodeGraphAPIYourAppDontLinkWithAnyOfficialAccount = -9003,
    kZaloSDKErrorCodeGraphAPIUserNotVisible = -9004,
    kZaloSDKErrorCodeGraphAPIAccessingFriendRequestsRequiresTheExtendedPermissionRead_Requests = -9005,
    kZaloSDKErrorCodeGraphAPISessionKeyInvalid = -9006,
    kZaloSDKErrorCodeGraphAPISendingOfRequestsHasBeenTemporarilyDisabledForThisApplication = -9007,
    kZaloSDKErrorCodeGraphAPISyntaxError = -9008,
    kZaloSDKErrorCodeGraphAPICallFail = -9009,
    kZaloSDKErrorCodeGraphAPIMethodIsNotSupportForThisApi = -9010,
    kZaloSDKErrorCodeGraphAPIUnknownException = -9011,
    kZaloSDKErrorCodeGraphAPIItemNotExits = -9012,
    kZaloSDKErrorCodeGraphAPIAppIdInUseIsDisabledOrBanded = -9013,
    kZaloSDKErrorCodeGraphAPIQuotaForYourAppIsLimited = -9014,
    kZaloSDKErrorCodeGraphAPILimitOfFriendsListIsTooLarge_MaximumIs50 = -9015,
    kZaloSDKErrorCodeGraphAPIQuotaDailyForYourAppIsLimited = -9016,
    kZaloSDKErrorCodeGraphAPIQuotaWeeklyForYourAppIsLimited = -9017,
    kZaloSDKErrorCodeGraphAPIQuotaMonthlyForYourAppIsLimited = -9018,
    kZaloSDKErrorCodeGraphAPIQuotaMonthlyForYourAppIsLimited2 = -9019,
    kZaloSDKErrorCodeGraphAPIUserHasNotPlayedGameFor30DaysAgo = -9020,
    kZaloSDKErrorCodeGraphAPIDoNotDisturbUserUserHasntTalkedToFriendFor30DaysAgo = -9021,
    kZaloSDKErrorCodeGraphAPIRecipientWasReachedQuotaMessageReceive_1MessagePer3Days = -9022,
    kZaloSDKErrorCodeGraphAPISenderAndRecipientIsNotFriend = -9023,
    kZaloSDKErrorCodeGraphAPIQuotaDailyPerUserForYourAppIsLimited = -9024,
    kZaloSDKErrorCodeGraphAPIYourFriendIsNotUsingApp = -9025,
    kZaloSDKErrorCodeGraphAPIYourFriendIsUsingApp = -9026,
};

typedef NS_ENUM(NSInteger, ZaloErrorCode) {
    kZaloErrorCodeNoneError = 0,
    kZaloErrorCodeAuthenticationFailed = 2,
    kZaloErrorCodeAuthenticationExceeded = 3,
    kZaloErrorCodeAppIdInvalid = 4,
    kZaloErrorCodeAccountInvalid = 5,
    kZaloErrorCodeRequestInvalid = 6,
    kZaloErrorCodeAccountNotFound = 7,
    kZaloErrorCodeDataNotFound = 8,
    kZaloErrorCodePermissionDenied = 9,
    kZaloErrorCodeRequestCanceled = 10,
    kZaloErrorCodeUnSupportVersion = 11,
    kZaloErrorCodeInvalidSecretKey = 12,
    kZaloErrorCodeCreateOauthCodeFail = 13,
    kZaloErrorCodeCreateAccessTokenFail = 14,
    kZaloErrorCodeInvalidOauthCode = 15,
    kZaloErrorCodeUserConsentFail = 16,
    kZaloErrorCodeInvalidSessionId = 17,
    kZaloErrorCodeInvalidParameter = 18,
    kZaloErrorCodeRequiredZaloInstalled = 19,
    kZaloErrorCodeDidNotLogIn = 20,
    kxZACErrorCodeCancelRequestViaWebViewStepLogin = -1011,
    kxZACErrorCodeCancelRequestViaWebViewStepPermission = -1005,
    kZaloErrorCodeUnknownException = 1000
};

typedef NS_ENUM(NSInteger, ServerErrorCodeV2) {
    kServerErrorCodeV2CouldNotLoginGoogle = -1205,
    kServerErrorCodeV2CouldNotLoginFacebook = -1105,
    kServerErrorCodeV2CouldNotLoginZingMe = -1023,
};

typedef NS_ENUM(NSInteger, ServerErrorCodeV4) {
    kServerErrorCodeV4AppIdInvalid = -14002,
    kServerErrorCodeV4InvalidCallbackURL = -14003,
    kServerErrorCodeV4InvalidSecretKey = -14004,
    kServerErrorCodeV4InvalidOauthCode = -14005,
    kServerErrorCodeV4InvalidIOSBundleID = -14008,
    kServerErrorCodeV4InvalidAndroidPackageName = -14009,
    kServerErrorCodeV4InvalidSessionId = -14010,
    kServerErrorCodeV4InvalidAndroidSignKey = -14011,
    kServerErrorCodeV4InvalidCodeChallenge = -14012,
    kServerErrorCodeV4InvalidCodeVerifier = -14013,
    kServerErrorCodeV4InvalidRefreshToken = -14014,
    kServerErrorCodeV4InvalidOAID = -14015,
    kServerErrorCodeV4InvalidBodyData = -14016,
    kServerErrorCodeV4InvalidParameter = -14017,
    kServerErrorCodeV4InvalidGrantType = -14018,
    kServerErrorCodeV4AuthorizedCodeExpired = -14019,
    kServerErrorCodeV4RefreshTokenExpired = -14020,
    kServerErrorCodeV4UserIsInvalid = -14006,
    kServerErrorCodeV4InvalidPermission = -14021,
    kServerErrorCodeV4DidNotLogin = -14022,
    kServerErrorCodeV4UserConsentFail = -14023,
    kServerErrorCodeV4UserNotOwnOa = -14024,
    kServerErrorCodeV4UserBanned = -14025,
    kServerErrorCodeV4InvalidCsrfToken = -14007,
    kServerErrorCodeV4CreateAccessTokenFail = -14026,
    kServerErrorCodeV4CreateOauthCodeFail = -14027,
    kServerErrorCodeV4HadAnErrorWhenVerifySessionUser = -14028,
    kServerErrorCodeV4YourApplicationMightBeNotApproveOrDisableByAdmin = -14029,
    kServerErrorCodeV4GuestRecoveryFailed = -14030,
    kServerErrorCodeV4BuildRedirectUriFailed = -14031,
    kServerErrorCodeV4RefreshTokenIsNotGuestRefreshToken = -14048,
    kServerErrorCodeV4UnknownException = -14001,
};

typedef NS_ENUM(NSInteger, ServerGraphAPIErrorCode) {
    kServerGraphAPIErrorCodeInvalidParameter = 100,
    kServerGraphAPIErrorCodeInvalidUserId = 110,
    kServerGraphAPIErrorCodeCantResolveToAValidUserId = 111,
    kServerGraphAPIErrorCodeYourAppDontLinkWithAnyOfficialAccount = 112,
    kServerGraphAPIErrorCodeUserNotVisible = 210,
    kServerGraphAPIErrorCodeAccessingFriendRequestsRequiresTheExtendedPermissionRead_Requests = 289,
    kServerGraphAPIErrorCodeSessionKeyInvalid = 452,
    kServerGraphAPIErrorCodeSendingOfRequestsHasBeenTemporarilyDisabledForThisApplication = 2004,
    kServerGraphAPIErrorCodeSyntaxError = 2500,
    kServerGraphAPIErrorCodeCallFail = 10000,
    kServerGraphAPIErrorCodeMethodIsNotSupportForThisApi = 10001,
    kServerGraphAPIErrorCodeUnknownException = 10002,
    kServerGraphAPIErrorCodeItemNotExits = 10003,
    kServerGraphAPIErrorCodeAppIdInUseIsDisabledOrBanded = 11004,
    kServerGraphAPIErrorCodeQuotaForYourAppIsLimited = 12000,
    kServerGraphAPIErrorCodeLimitOfFriendsListIsTooLarge_MaximumIs50 = 12001,
    kServerGraphAPIErrorCodeQuotaDailyForYourAppIsLimited = 12002,
    kServerGraphAPIErrorCodeQuotaWeeklyForYourAppIsLimited = 12003,
    kServerGraphAPIErrorCodeQuotaMonthlyForYourAppIsLimited = 12004,
    kServerGraphAPIErrorCodeQuotaMonthlyForYourAppIsLimited2 = 12005,
    kServerGraphAPIErrorCodeUserHasNotPlayedGameFor30DaysAgo = 12006,
    kServerGraphAPIErrorCodeDoNotDisturbUserUserHasntTalkedToFriendFor30DaysAgo = 12007,
    kServerGraphAPIErrorCodeRecipientWasReachedQuotaMessageReceive_1MessagePer3Days = 12008,
    kServerGraphAPIErrorCodeSenderAndRecipientIsNotFriend = 12009,
    kServerGraphAPIErrorCodeQuotaDailyPerUserForYourAppIsLimited = 12010,
    kServerGraphAPIErrorCodeYourFriendIsNotUsingApp = 12011,
    kServerGraphAPIErrorCodeYourFriendIsUsingApp = 12012,
};

#pragma mark Custom Error Message
static NSString *const kZaloErrorMessageInvalidState = @"Invalid State";
static NSString *const kZaloSDKErrorMessageInvalidAccessToken = @"Invalid AccessToken";
static NSString *const kZaloSDKErrorMessageInvalidOauthCode = @"Invalid OauthCode";
static NSString *const kZaloSDKErrorMessageInvalidRefreshToken = @"Invalid RefreshToken";

#endif

