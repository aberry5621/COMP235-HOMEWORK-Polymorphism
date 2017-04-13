//
//  Doodlebug.cpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//

#include "World.hpp"
#include "Doodlebug.hpp"
#include <iostream>
using std::cout;

Doodlebug::Doodlebug() {
    // blank constructor
}

Doodlebug::Doodlebug(int p_pos_x, int p_pos_y, World p_world) : character_symbol('D')
{
    worldObjectPtr = &p_world;
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

void Doodlebug::move() {
    cout << "Dbug Move Called!\n";
    
    /* randomly move left right up down */

    // get current position x, y coords on grid
    int cur_x = m_pos_x;
    int cur_y = m_pos_y;
    cout << "Current X: " << cur_x << "\n";
    cout << "Current Y: " << cur_y << "\n";
    
    // random generate move direction
    // 1: left -1,0
    // 2: up 0,1
    // 3: right 1,0
    // 4: down 0,-1
    int whichWay = Organism::randomGen(1, 4);
    cout << "Which Way: " << whichWay << "\n";
    
    // for each move direction
    // check if move direction is valid
    // is destination on grid?
    // is destination free? (not occupied)
    switch (whichWay) {
        case 1:
            // left
            // check y is not at zero column

            if (cur_y == 0) {
                cout << "Going left but alredy leftmost, RUH ROH! \n";
            }
            
            if (cur_y > 0) {
                cout << "Going left! \n";
            }
            
            
            
            break;
        case 2:
            // up
            cout << "Going up! \n";
            break;
        case 3:
            // right
            cout << "Going right! \n";
            break;
        case 4:
            // down
            cout << "Going down! \n";
            break;
        default:
            break;
    }
    
    // if neighoring cell is occupied,
    // or if selected move is off - grid
    // do not move
    // otherwise, move
    
}

// DIE
Doodlebug::~Doodlebug() {
    delete this;
}
