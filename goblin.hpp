//
//  groblin.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef goblin_hpp
#define goblin_hpp

#include "player.hpp"

class Goblin: public Player {
    
public:

    Goblin(); // Last int for maxhp
    
    virtual void attacked(Orc &) override;
    
    virtual void next(Game &) override;
    // receives an input and make next move (attack/move)
    
    virtual std::string get_pc_name() override; // return PC character name


    virtual ~Goblin() override;
};

#endif /* goblin_hpp */
