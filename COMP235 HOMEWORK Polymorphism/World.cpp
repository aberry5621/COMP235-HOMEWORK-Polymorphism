//
//  World.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by ax on 4/12/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "World.hpp"
#include <vector>
using std::vector;

World::World() {
    // on this site in 1984, nothing happened
}

World::World(int p_size_x, int p_size_y) {

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


// nothing here yet
