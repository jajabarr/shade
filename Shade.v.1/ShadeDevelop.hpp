//
//  ShadeDevelop.hpp
//  Shade
//
//  Created by jajabarr on 3/19/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#ifndef ShadeDevelope_hpp
#define ShadeDevelope_hpp

#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "Support.hpp"
#include "World.hpp"
#include "Object.hpp"

void normalDevelopment(World shade);
void checkBorder(World& world, int& posX, int& posY, int difficulty, int devType);
bool checkTop(World world, int& posX, int& posY, int x, int y, int devType);
bool checkBottom(World world, int& posX, int& posY, int x, int y, int devType);
bool checkLeft(World world, int& posX, int& posY, int x, int y, int devType);
bool checkRight(World world, int& posX, int& posY, int x, int y, int devType);

void circularDevelopment(World shade);
bool checkCirc(World world, int& posX, int& posY);

void checkCircBorder(World& world, int& posX, int& posY, int difficulty);

bool checkRad(World world, Position position);
void assignShade(World& world, int assignments, int difficulty, int devType);
bool checkAssignShade(int difficulty);

void addShade(World& world);








#endif /* ShadeDevelop_hpp */
