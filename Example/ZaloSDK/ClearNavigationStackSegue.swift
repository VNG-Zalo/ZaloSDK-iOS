//
//  ClearNavigationStackSegue.swift
//  EmeraldAdmin
//
//  Created by Liem Vo on 7/26/17.
//  Copyright © 2017 Celadon. All rights reserved.
//

import UIKit
class ClearNavigationStackSegue: UIStoryboardSegue {
    override func perform() {
        source.navigationController?.setViewControllers([destination], animated: true)
        destination.navigationItem.hidesBackButton = true
    }
}
