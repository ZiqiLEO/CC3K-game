//
//  drow.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef drow_hpp
#define drow_hpp

#include "player.hpp"

class Drow: public Player {
        
public:
    
    Drow(); // Last int for maxhp

    virtual void next(Game &) override;
    // receives an input and make next move (attack/move)
    
    virtual bool drow() override;
    
    virtual std::string get_pc_name() override; // return PC character name

    virtual ~Drow() override;
};

#endif /* drow_hpp */
