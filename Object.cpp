//
//  Object.cpp
//  Shade
//
//  Created by Jacob Barr on 3/18/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "Object.hpp"

Object::Object() {
    
    objectType = ' ';
    damage = 0;
    
}

Object::Object(char type) {
    
    createObject(type);
    
}

void Object::setType(char type) {
    
    createObject(type);
    
}

char Object::getType() {
    
    return objectType;
}

void Object::createObject(char type) {
    
    if (type == PLAYER) {
        
        objectType = PLAYER;
        playerFullHealth();
        setCenter();
        
        damage = 0;
        
    } else if (type == BEAST) {
        
        objectType = BEAST;
        damage = getBeastDamage();
        
    } else if (type == DARK) {
        
        objectType = DARK;
        damage = getDark();
    
    } else if (type == CAVE) {
        
        objectType = CAVE;
        damage = getCave();
    
    } else if (type == WIZARD) {
        
        objectType = WIZARD;
        damage = getWiz();
    }
}

void Object::setObject(istream& ins) {
    
    int health;
    int steps;
    int x;
    int y;
    int id;
    string name;
    
    ins >> objectType;
    
    if (objectType == PLAYER) {
        
        ins >> name >> health >> steps >> x >> y;
        
        setPlayerName(name);
        setPlayerHealth(health);
        setPlayerSteps(steps);
        
        setPlayerCoord(x, y);
        
        setX(x);
        setY(y);
        
        
        damage = 0;
        
    } else if (objectType == BEAST) {
        
        ins >> damage >> id >> x >> y;
        
        setX(x);
        setY(y);
        setBeastID(id);
        
    } else if (objectType == DARK) {
        
        ins >> x >> y;
        
        damage = getDark();
        
        setX(x);
        setY(y);
        
    } else if (objectType == WIZARD) {
        
        ins >> x >> y;
        
        damage = getWiz();
        
        setX(x);
        setY(y);
    
    } else if (objectType == CAVE) {
        
        ins >> x >> y;
        
        damage = getCave();
        
        setX(x);
        setY(y);
    }
    
}

void Object::getObject(ostream& outs) {
    
    char space = ' ';
    
    outs << objectType << space;
    
    if (objectType == PLAYER) {
        
        outs << getPlayerName() << space << getPlayerHealth() << space;
        outs << getPlayerSteps() << space << getX() << space << getY();
        
    } else if (objectType == BEAST) {
        
        outs << damage << space << getBeastID() << getX() << space << getY();
        
    } else if (objectType == DARK) {
        
        outs << getX() << space << getY();
        
    } else if (objectType == CAVE) {
        
        outs << getX() << space << getY();
        
    } else if (objectType == WIZARD) {
        
        outs << getX() << space << getY();
    }
}

istream& operator >> (istream& ins, Object& object) {
    
    object.setObject(ins);
    
    return ins;
}

ostream& operator << (ostream& outs, Object object) {
    
    object.getObject(outs);
    
    return outs;
}


