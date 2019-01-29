//
//  merchant.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef merchant_hpp
#define merchant_hpp

#include "enemy.hpp"

class Merchant: public Enemy {
public:
    Merchant();
    
    virtual void next(Game&) override;
    
    virtual bool merchant() override;

    virtual ~Merchant() override;
};

#endif /* merchant_hpp */
