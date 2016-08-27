//
//  World.hpp
//  Shade
//
//  Created by Jacob Barr on 3/18/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#ifndef World_hpp
#define World_hpp

#include <stdio.h>
#include <iostream>
#include "Object.hpp"
#include "Support.hpp"


using namespace std;

class World {
    
public:
    
    World();
    void load(istream& ins);
    void save(ostream& outs);
    void insert(Object object, int xPos, int yPos);
    void deleteWorld();
    void displayWorld();
    void displayPoint(int posX, int posY);
    Object peak(int posX, int posY);
    Player& getPlayer();
    void setPlayer(Player player1I );
    
    void setRadius(double newRadius);
    double getRadius();
    
    void setRadPoint(Position newRadPoint);
    Position getRadPoint();
    
    void trimRadPoint();
    
    double checkRadius(double newRadius);
    
    Position getCenter();
    
    bool isEmpty(int posX, int posY);
    
    void moveObject(Object& object, char direction);
    
    void setNumBeasts(int num);
    void addBeast();
    int getNumBeasts();
    
    
    
private:
    
    Object world[WORLD_SIZE_Y][WORLD_SIZE_X];
    Player player;
    Position center;
    Position radPoint;
    double radius;
    int numBeasts;
    int x;
    int y;
};

istream& operator >> (istream& ins, World& world);
ostream& operator << (ostream& outs, World world);





#endif /* World_hpp */
