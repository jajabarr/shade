//
//  World.cpp
//  Shade
//
//  Created by Jacob Barr on 3/18/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "World.hpp"

World::World() {
    
    x = 0;
    y = 0;
    numBeasts = 0;
    
    center.setCenter();
    radPoint.setX(RAD_X);
    radPoint.setY(RAD_Y);
    
    radius = radPoint.getDistance(center);
    
}

void World::setNumBeasts(int num) {
    
    numBeasts = num;
    
}

void World::addBeast() {
    
    numBeasts++;
}

int World::getNumBeasts() {
    
    return numBeasts;
}


void World::setRadius(double newRadius) {
    
    radius = checkRadius(newRadius);
}

double World::getRadius() {
    
    return radius;
}

void World::setRadPoint(Position newRadPoint) {
    
    newRadPoint.setX(newRadPoint.checkPosX(newRadPoint.getX()));
    newRadPoint.setY(newRadPoint.checkPosY(newRadPoint.getY()));
    
    if (newRadPoint.getX() > CENTER_POS_X) {
        
        newRadPoint.setX(CENTER_POS_X);
        
    }
    
    if (newRadPoint.getY() > CENTER_POS_Y) {
        
        newRadPoint.setY(CENTER_POS_Y);
    }
    
    
    
    radPoint = newRadPoint;
}

Position World::getRadPoint() {
    
    return radPoint;
}

void World::trimRadPoint() {
    
    radPoint.setY(radPoint.getY() + 1);
    
    if (radPoint.getX() > CENTER_POS_X) {
        
        radPoint.setX(CENTER_POS_X);
        
    }
    
    if (radPoint.getY() > CENTER_POS_Y) {
        
        radPoint.setY(CENTER_POS_Y);
    }

    
    
}

Position World::getCenter() {
    
    return center;
}

void World::moveObject(Object& object, char direction) {
    
    Object blank;
    Object temp = peak(object.getX(), object.getY());
    Object future;
    Object shade(DARK);
    
    switch (direction) {
        case MOVE_UP:
            future = peak(object.getX(), object.getY() - 1);
            object.moveUp();
            
            if (object.getType() == PLAYER) {
                object.getPlayerCoord().moveUp();
            }
            
            break;
        case MOVE_DOWN:
            future = peak(object.getX(), object.getY() + 1);
            object.moveDown();
            
            if (object.getType() == PLAYER) {
                object.getPlayerCoord().moveDown();
            }
            
            break;
        case MOVE_RIGHT:
            future = peak(object.getX() + 1, object.getY());
            object.moveRight();
            
            if (object.getType() == PLAYER) {
                object.getPlayerCoord().moveRight();
            }
            
            break;
        default:
            future = peak(object.getX() - 1, object.getY());
            object.moveLeft();
            
            if (object.getType() == PLAYER) {
                object.getPlayerCoord().moveLeft();
            }
            
            break;
    }
    
    if ((future.getType() == BEAST) && (object.getType() == BEAST)) {
        
        if (future.getBeastDamage() > object.getBeastDamage()) {
            
            insert(blank, temp.getX(), temp.getY());
            
        } else {
            
            insert(object, object.getX(), object.getY());
            insert(blank, temp.getX(), temp.getY());
        }
        
    } else if ((future.getType() == BEAST) && (object.getType() == PLAYER)) {
        
        object.setPlayerHealth(player.getPlayerHealth());
        object.setPlayerHealth(object.getPlayerHealth() -
                               future.getBeastDamage());
        
        player.setPlayerHealth(object.getPlayerHealth());
        
        player.setPlayerCoord(object.getX(), object.getY());
        player.setPlayerName(object.getPlayerName());
        player.addStep();
        object.addStep();
        
        if (object.getPlayerHealth() <= 0) {
            
            insert(blank, temp.getX(), temp.getY());
            
        } else {

            insert(object, object.getX(), object.getY());
            insert(blank, temp.getX(), temp.getY());
            
        }
        
    } else if ((future.getType() == PLAYER) && (object.getType() == BEAST)) {
        
        future.setPlayerHealth(player.getPlayerHealth());
        future.setPlayerHealth(future.getPlayerHealth() -
                               object.getBeastDamage());
        
        player.setPlayerHealth(future.getPlayerHealth());
        
        
        if (future.getPlayerHealth() <= 0) {
            
            insert(object, object.getX(), object.getY());
            insert(blank, temp.getX(), temp.getY());
        }
        
    } else if ((future.getType() == EMPTY) && (object.getType() == PLAYER)) {
        
        player.setPlayerCoord(object.getX(), object.getY());
        object.setPlayerHealth(player.getPlayerHealth());
        player.setPlayerHealth(object.getPlayerHealth());
        player.setPlayerName(object.getPlayerName());
        player.addStep();
        object.addStep();
        
        insert(object, object.getX(), object.getY());
        insert(blank, temp.getX(), temp.getY());

    } else if ((future.getType() == EMPTY) && (object.getType() == BEAST)) {
        
        insert(object, object.getX(), object.getY());
        insert(blank, temp.getX(), temp.getY());
        
    } else if (future.getType() == DARK) {
        
        insert(shade, temp.getX(), temp.getY());
        
        if (object.getType() == PLAYER) {
            player.killPlayer();
        }
    }
    
}

