//
//  character.cpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#include "character.hpp"
#include <vector>
#include <iostream>


Character:: Character (int hp, int atk, int def):
hp{hp}, atk{atk}, def{def} {
    output = "";
}

int Character:: get_x() {
    return x;
}

int Character:: get_y() {
    return y;
}

void Character:: set_x(int a) {
    x = a;
}

void Character:: set_y(int b) {
    y = b;
}

void Character:: set_damage(int d) {
    damage = d;
}

int Character:: get_atk() {
    return atk;
}

int Character:: get_hp() {
    return hp;
}

int Character:: get_def() {
    return def;
}

int Character:: get_damage() {
    return damage;
}

std::vector<int> Character:: change_xy(std::string dir) {
    if(dir == "no" || dir == "<no>" || dir == "0") {
        return {x, y-1};
    } else if(dir == "so" || dir == "<so>" || dir == "1") {
        return {x, y+1};
    } else if(dir == "ea" || dir == "<ea>" || dir == "2") {
        return {x+1, y};
    } else if(dir == "we" || dir == "<we>" || dir == "3") {
        return {x-1, y};
    } else if(dir == "ne" || dir == "<ne>" || dir == "4") {
        return {x+1, y-1};
    } else if(dir == "nw" || dir == "<nw>" || dir == "5") {
        return {x-1, y-1};
    } else if(dir == "se" || dir == "<se>" || dir == "6") {
        return {x+1, y+1};
    } else if(dir == "sw" || dir == "<se>" || dir == "7"){
        return {x-1, y+1};
    } else {
        return {0, 0};
    }
}

std::string Character:: get_output() {
    return output;
}

Character:: ~Character() {} 
