//
//  UserProject.swift
//  testpagecontrol
//
//  Created by Jean-pierre BLANCHARD on 5/12/17.
//  Copyright © 2017 Jean-pierre BLANCHARD. All rights reserved.
//

import Foundation

struct ProjectUser {
    var name : String
    var status : String
    var validated : Bool?
    var grade : Int?
    
    init(name : String, grade : Int?, status : String, validated : Bool?) {
        self.name = name
        self.grade = grade
        self.status = status
        self.validated = validated
    }
}