void World::load(istream& ins) {
    
    Object temp[WORLD_SIZE_Y][WORLD_SIZE_X];
    
    for (int i = 0; i < WORLD_SIZE_Y; i++) {
        
        for (int j = 0; j < WORLD_SIZE_X; j++) {
            
            ins >> temp[i][j];
            
            if (temp[i][j].getType() == PLAYER) {
                
                player = temp[i][j];
            }
            
            x = temp[i][j].getX();
            y = temp[i][j].getY();
            
            if (world[y][x].getType() == ' ') {
                
                world[y][x] = temp[i][j];
            }
            
        }
    }
    
    if (ins.fail()) {
        
        ins.clear();
        
        string eatStr;
        
        ins >> eatStr >> radius >> eatStr >> radPoint;
        
    }
    
}

void World::save(ostream &outs) {
    
    
    
    for (int i = 0; i < WORLD_SIZE_Y; i++) {
        
        for (int j = 0; j < WORLD_SIZE_X; j++) {
            
            outs << world[i][j];
            outs << endl;
        }
    }
    
    outs << RAD_STRING << radius << endl;
    outs << RAD_POINT << radPoint;
}

void World::insert(Object object, int xPos, int yPos) {
    
    world[yPos][xPos] = object;
    
}

Object World::peak(int posX, int posY) {
    
    return world[posY][posX];
}

Player& World::getPlayer() {
    
    return player;
}

void World::setPlayer(Player player1) {
    
    player.setPlayerName(player1.getPlayerName());
    player.setPlayerHealth(player1.getPlayerHealth());
    player.setPlayerSteps(player1.getPlayerSteps());
    
}

void World::deleteWorld() {
    
    Object newWorld;
    
    for (int i = 0; i < WORLD_SIZE_Y; i++) {
        
        for (int j = 0; j < WORLD_SIZE_X; j++) {
            
            world[i][j] = newWorld;
        }
    }
}

void World::displayWorld() {
    
    player.printPlayer();
    
    for (int i = 0; i < WORLD_SIZE_Y; i++) {
        
        for (int j = 0; j < WORLD_SIZE_X; j++) {
            
            cout << world[i][j].getType();
        }
        
        cout << endl;
    }
}

void World::displayPoint(int posX, int posY) {
    
    cout << world[posY][posX];
    
}

double World::checkRadius(double newRadius) {
    
    Position newPos;
    
    if (newRadius > newPos.getDistance(center)) {
        
        return newPos.getDistance(center);
        
    } else if (newRadius <= center.getDistance(center)) {
        
        return 1.0;
    }
    
    return newRadius;
}

bool World::isEmpty(int posX, int posY) {
    
    if (peak(posX, posY).getType() == ' ') {
        
        return true;
    }
    
    return false;
}


istream& operator >> (istream& ins, World& world) {
    
    world.load(ins);
    
    return ins;
}
ostream& operator << (ostream& outs, World world) {
    
    world.save(outs);
    
    return outs;
}