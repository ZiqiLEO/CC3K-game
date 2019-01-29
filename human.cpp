//
//  human.cpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#include "human.hpp"
#include "game.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;


Human:: Human(): Enemy(140, 20, 20) {
    race = 'H';
}

void Human:: next(Game &g) {
    damage = 0;
    output = "";
    if(x-1 <= g.p->get_x() && g.p->get_x() <= x+1 &&
       y-1 <= g.p->get_y() && g.p->get_y() <= y+1) {
        g.p->set_damage(0);
        
        int random = rand() % 2;
        if(random == 0) {
            g.p->attacked(*this);
            output = "H deals " + to_string(g.p->get_damage()) + " damage to PC. ";
            if(g.p->get_hp() <= 0) {
                throw string("PC dead");
            }
        } else {
            output = "hahaha the attack of H missed. ";
        }
    } else {
        
        vector<int> r_set = {0, 1, 2, 3, 4, 5, 6, 7};
        
        while(!r_set.empty()) {
            int s = r_set.size();
            int random = rand()%s;
            vector<int> xy = change_xy(to_string(random));
            if(g.floor[xy[1]][xy[0]] == '.') {
                g.floor[y][x] = '.';
                x = xy[0];
                y = xy[1];
                g.floor[y][x] = 'H';
                break;
            } else {
                r_set.erase(r_set.begin()+random);
            }
        }

        
    }
}


Human:: ~Human() {}
