//
//  Beast.hpp
//  Shade
//
//  Created by jajabarr on 3/18/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#ifndef Beast_hpp
#define Beast_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Beast {
    
private:
    
    int beastDamage;
    int beastID;
    bool smartBeast;
    
public:
    
    Beast();

    void setBeastDamage(int dmg);
    int getBeastDamage();
    
    void addBeastDamage();
    
    void setBeastID(int id);
    int getBeastID();
    
    void setSmartBeast(bool smart);
    bool getSmartBeast();
    
    
};

#endif /* Beast_hpp */
