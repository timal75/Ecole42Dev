//
//  FirstViewController.swift
//  testpagecontrol
//
//  Created by Jean-pierre BLANCHARD on 4/26/17.
//  Copyright © 2017 Jean-pierre BLANCHARD. All rights reserved.
//



import UIKit

var skillsarray : [SkillUser] = []

class CustomViewCell: UITableViewCell {
    
    @IBOutlet weak var SkillLevelNumber: UILabel!
    @IBOutlet weak var LevelBar: UIProgressView!
    @IBOutlet weak var SkillLevel: UILabel!
    
    
}

class SkillsViewController: UIViewController,UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet weak var cursus: UITableView!
        
    @IBOutlet weak var LevelViewLabel: UILabel!
    @IBOutlet weak var Level: UIProgressView!
    @IBOutlet weak var skills: UITableView!
    
    @IBOutlet weak var ReturnButton: UIButton!
    
    
    var formationref : String = ""
    var levelnum : Float = 0
    let cellidentifier : String = "cell"
    
    var numberofcursus : Int = 0
    var numberofskills : Int = 0
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if formation.count > 0 {
          formationref = formation[0]
        } else {
          formationref = ""  
        }
        
        cursus.delegate = self
        cursus.dataSource = self
        skills.delegate = self
        skills.dataSource = self
        self.constructArray ()
        DispatchQueue.main.async {
            self.ButtonReturn ()
        }
        
        DispatchQueue.main.async {
            self.PositionTableView ()
        }
        
        let index = IndexPath.init(row:0, section:0)
        cursus.selectRow(at: index, animated: true, scrollPosition: UITableViewScrollPosition.middle)
        
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        if (tableView.tag == 1){
           numberofcursus = formation.count
           return numberofcursus
        }
        else if (tableView.tag == 2) {
            numberofskills = skillsarray.count
            return numberofskills
        }
        else {
            return 0
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        screenWidth = Int(UIScreen.main.bounds.size.width)
        screenHeight = Int(UIScreen.main.bounds.size.height)
        
        if (tableView.tag == 1){
          let cell = tableView.dequeueReusableCell(withIdentifier: cellidentifier, for: indexPath) as UITableViewCell
          cell.textLabel?.text = formation[indexPath.row]
          return cell
            
        } else if (tableView.tag == 2) {
          let cell = tableView.dequeueReusableCell(withIdentifier: cellidentifier, for: indexPath) as! CustomViewCell
            cell.SkillLevel?.text = skillsarray[indexPath.row].name
            cell.SkillLevelNumber?.text = String(skillsarray[indexPath.row].level)
            cell.LevelBar.setProgress( skillsarray[indexPath.row].level/20, animated: true)
        
            if UIDevice.current.orientation.isPortrait {
                cell.SkillLevel.frame = CGRect (x:10,y:20,width:198,height:21)
                cell.SkillLevelNumber.frame = CGRect (x: screenWidth - 75,y:20,width:55,height:21)
                let rec = CGRect(origin: CGPoint(x: 10,y :CGFloat(45)), size: CGSize(width: CGFloat(screenWidth-60), height: 2))
                cell.LevelBar.frame = rec
            } else if UIDevice.current.orientation.isLandscape {
                cell.SkillLevel.frame = CGRect (x:10,y:20,width:198,height:21)
                cell.SkillLevelNumber.frame = CGRect (x: screenWidth - 115,y:20,width:55,height:21)
                let rec = CGRect(origin: CGPoint(x: 10,y :CGFloat(45)), size: CGSize(width: CGFloat(screenWidth-90), height: 2))
                cell.LevelBar.frame = rec
            }
            return cell
        } else {
          let cell = tableView.dequeueReusableCell(withIdentifier: cellidentifier, for: indexPath) as UITableViewCell
         return cell
       }
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        if (tableView.tag == 1){
            
        formationref = formation[indexPath.row]
        }
        
        LevelViewLabel.text = formationref
        
        self.constructArray ()
        skills.reloadData()
    }
    
    func constructArray () {
        
        //print(cursusjson)
        skillsarray.removeAll()
        for a in cursusjson as [AnyObject] {
            var b = a as! [String:AnyObject]
            var c = b["cursus"] as! [String:AnyObject]
            let d = c["slug"] as! String
            if (d == formationref) {
                levelnum = b["level"] as! Float
                let decimalpart = levelnum .truncatingRemainder(dividingBy: 1.0)
                Level.setProgress(decimalpart, animated: true)
                //print(decimalpart)
                LevelViewLabel.text = "Level : " + String(levelnum)
                let e = b["skills"] as! [[String:AnyObject]]
                for f in e {
                        let j = f["name"] as! String
                        let level = f["level"] as! Float
                   //print(level)
                    let NewSkill = SkillUser(name : j, level : level)
                    //print (NewSkill)
                    skillsarray.append(NewSkill)
                    }
                }
        }
        
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func ButtonReturn () {
        
        
        ReturnButton.restorationIdentifier = "Return"
        ReturnButton.setTitle("Return", for: .normal)
        ReturnButton.setTitleColor(UIColor.black, for: .normal)
        ReturnButton.isEnabled = true
        ReturnButton.addTarget(self, action: #selector(Return(button:)), for: .touchUpInside)
        DispatchQueue.main.async {
            self.PositionButton()
        }
        self.view.addSubview(ReturnButton)
    }
    
    func PositionButton () {
    
        
        screenWidth = Int(UIScreen.main.bounds.size.width)
        screenHeight = Int(UIScreen.main.bounds.size.height)
        
        let xpos = (screenWidth)/2 - 35
        if UIDevice.current.orientation.isPortrait {
          ReturnButton.frame = CGRect (x:CGFloat(xpos),y:CGFloat(screenHeight - 80),width:70,height:30)
              }
        else {
          ReturnButton.frame = CGRect (x:CGFloat(xpos),y:CGFloat(screenHeight - 40),width:70,height:30)
        }
        
    }
    
    func PositionTableView () {
        
        
        screenWidth = Int(UIScreen.main.bounds.size.width)
        screenHeight = Int(UIScreen.main.bounds.size.height)
        
        
        if UIDevice.current.orientation.isPortrait {
            cursus.frame = CGRect (x:CGFloat(10),y:CGFloat(28),width:CGFloat(screenWidth-20),height: 100)
            skills.frame = CGRect (x:CGFloat(10),y:CGFloat(239),width:CGFloat(screenWidth-20),height: 380)
            let rect = CGRect(origin: CGPoint(x: 30,y :CGFloat(200)), size: CGSize(width: CGFloat(screenWidth-60), height: 2))
            Level.frame = rect
            LevelViewLabel.frame = CGRect (x:CGFloat(30),y:CGFloat(175),width:100,height: 21 )
        }
        else if UIDevice.current.orientation.isLandscape {
            cursus.frame = CGRect (x:CGFloat(30),y:CGFloat(10),width:CGFloat(screenWidth-60),height: CGFloat(screenHeight/4))
            skills.frame = CGRect (x:CGFloat(30),y:CGFloat(180),width:CGFloat(screenWidth-60),height: CGFloat(CGFloat(screenHeight)/CGFloat(2.50)))
            let rect = CGRect(origin: CGPoint(x: 40,y :CGFloat(screenHeight/4  + 60)), size: CGSize(width: screenWidth-80, height: 2))
            Level.frame = rect
            LevelViewLabel.frame = CGRect (x:CGFloat(40),y:CGFloat(screenHeight/4  + 35),width:100,height: 21 )
        }
        
    }
    
    func Return(button: UIButton) {
        
        performSegue(withIdentifier: "ReturnToProfil",  sender: self)
    }
    
    
    override func viewWillTransition(to size: CGSize, with coordinator:
        
        UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        DispatchQueue.main.async {
            self.PositionButton ()
        }
        DispatchQueue.main.async {
            self.PositionTableView ()
        }
        DispatchQueue.main.async {
          self.skills.reloadData()
        }
        
        
    }
    
    
}
