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

void Ant::move() {
    cout << "Ant Move Called!\n";
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
                if (tBool == 0) {
                    cout << "Left cell is open, ANT CAN MOVE LEFT!\n";
                    cout << "Current ANT X: " << cur_x << "\n";
                    cout << "Current ANT Y: " << cur_y << "\n";
                    Ant * tmpAnt = this;
                    this->worldObjectPtr->setCellPointer(cur_x, nextLeft, *tmpAnt, 1);
                    tmpAnt->setPosition(cur_x, nextLeft);
                    worldObjectPtr->clearCell(cur_x, cur_y);
                }
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
                cout << tBool << "\n";
                
                if (tBool == 0) {
                    cout << "UP cell is open, ANT CAN MOVE UP!\n";
                    cout << "Current ANT X: " << cur_x << "\n";
                    cout << "Current ANT Y: " << cur_y << "\n";
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
                cout << "Going right but alredy rightmost, RUH ROH! \n";
                break;
            } else {
                // check next right space
                int nextRight = cur_y + 1;
                cout << "This bugs next right coords: " << cur_x << "," << nextRight << "\n";
                cout << "Right space is occupied bool check = ";
                bool tBool = worldObjectPtr->cellIsOccupied(cur_x, nextRight);
                cout << tBool << "\n";
                cout << "\n";
                if (tBool == 0) {
                    cout << "RIGHT cell is open, ANT CAN MOVE RIGHT!\n";
                    cout << "Current ANT X: " << cur_x << "\n";
                    cout << "Current ANT Y: " << cur_y << "\n";
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
                cout << "Going down but alredy lowermost, RUH ROH! \n";
                break;
            } else {
                // check next lower space
                int nextLower = cur_x + 1;
                cout << "This bugs next lower coords: " << nextLower << "," << cur_y << "\n";
                cout << "Lower space is occupied bool check = ";
                bool tBool = worldObjectPtr->cellIsOccupied(nextLower, cur_y);
                cout << tBool << "\n";
                if (tBool == 0) {
                    cout << "DOWN cell is open, ANT CAN MOVE DOWN!\n";
                    cout << "Current ANT X: " << cur_x << "\n";
                    cout << "Current ANT Y: " << cur_y << "\n";
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
Ant::~Ant() {}
