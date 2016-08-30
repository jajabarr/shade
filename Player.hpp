//
//  Player.hpp
//  Shade
//
//  Created by jajabarr on 3/18/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include "Support.hpp"

using namespace std;


class Player {
    
private:
    
    int playerHealth;
    int playerSteps;
    string playerName;
    Position playerCoord;
    bool inCave;
    int caveVisits;
    
    
public:
    
    Player();
    
    void printPlayer();
    
    void setPlayerHealth(int hp);
    int getPlayerHealth();
    
    void setPlayerSteps(int steps);
    int getPlayerSteps();
    
    void setPlayerName(string name);
    string getPlayerName();
    
    void setPlayerCoord(int posX, int posY);
    void setPlayerCoord(Position position);
    Position& getPlayerCoord();
    
    void addStep();
    void addHealth();
    void decreaseHealth();
    void killPlayer();
    void playerFullHealth();
    
    bool getCavePos();
    void setCave(bool caveman);
    
    int getNumVisits();
    void setNumVisits(int numVisits);
    void addVisit();
    
    
    
    
    
    
};




#endif /* Player_hpp */
