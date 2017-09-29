//
//  ButtonCell.swift
//  ZaloSDKFramework
//
//  Created by Liem Vo on 9/27/17.
//  Copyright © 2017 CocoaPods. All rights reserved.
//

import Eureka
class ButtonCell: Cell<Int>, CellType {
    @IBOutlet weak var button: UIButton!
    override func setup() {
        super.setup()
        row.value = button.tag
    }
}

final class ButtonRow : Row<ButtonCell>, RowType {
    required init(tag: String?) {
        super.init(tag: tag)
        cellProvider = CellProvider<ButtonCell>(nibName: "ButtonCell")
    }
}
