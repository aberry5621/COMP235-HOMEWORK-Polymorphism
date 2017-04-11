//
//  main.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Organism.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
using std::vector;
using std::cout;
using std::endl;
// main data structures
struct WorldBlock {
    int pos_x = 0;
    int pos_y = 0;
    bool isOccupied = false;
    Organism * occupantPtr;
};
struct CreatureCount {
    int num_ants = 0;
    int num_dbugs = 0;
};
// main function declares
void stepConfirmMessage();
void quitSimulation();
vector<vector<WorldBlock *>> createWorld(int size);
void printWorldMatrix(vector<vector<WorldBlock *>>);
CreatureCount countBugs(vector<vector<WorldBlock *>>);
void print_foo(vector<char>);
int get_rand(int p_lb, int p_ub);
// main fucntion
int main() {
    
    cout << "Ants and Doodlebugs World!!\n";
    // RANDOM
    srand(static_cast<int>(time(0)));
    // INITIALIZE WORLD
    const int WORLD_SIZE = 20;
    const int QTY_ANTS = 5;
    const int QTY_DOODLEBUGS = 100;
    // make a 2d matrix world to fill with bugs
    vector<vector<WorldBlock *>> world_matrix = createWorld(WORLD_SIZE);
    // populate initial bugs
    
    // 5 ants
    int antsSpawned = 0;
    while (antsSpawned < QTY_ANTS) {
        int r_x = get_rand(0,19);
        int r_y = get_rand(0,19);
        if (!(world_matrix[r_x][r_y]->isOccupied)) {
            world_matrix[r_x][r_y]->occupantPtr = new Ant(r_x, r_y);
            world_matrix[r_x][r_y]->isOccupied = true;
            antsSpawned++;
        }
    }

    // 100 doodlebugs
    int dbugsSpawned = 0;
    while (dbugsSpawned < QTY_DOODLEBUGS) {
        int r_x = get_rand(0,19);
        int r_y = get_rand(0,19);
        if (!(world_matrix[r_x][r_y]->isOccupied)) {
            world_matrix[r_x][r_y]->occupantPtr = new Doodlebug(r_x, r_y);
            world_matrix[r_x][r_y]->isOccupied = true;
            dbugsSpawned++;
        }
    }
    
    // count the bugs
    cout << "Critter Count:\n";
    CreatureCount count = countBugs(world_matrix);
    cout << "Ants:" << count.num_ants << "\n";
    cout << "Doodlebugs:" << count.num_dbugs << "\n";
    
    // simulate time
    // step forward when user presses enter key
    bool stepforth = false;

    while (stepforth == false) {
        // populate bugs
        
        // show the world
        printWorldMatrix(world_matrix);
        // user choice
        cout << "enter n to step forward, q to quit" << endl;
        char usr_input = ' ';
        std::cin >> usr_input;
        if (usr_input == 'n') {
            stepConfirmMessage();
        } else if (usr_input == 'q') {
            quitSimulation();
        }
    }
    return 0;
}
/* 
 main function definitions
 */
void stepConfirmMessage() {
    cout << "Stepping forward in teim!" << endl;
}

void quitSimulation() {
    cout << "Quitting, goodbye!" << endl;
    exit(1);
}

vector<vector<WorldBlock *>> createWorld(int size) {
    vector<vector<WorldBlock *>> tmpMatrix(size);
    for (int i = 0; i < size; i++) {
        tmpMatrix[i] = vector<WorldBlock *>(size);
    }
    // fill each row / col with a new world block
    for (int row = 0; row < tmpMatrix.size(); row++) {
        for (int col = 0; col < tmpMatrix[row].size(); col++) {
            tmpMatrix[row][col] = (new WorldBlock);
            tmpMatrix[row][col]->pos_x = row;
            tmpMatrix[row][col]->pos_y = col;
        }
    }
    return tmpMatrix;
}

void printWorldMatrix(vector<vector<WorldBlock *>> p_matrix) {
    cout << "Print Matrix World\n";
    cout << "Matrix Size: " << p_matrix.size() << " x " <<  p_matrix[0].size() << "\n";
    for (int row = 0; row < p_matrix.size(); row++) {
        for (int col = 0; col < p_matrix[row].size(); col++) {
            if (p_matrix[row][col]->isOccupied) {
                cout << "[" << p_matrix[row][col]->occupantPtr->getSymbol() << "]";
            } else {
                cout << "[ ]";
            }
            
        }
        cout << "\n";
    }
}

CreatureCount countBugs(vector<vector<WorldBlock *>> p_matrix) {
    CreatureCount current_count;
    for (int row = 0; row < p_matrix.size(); row++) {
        for (int col = 0; col < p_matrix[row].size(); col++) {
            if (p_matrix[row][col]->isOccupied) {
                char creature_symbol = p_matrix[row][col]->occupantPtr->getSymbol();
                if (creature_symbol == 'A') {
                    current_count.num_ants++;
                } else if (creature_symbol == 'D') {
                    current_count.num_dbugs++;
                }
            }
        }
    }
    return current_count;
}

int get_rand(int lb, int ub) {
    return lb + rand() % (ub - lb + 1);
}




