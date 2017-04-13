//
//  main.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include <iostream>
#include <vector>
#include "World.hpp"
#include "Organism.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
using std::vector;
using std::cout;
using std::endl;

// main function declares
void stepConfirmMessage();
void quitSimulation();

int get_rand(int p_lb, int p_ub);

/****************
* MAIN FUNCTION *
****************/
int main() {
    
    cout << "Ants and Doodlebugs World!!\n";
    // RANDOM
    srand(static_cast<int>(time(0)));
    // INITIALIZE WORLD
    const int WORLD_SIZE = 20;
    const int QTY_ANTS = 5;
    const int QTY_DOODLEBUGS = 100;

    // create world
    
    World SimBugWorld(WORLD_SIZE, WORLD_SIZE);
    
    // populate initial bugs
    
    // Vector of Ants
    vector<Ant *> vAnts(0);
    // 5 ants
    int antsSpawned = 0;
    while (antsSpawned < QTY_ANTS) {
        int r_x = get_rand(0,19);
        int r_y = get_rand(0,19);
        if ( ! (SimBugWorld.cellIsOccupied(r_x, r_y))) {
            Ant * tmpAntPtr;
            tmpAntPtr = new Ant(r_x, r_y);
            vAnts.push_back(tmpAntPtr);
            SimBugWorld.setCellPointer(r_x, r_y, *tmpAntPtr, true);
            antsSpawned++;
            cout << "Populating Ant Number: " << antsSpawned << " ";
            cout << "at location " << r_x << "," << r_y << endl;
        }
    }

    // Vector of Doodlebugs
    vector<Doodlebug *> vDoodlebugs(0);
    // 100 doodlebugs
    int dbugsSpawned = 0;
    while (dbugsSpawned < QTY_DOODLEBUGS) {
        int r_x = get_rand(0,19);
        int r_y = get_rand(0,19);
        if ( ! (SimBugWorld.cellIsOccupied(r_x, r_y))) {
            Doodlebug * tmpDbugPtr;
            tmpDbugPtr = new Doodlebug(r_x, r_y, SimBugWorld);
            vDoodlebugs.push_back(tmpDbugPtr);
            SimBugWorld.setCellPointer(r_x, r_y, *tmpDbugPtr, true);
            dbugsSpawned++;
            cout << "Populating Doodlebug Number: " << dbugsSpawned << " ";
            cout << "at location " << r_x << "," << r_y << endl;
        }
    }

    // simulate time
    // step forward when user presses enter key
    bool stepforth = true;

    do {
        // move doodlebugs
        for (int i = 0; i < vDoodlebugs.size(); i++) {
            cout << "Moving Doodlebug Number: " << i+1 << endl;
            vDoodlebugs[i]->move();
        }
        
        // age doodlebugs
        for (int i = 0; i < vDoodlebugs.size(); i++) {
            vDoodlebugs[i]->increaseAge(SimBugWorld);
        }
        
        SimBugWorld.printWorldSize();
        SimBugWorld.countBugs();
        SimBugWorld.printWorldContents();
        
        // user choice
        cout << "enter n to step forward, q to quit" << endl;
        char usr_input = ' ';
        std::cin >> usr_input;
        if (usr_input == 'n') {
            stepConfirmMessage();
        } else if (usr_input == 'q') {
            quitSimulation();
        }
    } while (stepforth);
        
    return 0;
}

/* 
 main function definitions
 */
void stepConfirmMessage() {
    cout << "Stepping forward in time!" << endl;
}

void quitSimulation() {
    cout << "Quitting, goodbye!" << endl;
    exit(1);
}

int get_rand(int lb, int ub) {
    return lb + rand() % (ub - lb + 1);
}




