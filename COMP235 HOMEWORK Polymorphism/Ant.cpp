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
using std::cout;
using std::endl;

Ant::Ant() {
    // blank constructor
}

Ant::Ant(int p_pos_x, int p_pos_y, World *p_world) : character_symbol('A')
{
    worldObjectPtr = p_world;
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

void Ant::increaseAge(World p_world_obj) {
    this->age++;
    if (age > 3) {
        cout << "Old ANT, clear cell: " << endl;
        // too old, die
        die(p_world_obj);
    }
}

void Ant::move() {
    /* randomly move left right up down */
    // get current position x, y coords on grid
    int cur_x = m_pos_x; // this ant's x pos
    int cur_y = m_pos_y; // this ant's y pos
    // random generate move direction
    // 1: left -1,0
    // 2: up 0,1
    // 3: right 1,0
    // 4: down 0,-1
    int whichWay = randomGen(1, 4);
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
                break;
            }
            else if (cur_y > 0) {
                // check next left space
                int nextLeft = cur_y - 1;
                bool tBool = worldObjectPtr->cellIsOccupied(cur_x, nextLeft);
                if (tBool == 0) {
                    Ant * tmpAnt = this;
                    this->worldObjectPtr->setCellPointer(cur_x, nextLeft, *tmpAnt, 1);
                    tmpAnt->setPosition(cur_x, nextLeft);
                    worldObjectPtr->clearCell(cur_x, cur_y);
                }
            }
            break;
        case 2:
            // up
            if (cur_x == 0) {
                // cant go up, dont do it
                break;
            } else {
                // check next left space
                int nextUp = cur_x - 1;
                bool tBool = worldObjectPtr->cellIsOccupied(nextUp, cur_y);
                if (tBool == 0) {
                    Ant * tmpAnt = this;
                    worldObjectPtr->setCellPointer(nextUp, cur_y, *tmpAnt, 1);
                    tmpAnt->setPosition(nextUp, cur_y);
                    worldObjectPtr->clearCell(cur_x, cur_y);
                }
            }
            break;
        case 3:
            // right
            //cout << "Going right! \n";
            if (cur_y == 19) {
                // cant go right, dont do it
                break;
            } else {
                // check next right space
                int nextRight = cur_y + 1;
                bool tBool = worldObjectPtr->cellIsOccupied(cur_x, nextRight);
                if (tBool == 0) {
                    Ant * tmpAnt = this;
                    worldObjectPtr->setCellPointer(cur_x, nextRight, *tmpAnt, 1);
                    tmpAnt->setPosition(cur_x, nextRight);
                    worldObjectPtr->clearCell(cur_x, cur_y);
                }
            }
            break;
        case 4:
            // down
            //cout << "Going down! \n";
            if (cur_x == 19) {
                // cant go down, dont do it
                break;
            } else {
                // check next lower space
                int nextLower = cur_x + 1;
                bool tBool = worldObjectPtr->cellIsOccupied(nextLower, cur_y);
                if (tBool == 0) {
                    Ant * tmpAnt = this;
                    worldObjectPtr->setCellPointer(nextLower, cur_y, *tmpAnt, 1);
                    tmpAnt->setPosition(nextLower, cur_y);
                    worldObjectPtr->clearCell(cur_x, cur_y);
                }
            }
            break;
        default:
            break;
    }
    
}

// DIE
void Ant::die(World p_world_obj) {
    worldObjectPtr->clearCell(m_pos_x, m_pos_y);
}

Ant::~Ant() {}
