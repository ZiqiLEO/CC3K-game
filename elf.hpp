//
//  elf.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef elf_hpp
#define elf_hpp

#include "enemy.hpp"

class Elf: public Enemy {
public:
    Elf();
    
    virtual void next(Game&) override;
    
    virtual ~Elf() override;
};

#endif /* elf_hpp */
