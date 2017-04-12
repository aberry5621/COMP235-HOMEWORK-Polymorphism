//
//  World.hpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by ax on 4/12/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "Organism.hpp"

#ifndef World_hpp
#define World_hpp

struct WorldBlock {
    int pos_x = 0;
    int pos_y = 0;
    bool isOccupied = false;
    Organism * occupantPtr;
};

#endif /* World_hpp */
