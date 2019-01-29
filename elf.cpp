//
//  elf.cpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#include "elf.hpp"
#include <cstdlib>
#include "game.hpp"
#include <string>
#include <vector>
using namespace std;

Elf:: Elf(): Enemy(140, 30, 10) {
    race = 'E';
}


void Elf:: next(Game &g) {
    damage = 0;
    output = "";
    if(x-1 <= g.p->get_x() && g.p->get_x() <= x+1 &&
       y-1 <= g.p->get_y() && g.p->get_y() <= y+1) {
        g.p->set_damage(0);
        //first attack
        
        int random1 = rand() % 2;
        if(random1 == 0) {
            g.p->attacked(*this);
            output = "E deals " + to_string(g.p->get_damage()) + " damage to PC. ";
            if(g.p->get_hp() <= 0) {
                throw string("PC dead");
            }
        } else {
            output = "hahaha the attack by E missed. ";
        }
        // second attack
        if(!g.p->drow()) { // if PC is not drow, attack PC twice
            int random2 = rand() % 2;
            if(random2 == 0) {
                g.p->attacked(*this);
                output = "E deals " + to_string(g.p->get_damage()) + " damage to PC. ";
                if(g.p->get_hp() <= 0) {
                    throw string("PC dead");
                }
            } else {
                output += "hahaha the second attack by E missed. ";
            }
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
                g.floor[y][x] = 'E';
                break;
            } else {
                r_set.erase(r_set.begin()+random);
            }
        }

    }
         
}



Elf:: ~Elf() {}
