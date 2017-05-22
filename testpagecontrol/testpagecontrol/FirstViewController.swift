//
//  FirstViewController.swift
//  testpagecontrol
//
//  Created by Jean-pierre BLANCHARD on 4/26/17.
//  Copyright © 2017 Jean-pierre BLANCHARD. All rights reserved.
//



import UIKit

var login = ""
var comefromloginview = 0

class FirstViewController: UIViewController {
    
    @IBOutlet weak var Submitbutton: UIButton!
    @IBOutlet weak var Input: UITextField!
    
    @IBAction func sendlogin(_ sender: UIButton) {
        
        if let text = Input.text, !text.isEmpty {
            login = text
            comefromloginview = 1
            performSegue(withIdentifier: "callaffiche",  sender: self)
            return
        } else {
            return
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        login = ""
        DispatchQueue.main.async {
            self.PositionElements()
        }
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func PositionElements() {
        
        screenWidth = Int(UIScreen.main.bounds.size.width)
        screenHeight = Int(UIScreen.main.bounds.size.height)
        
        let xpos = (screenWidth/2) - 40
        let ypos = (screenHeight/2) + 40
        
        if UIDevice.current.orientation.isPortrait {
            Submitbutton.frame = CGRect (x:CGFloat(xpos),y:CGFloat(ypos),width:70,height:30)
                   } else {
            Submitbutton.frame = CGRect (x:CGFloat(xpos),y:CGFloat(ypos),width:70,height:30)
                    }
            Input.center = CGPoint(x:CGFloat(self.view.center.x), y:CGFloat(self.view.center.y))
        
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        
        DispatchQueue.main.async {
            self.PositionElements()
        }
    }
    
}
