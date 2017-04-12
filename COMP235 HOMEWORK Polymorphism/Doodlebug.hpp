//
//  Doodlebug.hpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "World.hpp"
#include "Organism.hpp"
#include <vector>
using std::vector;

#ifndef Doodlebug_hpp
#define Doodlebug_hpp

class Doodlebug : public Organism {

public:
    Doodlebug();
    Doodlebug(int pos_x, int pos_y);
    char getSymbol();
    void setSymbol(char p_sym);
    void setPosition(int p_pos_x, int p_pos_y);
    void move(vector<vector<WorldBlock *>> p_matrix, vector<Doodlebug> p_vec);
private:
    char character_symbol = 'D';
    int age = 0;
    int m_pos_x = 0;
    int m_pos_y = 0;
};

#endif /* Doodlebug_hpp */
