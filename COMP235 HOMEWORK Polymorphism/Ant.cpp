//
//  Ant.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "World.hpp"
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

void Ant::move() {
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
