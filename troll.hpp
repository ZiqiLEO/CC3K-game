//
//  troll.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef troll_hpp
#define troll_hpp

#include "player.hpp"

class Troll: public Player {
    
public:
    
    Troll();
    
    virtual void next(Game &) override;
    // receives an input and make next move (attack/move)

    virtual std::string get_pc_name() override; // return PC character name
    
    virtual void regain_hp() override;

    virtual ~Troll() override;
};



#endif /* troll_hpp */
