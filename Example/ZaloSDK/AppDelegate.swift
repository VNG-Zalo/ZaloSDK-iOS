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
    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {

        print("\(ZaloSDK.sharedInstance().getVersion() ?? "")")
        /// 0a. Init zalo sdk
        ZaloSDK.sharedInstance().initialize(withAppId: Constant.ZALO_APP_ID)
        _customNavigationBarForiOS15()
        
        return true
    }
    
    func application(_ app: UIApplication, open url: URL, options: [UIApplicationOpenURLOptionsKey : Any] = [:]) -> Bool {
        /// 0b. Receive callback from zalo
        return ZDKApplicationDelegate.sharedInstance().application(app, open: url, options: options)
    }
    
    func _customNavigationBarForiOS15() {
        if #available(iOS 15.0, *) {
            let navigationBarAppearance = UINavigationBarAppearance()
            navigationBarAppearance.configureWithDefaultBackground()
            navigationBarAppearance.backgroundColor = UIColor(red: 0, green: 143.0/255.0, blue: 243.0/255.0, alpha: 255/255.0)
            navigationBarAppearance.titleTextAttributes = [NSAttributedString.Key.foregroundColor : UIColor.white]
            UINavigationBar.appearance().tintColor = .white;
            UINavigationBar.appearance().standardAppearance = navigationBarAppearance
            UINavigationBar.appearance().compactAppearance = navigationBarAppearance
            UINavigationBar.appearance().scrollEdgeAppearance = navigationBarAppearance
        }

    }
}

