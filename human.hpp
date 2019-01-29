//
//  human.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef human_hpp
#define human_hpp

#include "enemy.hpp"

class Human: public Enemy {
public:
    Human();
    
    virtual void next(Game&) override;

    
    virtual ~Human() override;
};


#endif /* human_hpp */
