//
//  SecondViewController.swift
//  testpagecontrol
//
//  Created by Jean-pierre BLANCHARD on 4/26/17.
//  Copyright © 2017 Jean-pierre BLANCHARD. All rights reserved.
//

import UIKit

var screenWidth = 0
var screenHeight = 0

class SecondViewController: UIViewController {
    
    var aut = Authentification()
    var act = UIActivityIndicatorView ()
    
    
    @IBOutlet weak var affiche: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        //print("ds viewdidload")
        
        DispatchQueue.main.async {
            self.act = self.DisplayActivityIndicator ()
            //print("act on")
        }
        if comefromloginview == 1 {
        comefromloginview = 0
        let qos = DispatchQoS.userInitiated.qosClass
        let queue = DispatchQueue.global(qos: qos)
        queue.sync {
            self.aut.GetToken(completionHandler: { (hasSucceed,coderetour) in
                if hasSucceed {
                    //print("good")
                    DispatchQueue.main.async {
                        self.act.stopAnimating()
                        self.AfficheElements()
                    }
                } else {
                    //print("bad")
                    var outputmessage = ""
                    if coderetour == 404 {
                        outputmessage = "This login doesn't exists"
                    } else {
                        outputmessage = "An Error has occured. Try Later!"
                    }
                    
                    let alert = UIAlertController(title: "Error", message: outputmessage, preferredStyle: UIAlertControllerStyle.alert)
                    alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: { action in
                        self.performSegue(withIdentifier: "ReturnToSearch",  sender: self)
                    })
                    )
                    self.present(alert, animated: true, completion: nil)
                }
            })
            } } else {
            DispatchQueue.main.async {
                self.act.stopAnimating()
                self.AfficheElements()
            }
        }
    }
    
    
    override func viewDidAppear(_ animated: Bool) {
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func DisplayActivityIndicator () -> UIActivityIndicatorView {
        
        
        let Act = UIActivityIndicatorView(activityIndicatorStyle: UIActivityIndicatorViewStyle.gray)
        Act.center = view.center
        Act.startAnimating()
        view.addSubview(Act)
        return Act
        
    }
    
    func AfficheElements() {
    
        self.ImageAffiche()
        self.NameAffiche()
        self.PhoneAffiche ()
        self.MailAffiche()
        self.WalletAffiche ()
        self.CorrectionAffiche ()
        self.LocationAffiche ()
        self.ButtonBackAffiche ()
        self.ButtonSkillsAffiche ()
        self.ButtonProjectsAffiche ()
        self.ButtonMapAffiche ()
        
    }
    
    func NameAffiche () {
    
       let Imagename:UIImageView = UIImageView ()
       Imagename.image = UIImage(named: "name" )
        
        
       let label = UILabel()
       label.textAlignment = .left
       label.text = DisplayName
        if UIDevice.current.orientation.isPortrait {
          label.frame = CGRect (x:(screenWidth/4 + 41),y:(screenHeight/10) + 110,width:250,height:21)
          Imagename.frame = CGRect (x:(screenWidth/4),y:(screenHeight/10) + 110,width:21,height:21)
        } else {
            label.frame = CGRect (x:(screenWidth/10 + 240),y:(screenHeight/10) + 20,width:250,height:21)
            Imagename.frame = CGRect (x:(screenWidth/10 + 200),y:(screenHeight/10) + 20,width:21,height:21)
        }
        self.view.addSubview(Imagename)
        self.view.addSubview(label)
    }
    
    func MailAffiche () {
       
        let Imagename:UIImageView = UIImageView ()
        Imagename.image = UIImage(named: "mail" )
        
        let label = UILabel()
        label.textAlignment = .left
        label.text = email
        if UIDevice.current.orientation.isPortrait {
            label.frame = CGRect (x:(screenWidth/4 + 41),y:(screenHeight/10) + 140,width:250,height:21)
            Imagename.frame = CGRect (x:(screenWidth/4),y:(screenHeight/10) + 140,width:21,height:21)
        } else {
            label.frame = CGRect (x:(screenWidth/10 + 240),y:(screenHeight/10) + 50,width:250,height:21)
            Imagename.frame = CGRect (x:(screenWidth/10 + 200),y:(screenHeight/10) + 50,width:21,height:21)
        }
        self.view.addSubview(Imagename)
        self.view.addSubview(label)
    }
    
    func PhoneAffiche () {
        
        let Imagename:UIImageView = UIImageView ()
        Imagename.image = UIImage(named: "phone" )
        
        let label = UILabel()
        label.textAlignment = .left
        if phone.isEmpty {
            phone = "Unknown"
        }
        label.text = phone
        if UIDevice.current.orientation.isPortrait {
            label.frame = CGRect (x:(screenWidth/4 + 41),y:(screenHeight/10) + 170,width:200,height:21)
            Imagename.frame = CGRect (x:(screenWidth/4),y:(screenHeight/10) + 170,width:21,height:21)
        } else {
            label.frame = CGRect (x:(screenWidth/10 + 240),y:(screenHeight/10) + 80,width:200,height:21)
            Imagename.frame = CGRect (x:(screenWidth/10 + 200),y:(screenHeight/10) + 80,width:21,height:21)
        }
        self.view.addSubview(Imagename)
        self.view.addSubview(label)
    }
    
    func LocationAffiche () {
        
        let Imagename:UIImageView = UIImageView ()
        Imagename.image = UIImage(named: "location" )
        
        let label = UILabel()
        label.textAlignment = .left
        label.text = location
        if UIDevice.current.orientation.isPortrait {
            label.frame = CGRect (x:(screenWidth/4 + 41),y:(screenHeight/10) + 200,width:200,height:21)
            Imagename.frame = CGRect (x:(screenWidth/4),y:(screenHeight/10) + 200,width:21,height:21)
        } else {
            label.frame = CGRect (x:(screenWidth/10 + 240),y:(screenHeight/10) + 110,width:200,height:21)
            Imagename.frame = CGRect (x:(screenWidth/10 + 200),y:(screenHeight/10) + 110,width:21,height:21)
        }
        self.view.addSubview(Imagename)
        self.view.addSubview(label)
    }
    
    func WalletAffiche () {
        
        let Imagename:UIImageView = UIImageView ()
        Imagename.image = UIImage(named: "wallet" )
        
        let str = "\(wallet)"
        let label = UILabel()
        label.textAlignment = .left
        if wallet != -500 {
           label.text = str
        } else {
           label.text = "Unknown"
        }
        if UIDevice.current.orientation.isPortrait {
            label.frame = CGRect (x:(screenWidth/4 + 41),y:(screenHeight/10) + 230,width:200,height:21)
            Imagename.frame = CGRect (x:(screenWidth/4),y:(screenHeight/10) + 230,width:21,height:21)
        } else {
            label.frame = CGRect (x:(screenWidth/10 + 240),y:(screenHeight/10) + 140,width:200,height:21)
            Imagename.frame = CGRect (x:(screenWidth/10 + 200),y:(screenHeight/10) + 140,width:21,height:21)
        }
        self.view.addSubview(Imagename)
        self.view.addSubview(label)
    }
    
    func CorrectionAffiche () {
        
        let Imagename:UIImageView = UIImageView ()
        Imagename.image = UIImage(named: "CorrectionPoints" )
        
        let str = "\(correction_point)"
        let label = UILabel()
        label.textAlignment = .left
        if correction_point != -500 {
            label.text = str
        } else {
            label.text = "Unknown"
        }
        if UIDevice.current.orientation.isPortrait {
            label.frame = CGRect (x:(screenWidth/4 + 41),y:(screenHeight/10) + 260,width:200,height:21)
            Imagename.frame = CGRect (x:(screenWidth/4),y:(screenHeight/10) + 260,width:21,height:21)
        } else {
            label.frame = CGRect (x:(screenWidth/10 + 240),y:(screenHeight/10) + 170,width:200,height:21)
            Imagename.frame = CGRect (x:(screenWidth/10 + 200),y:(screenHeight/10) + 170,width:21,height:21)
        }
        self.view.addSubview(Imagename)
        self.view.addSubview(label)
    }
    
    func ButtonBackAffiche () {
        
        let button = UIButton()
        button.restorationIdentifier = "ReturnToSearch"
        button.setTitle("Back", for: .normal)
        button.setTitleColor(UIColor.black, for: .normal)
        button.isEnabled = true
        button.backgroundColor = UIColor.gray
        button.addTarget(self, action: #selector(ReturnToSearch(button:)), for: .touchUpInside)
//        if UIDevice.current.orientation.isPortrait {
            button.frame = CGRect (x:CGFloat(15),y:CGFloat(screenHeight - 80),width:70,height:30)
//        } else {
//            button.frame = CGRect (x:CGFloat(350),y:CGFloat(360),width:55,height:30)
//        }
        self.view.addSubview(button)
    }
    
    func ButtonSkillsAffiche () {
        
        let xpos = (screenWidth - 310)/3 + 85
        let button = UIButton()
        button.restorationIdentifier = "GoToSkills"
        button.setTitle("Skills", for: .normal)
        button.setTitleColor(UIColor.black, for: .normal)
        button.backgroundColor = UIColor.gray
        button.isEnabled = true
        button.addTarget(self, action: #selector(GoToSkills(button:)), for: .touchUpInside)
//        if UIDevice.current.orientation.isPortrait {
            button.frame = CGRect (x:CGFloat(xpos),y:CGFloat(screenHeight - 80),width:70,height:30)
//        } else {
//            button.frame = CGRect (x:CGFloat(350),y:CGFloat(360),width:55,height:30)
//        }
        self.view.addSubview(button)
    }
    
    func ButtonProjectsAffiche () {
        
        let xpos = ((screenWidth - 310)/3) * 2 + 155
        let button = UIButton()
        button.restorationIdentifier = "GoToProjects"
        button.setTitle("Projects", for: .normal)
        button.setTitleColor(UIColor.black, for: .normal)
        button.isEnabled = true
        button.backgroundColor = UIColor.gray
        button.addTarget(self, action: #selector(GoToProjects(button:)), for: .touchUpInside)
//        if UIDevice.current.orientation.isPortrait {
            button.frame = CGRect (x:CGFloat(xpos),y:CGFloat(screenHeight - 80),width:70,height:30)
//        } else {
//            button.frame = CGRect (x:CGFloat(350),y:CGFloat(360),width:50,height:30)
//        }
        self.view.addSubview(button)
    }
    
    func ButtonMapAffiche () {
        
        let xpos = ((screenWidth - 310)/3) * 3 + 225
        let button = UIButton()
        button.restorationIdentifier = "GoToMap"
        button.setTitle("Campus", for: .normal)
        button.setTitleColor(UIColor.black, for: .normal)
        button.isEnabled = true
        button.backgroundColor = UIColor.gray
        button.addTarget(self, action: #selector(GoToMap(button:)), for: .touchUpInside)
        button.frame = CGRect (x:CGFloat(xpos),y:CGFloat(screenHeight - 80),width:70,height:30)
        self.view.addSubview(button)
    }
    
    func ImageAffiche () {
     
      screenWidth = Int(UIScreen.main.bounds.size.width)
      screenHeight = Int(UIScreen.main.bounds.size.height)
      
      let bongtuyet:UIImageView = UIImageView ()
        
     //Get image (Data) from URL Internet
        if image_url != "Unknown" && image_url != "https://cdn.intra.42.fr/images/default.png" {
          let strurl = NSURL(string: image_url)!
          let dtinternet = NSData(contentsOf:strurl as URL)!
          bongtuyet.image = UIImage(data:dtinternet as Data)
        } else {
            bongtuyet.image = UIImage(named: "default" )
        }

          if UIDevice.current.orientation.isPortrait {
            bongtuyet.frame = CGRect (x:(screenWidth/2 - 45),y:(screenHeight/10),width:90,height:90)
          } else {
            bongtuyet.frame = CGRect (x:(screenWidth/10),y:(screenHeight/10),width:90,height:120)
          }
         self.view.addSubview(bongtuyet)
    }
    
    func ReturnToSearch(button: UIButton) {
        
        performSegue(withIdentifier: "ReturnToSearch",  sender: self)
    }
    
    func GoToSkills(button: UIButton) {
        
        performSegue(withIdentifier: "GoToSkills",  sender: self)
    }
    
    func GoToProjects(button: UIButton) {
        
        performSegue(withIdentifier: "GoToProjects",  sender: self)
    }
    
    func GoToMap(button: UIButton) {
        
        performSegue(withIdentifier: "GoToMap",  sender: self)
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
         while let subview = self.view.subviews.last {
               subview.removeFromSuperview()
            }
        DispatchQueue.main.async {
          self.AfficheElements()
        }
    }
    
    
}
