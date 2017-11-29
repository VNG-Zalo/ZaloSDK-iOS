//
//  OpenAPIDemoViewController.swift
//  ZaloSDKFramework
//
//  Created by Liem Vo on 9/27/17.
//  Copyright © 2017 VNG. All rights reserved.
//

import Eureka
import ZaloSDK

class OpenAPIDemoViewController : FormViewController {
    let ds = OpenAPIDemoDataSource()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        buildForm()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.navigationBar.isHidden = false
    }
    
    func onSelectAPIDemo(sender: UIButton) {
        let api = ds.apis[sender.tag]
        let controller = OpenAPIExectueViewController()
        controller.api = api
        self.navigationController?.pushViewController(controller, animated: true)
    }
}

extension OpenAPIDemoViewController {
    func buildForm() {
        tableView.backgroundColor = .white
        tableView.separatorStyle = .none
        tableView.allowsSelection = false
        tableView.bounces = false
        
        let section = Section()
        form +++ section
        ds.apis.enumerated().forEach { (idx, elm) in
            section <<< ButtonRow("\(elm.id)") { row in
                row.cell.button.tag = idx
                row.cell.button.setTitle(elm.name, for: .normal)
                row.cell.button.addTarget(self, action: #selector(onSelectAPIDemo(sender:)), for: .touchUpInside)
                row.cell.height =  {
                    return 60
                }
            }
        }
    }
}

class OpenAPIExectueViewController: FormViewController {
    var api: OpenAPI!
    var resultRow: TextAreaRow!
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = api.name
        buildForm()
    }
    
    func execute() {
        self.showResultText("loading...")
        UIApplication.shared.isNetworkActivityIndicatorVisible = true
        api.exectuor.execute(params: form.values()) {[weak self] (response) in
            UIApplication.shared.isNetworkActivityIndicatorVisible = false
            self?.displayResult(response)
        }
    }
    
    func displayResult(_ response: ZOGraphResponseObject?) {
        guard let response = response else {
            self.showResultText("Unknown error")
            return
        }
        guard response.isSucess == true else {
            self.showResultText("Error[\(response.errorCode)]: \(response.errorMessage)")
            return
        }
        
        if let data = try? JSONSerialization.data(withJSONObject: response.data, options: [.prettyPrinted]),
            let string = String(data: data, encoding: .utf8) {
            resultRow.value = string
        } else {
            resultRow.value = "\(response.data)"
        }
        
        resultRow.updateCell()
    }
    
    func showResultText(_ text: String) {
        resultRow.value = text
        resultRow.updateCell()
    }
}

