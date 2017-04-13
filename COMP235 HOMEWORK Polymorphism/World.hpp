//
//  World.hpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by ax on 4/12/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "Organism.hpp"
#include <vector>
using std::vector;

#ifndef World_hpp
#define World_hpp

struct WorldBlock {
    int pos_x = 0;
    int pos_y = 0;
    bool isOccupied = false;
    Organism * occupantPtr;
};

class World {
public:
    World();
    World(int p_size_x, int p_size_y);
    
    // check if cell is occupied
    bool cellIsOccupied(int p_x, int p_y);
    
    // add something to a cell
    
    // set cell pointer
    void setCellPointer(int p_x, int p_y, Organism &ptr, bool p_occupy);
    
    // print out size of world
    void printWorldSize();
    
    // print out contents of the world
    void printWorldContents();
    
    // other world tasks
    
private:
    vector<vector<WorldBlock *>> vWorldMatrix;
    int m_size_x;
    int m_size_y;
};

#endif /* World_hpp */











