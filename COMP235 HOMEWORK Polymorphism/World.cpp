//
//  World.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by ax on 4/12/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "World.hpp"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

World::World() {
    // on this site in 1984, nothing happened
}

World::World(int p_size_x, int p_size_y) {
    // store x y world size in world size member variables
    m_size_x = p_size_x;
    m_size_y = p_size_y;
    
    // construct world
    vWorldMatrix.resize(p_size_x);
    
    for (int i = 0; i < p_size_x; i++) {
        vWorldMatrix[i] = vector<WorldBlock *>(p_size_x);
    }
    // fill each row / col with a new world block
    for (int row = 0; row < vWorldMatrix.size(); row++) {
        for (int col = 0; col < vWorldMatrix[row].size(); col++) {
            vWorldMatrix[row][col] = (new WorldBlock);
            vWorldMatrix[row][col]->pos_x = row;
            vWorldMatrix[row][col]->pos_y = col;
        }
    }
}

bool World::cellIsOccupied(int p_x, int p_y) {
    cout << "cellIsOccupied checking location " << p_x << "," << p_y << endl;
    bool tBool = false;
    if ((p_x >= 0 && p_x < m_size_x) && (p_y >= 0 && p_y < m_size_y)) {
        WorldBlock * tmpPtr;
        tmpPtr = vWorldMatrix[p_x][p_y];
        if (tmpPtr->isOccupied) {
            tBool = true;
        }
    } else {
        cout << "ERROR: cellIsOccupied check outside grid bounds! ";
        cout << "Dont trust bool tBool!\n";
    }
    return tBool;
}

void World::checkCellContents(int p_x, int p_y) {
    WorldBlock * tmpPtr;
    tmpPtr = vWorldMatrix[p_x][p_y];
    char bugChar = tmpPtr->occupantPtr->getSymbol();
    if (bugChar == 'D') {
        cout << "This cell contains a Doodlebug!" << endl;
    } else if (bugChar == 'A') {
        cout << "This cell contains an Ant!" << endl;
    }
    
}

// set cell pointer
void World::setCellPointer(int p_x, int p_y, Organism &ptr, bool p_occupy) {
    vWorldMatrix[p_x][p_y]->occupantPtr = &ptr;
    vWorldMatrix[p_x][p_y]->isOccupied = p_occupy;
}

void World::clearCell(int p_x, int p_y) {
    // cout << "Clear Cell with coords: " << p_x << "," << p_y << "\n";
    tmpWorldBlockPtr = new WorldBlock();
    // point cell x, y to it
    tmpWorldBlockPtr = vWorldMatrix[p_x][p_y];
    tmpWorldBlockPtr->isOccupied = false;
    tmpWorldBlockPtr->occupantPtr = nullptr;
}

void World::printWorldSize() {
    cout << "World X Size: " << vWorldMatrix.size() << endl;
    cout << "World Y Size: " << vWorldMatrix[0].size() << endl;

}

void World::printWorldContents() {
    // print the grid
    cout << "Printing the World * * * * * * * * *" << endl;
    for (int row = 0; row < vWorldMatrix.size(); row++) {
        for (int col = 0; col < vWorldMatrix[row].size(); col++) {
            if (vWorldMatrix[row][col]->isOccupied) {
                cout << "[" << vWorldMatrix[row][col]->occupantPtr->getSymbol() << "]";
            } else {
                cout << "[ ]";
            }
        }
        cout << "\n";
    }
}

void World::countBugs() {
    CreatureCount current_count;
    for (int row = 0; row < vWorldMatrix.size(); row++) {
        for (int col = 0; col < vWorldMatrix[row].size(); col++) {
            if (vWorldMatrix[row][col]->isOccupied) {
                char creature_symbol = vWorldMatrix[row][col]->occupantPtr->getSymbol();
                if (creature_symbol == 'A') {
                    current_count.num_ants++;
                } else if (creature_symbol == 'D') {
                    current_count.num_dbugs++;
                }
            }
        }
    }

    cout << "Ants:" << current_count.num_ants << "\n";
    cout << "Doodlebugs:" << current_count.num_dbugs << "\n";
}

























