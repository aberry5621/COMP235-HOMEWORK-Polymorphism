//
//  Doodlebug.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "Doodlebug.hpp"
#include <iostream>

Doodlebug::Doodlebug() {
    // blank constructor
}

Doodlebug::Doodlebug(int pos_x, int pos_y) : character_symbol('D')
{
    // blank constructor - set in initializer
}

char Doodlebug::getSymbol() {
    // std::cout << "DOODLEBUG GET SYMBOL INVOKED!\n";
    return character_symbol;
}

void Doodlebug::setPosition(int p_pos_x, int p_pos_y) {
    m_pos_x = p_pos_x;
    m_pos_y = p_pos_y;
}
