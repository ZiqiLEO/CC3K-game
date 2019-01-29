//
//  enemy.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef enemy_hpp
#define enemy_hpp

#include "character.hpp"

class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Game;

class Enemy: public Character {
    
    //virtual std::vector<int> change_xy(std::string cmd) override;
    
public:
    Enemy(int, int, int);
    virtual void attacked(Shade&);
    virtual void attacked(Drow&);
    virtual int attacked(Vampire&);
    virtual void attacked(Troll&);
    virtual void attacked(Goblin&);
    virtual void next(Game&) =0;

    bool dead(); // return true if the enemy dead
    
    
    virtual bool halfling(); // return true if the enemy is a Halfing
    virtual bool merchant(); // return true if the enemy is merchant
    
    
    virtual char get_race();
        // retrun the symbol represent that represent the race of the enemy
    
    virtual void add_hoard_pos(int x, int y);
    virtual std::vector<int> hoard_pos();
    
    virtual ~Enemy()=0;
};


#endif /* enemy_hpp */
