//
//  Player.cpp
//  Shade
//
//  Created by jajabarr on 3/18/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#include "Player.hpp"

Player::Player() {
    
    playerHealth = 0;
    playerSteps = 0;
    playerName = "";
    inCave = false;
    wizTouch = false;
    caveVisits = 0;
    
}

void Player::printPlayer() {
    
    char space = ' ';
    
    cout << playerName << space << space;
    cout << "HP: " << playerHealth << space << space;
    cout << "Steps: " << playerSteps << space << space;
    cout << "Caves: " << caveVisits;
    cout << endl << endl;
}

void Player::setPlayerHealth(int hp) {
    
    playerHealth = hp;
    
}

int Player::getPlayerHealth() {
    
    return playerHealth;
    
}

void Player::setPlayerSteps(int steps) {
    
    playerSteps = steps;
    
}

int Player::getPlayerSteps() {
    
    return playerSteps;
    
}

void Player::setPlayerName(string name) {
    
    playerName = name;
    
}

string Player::getPlayerName() {
    
    return playerName;
    
}

void Player::setPlayerCoord(int posX, int posY) {
    
    Position temp(posX, posY);
    playerCoord = temp;
    
}

void Player::setPlayerCoord(Position position) {
    
    playerCoord = position;
}

Position& Player::getPlayerCoord() {
    
    return playerCoord;
}

void Player::setCave(bool caveman) {
    
    if (caveman) {
        
        inCave = true;
        
    } else {
        
        inCave = false;
    }
}

bool Player::getCavePos() {
    
    return inCave;
}

int Player::getNumVisits() {
    
    return caveVisits;
}

void Player::setNumVisits(int numVisits) {
    
    if (numVisits < 0) {
        
        caveVisits = 0;
        
    } else {
        
        caveVisits = numVisits;
        
    }
    
}

bool Player::getWizTouch() {
    
    return wizTouch;
}

void Player::setWizTouch(bool touchWiz) {
    
    wizTouch = touchWiz;
    
}

void Player::addVisit() {
    
    caveVisits++;
}

void Player::addStep() {
    
    playerSteps++;
}

void Player::addHealth() {
    
    playerHealth++;
}

void Player::decreaseHealth() {
    
    playerHealth--;
}

void Player::killPlayer() {
    
    playerHealth = 0;
}

void Player::playerFullHealth() {
    
    playerHealth = PLAYER_MAX_HP;
}