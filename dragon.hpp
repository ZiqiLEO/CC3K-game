//
//  dragon1.hpp
//  cc3k_final_project
//
//  Created by group on 29/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef dragon_hpp
#define dragon_hpp

#include "enemy.hpp"


class Dragon: public Enemy {
    int hoard_x;
    int hoard_y;
public:
    Dragon();
    
    virtual void next(Game&) override;
    
    virtual void add_hoard_pos(int x, int y) override; // store the dragon hoard position
    virtual std::vector<int> hoard_pos() override; // return the dragon hoard position
    
    virtual ~Dragon() override;
};

#endif /* dragon_hpp */
