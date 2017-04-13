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

// for counting creatures
struct CreatureCount {
    int num_ants = 0;
    int num_dbugs = 0;
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
    
    // clear cell
    void clearCell(int p_x, int p_y);
    
    // print out size of world
    void printWorldSize();
    
    // print out contents of the world
    void printWorldContents();
    
    // other world tasks
    void countBugs();
    
private:
    vector<vector<WorldBlock *>> vWorldMatrix;
    WorldBlock * tmpWorldBlockPtr;
    int m_size_x;
    int m_size_y;
};

#endif /* World_hpp */











