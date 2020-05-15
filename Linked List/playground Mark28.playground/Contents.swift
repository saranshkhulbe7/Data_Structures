import UIKit

struct Town {
    let name : String
    var citizens : [String]
    var resources : [String : Int]
    
    init(name: String, citizens: [String], resources: [String : Int]) {
        self.name = name
        self.citizens = citizens
        self.resources = resources
    }
    
    func fortify() {
        print("\(name)'s Defences Increased !")
    }
}

var town1 = Town(name: "towny", citizens: ["Saransh"] , resources: ["weed" : 1000])

