//
//  Organism.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "Organism.hpp"
#include <iostream>

Organism::Organism() {
    // blank constructor
}

char Organism::getSymbol() {
    std::cout << "ORGANISM GET SYMBOL INVOKED!\n";
    return character_symbol;
}

void Organism::setSymbol(char p_sym) {
    character_symbol = p_sym;
}

void Organism::setPosition(int p_pos_x, int p_pos_y) {
    m_pos_x = p_pos_x;
    m_pos_y = p_pos_y;
}

void Organism::move() {
    // void
}
