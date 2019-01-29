//
//  enemy.cpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#include <cmath>
#include "enemy.hpp"
#include "shade.hpp"
#include "drow.hpp"
#include "vampire.hpp"
#include "troll.hpp"
#include "goblin.hpp"
#include "game.hpp"
#include <cstdlib>
using namespace std;

Enemy:: Enemy(int hp, int atk, int def):
Character(hp, atk, def) {}

void Enemy:: attacked(Shade &s) {
    damage = ceil((100.0/(100.0+def)) * s.get_atk());
    hp -= damage;
}


void Enemy:: attacked(Drow &d) {
    damage = ceil((100.0/(100.0+def)) * d.get_atk());
    hp -= damage;
}



int Enemy:: attacked(Vampire &v) {
    damage = ceil((100.0/(100.0+def)) * v.get_atk());
    hp -= damage;
    return 5; //gain 5 hp for every successful attack
}

void Enemy:: attacked(Troll &t) {
    damage = ceil((100.0/(100.0+def)) * t.get_atk());
    hp -= damage;
}

void Enemy:: attacked(Goblin &g) {
    damage = ceil((100.0/(100.0+def)) * g.get_atk());
    hp -= damage;
}


bool Enemy:: dead() {
    if(hp <= 0) {
        return true;
    }
    return false;
}


bool Enemy:: halfling() {
    return false;
}

bool Enemy:: merchant() {
    return false;
}

char Enemy:: get_race() {
    return race;
}

void Enemy:: add_hoard_pos(int x, int y) {}

vector<int> Enemy:: hoard_pos() {
    vector<int> v = {-1, -1};
    return v;
}

Enemy:: ~Enemy() {}













