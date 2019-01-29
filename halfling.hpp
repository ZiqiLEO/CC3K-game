//
//  halfing.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef halfling_hpp
#define halfling_hpp

#include "enemy.hpp"

class Halfling: public Enemy {
public:
    Halfling();

    virtual void next(Game&) override;
    
    virtual bool halfling() override;
    
    virtual ~Halfling() override;
};

#endif /* halfling_hpp */
