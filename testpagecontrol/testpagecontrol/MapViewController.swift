//
//  FirstViewController.swift
//  testpagecontrol
//
//  Created by Jean-pierre BLANCHARD on 4/26/17.
//  Copyright © 2017 Jean-pierre BLANCHARD. All rights reserved.
//



import UIKit
import MapKit
import CoreLocation

class MapViewController: UIViewController {
    
    @IBOutlet weak var ReturnButton: UIButton!
    @IBOutlet weak var Map: MKMapView!
    var CampusAddress:String = ""
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        SetMapWidth ()
        ButtonReturn()
        FindCampusAddress ()
        
        CLGeocoder().geocodeAddressString(CampusAddress, completionHandler: { (placemarks, error) -> Void in
            if error != nil {
                print(error!)
                return
            }
            if placemarks!.count > 0 {
                let placemark = placemarks?[0]
                let location = placemark?.location
                let coordinates = location?.coordinate
                print ((coordinates?.latitude)!)
                print ((coordinates?.longitude)!)
                let Location = CLLocationCoordinate2DMake((coordinates?.latitude)!,(coordinates?.longitude)!)
                
                let span =  MKCoordinateSpanMake(0.5, 0.5)
                let region = MKCoordinateRegion(center: Location, span: span)
                self.Map.setRegion(region, animated: true)
                
                let annotation = MKPointAnnotation()
                annotation.coordinate = Location
                annotation.title = "Ecole 42"
                annotation.subtitle = self.CampusAddress
                
                self.Map.addAnnotation(annotation)
            }
        })
        
        
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
        DispatchQueue.main.async {
            self.PositionButton ()
        }
        DispatchQueue.main.async {
            self.SetMapWidth ()
        }
        
    }
    
    func FindCampusAddress () {
        
        var maincampusid:Int = -1
        let campus_users = (jsonData?["campus_users"] as? [AnyObject])
        for campususers in campus_users! {
            let campus_id = campususers["campus_id"] as! Int
            print(campus_id)
            let isprimary = campususers["is_primary"] as! Bool
            print(isprimary)
            if (isprimary){
                maincampusid = campus_id
            }
        }
        print(maincampusid)
        let campus = (jsonData?["campus"] as? [AnyObject])
        for varcampus in campus! {
            let id = varcampus["id"] as! Int
            print(id)
            if (id == maincampusid) {
                CampusAddress = varcampus["name"] as! String
            }
            print(CampusAddress)
        }
    }
    
    func SetMapWidth () {
        
        screenWidth = Int(UIScreen.main.bounds.size.width)
        screenHeight = Int(UIScreen.main.bounds.size.height)
        
        Map.frame = CGRect (x:0,y:0,width:screenWidth,height:screenHeight-80)
        
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
    
    func Return(button: UIButton) {
        
        performSegue(withIdentifier: "ReturnToProfile",  sender: self)
    }
    
    
}
