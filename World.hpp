//
//  World.hpp
//  Shade
//
//  Created by jajabarr on 3/18/16.
//  Copyright © 2016 jajabarr. All rights reserved.
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
    void setPlayer(Player player1);
    
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
    
    void setPlayerCave (bool caveTruth);
    void setCaveCoord (int posX, int posY);
    Position getCaveCoord();
    void deleteCave();
    
    bool getPlayerHit();
    void setPlayerHit(bool isPlayeHit);
    
    void endGame();
    
    
    
    
private:
    
    Object world[WORLD_SIZE_Y][WORLD_SIZE_X];
    Player player;
    Position center;
    Position radPoint;
    Position caveCoord;
    double radius;
    int numBeasts;
    bool playerHit;
    int x;
    int y;
};

istream& operator >> (istream& ins, World& world);
ostream& operator << (ostream& outs, World world);





#endif /* World_hpp */
