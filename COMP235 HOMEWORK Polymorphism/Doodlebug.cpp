//
//  Doodlebug.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "World.hpp"
#include "Doodlebug.hpp"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;

Doodlebug::Doodlebug() {
    // blank constructor
}

Doodlebug::Doodlebug(int p_pos_x, int p_pos_y) : character_symbol('D')
{
    m_pos_x = p_pos_x;
    m_pos_y = p_pos_y;
}

char Doodlebug::getSymbol() {
    // std::cout << "DOODLEBUG GET SYMBOL INVOKED!\n";
    return character_symbol;
}

void Doodlebug::setSymbol(char p_sym) {
    character_symbol = p_sym;
}

void Doodlebug::setPosition(int p_pos_x, int p_pos_y) {
    m_pos_x = p_pos_x;
    m_pos_y = p_pos_y;
}

void Doodlebug::increaseAge(World p_world_obj) {
    this->age++;
    if (age > 3) {
        // too old, die
        die(p_world_obj);
    }
}

void Doodlebug::die(World p_world_obj) {
    p_world_obj.clearCell(m_pos_x, m_pos_y);
}

void Doodlebug::move(vector<vector<WorldBlock *>> p_matrix, vector<Doodlebug> p_vec) {
    cout << "Holee chit Dbug Move Called!\n";
    
    // testing
    cout << "Matrix coord ping 0,0: " << p_matrix[0][0] << "\n";
    
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
Doodlebug::~Doodlebug() {
    delete this;
}
