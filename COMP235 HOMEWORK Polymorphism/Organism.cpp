//
//  Organism.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//


#include "Organism.hpp"
#include <iostream>
using std::cout;
using std::endl;

Organism::Organism() {
    // blank constructor
}

void Organism::shoutOut() {
    cout << "HEY! Check out my symbol: ";
    cout << this->getSymbol();
    cout << endl;
}

void Organism::setSymbol(char p_sym) {
    character_symbol = p_sym;
}

void Organism::setPosition(int p_pos_x, int p_pos_y) {
    m_pos_x = p_pos_x;
    m_pos_y = p_pos_y;
}

int Organism::randomGen(int lb, int ub) {
    return lb + rand() % (ub - lb + 1);
}

void Organism::move() {
  // organismz cant move
    
}

// DIE
Organism::~Organism() {
    delete this;
}
