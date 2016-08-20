//
//  Position.hpp
//  Shade
//
//  Created by Jacob Barr on 3/18/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#ifndef Position_hpp
#define Position_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include "Support.hpp"

using namespace std;

class Position {
    
private:
    int x;
    int y;
    
public:
    
    Position();
    Position(int posX, int posY);
    
    void setX(int posX);
    int getX();
    
    void setY(int posY);
    int getY();
    
    void setDefaultPlayer();
    
    int checkPosX(int pos);
    int checkPosY(int pos);
    
    void moveRight();
    void moveUp();
    void moveLeft();
    void moveDown();
    
    void load(istream& ins);
    void save(ostream& outs);
    
    double getDistance(Position position);
    char closeDistance(Position position);
    
    void setCenter();
};

istream& operator >> (istream& ins, Position& position);
ostream& operator << (ostream& outs, Position position);

#endif /* Position_hpp */
