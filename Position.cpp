//
//  Position.cpp
//  Shade
//
//  Created by jajabarr on 3/18/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#include "Position.hpp"


Position::Position() {
    
    x = 0;
    y = 0;
}

Position::Position(int posX, int posY) {
    
    x = checkPosX(posX);
    y = checkPosY(posY);
    
}

int Position::checkPosX(int pos) {
    
    if (pos >= WORLD_SIZE_X - 1) {
        
        return WORLD_SIZE_X - 1;
        
    } else if (pos < 0) {
        
        return 0;
    }
    
    return pos;
}

int Position::checkPosY(int pos) {
    
    if (pos >= WORLD_SIZE_Y - 1) {
        
        return WORLD_SIZE_Y - 1;
        
    } else if (pos < 0) {
        
        return 0;
    }
    
    return pos;
}


void Position::setX(int posX) {
    
    x = checkPosX(posX);
}

int Position::getX() {
    
    return x;
}

void Position::setY(int posY) {
    
    y = checkPosY(posY);
}

int Position::getY() {
    
    return y;
}

void Position::setDefaultPlayer() {
    
    x = CENTER_POS_X;
    y = CENTER_POS_Y;
}

void Position::moveRight() {
    
    x++;
    
    x = checkPosX(x);
}

void Position::moveLeft() {
    
    x--;
    
    x = checkPosX(x);
}

void Position::moveUp() {
    
    y--;
    
    y = checkPosY(y);
}

void Position::moveDown() {
    
    y++;
    
    y = checkPosY(y);
}

double Position::getDistance(Position position) {
    

    return sqrt(pow((position.getX() - x), 2) +
                pow((2 * (position.getY() - y)), 2));
    
}

char Position::closeDistance(Position position) {
    
    Position moveUp = position;
    Position moveDown = position;
    Position moveLeft = position;
    Position moveRight = position;
    
    moveUp.moveUp();
    moveDown.moveDown();
    moveLeft.moveLeft();
    moveRight.moveRight();
    
    int index = 0;
    
    char direction = ' ';
    
    double checkDist[] = {getDistance(moveUp), getDistance(moveDown),
                           getDistance(moveLeft), getDistance(moveRight)};
    
    index = findMin(DIRECTIONS_CNT, checkDist);
    
    if (index == 0) {
        
        direction = MOVE_UP;
        
    } else if (index == 1) {
        
        direction = MOVE_DOWN;
        
    } else if (index == 2) {
        
        direction = MOVE_LEFT;
        
    } else {
        
        direction = MOVE_RIGHT;
    }
        
    
    return direction;
    
}

void Position::setCenter() {
    
    x = CENTER_POS_X;
    y = CENTER_POS_Y;
}

void Position::load(istream &ins) {
    
    ins >> x >> y;
    
}

void Position::save(ostream &outs) {
    
    outs << x << " "  << y;
}

istream& operator >> (istream& ins, Position& position) {
    
    position.load(ins);
    
    return ins;
}
ostream& operator << (ostream& outs, Position position) {
    
    position.save(outs);
    
    return outs;
}

