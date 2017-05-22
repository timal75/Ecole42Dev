//
//  Authentification.swift
//  testpagecontrol
//
//  Created by Jean-pierre BLANCHARD on 5/6/17.
//  Copyright © 2017 Jean-pierre BLANCHARD. All rights reserved.
//

import UIKit

var DisplayName = ""
var image_url = ""
var email = ""
var wallet = 0
var correction_point = 0
var phone = ""
var location = ""
var formation = [String]()
var projects = [String]()
var cursusjson:[AnyObject] = []
var jsonData:NSDictionary? = nil

class Authentification: NSObject {

    var token = String()
    let url_token = NSURL(string : "https://api.intra.42.fr/oauth/token")
    let url_check = NSURL(string : "https://api.intra.42.fr/oauth/token")
    let uid = "555e04f2bc6d2bf639e63ae7ffa862666991b347000e228db774c1d5582ffb77"
    let secret = "1213bac9c312575d4913ebfe657bb1a48e9c9afd9a9bb9e91955d78f5f5053de"
    
    func GetToken(completionHandler: @escaping (Bool, Int)-> ()) {
       
        let verif = UserDefaults.standard.object(forKey: "token")
        if verif == nil {
            
            let request = NSMutableURLRequest(url: url_token as! URL)
            request.httpMethod = "POST"
            request.setValue("application/x-www-form-urlencoded", forHTTPHeaderField: "Content-Type")
            request.setValue("application/json", forHTTPHeaderField: "Accept")
            let tokenStr = "grant_type=client_credentials&client_id="+uid+"&client_secret="+secret+""
            request.httpBody = tokenStr.data(using: String.Encoding.utf8)!
            
            let session = URLSession.shared
            let task = session.dataTask(with: request as URLRequest) { (data, response, error) in
              
                guard error == nil && data != nil else {
                    print("error=\(error)")
                    completionHandler(false,1)
                    return
                }
                if let httpStatus = response as? HTTPURLResponse, httpStatus.statusCode != 200 {
                    print("statusCode should be 200, but is \(httpStatus.statusCode)")
                    completionHandler(false, httpStatus.statusCode)
                    return
                }
                do {
                    if let jsonDic: NSDictionary = try JSONSerialization.jsonObject(with: data!, options: JSONSerialization.ReadingOptions()) as? NSDictionary {
                        if let access_token = jsonDic["access_token"] as? String {
                            self.token = access_token
                            print(self.token)
                            UserDefaults.standard.set(self.token, forKey: "token")
                            self.GetData (completionHandler: { (hasSucceed,coderetour) in
                                if hasSucceed {
                                    completionHandler(true, 0)
                                } else {
                                    completionHandler(false,coderetour)
                                }
                            })
                        }
                    }
                } catch {
                    print(error)
                    completionHandler(false, 1)
                }
            }
            task.resume()
        }
        else {
                self.token = verif as! String
                print("SAME token:", self.token)
                CheckToken(completionHandler: { (hasSucceed, coderetour) in
                if hasSucceed {
                    completionHandler(true,0)
                } else {
                    completionHandler(false, coderetour)
                }
            })
        }
    
    }
    
    fileprivate func CheckToken(completionHandler: @escaping (Bool, Int) -> ()) {
        
        //self.token = "ba6498527b0aa3550b1a5af3df48a708c3486ad53932c0fe9af62bc0e83b6bbe"
        let request = NSMutableURLRequest(url: NSURL(string: "https://api.intra.42.fr/oauth/token/info" + "?access_token=" + token)! as URL)
        request.httpMethod = "GET"
        
        let session = URLSession.shared
        let task = session.dataTask(with: request as URLRequest) { (data, response, error) in
        
            guard error == nil && data != nil else {
                print("error=\(error)")
                completionHandler(false,1)
                return
            }
            if let httpStatus = response as? HTTPURLResponse, httpStatus.statusCode == 401 {
                print("Error: Trying to get a new token...")
                UserDefaults.standard.removeObject(forKey: "token")
                self.GetToken(completionHandler: { (hasSucceed, coderetour) in
                    if hasSucceed {
                        print("Get Token has succeeded")
                        completionHandler(true,0)
                    } else {
                        print("Get Token has failed")
                        completionHandler(false,coderetour)
                    }
                })
            } else
            if let httpStatus = response as? HTTPURLResponse, httpStatus.statusCode != 200 {
                  print("statusCode should be 200, but is \(httpStatus.statusCode)")
                  completionHandler(false, httpStatus.statusCode)
                  return
            } else {
            do {
                print("begining do")
                if let jsonDic: NSDictionary = try JSONSerialization.jsonObject(with: data!, options: JSONSerialization.ReadingOptions()) as? NSDictionary {
                    print("The token will expire in:", jsonDic["expires_in_seconds"]!, "seconds.")
                    self.GetData (completionHandler: { (hasSucceed, coderetour) in
                        if hasSucceed {
                            completionHandler(true,0)
                        } else {
                            completionHandler(false, coderetour)
                        }
                    })
                }
            } catch {
                completionHandler(false, 2)
                print(error)
            }
         }
        }
        task.resume()
    }
    