extension OpenAPIExectueViewController {
    func buildForm() {
        tableView.backgroundColor = .white
        tableView.separatorStyle = .none
        tableView.allowsSelection = false
        tableView.bounces = false
        
        let section = Section()
        form +++ section
        
        api.params.forEach { (param) in
            section <<< TextRow(param.key) {row in
                row.title = param.key
                row.value = param.defaultValue
            }
        }
        
        section <<< ButtonRow("") { row in
            row.cell.button.setTitle("Execture", for: .normal)
            row.cell.button.addTarget(self, action: #selector(execute), for: .touchUpInside)
            row.cell.height =  {
                return 60
            }
        }
        
        resultRow = TextAreaRow("result_row") { row in
            row.value = ""
            row.textAreaHeight = TextAreaHeight.fixed(cellHeight: 400)
        }
        form +++ Section("Result")
        <<< resultRow
    }
}

protocol OpenAPIExecutor {
    func execute(params: [String: Any?], callback: @escaping ZOGraphCallback)
}

typealias OpenAPIParam = (key: String, defaultValue: String?)
typealias OpenAPI = (id: Int, name: String, params: [OpenAPIParam], exectuor: OpenAPIExecutor)
struct OpenAPIDemoDataSource {
    let apis: [OpenAPI] = [
        (id: 0, name: "Get profile", params: GetProfileExecutor.Params, exectuor: GetProfileExecutor()),
        (id: 1, name: "Get friend list", params: GetFriendListExecutor.Params, exectuor: GetFriendListExecutor()),
        (id: 3, name: "Get invitable firend list", params: GetInvitableFriendListExecutor.Params, exectuor: GetInvitableFriendListExecutor()),
        (id: 5, name: "Post feed", params: PostFeedExecutor.Params, exectuor: PostFeedExecutor()),
        (id: 6, name: "Send message", params: SendMessageExecutor.Params, exectuor: SendMessageExecutor()),
        (id: 7, name: "Send app request", params: SendAppRequestExecutor.Params, exectuor: SendAppRequestExecutor()),
        (id: 8, name: "Send offical account message", params: SendOfficalAccountMessageExecutor.Params, exectuor: SendOfficalAccountMessageExecutor())
    ]
}

class GetProfileExecutor : OpenAPIExecutor {
    static let Params: [OpenAPIParam] = []
    func execute(params: [String : Any?], callback: @escaping ZOGraphCallback) {
        ZaloSDK.sharedInstance().getZaloUserProfile(callback: callback)
    }
}

class GetFriendListExecutor : OpenAPIExecutor {
    static let Params: [OpenAPIParam] = [
        (key: "offset", defaultValue: "0"),
        (key: "limit", defaultValue: "50")
    ]
    func execute(params: [String : Any?], callback: @escaping ZOGraphCallback) {
        let offset = UInt(params["offset"] as? String ?? "") ?? 0
        let limit = UInt(params["limit"] as? String ?? "") ?? 50
        ZaloSDK.sharedInstance().getUserFriendList(atOffset: offset, count: limit, callback: callback)
    }
}

class GetInvitableFriendListExecutor : OpenAPIExecutor {
    static let Params: [OpenAPIParam] = [
        (key: "offset", defaultValue: "0"),
        (key: "limit", defaultValue: "50")
    ]
    func execute(params: [String : Any?], callback: @escaping ZOGraphCallback) {
        let offset = UInt(params["offset"] as? String ?? "") ?? 0
        let limit = UInt(params["limit"] as? String ?? "") ?? 50
        ZaloSDK.sharedInstance().getUserInvitableFriendList(atOffset: offset, count: limit, callback: callback)
    }
}

class PostFeedExecutor : OpenAPIExecutor {
    static let Params: [OpenAPIParam] = [
        (key: "message", defaultValue: "Zalo Developer"),
        (key: "link", defaultValue: "http://developers.zalo.me/")
    ]
    func execute(params: [String : Any?], callback: @escaping ZOGraphCallback) {
        let message = params["message"] as? String ?? ""
        let link = params["link"] as? String ?? ""
        ZaloSDK.sharedInstance().postFeed(withMessage: message, link: link, callback: callback)
    }
}

class SendMessageExecutor : OpenAPIExecutor {
    static let Params: [OpenAPIParam] = [
        (key: "to", defaultValue: ""),
        (key: "message", defaultValue: "Zalo Developer"),
        (key: "link", defaultValue: "http://developers.zalo.me/")
    ]
    func execute(params: [String : Any?], callback: @escaping ZOGraphCallback) {
        let to = params["to"] as? String ?? ""
        let message = params["message"] as? String ?? ""
        let link = params["link"] as? String ?? ""
        ZaloSDK.sharedInstance().sendMessage(to: to, message: message, link: link, callback: callback)
    }
}

class SendAppRequestExecutor : OpenAPIExecutor {
    static let Params: [OpenAPIParam] = [
        (key: "to", defaultValue: ""),
        (key: "message", defaultValue: "Zalo Developer")
    ]
    func execute(params: [String : Any?], callback: @escaping ZOGraphCallback) {
        let to = params["to"] as? String ?? ""
        let message = params["message"] as? String ?? ""
        ZaloSDK.sharedInstance().sendAppRequest(to: to, message: message, callback: callback)
    }
}

class SendOfficalAccountMessageExecutor : OpenAPIExecutor {
    static let Params: [OpenAPIParam] = [
        (key: "template", defaultValue: ""),
        (key: "templateData", defaultValue: "{ \"key\": \"value\" }")
    ]
    func execute(params: [String : Any?], callback: @escaping ZOGraphCallback) {
        let template = params["template"] as? String ?? ""
        let templateDataString = params["templateData"] as? String ?? ""
        var templateData: [String: Any] = [:]
        
        if let td = templateDataString.data(using: .utf8),
           let dict1 = try? JSONSerialization.jsonObject(with: td, options: []),
            let dict2 = dict1 as? [String: Any] {
            templateData = dict2
        }
        
        ZaloSDK.sharedInstance().sendOfficalAccountMessage(with: template, templateData: templateData, callback: callback)
    }
}

