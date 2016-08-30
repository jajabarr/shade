//
//  Beast.cpp
//  Shade
//
//  Created by jajabarr on 3/18/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#include "Beast.hpp"

Beast::Beast() {
    
    beastDamage = 1;
    beastID = 0;
}

void Beast::setBeastDamage(int dmg) {
    
    beastDamage = dmg;
    
}

int Beast::getBeastDamage() {
    
    return beastDamage;
    
}

void Beast::addBeastDamage() {
    
    beastDamage++;
}

void Beast::setBeastID(int id) {
    
    beastID = id;
    
}

int Beast::getBeastID() {
    
    return beastID;
}
