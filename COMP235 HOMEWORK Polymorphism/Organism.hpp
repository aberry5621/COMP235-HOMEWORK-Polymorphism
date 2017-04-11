//
//  Organism.hpp
//  COMP235 HOMEWORK Polymorphism
//
//  Created by gb_man on 4/11/17.
//  Copyright © 2017 alex. All rights reserved.
//

#ifndef Organism_hpp
#define Organism_hpp

// organism
// parent to ants and doodlebugs

class Organism {
public:
    // spawn - this may be better said as 'constructor'
    Organism();
    // getters / accessors
    virtual char getSymbol();
    // setters / mutators
    void setSymbol(char p_sym);
    virtual void setPosition(int p_pos_x, int p_pos_y);
    // move
    // breed
    // eat
    // die
private:
    // data vars
    char character_symbol = '0';
    int age = 0;
    int m_pos_x = 0;
    int m_pos_y = 0;
};

#endif /* Organism_hpp */
