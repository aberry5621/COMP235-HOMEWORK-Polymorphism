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
using std::endl;

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
    if (age > 25) {
        // too old, die
        die(p_world_obj);
    }
}

void Doodlebug::starve(World p_world_obj) {
    this->ticks_since_eaten--;
    if (ticks_since_eaten == 0) {
        // starved, die
        die(p_world_obj);
    }
}

void Doodlebug::move() {
    /* randomly move left right up down */
    // get current position x, y coords on grid
    int cur_x = m_pos_x; // this doodlebug's x pos
    int cur_y = m_pos_y; // this doodlebug's y pos
    // random generate move direction
    // 1: left -1,0
    // 2: up 0,1
    // 3: right 1,0
    // 4: down 0,-1
    int whichWay = Organism::randomGen(1, 4);
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
                if (tBool == 1) {
                char bugTypeChar = worldObjectPtr->checkCellContents(cur_x, nextLeft);
                    if (bugTypeChar == 'A') {
                        // MOVE
                        cout << "Doodlebug found an ant at: " << cur_x << "," << nextLeft << " ";
                        Doodlebug * tmpDbug = this;
                        this->worldObjectPtr->setCellPointer(cur_x, nextLeft, *tmpDbug, 1);
                        tmpDbug->setPosition(cur_x, nextLeft);
                        worldObjectPtr->clearCell(cur_x, cur_y);
                        // ATE ANT
                        this->ticks_since_eaten = 3;
                    cout << "and ate it. \n";
                    } else if (bugTypeChar == 'D') {
                        break;
                    }
                    
                } else {
                    // MOVE
                    Doodlebug * tmpDbug = this;
                    this->worldObjectPtr->setCellPointer(cur_x, nextLeft, *tmpDbug, 1);
                    tmpDbug->setPosition(cur_x, nextLeft);
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
                if (tBool == 1) {
                    // EAT ANT
                    cout << "Doodlebug found an ant at: " << nextUp << "," << cur_y << "\n";
                } else {
                    // MOVE
                    Doodlebug * tmpDbug = this;
                    worldObjectPtr->setCellPointer(nextUp, cur_y, *tmpDbug, 1);
                    tmpDbug->setPosition(nextUp, cur_y);
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
                if (tBool == 1) {
                    // EAT ANT
                    cout << "Doodlebug found an ant at: " << cur_x << "," << nextRight << "\n";

                } else {
                    // MOVE
                    Doodlebug * tmpDbug = this;
                    worldObjectPtr->setCellPointer(cur_x, nextRight, *tmpDbug, 1);
                    tmpDbug->setPosition(cur_x, nextRight);
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
                if (tBool == 1) {
                    // EAT ANT
                    cout << "Doodlebug found an ant at: " << nextLower << "," << cur_y << "\n";
                } else {
                    // MOVE
                    Doodlebug * tmpDbug = this;
                    worldObjectPtr->setCellPointer(nextLower, cur_y, *tmpDbug, 1);
                    tmpDbug->setPosition(nextLower, cur_y);
                    worldObjectPtr->clearCell(cur_x, cur_y);
                }
            }
            break;
        default:
            break;
    }

}

// DIE
void Doodlebug::die(World p_world_obj) {
    worldObjectPtr->clearCell(m_pos_x, m_pos_y);
}

Doodlebug::~Doodlebug() {}
