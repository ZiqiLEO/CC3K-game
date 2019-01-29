//
//  game.cpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#include "game.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "shade.hpp"
#include "drow.hpp"
#include "vampire.hpp"
#include "troll.hpp"
#include "goblin.hpp"
#include "enemy.hpp"
#include "human.hpp"
#include "dwarf.hpp"
#include "halfling.hpp"
#include "elf.hpp"
#include "orc.hpp"
#include "merchant.hpp"
#include "dragon.hpp"
using namespace std;


Game::Game(){
    //pass all coordinates to corresponding chambers.
    
    //chamber one.
    for (int i = 3; i < 7; ++i){
        for(int j = 3; j < 29; ++j){
            Coordinate c;
            c.x = j;
            c.y = i;
            chambers[0].coords.push_back(c);
        }
    }
    //chamber two.
    for (int i = 3; i < 5; ++i){
        for (int j = 39; j < 62; ++j){
            Coordinate c;
            c.x = j;
            c.y = i;
            chambers[1].coords.push_back(c);
        }
    }
    for (int i = 39; i < 70; ++i){
        Coordinate c;
        c.x = i;
        c.y = 5;
        chambers[1].coords.push_back(c);
    }
    for (int i = 39; i < 73; ++i){
        Coordinate c;
        c.x = i;
        c.y = 6;
        chambers[1].coords.push_back(c);
    }
    for (int i = 7; i < 13; ++i){
        for (int j = 61; j < 76; ++j){
            Coordinate c;
            c.x = j;
            c.y = i;
            chambers[1].coords.push_back(c);
        }
    }
    //chamber three.
    for (int i = 10; i < 13; ++i){
        for (int j = 38; j < 50; ++j){
            Coordinate c;
            c.x = j;
            c.y = i;
            chambers[2].coords.push_back(c);
        }
    }
    //chamber four.
    for (int i = 15; i < 22; ++i){
        for (int j = 4; j < 25; ++j){
            Coordinate c;
            c.x = j;
            c.y = i;
            chambers[3].coords.push_back(c);
        }
    }
    //chamber five.
    for (int i = 16; i < 19; ++i){
        for (int j = 65; j < 76; ++j){
            Coordinate c;
            c.x = j;
            c.y = i;
            chambers[4].coords.push_back(c);
        }
    }
    for (int i = 19; i < 22; ++i){
        for (int j = 37 ; j < 76; ++j){
            Coordinate c;
            c.x = j;
            c.y = i;
            chambers[4].coords.push_back(c);
        }
    }
}


void Game::new_game(string f_name){ // new_game with arg
    int height = 25;
    ifstream input;
    input.open(f_name);
    for (int i = 0; i < 5*height; ++i){
        string s;
        getline(input,s);
        empty_floor.push_back(s);
    }
    input.close();
    
    current_floor = 0;
    // delete golds if needed
    while(!golds.empty()) {
        golds.pop_back();
    }
    // delete potions if needed
    while(!potions.empty()) {
        potions.pop_back();
    }
    // delete enemies if needed
    while(!e.empty()) {
        Enemy *en = e.back();
        delete en;
        e.pop_back();
    }
}