    fileprivate func GetData(completionHandler: @escaping (Bool, Int) -> ()) {
     
        let request = NSMutableURLRequest(url: NSURL(string: "https://api.intra.42.fr/v2/users/" + login + "?access_token=" + token)! as URL)
        request.httpMethod = "GET"
        
        let session = URLSession.shared
        let task = session.dataTask(with: request as URLRequest ) { (data, response, error) in
            
            guard error == nil && data != nil else {
                print("error=\(error)")
                completionHandler(false,1)
                return
            }
            if let httpStatus = response as? HTTPURLResponse, httpStatus.statusCode == 404 {
                print("Error: Login incorrect...")
                completionHandler(false, 404)
            } else
                if let httpStatus = response as? HTTPURLResponse, httpStatus.statusCode != 200 {
                    print("statusCode ds getdata should be 200, but is \(httpStatus.statusCode)")
                    completionHandler(false,httpStatus.statusCode )
                    return
                } else {
            do {
                if let jsonDic: NSDictionary = try JSONSerialization.jsonObject(with: data!, options: JSONSerialization.ReadingOptions()) as? NSDictionary {
                    //print(jsonDic)
                    jsonData = jsonDic
                    if (jsonDic["displayname"] as? String) != nil {
                       DisplayName = (jsonDic["displayname"] as? String)!
                    } else {
                       DisplayName = "Unknown"
                    }
                    print ("DisplayName : \(DisplayName)")
                    if (jsonDic["email"] as? String!) != nil {
                      email = (jsonDic["email"] as? String!)!
                    } else {
                       email = "Unknown"
                    }
                    print ("email : \(email)")
                    if (jsonDic["image_url"] as? String) != nil {
                      image_url = (jsonDic["image_url"] as? String)!
                    } else {
                      image_url = "Unknown"
                    }
                    print ("image_url : \(image_url)")
                    if (jsonDic["wallet"] as? Int) != nil {
                        wallet = (jsonDic["wallet"] as? Int)!
                    } else {
                        wallet = -500
                    }
                        print ("wallet : \(wallet)")
                    if (jsonDic["correction_point"] as? Int) != nil {
                        correction_point = (jsonDic["correction_point"] as? Int)!
                    } else {
                        correction_point = -500
                    }
                    print ("correction_point : \(correction_point)")
                    if ((jsonDic["phone"] as? String)) != nil {
                        phone = ((jsonDic["phone"] as? String))!
                    }
                    else {
                        phone = ""
                    }
                    print ("phone : \(phone)")
                    if (jsonDic["location"] as? String) != nil {
                       location = ((jsonDic["location"] as? String))!
                    } else {
                       location = "Absent"
                    }
                    print ("location : \(location)")
                    formation.removeAll()
                    cursusjson = (jsonDic["cursus_users"] as? [AnyObject])!
                        //print (cursusjson)
                    for x in cursusjson {
                          let z = x["cursus"] as! [String:AnyObject]
                          let j = z["slug"] as! String
                           formation.append(j)
                        }
                    print (formation)
                    completionHandler(true, 0)
                }
                
            } catch {
                print(error)
                completionHandler(false, 3)
                return
            }
        } }
        task.resume()
        
        
    }
}
