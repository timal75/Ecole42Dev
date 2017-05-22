//
//  FirstViewController.swift
//  testpagecontrol
//
//  Created by Jean-pierre BLANCHARD on 4/26/17.
//  Copyright © 2017 Jean-pierre BLANCHARD. All rights reserved.
//



import UIKit

var Projectsarray : [String] = []

class CustomProjectCell: UITableViewCell {
    
    @IBOutlet weak var ImageOK: UIImageView!
    
    @IBOutlet weak var ProjectNameLabel: UILabel!
    @IBOutlet weak var GradeLabel: UILabel!
}

class ProjectsViewController: UIViewController,UITableViewDelegate, UITableViewDataSource {


    
    @IBOutlet weak var ReturnButton: UIButton!
        
    @IBOutlet weak var Projects: UITableView!
    //var pojectreference : ProjectUser
    let cellidentifier : String = "cell"
    
    var numberofprojects : Int = 0
    var projects : [ProjectUser] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.constructArray ()
        Projects.delegate = self
        Projects.dataSource = self
        
        DispatchQueue.main.async {
            self.ButtonReturn ()
        }
        DispatchQueue.main.async {
            self.PositionTableView ()
        }
        
        
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        if (tableView.tag == 1) {
            numberofprojects = projects.count
            return numberofprojects
        }
        else {
            return 0
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        screenWidth = Int(UIScreen.main.bounds.size.width)
        screenHeight = Int(UIScreen.main.bounds.size.height)
        
        print(UIDeviceOrientation.self)
        
        let cell = tableView.dequeueReusableCell(withIdentifier: cellidentifier, for: indexPath) as! CustomProjectCell
        
        if (tableView.tag == 1) {
            cell.ProjectNameLabel.text = projects[indexPath.row].name
            if projects[indexPath.row].grade != nil {
              cell.GradeLabel.text = String(describing: projects[indexPath.row].grade!) + "%"
            } else {
              cell.GradeLabel.text = projects[indexPath.row].status
            }
            cell.ImageOK.isHidden = true
            if (projects[indexPath.row].validated != nil) {
                if (projects[indexPath.row].validated)! {
                  cell.ImageOK.isHidden = false
                }
            }
            if UIDevice.current.orientation.isPortrait {
                cell.ProjectNameLabel.frame = CGRect (x:10,y:25,width:245,height:21)
                cell.GradeLabel.frame = CGRect (x: screenWidth - 155,y:25,width:125,height:21)
//                let rec = CGRect(origin: CGPoint(x: 10,y :CGFloat(45)), size: CGSize(width: CGFloat(screenWidth-60), height: 2))
                cell.ImageOK.frame = CGRect (x: screenWidth - 45,y:5,width:15,height:15)
            } else if UIDevice.current.orientation.isLandscape {
                cell.ProjectNameLabel.frame = CGRect (x:10,y:25,width:245,height:21)
                cell.GradeLabel.frame = CGRect (x: screenWidth - 155,y:25,width:125,height:21)
//                let rec = CGRect(origin: CGPoint(x: 10,y :CGFloat(45)), size: CGSize(width: CGFloat(screenWidth-90), height: 2))
                cell.ImageOK.frame = CGRect (x: screenWidth - 45,y:5,width:15,height:15)
            }
        }
        else {
            
        }
        return cell
    }
    
    
    func constructArray () {
        
        Projectsarray.removeAll()
        let ProjectInfo = (jsonData?["projects_users"] as? [AnyObject])
        for eachprojectinfo in ProjectInfo! {
            let grade = eachprojectinfo["final_mark"] as? Int
            let status = eachprojectinfo["status"] as? String
            let isvalidated = eachprojectinfo["validated?"] as? Bool
            let project = eachprojectinfo["project"] as! [String:AnyObject]
            let projectname = project["slug"] as! String
            print(projectname)
            let NewProjet = ProjectUser(name: projectname, grade : grade, status: status!, validated : isvalidated)
            projects.append(NewProjet)
            Projectsarray.append(projectname)
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
            self.PositionButton ()
        }
        
        self.view.addSubview(ReturnButton)
    }
    
    func PositionButton () {
        
        
        screenWidth = Int(UIScreen.main.bounds.size.width)
        screenHeight = Int(UIScreen.main.bounds.size.height)
        
        let xpos = (screenWidth)/2 - 35
        if UIDevice.current.orientation.isPortrait {
            ReturnButton.frame = CGRect (x:CGFloat(xpos),y:CGFloat(screenHeight - 40),width:70,height:30)
        }
        else {
            ReturnButton.frame = CGRect (x:CGFloat(xpos),y:CGFloat(screenHeight - 40),width:70,height:30)
        }
        
    }
    
    func PositionTableView () {
        
        
        screenWidth = Int(UIScreen.main.bounds.size.width)
        screenHeight = Int(UIScreen.main.bounds.size.height)
        
        
        if UIDevice.current.orientation.isPortrait {
            Projects.frame = CGRect (x:CGFloat(10),y:CGFloat(20),width:CGFloat(screenWidth - 20),height: CGFloat(screenHeight - 80))
        }
        else {
            
            Projects.frame = CGRect (x:CGFloat(10),y:CGFloat(10),width:CGFloat(screenWidth - 20),height: CGFloat(screenHeight - 80))
        }
        
    }
    
    func Return(button: UIButton) {
        
        performSegue(withIdentifier: "ReturnFromProjects",  sender: self)
    }
    
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        DispatchQueue.main.async {
            self.PositionButton ()
        }
        DispatchQueue.main.async {
            self.PositionTableView ()
        }
        DispatchQueue.main.async {
            self.Projects.reloadData()
        }
    }
    
    
}