void Game::new_floor(string){ // new_floor with arg
    int height = 25;
    
    // clear floor if needed
    while(!floor.empty()) {
        floor.pop_back();
    }
    
    // delete enemies if needed
    while(!e.empty()) {
        delete(e.back());
        e.pop_back();
    }
    
    // clear vector which store golds
    while(!golds.empty()) {
        golds.pop_back();
    }
    
    // clear vector which store potions
    while(!potions.empty()) {
        potions.pop_back();
    }
    
    
    for(int i = current_floor*height; i < (current_floor+1)*height; ++i) {
        floor.push_back(empty_floor[i]);
    }

    for(int i = 0; i < height; ++i) {
        for(int j = 0; floor[i][j] != '\0'; ++j) {
            if(floor[i][j] == '0') {
                Item item;
                item.x = j; item.y = i;
                item.used = false;
                item.type = "Potion";
                item.gold_name = "";
                item.value = 0;
                item.potion_name = "RH";
                item.effect = 10;
                potions.push_back(item);
                floor[i][j] = 'P';
            } else if(floor[i][j] == '1') {
                Item item;
                item.x = j; item.y = i;
                item.used = false;
                item.type = "Potion";
                item.gold_name = "";
                item.value = 0;
                item.potion_name = "BA";
                item.effect = 5;
                potions.push_back(item);
                floor[i][j] = 'P';
            } else if(floor[i][j] == '2') {
                Item item;
                item.x = j; item.y = i;
                item.used = false;
                item.type = "Potion";
                item.gold_name = "";
                item.value = 0;
                item.potion_name = "BD";
                item.effect = 5;
                potions.push_back(item);
                floor[i][j] = 'P';
            } else if(floor[i][j] == '3') {
                Item item;
                item.x = j; item.y = i;
                item.used = false;
                item.type = "Potion";
                item.gold_name = "";
                item.value = 0;
                item.potion_name = "PH";
                item.effect = -10;
                potions.push_back(item);
                floor[i][j] = 'P';
            } else if(floor[i][j] == '4') {
                Item item;
                item.x = j; item.y = i;
                item.used = false;
                item.type = "Potion";
                item.gold_name = "";
                item.value = 0;
                item.potion_name = "WA";
                item.effect = -5;
                potions.push_back(item);
                floor[i][j] = 'P';
            } else if(floor[i][j] == '5') {
                Item item;
                item.x = j; item.y = i;
                item.used = false;
                item.type = "Potion";
                item.gold_name = "";
                item.value = 0;
                item.potion_name = "WD";
                item.effect = -5;
                potions.push_back(item);
                floor[i][j] = 'P';
            } else if(floor[i][j] == '6') {
                Item item;
                item.x = j; item.y = i;
                item.used = false;
                item.type = "Gold";
                item.gold_name = "normal";
                item.value = 2;
                item.potion_name = "";
                item.effect = 0;
                golds.push_back(item);
                floor[i][j] = 'G';
            } else if(floor[i][j] == '7') {
                Item item;
                item.x = j; item.y = i;
                item.used = false;
                item.type = "Gold";
                item.gold_name = "small";
                item.value = 1;
                item.potion_name = "";
                item.effect = 0;
                golds.push_back(item);
                floor[i][j] = 'G';
            } else if(floor[i][j] == '8') {
                Item item;
                item.x = j; item.y = i;
                item.used = false;
                item.type = "Gold";
                item.gold_name = "merchant_hoard";
                item.value = 4;
                item.potion_name = "";
                item.effect = 0;
                golds.push_back(item);
                floor[i][j] = 'G';
            } else if(floor[i][j] == '9') {
                Item item;
                item.x = j; item.y = i;
                item.used = false;
                item.type = "Gold";
                item.gold_name = "dragon_hoard";
                item.value = 8;
                item.potion_name = "";
                item.effect = 0;
                golds.push_back(item);
                floor[i][j] = 'G';
                
                
                // find D in map, create a new Dragon, set dragon hoard position
                for(int n = i-1; n <= i+1; ++i) {
                    bool find_d = false;
                    for(int m = j-1; m <= j+1; ++j) {
                        if(floor[i][j] == 'D') {
                            int s_e = e.size();
                            for(int k = 0; k < s_e; ++k) { // find dragon without dragon hoard set
                                if(e[k]->get_race() == 'D' &&
                                   e[k]->get_x() == j &&
                                   e[k]->get_y() == i) {
                                    find_d = true;
                                    break;
                                }
                            }
                            if(!find_d) {
                                Dragon *d = new Dragon();
                                d->set_x(m);
                                d->set_y(n);
                                d->add_hoard_pos(j, i);
                                break;
                            }
                        }
                    }
                    if(!find_d) {break;}
                }
            } else if(floor[i][j] == '@') {
                p->set_x(j);
                p->set_y(i);
            } else if(floor[i][j] == 'H') {
                Human *h = new Human();
                h->set_x(j);
                h->set_y(i);
                e.push_back(h);
            } else if(floor[i][j] == 'W') {
                Dwarf *d = new Dwarf();
                d->set_x(j);
                d->set_y(i);
                e.push_back(d);
            } else if(floor[i][j] == 'E') {
                Elf *elf = new Elf();
                elf->set_x(j);
                elf->set_y(i);
                e.push_back(elf);
            } else if(floor[i][j] == 'O') {
                Orc *o = new Orc();
                o->set_x(j);
                o->set_y(i);
                e.push_back(o);
            } else if(floor[i][j] == 'M') {
                Merchant *m = new Merchant();
                m->set_x(j);
                m->set_y(i);
                e.push_back(m);
            } else if(floor[i][j] == 'L') {
                Halfling *l = new Halfling();
                l->set_x(j);
                l->set_y(i);
                e.push_back(l);
            }
        }
    }
    
}


