//
//  Object.hpp
//  Shade
//
//  Created by jajabarr on 3/18/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <iostream>
#include "Support.hpp"
#include "Player.hpp"
#include "Beast.hpp"
#include "Dark.hpp"
#include "Cave.hpp"
#include "Wizard.hpp"
#include "Position.hpp"

using namespace std;

class Object : public Player, public Beast, public Dark, public Cave, public Wizard, public Position {
    
public:
    
    Object();
    Object(char type);
    void setType(char type);
    char getType();
    void createObject(char type);
    void setObject(istream& ins);
    void getObject(ostream& outs);
    
private:
    
    
    char objectType;
    int damage;
    
    
};

istream& operator >> (istream& ins, Object& object);
ostream& operator << (ostream& outs, Object object);

#endif /* Object_hpp */
