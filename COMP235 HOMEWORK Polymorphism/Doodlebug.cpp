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

Doodlebug::Doodlebug(int p_pos_x, int p_pos_y, World *p_world) : character_symbol('D')
{
    worldObjectPtr = p_world;
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
    
    int cur_x = m_pos_x; // this doodlebug's x pos
    
    int cur_y = m_pos_y; // this doodlebug's y pos
    
    //cout << "Current Doodlebug X: " << cur_x << "\n";
    
    //cout << "Current Doodlebug Y: " << cur_y << "\n";
    
    // random generate move direction
    
    // 1: left -1,0
    
    // 2: up 0,1
    
    // 3: right 1,0
    
    // 4: down 0,-1
    
    int whichWay = Organism::randomGen(1, 4);
    
    //cout << "Which Way: " << whichWay << "\n";
    
    // for each move direction
    
    // check if move direction is valid
    
    // is destination on grid?
    
    // is destination free? (not occupied)
    
    switch (whichWay) {
            
        case 1:
            
            // left
            
            // check y is not at zero column
            
            if (cur_y == 0) {
                
                // cant go left, dont do it
                
                cout << "Going left but alredy leftmost, RUH ROH! \n";
                
                break;
                
            }
            
            else if (cur_y > 0) {
                
                // check next left space
                
                int nextLeft = cur_y - 1;
                
                cout << "This bugs next left coords: " << cur_x << "," << nextLeft << "\n";
                
                cout << "Left space is occupied bool check = ";
                
                bool tBool = worldObjectPtr->cellIsOccupied(cur_x, nextLeft);
                
                cout << tBool << "\n";
                
                cout << "\n";
                
            }
            
            break;
            
        case 2:
            
            // up
            
            //cout << "Going up! \n";
            
            if (cur_x == 0) {
                
                // cant go up, dont do it
                
                cout << "Going up but alredy uppermost, RUH ROH! \n";
                
                break;
                
            } else {
                
                // check next left space
                
                int nextUp = cur_x - 1;
                
                cout << "This bugs next up coords: " << nextUp << "," << cur_y << "\n";
                
                cout << "Up space is occupied bool check = ";
                
                bool tBool = worldObjectPtr->cellIsOccupied(nextUp, cur_y);
                
                cout << tBool;
                
                cout << "\n";
                
            }
            
            break;
            
        case 3:
            
            // right
            
            //cout << "Going right! \n";
            
            if (cur_y == 19) {
                
                // cant go right, dont do it
                
                cout << "Going right but alredy rightmost, RUH ROH! \n";
                
                break;
                
            } else {
                
                // check next right space
                
                int nextRight = cur_y + 1;
                
                cout << "This bugs next right coords: " << cur_x << "," << nextRight << "\n";
                
                cout << "Right space is occupied bool check = ";
                
                bool tBool = worldObjectPtr->cellIsOccupied(cur_x, nextRight);
                
                cout << tBool;
                
                cout << "\n";
                
            }
            
            break;
            
        case 4:
            
            // down
            
            //cout << "Going down! \n";
            
            if (cur_x == 19) {
                
                // cant go down, dont do it
                
                cout << "Going down but alredy lowermost, RUH ROH! \n";
                
                break;
                
            } else {
                
                // check next lower space
                
                int nextLower = cur_x + 1;
                
                cout << "This bugs next lower coords: " << nextLower << "," << cur_y << "\n";
                
                cout << "Lower space is occupied bool check = ";
                
                bool tBool = worldObjectPtr->cellIsOccupied(nextLower, cur_y);
                
                cout << tBool;
                
                cout << "\n";
                
            }
            
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
