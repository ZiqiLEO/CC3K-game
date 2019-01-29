//
//  player.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef player_hpp
#define player_hpp


#include "character.hpp"
#include <vector>
class Halfling;
class Human;
class Dwarf;
class Elf;
class Orc;
class Merchant;
class Dragon;
class Game;

class Player: public Character {
protected:
    bool merchant_hostile;
    int gold;
    int maxhp;
    int begain_atk; // begaining atk
    int begain_def; // begaining def
    char sym_before; // store the symble before PC moves to this pos
    std::vector<std::string> used_p; // store used potions
    
    //virtual std::vector<int> change_xy(std::string cmd) override;
    
public:
    Player(int, int, int);
    virtual void attacked(Halfling &);
    virtual void attacked(Human &);
    virtual void attacked(Dwarf &);
    virtual void attacked(Elf &);
    virtual void attacked(Orc &);
    virtual void attacked(Merchant &);
    virtual void attacked(Dragon &);
    virtual void next(Game &) = 0;
        // receives an input and make next move (attack/move)
    
    bool is_merchant_hostile();
    Player * new_player();
        // retrun a pointer to Player which atk and def become default value
    
    virtual bool drow(); // return true if PC is drow
    int return_gold(); // return the gold that PC gain
    virtual std::string get_pc_name() = 0; // return PC character name
    
    virtual void regain_hp(); // regain hp if pc is Troll
    
    
    virtual ~Player()=0;
};


#endif /* player_hpp */
