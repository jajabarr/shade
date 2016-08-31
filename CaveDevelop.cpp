//
//  CaveDevelop.cpp
//  Shade
//
//  Created by prog on 8/27/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#include "CaveDevelop.hpp"


void assignCave(World& world) {
    
    Position caveStart(CAVE_START_X, CAVE_START_Y);
    
    if ((world.getPlayer().getPlayerSteps() % 100) == 0) {
    
        if ((world.getPlayer().getPlayerCoord().getX() != CENTER_POS_X) ||
            (world.getPlayer().getPlayerCoord().getY() != CENTER_POS_Y)) {
        
            world.insert(CAVE, CENTER_POS_X, CENTER_POS_Y);
            world.setCaveCoord(CENTER_POS_X, CENTER_POS_Y);

        } else {
        
            world.insert(CAVE, CENTER_POS_X, CENTER_POS_Y - 1);
            world.setCaveCoord(CENTER_POS_X, CENTER_POS_Y - 1);
        }
    }
}

void caveText(Player player1) {
    
    if (player1.getWizTouch()) {
        
        switch (player1.getNumVisits()) {
                
            case 1:
                cout << "\n Wizard: \"Stay in here. It's warm.\" \n \n";
                break;
            case 2:
                cout << "\n Wizard: ";
                cout << "\"I worry about my friends. Can you help them?\" \n \n";
                break;
            case 3:
                cout << "\n Wizard: ";
                cout << "\"You look tired. Why don't you rest?\" \n \n";
                break;
            case 4:
                cout << "\n Wizard: \"The shade is getting so close.\" \n \n";
                break;
            case 5:
                cout << "\n Wizard: \"The beasts are fearful too. "
                "They will move faster now.\" \n \n";
                break;
            case 6:
                cout << "\n Wizard: \"Stay bright, ";
                cout << player1.getPlayerName();
                cout << ". Your journey is nearly done.\" \n \n";
                break;
            case 7:
                cout << "\n Wizard: ";
                cout << "\"Why don't you keep me company, before we depart?\" \n \n";
                break;
            case 8:
                cout << "\n Wizard: ";
                cout << "\"I knew you could make it. You have done so well.\" \n \n";
                break;
            default:
                cout << "\n Wizard: \"The shadows are close.\" \n \n";
                break;
                
        }
        
    } else {
        
        cout << "\n ...There's someone else here. \n \n";
    }
    
    
}