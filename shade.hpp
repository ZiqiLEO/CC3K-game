//
//  shade.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef shade_hpp
#define shade_hpp

#include "player.hpp"

class Shade: public Player {

public:
    
    Shade(); 

    virtual void next(Game &) override;
    // receives an input and make next move (attack/move)
    
    virtual std::string get_pc_name() override; // return PC character name

    virtual ~Shade() override;
};

#endif /* shade_hpp */
