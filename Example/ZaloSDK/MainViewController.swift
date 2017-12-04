//
//  MainViewController.swift
//  ZaloSDKFramework
//
//  Created by Liem Vo on 9/26/17.
//  Copyright © 2017 VNG. All rights reserved.
//

import UIKit
import ZaloSDK
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
}

extension MainViewController {
    func logout() {
        ZaloSDK.sharedInstance().unauthenticate()
    }
    
    func showProfile() {
        profileLoadingIndicator.startAnimating()
        ZaloSDK.sharedInstance().getZaloUserProfile { (response) in
            self.onLoad(profile: response)
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
        profileImageView.af_setImage(withURL: url)
    }
}
