//
//  BeastDevelop.hpp
//  Shade
//
//  Created by prog on 4/27/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#ifndef BeastDevelop_hpp
#define BeastDevelop_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Support.hpp"
#include "World.hpp"
#include "Object.hpp"
#include "ShadeDevelop.hpp"

void assignBeast(World& world, int devType);
void moveBeasts(World& world);
bool checkBeasts(Object beasts[], int size, Object test);


#endif /* BeastDevelop_hpp */
