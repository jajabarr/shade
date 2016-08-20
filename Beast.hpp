//
//  Beast.hpp
//  Shade
//
//  Created by Jacob Barr on 3/18/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
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
    
public:
    
    Beast();

    void setBeastDamage(int dmg);
    int getBeastDamage();
    
    void addBeastDamage();
    
    void setBeastID(int id);
    int getBeastID();
    
    
};

#endif /* Beast_hpp */
