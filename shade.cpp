//
//  main.cpp
//  Shade
//
//  Created by Jacob Barr on 3/18/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "World.hpp"
#include "Gameplay.hpp"
#include "ShadeDevelop.hpp"
#include "Support.hpp"

int main() {
    
    World shade;
    World cave;
    Position playerPos;
    
    
    defaultWorld(shade);
    circularDevelopment(shade);
    
    caveWorld(cave);
    
    addShade(shade);
    
    cave.displayWorld();
    
    cout << endl << endl;
    
    while (shade.getPlayer().getPlayerHealth() > 0) {
       
        movePlayer(shade);
        assignShade(shade, 1, SHADE_DIFFICULTY, CIRC_DEVELOP);
        assignBeast(shade, CIRC_DEVELOP);
        shade.displayWorld();
    }
    
    
        
   
    
    
    
    
  
    
    
    
    
   
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