void Game::new_game(){ // new_game without arg
    ifstream input;
    input.open("cc3kfloor.txt");
    for (int i = 0; i < 25; ++i){
        string s;
        getline(input,s);
        empty_floor.push_back(s);
    }
    input.close();
    
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < chambers[i].coords.size(); ++j){
            empty_floor[chambers[i].coords[j].y][chambers[i].coords[j].x] = '.';
        }
    }
    
    current_floor = 0;
    // delete golds if needed
    while(!golds.empty()) {
        golds.pop_back();
    }
    // delete potions if needed
    while(!potions.empty()) {
        potions.pop_back();
    }
    // delete enemies if needed
    while(!e.empty()) {
        Enemy *en = e.back();
        delete en;
        e.pop_back();
    }
}



void Game::new_floor(){ // new_floor without arg
    
    // delete enemies if needed
    while(!e.empty()) {
        delete(e.back());
        e.pop_back();
    }
    
    // clear vector which store golds
    while(!golds.empty()) {
        golds.pop_back();
    }
    
    // clear vector which store potions
    while(!potions.empty()) {
        potions.pop_back();
    }
    
    floor = empty_floor;
    
    int enemy_num = 20; //the default number of enemies.
    for (int i = 0; i < 10; ++i){ //generate 10 potions randomly.
        int r;
        
        r = rand() % 6;
        if (r == 0){
            Item i;
            i.x = 0; i.y = 0;
            i.used = false;
            i.type = "Potion";
            i.gold_name = "";
            i.value = 0;
            i.potion_name = "RH";
            i.effect = 10;
            potions.push_back(i);
        } else if (r == 1){
            Item i;
            i.x = 0; i.y = 0;
            i.used = false;
            i.type = "Potion";
            i.gold_name = "";
            i.value = 0;
            i.potion_name = "BA";
            i.effect = 5;
            potions.push_back(i);
        } else if (r == 2){
            Item i;
            i.x = 0; i.y = 0;
            i.used = false;
            i.type = "Potion";
            i.gold_name = "";
            i.value = 0;
            i.potion_name = "BD";
            i.effect = 5;
            potions.push_back(i);
        } else if (r == 3){
            Item i;
            i.x = 0; i.y = 0;
            i.used = false;
            i.type = "Potion";
            i.gold_name = "";
            i.value = 0;
            i.potion_name = "PH";
            i.effect = -10;
            potions.push_back(i);
        } else if (r == 4){
            Item i;
            i.x = 0; i.y = 0;
            i.used = false;
            i.type = "Potion";
            i.gold_name = "";
            i.value = 0;
            i.potion_name = "WA";
            i.effect = -5;
            potions.push_back(i);
        } else {
            Item i;
            i.x = 0; i.y = 0;
            i.used = false;
            i.type = "Potion";
            i.gold_name = "";
            i.value = 0;
            i.potion_name = "WD";
            i.effect = -5;
            potions.push_back(i);
        }
    }
    for (int i = 0; i < 10; ++i){ //generate 10 golds randomly.
        int r;
        r = rand() % 8;
        if (r==0 ||r==1 ||r==2 ||r==3 ||r==4){
            Item i;
            i.x = 0; i.y = 0;
            i.used = false;
            i.type = "Gold";
            i.gold_name = "normal";
            i.value = 2;
            i.potion_name = "";
            i.effect = 0;
            golds.push_back(i);
        } else if(r == 5 || r == 6){
            Item i;
            i.x = 0; i.y = 0;
            i.used = false;
            i.type = "Gold";
            i.gold_name = "small";
            i.value = 1;
            i.potion_name = "";
            i.effect = 0;
            golds.push_back(i);
        } else {
            Item i;
            i.x = 0; i.y = 0;
            i.used = false;
            i.type = "Gold";
            i.gold_name = "dragon_hoard";
            i.value = 6;
            i.potion_name = "";
            i.effect = 0;
            golds.push_back(i);
            Dragon *d = new Dragon();
            e.push_back(d);
            --enemy_num;
        }
    }
    
    
    
    //generate player position on the map.
    int pc_chamb;
    int pc_pos;
    pc_chamb = rand() % 5;
    pc_pos = rand() % chambers[pc_chamb].coords.size();
    floor[chambers[pc_chamb].coords[pc_pos].y][chambers[pc_chamb].coords[pc_pos].x] = '@';
    p->set_x(chambers[pc_chamb].coords[pc_pos].x);
    p->set_y(chambers[pc_chamb].coords[pc_pos].y);
    
    //generate stair position on the map.
    int stair_chamb;
    int stair_pos;
    while(true){
        stair_chamb = rand() % 5;
        if (stair_chamb != pc_chamb){
            stair_pos = rand() % chambers[stair_chamb].coords.size();
            floor[chambers[stair_chamb].coords[stair_pos].y][chambers[stair_chamb].coords[stair_pos].x] = '\\';
            break;
        }
    }
    
    //generate potions on the map.
    for (int i = 0; i < potions.size(); ++i){
        int pot_chamb;
        int pot_pos;
        pot_chamb = rand() % 5;
        while(true){
            pot_pos = rand() % chambers[pot_chamb].coords.size();
            if(floor[chambers[pot_chamb].coords[pot_pos].y][chambers[pot_chamb].coords[pot_pos].x] == '.'){
                floor[chambers[pot_chamb].coords[pot_pos].y][chambers[pot_chamb].coords[pot_pos].x] = 'P';
                potions[i].x = chambers[pot_chamb].coords[pot_pos].x;
                potions[i].y = chambers[pot_chamb].coords[pot_pos].y;
                break;
            }
        }
    }
    
    //generate golds on the map.
    for (int i = 0; i < golds.size(); ++i){
        int gold_chamb;
        int gold_pos;
        gold_chamb = rand() % 5;
        while(true){
            gold_pos = rand() % chambers[gold_chamb].coords.size();
            if(floor[chambers[gold_chamb].coords[gold_pos].y][chambers[gold_chamb].coords[gold_pos].x] == '.'){
                floor[chambers[gold_chamb].coords[gold_pos].y][chambers[gold_chamb].coords[gold_pos].x] = 'G';
                golds[i].x = chambers[gold_chamb].coords[gold_pos].x;
                golds[i].y = chambers[gold_chamb].coords[gold_pos].y;
                break;
            }
        }
    }
    
    //generate drogons on the map;
    int num_d = 0;
    for (int j = 0; j < golds.size(); ++j){
        
        if(golds[j].gold_name == "dragon_hoard"){
            while (true) {
                int d_pos = rand() % 8;
                if(d_pos == 0 && floor[golds[j].y][golds[j].x + 1]=='.'){
                    e[num_d]->set_x(golds[j].x + 1);
                    e[num_d]->set_y(golds[j].y);
                    e[num_d]->add_hoard_pos(golds[j].x, golds[j].y);
                    floor[golds[j].y][golds[j].x + 1] = 'D';
                    ++num_d;
                    break;
                }
                else if(d_pos == 1 && floor[golds[j].y][golds[j].x - 1]=='.'){
                    e[num_d]->set_x(golds[j].x - 1);
                    e[num_d]->set_y(golds[j].y);
                    e[num_d]->add_hoard_pos(golds[j].x, golds[j].y);
                    floor[golds[j].y][golds[j].x - 1] = 'D';
                    ++num_d;
                    break;
                }
                else if(d_pos == 2 && floor[golds[j].y - 1][golds[j].x]=='.'){
                    e[num_d]->set_x(golds[j].x);
                    e[num_d]->set_y(golds[j].y - 1);
                    e[num_d]->add_hoard_pos(golds[j].x, golds[j].y);
                    floor[golds[j].y - 1][golds[j].x] = 'D';
                    ++num_d;
                    break;
                }
                else if(d_pos == 3 && floor[golds[j].y + 1][golds[j].x]=='.'){
                    e[num_d]->set_x(golds[j].x);
                    e[num_d]->set_y(golds[j].y + 1);
                    e[num_d]->add_hoard_pos(golds[j].x, golds[j].y);
                    floor[golds[j].y + 1][golds[j].x] = 'D';
                    ++num_d;
                    break;
                }
                else if(d_pos == 4 && floor[golds[j].y-1][golds[j].x-1]=='.'){
                    e[num_d]->set_x(golds[j].x-1);
                    e[num_d]->set_y(golds[j].y-1);
                    e[num_d]->add_hoard_pos(golds[j].x, golds[j].y);
                    floor[golds[j].y - 1][golds[j].x - 1] = 'D';
                    ++num_d;
                    break;
                }
                else if(d_pos == 5 && floor[golds[j].y+1][golds[j].x-1]=='.'){
                    e[num_d]->set_x(golds[j].x-1);
                    e[num_d]->set_y(golds[j].y+1);
                    e[num_d]->add_hoard_pos(golds[j].x, golds[j].y);
                    floor[golds[j].y + 1][golds[j].x - 1] = 'D';
                    ++num_d;
                    break;
                }
                else if(d_pos == 6 && floor[golds[j].y-1][golds[j].x+1]=='.'){
                    e[num_d]->set_x(golds[j].x+1);
                    e[num_d]->set_y(golds[j].y-1);
                    e[num_d]->add_hoard_pos(golds[j].x, golds[j].y);
                    floor[golds[j].y - 1][golds[j].x + 1] = 'D';
                    ++num_d;
                    break;
                }
                else if(d_pos == 7 && floor[golds[j].y+1][golds[j].x+1]=='.'){
                    e[num_d]->set_x(golds[j].x+1);
                    e[num_d]->set_y(golds[j].y+1);
                    e[num_d]->add_hoard_pos(golds[j].x, golds[j].y);
                    floor[golds[j].y + 1][golds[j].x + 1] = 'D';
                    ++num_d;
                    break;
                }
            }
            
        }
    }
    
    //generate all enemies on the map.
    for (int i = num_d; i < 20; ++i){ //generate all enemies randomly.
        int r;
        r = rand() % 18;
        if(r==0 || r==1 || r==2|| r==3){
            Human *h = new Human();
            e.push_back(h);
            int enem_chamb;
            int enem_pos;
            enem_chamb = rand() % 5;
            while(true){
                enem_pos = rand() % chambers[enem_chamb].coords.size();
                if(floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] == '.'){
                    floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] = 'H';
                    e[i]->set_x(chambers[enem_chamb].coords[enem_pos].x);
                    e[i]->set_y(chambers[enem_chamb].coords[enem_pos].y);
                    break;
                }
            }
        }
        else if(r==4 || r==5 || r==6){
            Dwarf *w = new Dwarf();
            e.push_back(w);
            int enem_chamb;
            int enem_pos;
            enem_chamb = rand() % 5;
            while(true){
                enem_pos = rand() % chambers[enem_chamb].coords.size();
                if(floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] == '.'){
                    floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] = 'W';
                    e[i]->set_x(chambers[enem_chamb].coords[enem_pos].x);
                    e[i]->set_y(chambers[enem_chamb].coords[enem_pos].y);
                    break;
                }
            }
            
        }
        else if(r==7 || r==8 || r==9 || r==10 || r==11){
            Halfling *l = new Halfling();
            e.push_back(l);
            int enem_chamb;
            int enem_pos;
            enem_chamb = rand() % 5;
            while(true){
                enem_pos = rand() % chambers[enem_chamb].coords.size();
                if(floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] == '.'){
                    floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] = 'L';
                    e[i]->set_x(chambers[enem_chamb].coords[enem_pos].x);
                    e[i]->set_y(chambers[enem_chamb].coords[enem_pos].y);
                    break;
                }
            }
            
        }
        else if(r==12 || r ==13){
            Elf *elf = new Elf();
            e.push_back(elf);
            int enem_chamb;
            int enem_pos;
            enem_chamb = rand() % 5;
            while(true){
                enem_pos = rand() % chambers[enem_chamb].coords.size();
                if(floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] == '.'){
                    floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] = 'E';
                    e[i]->set_x(chambers[enem_chamb].coords[enem_pos].x);
                    e[i]->set_y(chambers[enem_chamb].coords[enem_pos].y);
                    break;
                }
            }
            
        }
        else if(r==14 || r==15){
            Orc *o = new Orc();
            e.push_back(o);
            int enem_chamb;
            int enem_pos;
            enem_chamb = rand() % 5;
            while(true){
                enem_pos = rand() % chambers[enem_chamb].coords.size();
                if(floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] == '.'){
                    floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] = 'O';
                    e[i]->set_x(chambers[enem_chamb].coords[enem_pos].x);
                    e[i]->set_y(chambers[enem_chamb].coords[enem_pos].y);
                    break;
                }
            }
            
        } else {
            Merchant *m = new Merchant();
            e.push_back(m);
            int enem_chamb;
            int enem_pos;
            enem_chamb = rand() % 5;
            while(true){
                enem_pos = rand() % chambers[enem_chamb].coords.size();
                if(floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] == '.'){
                    floor[chambers[enem_chamb].coords[enem_pos].y][chambers[enem_chamb].coords[enem_pos].x] = 'M';
                    e[i]->set_x(chambers[enem_chamb].coords[enem_pos].x);
                    e[i]->set_y(chambers[enem_chamb].coords[enem_pos].y);
                    break;
                }
            }
            
        }
    }
    
    
    
}

