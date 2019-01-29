//
//  player.cpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#include <cmath>
#include <string>
#include <iostream>
#include "player.hpp"
#include "halfling.hpp"
#include "human.hpp"
#include "dwarf.hpp"
#include "elf.hpp"
#include "orc.hpp"
#include "merchant.hpp"
#include "dragon.hpp"
#include "game.hpp"
using namespace std;

Player:: Player(int hp, int atk, int def):
Character(hp, atk, def) {
    gold = 0;
    race = '@';
    sym_before = '.';
    maxhp = hp;
    begain_atk = atk;
    begain_def = def;
    merchant_hostile = false;
}


void Player:: attacked(Halfling &h) {
    damage = ceil((100.0/(100.0+def)) * h.get_atk());
    hp -= damage;
}

void Player:: attacked(Human &h) {
    damage = ceil((100.0/(100.0+def)) * h.get_atk());
    hp -= damage;
}

void Player:: attacked(Dwarf &d) {
    damage = ceil((100.0/(100.0+def)) * d.get_atk());
    hp -= damage;
}

void Player:: attacked(Elf &e) {
    damage = ceil((100.0/(100.0+def)) * e.get_atk());
    hp -= damage;
}

void Player:: attacked(Orc &o) {
    damage = ceil((100.0/(100.0+def)) * o.get_atk());
    hp -= damage;
}

void Player:: attacked(Merchant &m) {
    damage = ceil((100.0/(100.0+def)) * m.get_atk());
    hp -= damage;
}

void Player:: attacked(Dragon &d) {
    damage = ceil((100.0/(100.0+def)) * d.get_atk());
    hp -= damage;
}


bool Player:: drow() {
    return false;
}

bool Player:: is_merchant_hostile() {
    return merchant_hostile;
}

Player * Player:: new_player() {
    while(!used_p.empty()) {
        used_p.pop_back();
    }
    atk = begain_atk;
    def = begain_def;
    return this;
}

int Player:: return_gold() {
    return gold;
}

void Player:: regain_hp() {}

Player:: ~Player() {}















