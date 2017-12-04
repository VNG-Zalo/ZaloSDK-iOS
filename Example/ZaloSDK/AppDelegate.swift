//
//  AppDelegate.swift
//  ZaloSDKFramework
//
//  Created by Liem Vo on 9/27/17.
//  Copyright (c) 2017 VNG. All rights reserved.
//

import UIKit
import ZaloSDK

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    let zaloAppId = "1829577289837795818"
    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {

        /// 0a. Init zalo sdk
        ZaloSDK.sharedInstance().initialize(withAppId: zaloAppId)
        return true
    }
    func application(_ application: UIApplication, open url: URL, sourceApplication: String?, annotation: Any) -> Bool {
        
        /// 0b. Receive callback from zalo
        return ZDKApplicationDelegate.sharedInstance().application(application, open: url, sourceApplication: sourceApplication, annotation: annotation)
    }
}

