//
// Created by ToanTM on 07/10/2021.
// Copyright (c) 2021 acct<blob>=<NULL>. All rights reserved.
//

import Foundation

class Constant {

    public static let EXT_INFO = [
        "appVersion": "1.0.0",
    ]
    public static let ZALO_APP_ID = "1829577289837795818"

}

enum UserDefaultsKeys: String, CaseIterable {
    case refreshToken = "refreshToken"
    case accessToken = "accessToken"
    case expriedTime = "expriedTime"
}
