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

int Organism::randomGen(int lb, int ub) {
    return lb + rand() % (ub - lb + 1);
}

void Organism::move() {
    cout << "Organism Move Called!\n";
    /* randomly move left right up down */
    
    // get current position x, y coords on grid
    
    // random generate move direction
    // left -1,0
    // up 0,1
    // right 1,0
    // down 0,-1
    
    // check if move direction is valid
    // is destination on grid?
    // is destination free? (not occupied)
    
    // if neighoring cell is occupied,
    // or if selected move is off - grid
    // do not move
    // otherwise, move
    
}

// DIE
Organism::~Organism() {
    delete this;
}
