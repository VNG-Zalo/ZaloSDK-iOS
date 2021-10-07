//
// Created by ToanTM on 07/10/2021.
// Copyright (c) 2021 acct<blob>=<NULL>. All rights reserved.
//

import Foundation

class Constant {

    public static let CODE_CHALLENGE = "nwq1ksIjN6774Bvdv47iMyONT721aFrjBsZCOYRLRoI"
    public static let CODE_VERIFIER = "FyQll83kk08PGYagSZRR5LIBYKBwFPc82gHnQO6VAdR8gN7G91s8iRl4UuY0e5_XQlp05rquCd9~kRaMvVfb9d00d5cr_k.Nb~3vEishGj0cEyfe3ykyaTeT3TETeXFk"
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
