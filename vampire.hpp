//
//  vampire.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef vampire_hpp
#define vampire_hpp

#include "player.hpp"

class Vampire: public Player {
        
public:
    
    Vampire();
   
    virtual void next(Game &) override;
    // receives an input and make next move (attack/move)
    
    virtual std::string get_pc_name() override; // return PC character name
    
    virtual ~Vampire() override;
};


#endif /* vampire_hpp */