void Game::drop_gold(int x, int y, string gold_name, int gold_value){
    Item *i = new Item;
    i->type = "Gold";
    i->x = x;
    i->y = y;
    i->used = false;
    i->gold_name = gold_name;
    i->value = gold_value;
    i->potion_name = "";
    i->effect = 0;
    golds.push_back(*i);
}


void Game:: set_pc(Player *pc) {
    p = pc;
}

Player * Game:: get_pc() {
    return p;
}

vector<Enemy *> Game:: get_e() {
    return e;
}

int Game:: get_floor() {
    return current_floor;
}

void Game:: upstairs() {
    ++current_floor;
}


Game:: ~Game() {
    if(p != nullptr) {
        delete p; // delete p
        p = nullptr;
    }
    
    // delete enemy
    while(!e.empty()) {
        Enemy *en = e.back();
        if(en != nullptr) {
            delete en;
        }
        e.pop_back();
    }
    
    while(!golds.empty()) {
        golds.pop_back();
    }
    
    while(!potions.empty()) {
        potions.pop_back();
    }
    
    while(!empty_floor.empty()) {
        empty_floor.pop_back();
    }
    
    while(!floor.empty()) {
        floor.pop_back();
    }
    
    
    
}



std::ostream & operator<< (std::ostream &out, Game &g) {
    
    // print the map(floor)
    for(int i = 0; i < g.floor.size(); ++i) {
        cout << g.floor[i] << endl;
    }
    
    cout << "Floor: " << g.current_floor+1 << endl;
    
    cout << "Race: " << g.p->get_pc_name() << endl;
    
    cout << "Gold: " << g.p->return_gold() << endl;
    cout << "HP: " << g.p->get_hp() << endl;
    cout << "Atk: " << g.p->get_atk() << endl;
    cout << "Def: " << g.p->get_def() << endl;
    
    
    // print PC's command
    cout << "Action: ";
    if(g.p->get_output() != "") {
        cout << g.p->get_output() << endl;
    }
    
    
    // print enemies's command
    int s = g.e.size();
    for(int i = 0; i < s; ++i) {
        if(g.e[i]->get_output() != "") {
            cout << g.e[i]->get_output() << endl;
        }
    }
    return out;
}







