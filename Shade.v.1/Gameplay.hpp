//
//  Gameplay.hpp
//  Shade
//
//  Created by jajabarr on 3/19/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#ifndef Gameplay_hpp
#define Gameplay_hpp

#include <stdio.h>
#include <fstream>
#include "World.hpp"
#include "Support.hpp"
#include "ShadeDevelop.hpp"
#include "BeastDevelop.hpp"



void defaultWorld(World& world);
void caveWorld(World& world);
void movePlayer(World& world);
void newScreen();
void endTitle();
int checkDiff(World world);











#endif /* Gameplay_hpp */
