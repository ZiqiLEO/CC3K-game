//
//  orcs.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef orc_hpp
#define orc_hpp

#include "enemy.hpp"

class Orc: public Enemy {
public:
    Orc();

    virtual void next(Game&) override;

    virtual ~Orc() override;
};

#endif /* orc_hpp */
