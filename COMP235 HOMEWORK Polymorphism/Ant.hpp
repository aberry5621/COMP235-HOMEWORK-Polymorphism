//
//  Ant.hpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//
#ifndef Ant_hpp
#define Ant_hpp

#include "World.hpp"
#include "Organism.hpp"

class Ant : public Organism {

public:
    Ant();
    Ant(int p_pos_x, int p_pos_y, World *p_world);
    char getSymbol();
    void setSymbol(char p_sym);
    void setPosition(int p_pos_x, int p_pos_y);
    void increaseAge(World p_world_obj);
    void move();
    void die(World p_world_obj);
    ~Ant();
private:
    World * worldObjectPtr;
    char character_symbol = 'A';
    int age = 0;
    int m_pos_x = 0;
    int m_pos_y = 0;
};

#endif /* Ant_hpp */
