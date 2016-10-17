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
                cout << "\n Wizard: \"Leave now.\" \n \n";
                break;
            case 2:
                cout << "\n Wizard: ";
                cout << "\"Look at them run. See how scared they are?\" \n \n";
                break;
            case 3:
                cout << "\n Wizard: ";
                cout << "\"You look tired. Why don't you rest?\" \n \n";
                break;
            case 4:
                cout << "\n Wizard: \"The shade is getting so close.\" \n \n";
                break;
            case 5:
                cout << "\n Wizard: \"Are you afraid of the dark? "
                "I am.\" \n \n";
                break;
            case 6:
                cout << "\n Wizard: \"Do you think they are dumb, ";
                cout << player1.getPlayerName();
                cout << "? They are just lke us.\" \n \n";
                break;
            case 7:
                cout << "\n Wizard: ";
                cout << "\"Why don't you keep me company, before we depart?\" \n \n";
                break;
            case 8:
                cout << "\n ...";
                cout << "A cool wind blows. \n \n";
                break;
            default:
                cout << "\n Wizard: \"The shadows are close.\" \n \n";
                break;
                
        }
        
    } else {
        
        cout << "\n ...There's someone else here. \n \n";
    }
    
    
}