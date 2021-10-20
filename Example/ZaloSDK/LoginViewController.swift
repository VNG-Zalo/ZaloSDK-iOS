//
//  ViewController.swift
//  ZaloSDKFramework
//
//  Created by Liem Vo on 9/27/17.
//  Copyright (c) 2017 VNG. All rights reserved.
//

import UIKit
import ZaloSDK

class LoginViewController: UIViewController {
    @IBOutlet weak var loadingIndicator: UIActivityIndicatorView!
    @IBOutlet weak var loginButton: UIButton!

    override func viewDidLoad() {
        super.viewDidLoad()
        loginButton.alignButtonIconAndTitle()
        checkIsAuthenticated()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.navigationBar.isHidden = true
    }

    @IBAction func loginButtonDidTouch(_ sender: Any) {
        login()
    }

    func showMainController() {
        self.performSegue(withIdentifier: "showMainController", sender: self)
    }
}

extension LoginViewController {
    func login() {
        AuthenUtils.shared.renewPKCECode()
        ZaloSDK.sharedInstance().authenticateZalo(with: ZAZAloSDKAuthenTypeViaZaloAppAndWebView, parentController: self, codeChallenge: AuthenUtils.shared.getCodeChallenge(), extInfo: Constant.EXT_INFO) { (response) in
            self.onAuthenticateComplete(with: response)
        }
    }
    
    func checkIsAuthenticated() {
        loadingIndicator.startAnimating()
        loginButton.isHidden = true

        let refreshToken = UserDefaults.standard.string(forKey: UserDefaultsKeys.refreshToken.rawValue)
        if let refreshToken = refreshToken {
            ZaloSDK.sharedInstance().validateRefreshToken(refreshToken, extInfo: Constant.EXT_INFO) { (response) in
            self.loadingIndicator.stopAnimating()
                if response?.isSucess == true {
                    self.showMainController()
                } else {
                    self.loginButton.isHidden = false
                }
            }
        } else {
            loadingIndicator.stopAnimating()
            loginButton.isHidden = false
        }
    }
    
    func onAuthenticateComplete(with response: ZOOauthResponseObject?) {
        loadingIndicator.stopAnimating()
        loginButton.isHidden = false
        
        if response?.isSucess == true {
            getAccessTokenFromOAuthCode(response?.oauthCode);
        } else if let response = response,
             response.errorCode != -1001 { // not cancel
            showAlert(with: "Error \(response.errorCode)", message: response.errorMessage ?? "")
        }
    }

    private func getAccessTokenFromOAuthCode(_ oauthCode: String?) {
        ZaloSDK.sharedInstance().getAccessToken(withOAuthCode: oauthCode, codeVerifier: AuthenUtils.shared.getCodeVerifier()) { (tokenResponse) in
            AuthenUtils.shared.saveTokenResponse(tokenResponse)
            if let tokenResponse = tokenResponse {
                print("""
                      getAccessTokenFromOAuthCode:
                      accessToken: \(tokenResponse.accessToken ?? "")
                      refreshToken: \(tokenResponse.refreshToken ?? "")
                      expriedTime: \(tokenResponse.expriedTime)
                      """)
                self.showMainController()
            } else {
                self.showAlert(with: "Get AccessToken from OauthCode error \(tokenResponse?.errorCode ?? ZaloSDKErrorCode.sdkErrorCodeUnknownException.rawValue)", message: tokenResponse?.errorMessage ?? "")
            }
        }
    }
}

extension UIViewController {
    func showAlert(with title: String = "ZaloSDK", message: String) {
        let controller = UIAlertController(title: title, message: message, preferredStyle: .alert)
        let action = UIAlertAction(title: "OK", style: .default) { (action) in
            controller.dismiss(animated: true, completion: nil)
        }
        controller.addAction(action)
        self.present(controller, animated: true, completion: nil)
    }
}

extension UIButton {
    func alignButtonIconAndTitle() {
        guard let imageView = self.imageView,
            let titleLabel = self.titleLabel else {
            return
        }
        self.contentHorizontalAlignment = .left
        self.imageEdgeInsets = UIEdgeInsets(top: 0, left: 16, bottom: 0, right: 0)
        let space = UIEdgeInsetsInsetRect(self.bounds, self.contentEdgeInsets)
        let width = space.width - self.imageEdgeInsets.right - imageView.frame.size.width - titleLabel.frame.size.width
        self.titleEdgeInsets = UIEdgeInsets(top: 0, left: width/2, bottom: 0, right: 0)
    }
}
