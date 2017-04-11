//
//  Ant.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "Ant.hpp"
#include <iostream>

Ant::Ant() {
    // blank constructor
}

Ant::Ant(int p_pos_x, int p_pos_y) : character_symbol('A')
{
    m_pos_x = p_pos_x;
    m_pos_y = p_pos_y;
}

char Ant::getSymbol() {
    // std::cout << "ANT GET SYMBOL INVOKED!\n";
    return character_symbol;
}

void Ant::setSymbol(char p_sym) {
    character_symbol = p_sym;
}

void Ant::setPosition(int p_pos_x, int p_pos_y) {
    m_pos_x = p_pos_x;
    m_pos_y = p_pos_y;
}
