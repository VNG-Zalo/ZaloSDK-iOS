//
//  MainViewController.swift
//  ZaloSDKFramework
//
//  Created by Liem Vo on 9/26/17.
//  Copyright © 2017 VNG. All rights reserved.
//

import UIKit
import ZaloSDK
import Alamofire
import AlamofireImage

class MainViewController: UITableViewController {
    @IBOutlet weak var profileImageView: UIImageView!
    @IBOutlet weak var profileLabel: UILabel!
    @IBOutlet weak var profileLoadingIndicator: UIActivityIndicatorView!

    override func viewDidLoad() {
        super.viewDidLoad()
        showProfile()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.navigationBar.isHidden = false
    }
    
    @IBAction func logoutButtonDidTouch(_ sender: Any) {
        logout()
        self.performSegue(withIdentifier: "showLoginController", sender: self)
    }
    
    @IBAction func shareMessageButtonDidTouch(_ sender: Any) {
        let feed = ZOFeed(
                link: "http://developers.zalo.me/",
                appName: "Tên Của App Tích Hợp",
                message: "Câu message muốn chia sẻ", others: nil)
        ZaloSDK.sharedInstance().sendMessage(feed, in: self) { response in
            print("\(#function): \(response?.isSucess)")
        }
    }
    
    
    @IBAction func shareFeedButtonDidTouch(_ sender: Any) {
        let feed = ZOFeed(
                link: "http://developers.zalo.me/",
                appName: "Tên Của App Tích Hợp",
                message: "Câu message muốn chia sẻ", others: nil)
        ZaloSDK.sharedInstance().share(feed, in: self) { response in
            print("\(#function): \(response?.isSucess)")
        }
    }
    
}

extension MainViewController {
    func logout() {
        AuthenUtils.shared.logout()
        ZaloSDK.sharedInstance().unauthenticate()
    }
    
    func showProfile() {
        profileLoadingIndicator.startAnimating()
        AuthenUtils.shared.getAccessToken { (accessToken) in
            if let accessToken = accessToken {
                ZaloSDK.sharedInstance().getZaloUserProfile(withAccessToken: accessToken) { (response) in
                    self.onLoad(profile: response)
                }
            }
        }
    }
    
    func onLoad(profile: ZOGraphResponseObject?) {
        profileLoadingIndicator.stopAnimating()
        guard let profile = profile,
            profile.isSucess,
            let name = profile.data["name"] as? String,
            let id = profile.data["id"] as? String,
            let gender = profile.data["gender"] as? String,
            let picture = profile.data["picture"] as? [String: Any?],
            let pictureData = picture["data"] as? [String: Any?],
            let sUrl = pictureData["url"] as? String,
            let url = URL(string: sUrl)
            else {
            return
        }
        
        profileLabel.text = "\(name)\n\(id)\n\(gender)"
        Alamofire.request(url).responseData { [self] (response) in
            if case .success(let data) = response.result {
                let image = UIImage(data: data)
                profileImageView.image = image
            }
        }
    }
}
