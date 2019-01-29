//
//  dragon1.cpp
//  cc3k_final_project
//
//  Created by group on 29/11/2016.
//  Copyright © 2016 group. All rights reserved.
//


#include "dragon.hpp"
#include "game.hpp"
#include <cstdlib>
using namespace std;

Dragon:: Dragon(): Enemy(150, 20, 20) {
    race = 'D';
    hoard_x = 0;
    hoard_y = 0;
}


void Dragon:: next(Game &g) {
    damage = 0;
    output = "";
    vector<int> hoard = {0, 0};
    for(int i = y-1; i <= y+1; ++i) {
        for(int j = x-1; j <= x+1; ++j) {
            if(g.floor[i][j] == 'G') {
                int s = g.golds.size();
                for(int k = 0; k < s; ++k) {
                    if(i == g.golds[k].y && j == g.golds[k].x &&
                       g.golds[k].gold_name == "dragon_hoard") {
                        hoard = {j, i};
                        break;
                    }
                }
            }
        }
    }
    if((x-1 <= g.p->get_x() && g.p->get_x() <= x+1 &&
        y-1 <= g.p->get_y() && g.p->get_y() <= y+1) ||
       (hoard[0]-1 <= g.p->get_x() && g.p->get_x() <= hoard[0]+1 &&
        hoard[1]-1 <= g.p->get_y() && g.p->get_y() <= hoard[1]+1)) {
           g.p->set_damage(0);
           // attack PC if there is a PC nearby
           
           int random = rand() % 2;
           if(random == 0) { // randomly attack player
               g.p->attacked(*this);
               output = "D deals " + to_string(g.p->get_damage()) + " damage to PC. ";
               if(g.p->get_hp() <= 0) {
                   throw string("PC dead");
               }
           } else {
               output = "hahaha the attack of D missed. ";
           }
       }
    // else the dragon do nothing
}


vector<int> Dragon:: hoard_pos() {
    vector<int> v = {hoard_x, hoard_y};
    return v;
}

void Dragon:: add_hoard_pos(int x, int y) {
    hoard_x = x;
    hoard_y = y;
}

Dragon:: ~Dragon() {}
