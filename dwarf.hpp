//
//  dwarf.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef dwarf_hpp
#define dwarf_hpp

#include "enemy.hpp"

class Dwarf: public Enemy {
public:
    Dwarf();
    
    virtual int attacked(Vampire&) override;
    
    virtual void next(Game&) override;
    
    virtual ~Dwarf() override;
};

#endif /* dwarf_hpp */
