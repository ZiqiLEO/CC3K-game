//
//  shade.cpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#include "shade.hpp"
#include "game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;



Shade:: Shade(): Player(120, 25, 25) {}


void Shade:: next(Game &g) {
    damage = 0;
    output = "";
    if(hp <= 0) { // if PC is dead
        throw string("PC dead");
    }
    output = "";
    string cmd;
    cin >> cmd;
    if(cmd == "no") { // if the PC move North
        bool move = true;
        if(g.floor[y-1][x] == '.'
            || g.floor[y-1][x] == '+'
            || g.floor[y-1][x] == '#') { // if the PC move to ., + or #
            g.floor[y][x] = sym_before;
            // change the char at this position to previous char
            sym_before = g.floor[y-1][x]; // save the char at this position
            y -= 1;
            g.floor[y][x] = '@'; // change the char to @
        } else if(g.floor[y-1][x] == '\\') { // PC go upstairs
            throw string("upstair");
        } else if(g.floor[y-1][x] == 'G') { // pick gold
            g.floor[y][x] = sym_before;
            sym_before = '.'; // save the char at this position as .
            y -= 1;
            g.floor[y][x] = '@';
            
            // find if the gold
            int s = g.golds.size();
            for(int i = 0; i < s; ++i) {
                if(g.golds[i].x == x && g.golds[i].y == y) {
                    if(g.golds[i].gold_name != "dragon_hoard") {
                        // if gold is not dragon hoard
                        int v = g.golds[i].value;
                        output += "PC picked a gold with value " + to_string(v) + ". ";
                        gold += v;
                            
                            
                    } else {
                        // if the gold is dragon hoard, check if dragon is still alive
                        bool found = false;
                        for(int n = y-1; n <= y+1; ++n) {
                            for(int m = x-1; m <= x+1; ++m) {
                                
                                // check if there is a dragon around the dragon hoard
                                if(g.floor[n][m] == 'D') {
                                        
                                    // if so, check if the dragon is the one belong to this dragon hoard
                                    int s = g.e.size();
                                    for(int a = 0; a < s; ++a) {
                                        if(g.e[a]->get_x()==m && g.e[a]->get_y()==n &&
                                            g.e[a]->hoard_pos()[0]==x && g.e[a]->hoard_pos()[1]==y) {
                                            found = true; // dragon is found
                                            output += "Dragon is still alive, Dragon Hoard cannot be picked";
                                            sym_before = 'G';
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        if(!found) {
                            int v = g.golds[i].value;
                            output += "PC picked a gold with value " + to_string(v) + ". ";
                            gold += v;
                        }
                    }
                }
            }
        } else {
            move = false;
            output += "Cannot move to North. Please check if type in right command. ";
        }
        
        // find if there are posion next to PC
        if(move) {
            for(int i = y-1; i <= y+1; ++i){
                for(int j = x-1; j <= x+1; ++j) {
                    if(g.floor[i][j] == 'P') {
                        output += "PC moves North and sees ";
                        int s = g.potions.size();
                        for(int k = 0; k < s; ++k) {
                            if(g.potions[k].y == i && g.potions[k].x == j) {
                                int s_p = used_p.size();
                                bool found_p = false;
                                for(int i =0; i < s_p; ++i) {
                                    if(used_p[i] == g.potions[k].potion_name) {
                                        output += "a " + g.potions[k].potion_name + ". ";
                                        found_p = true;
                                        break;
                                    }
                                }
                                if(!found_p) {
                                    output += "an unknow potion. ";
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else if(cmd == "so") {
        bool move = true;
        if(g.floor[y+1][x] == '.'
            || g.floor[y+1][x] == '+'
            || g.floor[y+1][x] == '#') {
            g.floor[y][x] = sym_before;
            sym_before = g.floor[y+1][x];
            y += 1;
            g.floor[y][x] = '@';
        } else if(g.floor[y+1][x] == '\\') { // go upstairs
            throw string("upstair");
        } else if(g.floor[y+1][x] == 'G') { // pick gold
            g.floor[y][x] = sym_before;
            sym_before = '.';
            y += 1;
            g.floor[y][x] = '@';
            int s = g.golds.size();
            // find the value of gold
            for(int i = 0; i < s; ++i) {
                if(g.golds[i].x == x && g.golds[i].y == y) {
                    if(g.golds[i].gold_name != "dragon_hoard") {
                        int v = g.golds[i].value;
                        output += "PC picked a gold with value " + to_string(v) + ". ";
                        gold += v;
                    } else { // if the gold is dragon hoard
                        bool found = false;
                        for(int n = y-1; n <= y+1; ++n) {
                            for(int m = x-1; m <= x+1; ++m) {
                                // check if there is a dragon around the dragon hoard
                                if(g.floor[n][m] == 'D') {
                                    
                                    // if so, check if the dragon is the one belong to this dragon hoard
                                    int s = g.e.size();
                                    for(int a = 0; a < s; ++a) {
                                        if(g.e[a]->get_x()==m && g.e[a]->get_y()==n &&
                                            g.e[a]->hoard_pos()[0]==x && g.e[a]->hoard_pos()[1]==y) {
                                            found = true; // dragon is found
                                            output += "Dragon is still alive, Dragon Hoard cannot be picked";
                                            sym_before = 'G';
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        if(!found) { // if the dragon was dead
                            int v = g.golds[i].value;
                            output += "PC picked a gold with value " + to_string(v) + ". ";
                            gold += v;
                        }
                    }
                }
            }
        } else {
            move = false;
            output += "Cannot move to South. Please check if type in right command. ";
        }
        // find potion
        if(move) {
            for(int i = y-1; i <= y+1; ++i){
                for(int j = x-1; j <= x+1; ++j) {
                    if(g.floor[i][j] == 'P') {
                        output += "PC moves South and sees ";
                        int s = g.potions.size();
                        for(int k = 0; k < s; ++k) {
                            if(g.potions[k].y == i && g.potions[k].x == j) {
                                int s_p = used_p.size();
                                bool found_p = false;
                                for(int i =0; i < s_p; ++i) {
                                    if(used_p[i] == g.potions[k].potion_name) {
                                        output += "a " + g.potions[k].potion_name + ". ";
                                        found_p = true;
                                        break;
                                    }
                                }
                                if(!found_p) {
                                    output += "an unknow potion. ";
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else if(cmd == "ea") {
        bool move = true;
        if(g.floor[y][x+1] == '.'
            || g.floor[y][x+1] == '+'
            || g.floor[y][x+1] == '#') {
            g.floor[y][x] = sym_before;
            sym_before = g.floor[y][x+1];
            x += 1;
            g.floor[y][x] = '@';
        } else if(g.floor[y][x+1] == '\\') { // '\'
            throw string("upstair");
        } else if(g.floor[y][x+1] == 'G') {
            g.floor[y][x] = sym_before;
            sym_before = '.';
            x += 1;
            g.floor[y][x] = '@';
            int s = g.golds.size();
            for(int i = 0; i < s; ++i) {
                if(g.golds[i].x == x && g.golds[i].y == y) {
                    if(g.golds[i].gold_name != "dragon_hoard") {
                        int v = g.golds[i].value;
                        output += "PC picked a gold with value " + to_string(v) + ". ";
                        gold += v;
                    } else {
                        bool found = false;
                        for(int n = y-1; n <= y+1; ++n) {
                            for(int m = x-1; m <= x+1; ++m) {
                                // check if there is a dragon around the dragon hoard
                                if(g.floor[n][m] == 'D') {
                                    
                                    // if so, check if the dragon is the one belong to thisdragon hoard
                                    int s = g.e.size();
                                    for(int a = 0; a < s; ++a) {
                                        if(g.e[a]->get_x()==m && g.e[a]->get_y()==n &&
                                            g.e[a]->hoard_pos()[0]==x && g.e[a]->hoard_pos()[1]==y) {
                                            found = true; // dragon is found
                                            output += "Dragon is still alive, Dragon Hoard cannot be picked";
                                            sym_before = 'G';
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        if(!found) {
                            int v = g.golds[i].value;
                            output += "PC picked a gold with value " + to_string(v) + ". ";
                            gold += v;
                        }
                    }
                }
            }
        } else {
            move = false;
            output += "Cannot move to East. Please check if type in right command. ";
        }
        if(move){
            for(int i = y-1; i <= y+1; ++i){
                for(int j = x-1; j <= x+1; ++j) {
                    if(g.floor[i][j] == 'P') {
                        output += "PC moves East and sees ";
                        int s = g.potions.size();
                        for(int k = 0; k < s; ++k) {
                            if(g.potions[k].y == i && g.potions[k].x == j) {
                                int s_p = used_p.size();
                                bool found_p = false;
                                for(int i =0; i < s_p; ++i) {
                                    if(used_p[i] == g.potions[k].potion_name) {
                                        output += "a " + g.potions[k].potion_name + ". ";
                                        found_p = true;
                                        break;
                                    }
                                }
                                if(!found_p) {
                                    output += "an unknow potion. ";
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else if(cmd == "we") {
        bool move = true;
        if(g.floor[y][x-1] == '.'
            || g.floor[y][x-1] == '+'
            || g.floor[y][x-1] == '#') {
            g.floor[y][x] = sym_before;
            sym_before = g.floor[y][x-1];
            x -= 1;
            g.floor[y][x] = '@';
        } else if(g.floor[y][x-1] == '\\') { // '\'
            throw string("upstair");
        } else if(g.floor[y][x-1] == 'G') {
            g.floor[y][x] = sym_before;
            sym_before = '.';
            x -= 1;
            g.floor[y][x] = '@';
            int s = g.golds.size();
            // find the value of gold
            for(int i = 0; i < s; ++i) {
                if(g.golds[i].x == x && g.golds[i].y == y) {
                    if(g.golds[i].gold_name != "dragon_hoard") {
                        int v = g.golds[i].value;
                        output += "PC picked a gold with value " + to_string(v) + ". ";
                        gold += v;
                    } else { // if the gold is dragon hoard
                        bool found = false;
                        for(int n = y-1; n <= y+1; ++n) {
                            for(int m = x-1; m <= x+1; ++m) {
                                
                                // check if there is a dragon around the dragon hoard
                                if(g.floor[n][m] == 'D') {
                                    
                                    // if so, check if the dragon is the one belong to this dragon hoard
                                    int s = g.e.size();
                                    for(int a = 0; a < s; ++a) {
                                        if(g.e[a]->get_x()==m && g.e[a]->get_y()==n &&
                                            g.e[a]->hoard_pos()[0]==x && g.e[a]->hoard_pos()[1]==y) {
                                            found = true; // dragon is found
                                            output += "Dragon is still alive, Dragon Hoard cannot be picked";
                                            sym_before = 'G';
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        if(!found) { // if the dradong was dead
                            int v = g.golds[i].value;
                            output += "PC picked a gold with value " + to_string(v) + ". ";
                            gold += v;
                        }
                    }
                }
            }
        } else {
            move = false;
            output += "Cannot move to West. Please check if type in right command. ";
        }
        if(move) {
            for(int i = y-1; i <= y+1; ++i){
                for(int j = x-1; j <= x+1; ++j) {
                    if(g.floor[i][j] == 'P') {
                        output += "PC moves West and sees ";
                        int s = g.potions.size();
                        for(int k = 0; k < s; ++k) {
                            if(g.potions[k].y == i && g.potions[k].x == j) {
                                int s_p = used_p.size();
                                bool found_p = false;
                                for(int i =0; i < s_p; ++i) {
                                    if(used_p[i] == g.potions[k].potion_name) {
                                        output += "a " + g.potions[k].potion_name + ". ";
                                        found_p = true;
                                        break;
                                    }
                                }
                                if(!found_p) {
                                    output += "an unknow potion. ";
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else if(cmd == "ne") {
        bool move = true;
        if(g.floor[y-1][x+1] == '.'
            || g.floor[y-1][x+1] == '+'
            || g.floor[y-1][x+1] == '#') {
            g.floor[y][x] = sym_before;
            sym_before = g.floor[y-1][x+1];
            y -= 1;
            x += 1;
            g.floor[y][x] = '@';
        } else if(g.floor[y+1][x-1] == '\\') { // '\'
            throw string("upstair");
        } else if(g.floor[y-1][x+1] == 'G') {
            g.floor[y][x] = sym_before;
            sym_before = '.';
            y -= 1;
            x += 1;
            g.floor[y][x] = '@';
            int s = g.golds.size();
            // find the value of gold
            for(int i = 0; i < s; ++i) {
                if(g.golds[i].x == x && g.golds[i].y == y) {
                    if(g.golds[i].gold_name != "dragon_hoard") {
                        int v = g.golds[i].value;
                        output += "PC picked a gold with value " + to_string(v) + ". ";
                        gold += v;
                    } else { // if the gold is dragon hoard
                        bool found = false;
                        for(int n = y-1; n <= y+1; ++n) {
                            for(int m = x-1; m <= x+1; ++m) {
                                // check if there is a dragon around the dragon hoard
                                if(g.floor[n][m] == 'D') {
                                    
                                    // if so, check if the dragon is the one belong to this dragon hoard
                                    int s = g.e.size();
                                    for(int a = 0; a < s; ++a) {
                                        if(g.e[a]->get_x()==m && g.e[a]->get_y()==n &&
                                            g.e[a]->hoard_pos()[0]==x && g.e[a]->hoard_pos()[1]==y) {
                                            found = true; // dragon is found
                                            output += "Dragon is still alive, Dragon Hoard cannot be picked";
                                            sym_before = 'G';
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        if(!found) { // if the dradong was dead
                            int v = g.golds[i].value;
                            output += "PC picked a gold with value " + to_string(v) + ". ";
                            gold += v;
                        }
                    }
                }
            }
        } else {
            move = false;
            output += "Cannot move to North East. Please check if type in right command. ";
        }
        if(move){
            for(int i = y-1; i <= y+1; ++i){
                for(int j = x-1; j <= x+1; ++j) {
                    if(g.floor[i][j] == 'P') {
                        output += "PC moves North East and sees ";
                        int s = g.potions.size();
                        for(int k = 0; k < s; ++k) {
                            if(g.potions[k].y == i && g.potions[k].x == j) {
                                int s_p = used_p.size();
                                bool found_p = false;
                                for(int i =0; i < s_p; ++i) {
                                    if(used_p[i] == g.potions[k].potion_name) {
                                        output += "a " + g.potions[k].potion_name + ". ";
                                        found_p = true;
                                        break;
                                    }
                                }
                                if(!found_p) {
                                    output += "an unknow potion. ";
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else if(cmd == "nw") {
        bool move = true;
        if(g.floor[y-1][x-1] == '.'
            || g.floor[y-1][x-1] == '+'
            || g.floor[y-1][x-1] == '#') {
            g.floor[y][x] = sym_before;
            sym_before = g.floor[y-1][x-1];
            y -= 1;
            x -= 1;
            g.floor[y][x] = '@';
        } else if(g.floor[y-1][x-1] == '\\') { // '\'
            throw string("upstair");
        } else if(g.floor[y-1][x-1] == 'G') {
            g.floor[y][x] = sym_before;
            sym_before = '.';
            y -= 1;
            x -= 1;
            g.floor[y][x] = '@';
            int s = g.golds.size();
            // find the value of gold
            for(int i = 0; i < s; ++i) {
                if(g.golds[i].x == x && g.golds[i].y == y) {
                    if(g.golds[i].gold_name != "dragon_hoard") {
                        int v = g.golds[i].value;
                        output += "PC picked a gold with value " + to_string(v) + ". ";
                        gold += v;
                    } else { // if the gold is dragon hoard
                        bool found = false;
                        for(int n = y-1; n <= y+1; ++n) {
                            for(int m = x-1; m <= x+1; ++m) {
                                // check if there is a dragon around the dragon hoard
                                if(g.floor[n][m] == 'D') {
                                    
                                    // if so, check if the dragon is the one belong to this dragon hoard
                                    int s = g.e.size();
                                    for(int a = 0; a < s; ++a) {
                                        if(g.e[a]->get_x()==m && g.e[a]->get_y()==n &&
                                            g.e[a]->hoard_pos()[0]==x && g.e[a]->hoard_pos()[1]==y) {
                                            found = true; // dragon is found
                                            output += "Dragon is still alive, Dragon Hoard cannot be picked";
                                            sym_before = 'G';
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        if(!found) { // if the dradong was dead
                            int v = g.golds[i].value;
                            output += "PC picked a gold with value " + to_string(v) + ". ";
                            gold += v;
                        }
                    }
                }
            }
        } else {
            move = false;
            output += "Cannot move to North West. Please check if type in right command. ";
        }
        if(move){
            for(int i = y-1; i <= y+1; ++i){
                for(int j = x-1; j <= x+1; ++j) {
                    if(g.floor[i][j] == 'P') {
                        output += "PC moves North West and sees ";
                        int s = g.potions.size();
                        for(int k = 0; k < s; ++k) {
                            if(g.potions[k].y == i && g.potions[k].x == j) {
                                int s_p = used_p.size();
                                bool found_p = false;
                                for(int i =0; i < s_p; ++i) {
                                    if(used_p[i] == g.potions[k].potion_name) {
                                        output += "a " + g.potions[k].potion_name + ". ";
                                        found_p = true;
                                        break;
                                    }
                                }
                                if(!found_p) {
                                    output += "an unknow potion. ";
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else if(cmd == "se") {
        bool move = true;
        if(g.floor[y+1][x+1] == '.'
            || g.floor[y+1][x+1] == '+'
            || g.floor[y+1][x+1] == '#') {
            g.floor[y][x] = sym_before;
            sym_before = g.floor[y+1][x+1];
            y += 1;
            x += 1;
            g.floor[y][x] = '@';
        } else if(g.floor[y+1][x+1] == '\\') { // '\'
            throw string("upstair");
        } else if(g.floor[y+1][x+1] == 'G') {
            g.floor[y][x] = sym_before;
            sym_before = '.';
            y += 1;
            x += 1;
            g.floor[y][x] = '@';
            int s = g.golds.size();
            // find the value of gold
            for(int i = 0; i < s; ++i) {
                if(g.golds[i].x == x && g.golds[i].y == y) {
                    if(g.golds[i].gold_name != "dragon_hoard") {
                        int v = g.golds[i].value;
                        output += "PC picked a gold with value " + to_string(v) + ". ";
                        gold += v;
                    } else { // if the gold is dragon hoard
                        bool found = false;
                        for(int n = y-1; n <= y+1; ++n) {
                            for(int m = x-1; m <= x+1; ++m) {
                                // check if there is a dragon around the dragon hoard
                                if(g.floor[n][m] == 'D') {
                                    
                                    // if so, check if the dragon is the one belong to this dragon hoard
                                    int s = g.e.size();
                                    for(int a = 0; a < s; ++a) {
                                        if(g.e[a]->get_x()==m && g.e[a]->get_y()==n &&
                                            g.e[a]->hoard_pos()[0]==x && g.e[a]->hoard_pos()[1]==y) {
                                            found = true; // dragon is found
                                            output += "Dragon is still alive, Dragon Hoard cannot be picked";
                                            sym_before = 'G';
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        if(!found) { // if the dradong was dead
                            int v = g.golds[i].value;
                            output += "PC picked a gold with value " + to_string(v) + ". ";
                            gold += v;
                        }
                    }
                }
            }
        } else {
            move = false;
            output += "Cannot move to South East. Please check if type in right command. ";
        }
        if(move) {
            for(int i = y-1; i <= y+1; ++i){
                for(int j = x-1; j <= x+1; ++j) {
                    if(g.floor[i][j] == 'P') {
                        output += "PC moves South East and sees ";
                        int s = g.potions.size();
                        for(int k = 0; k < s; ++k) {
                            if(g.potions[k].y == i && g.potions[k].x == j) {
                                int s_p = used_p.size();
                                bool found_p = false;
                                for(int i =0; i < s_p; ++i) {
                                    if(used_p[i] == g.potions[k].potion_name) {
                                        output += "a " + g.potions[k].potion_name + ". ";
                                        found_p = true;
                                        break;
                                    }
                                }
                                if(!found_p) {
                                    output += "an unknow potion. ";
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else if(cmd == "sw") {
        bool move = true;
        if(g.floor[y+1][x-1] == '.'
            || g.floor[y+1][x-1] == '+'
            || g.floor[y+1][x-1] == '#') {
            g.floor[y][x] = sym_before;
            sym_before = g.floor[y+1][x-1];
            y += 1;
            x -= 1;
            g.floor[y][x] = '@';
        } else if(g.floor[y+1][x-1] == '\\') { // '\'
            throw string("upstair");
        } else if(g.floor[y+1][x-1] == 'G') {
            g.floor[y][x] = sym_before;
            sym_before = '.';
            y += 1;
            x -= 1;
            g.floor[y][x] = '@';
            int s = g.golds.size();
            // find the value of gold
            for(int i = 0; i < s; ++i) {
                if(g.golds[i].x == x && g.golds[i].y == y) {
                    if(g.golds[i].gold_name != "dragon_hoard") {
                        int v = g.golds[i].value;
                        output += "PC picked a gold with value " + to_string(v) + ". ";
                        gold += v;
                    } else { // if the gold is dragon hoard
                        bool found = false;
                        for(int n = y-1; n <= y+1; ++n) {
                            for(int m = x-1; m <= x+1; ++m) {
                                // check if there is a dragon around the dragon hoard
                                if(g.floor[n][m] == 'D') {
                                
                                    // if so, check if the dragon is the one belong to this dragon hoard
                                    int s = g.e.size();
                                    for(int a = 0; a < s; ++a) {
                                        if(g.e[a]->get_x()==m && g.e[a]->get_y()==n &&
                                            g.e[a]->hoard_pos()[0]==x && g.e[a]->hoard_pos()[1]==y) {
                                            found = true; // dragon is found
                                            output += "Dragon is still alive, Dragon Hoard cannot be picked";
                                            sym_before = 'G';
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        if(!found) { // if the dradong was dead
                            int v = g.golds[i].value;
                            output += "PC picked a gold with value " + to_string(v) + ". ";
                            gold += v;
                        }
                    }
                }
            }
        } else {
            move = false;
            output += "Cannot move to South West. Please check if type in right command. ";
        }
        if(move) {
            for(int i = y-1; i <= y+1; ++i){
                for(int j = x-1; j <= x+1; ++j) {
                    if(g.floor[i][j] == 'P') {
                        output += "PC moves South West and sees ";
                        int s = g.potions.size();
                        for(int k = 0; k < s; ++k) {
                            if(g.potions[k].y == i && g.potions[k].x == j) {
                                int s_p = used_p.size();
                                bool found_p = false;
                                for(int i =0; i < s_p; ++i) {
                                    if(used_p[i] == g.potions[k].potion_name) {
                                        output += "a " + g.potions[k].potion_name + ". ";
                                        found_p = true;
                                        break;
                                    }
                                }
                                if(!found_p) {
                                    output += "an unknow potion. ";
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else if(cmd == "u") { // PC want to use posion
        string dir;
        cin >> dir;
        vector<int> xy = change_xy(dir);
        int s = g.potions.size();
        bool found_p = false;
        for(int i = 0; i < s; ++i) {
            if(g.potions[i].x == xy[0] && g.potions[i].y == xy[1]) {
                if(g.potions[i].potion_name == "RH") {
                    hp += g.potions[i].effect;
                    if(hp >= maxhp) {
                        hp = maxhp;
                    }
                    output += "PC used a RH. ";
                    g.floor[xy[1]][xy[0]] = '.';
                    int s_p = used_p.size();
                    bool used = false;
                    for(int i = 0; i < s_p; ++i) {
                        if(used_p[i] == "RH") {
                            used = true;
                        }
                    }
                    if(!used) {
                        used_p.push_back("RH");
                    }
                } else if(g.potions[i].potion_name == "PH") {
                    hp += g.potions[i].effect;
                    if(hp <= 0) {
                        hp = 0;
                        throw string("PC dead");
                    }
                    output += "PC used a PH. ";
                    g.floor[xy[1]][xy[0]] = '.';
                    int s_p = used_p.size();
                    bool used = false;
                    for(int i = 0; i < s_p; ++i) {
                        if(used_p[i] == "PH") {
                            used = true;
                        }
                    }
                    if(!used) {
                        used_p.push_back("PH");
                    }
                } else if(g.potions[i].potion_name == "BA") {
                    atk += g.potions[i].effect;
                    output += "PC used a BA. ";
                    g.floor[xy[1]][xy[0]] = '.';
                    int s_p = used_p.size();
                    bool used = false;
                    for(int i = 0; i < s_p; ++i) {
                        if(used_p[i] == "BA") {
                            used = true;
                        }
                    }
                    if(!used) {
                        used_p.push_back("BA");
                    }
                } else if(g.potions[i].potion_name == "WA") {
                    atk += g.potions[i].effect;
                    output += "PC used a WA. ";
                    g.floor[xy[1]][xy[0]] = '.';
                    int s_p = used_p.size();
                    bool used = false;
                    for(int i = 0; i < s_p; ++i) {
                        if(used_p[i] == "WA") {
                            used = true;
                        }
                    }
                    if(!used) {
                        used_p.push_back("WA");
                    }
                } else if(g.potions[i].potion_name == "BD") {
                    def += g.potions[i].effect;
                    output += "PC used a BD. ";
                    g.floor[xy[1]][xy[0]] = '.';
                    int s_p = used_p.size();
                    bool used = false;
                    for(int i = 0; i < s_p; ++i) {
                        if(used_p[i] == "BD") {
                            used = true;
                        }
                    }
                    if(!used) {
                        used_p.push_back("BD");
                    }
                } else if(g.potions[i].potion_name == "WD") {
                    def += g.potions[i].effect;
                    output += "PC used a WD. ";
                    g.floor[xy[1]][xy[0]] = '.';
                    int s_p = used_p.size();
                    bool used = false;
                    for(int i = 0; i < s_p; ++i) {
                        if(used_p[i] == "WD") {
                            used = true;
                        }
                    }
                    if(!used) {
                        used_p.push_back("WD");
                    }
                }
                found_p = true;
                break;
            }
        } // if there is no posion at the position PC wanna use, do nothing
        if(!found_p) {
            output += "No such potion found. Please check if type in right command";
        }
    } else if(cmd == "a") { // PC wanna attack enemy
        string dir;
        cin >> dir;
        char sym_en;
        Enemy *en = nullptr; // if there is no enemy, do nothing
        vector<int> xy = change_xy(dir);
        int len = g.e.size();
        int pos = 0;
        for(pos = 0; pos < len; ++pos) {
            int e_x = g.e[pos]->get_x();
            int e_y = g.e[pos]->get_y();
            if(xy[0] == e_x && xy[1] == e_y) {
                en = g.e[pos]; // en point to the enemy
                break;
            }
        }
        if(en == nullptr) {
            output += "No such enemy. Please check if type in a right command. ";
        } else {
            en->set_damage(0);
            sym_en = g.floor[xy[1]][xy[0]];
            int random = 0;
            if(en->halfling()) { // if the enemy if a halfling, may caused PC miss
                
                random = rand() % 2;
                if(random == 0) {
                    en->attacked(*this);
                    if(en->get_hp() <= 0) {
                        output += "PC deals " + to_string(en->get_damage()) + " damage to " + sym_en + " " + "(0 HP). ";
                    } else {
                        output += "PC deals " + to_string(en->get_damage()) + " damage to "
                        + sym_en + " " + "(" + to_string(en->get_hp()) + " HP). ";
                    }
                } else {
                    output += "L caused the attack of PC missed. ";
                }
            } else if(en->merchant()) { // the PC attack merchant
                en->attacked(*this);
                if(en->get_hp() <= 0) {
                    output += "PC deals " + to_string(en->get_damage()) + " damage to " + sym_en + " " + "(0 HP). ";
                } else {
                    output += "PC deals " + to_string(en->get_damage()) + " damage to "
                    + sym_en + " " + "(" + to_string(en->get_hp()) + " HP). ";
                }
                if(!merchant_hostile) {
                    output += "Because PC caused damage to a merchant, all merchant become hostile. ";
                }
                merchant_hostile = true;
            } else {
                en->attacked(*this);
                if(en->get_hp() <= 0) {
                    output += "PC deals " + to_string(en->get_damage()) + " damage to " + sym_en + " " + "(0 HP). ";
                } else {
                    output += "PC deals " + to_string(en->get_damage()) + " damage to "
                            + sym_en + " " + "(" + to_string(en->get_hp()) + " HP). ";
                }
            }
            
            if(en->dead() && random != 1) { // if the enemy dead, drop gold(s)
                
                // generate gold that enemy drop
                if(en->get_race() == 'H') {
                    // if the enemy is Human, drop 2 normal golds
                    
                    g.drop_gold(xy[0], xy[1], "normal", 2);
                        // drop a normal gold at the position Human was on
                    
                    // randomly drop a normal gold around the position Human was on
                    for(int i = 0; i < 100; ++i) {
                        
                        int random_drop = rand() % 8;
                        vector<int> xy_drop = change_xy(to_string(random_drop));
                        if(g.floor[xy_drop[1]][xy_drop[0]] == '.') {
                            g.floor[xy_drop[1]][xy_drop[0]] = 'G';
                            g.drop_gold(xy_drop[0], xy_drop[1], "normal", 2);
                            break;
                        }
                    }
                    output += "Human dead and drops 2 normal golds. ";
                    
                } else if(en->get_race() == 'M') {
                    // if the enemy is Merchant, drop a Merchant Hoard
                    g.drop_gold(xy[0], xy[1], "merchant hoard", 4);
                    output += "Merchant dead and drops a Merchant Hoard. ";
                    
                } else if(en->get_race() == 'D') {
                    // if the enemy is Dragon,
                    // just remove the enemy from both vector of enemies and map(floor)
                    output += "Dragon dead and you can pick up Dragon Hoard now! ";
                    
                } else {
                    // if the enemy is not H, M, or D, drop either a small or a normal gold
                
                    
                    int random_drop = rand() % 2;
                    if(random_drop == 0) { // randomly drop gold
                        g.drop_gold(xy[0], xy[1], "small", 1);
                        output += "Enemy dead and drops a small pile of gold. ";
                    } else {
                        g.drop_gold(xy[0], xy[1], "normal", 2);
                        output += "Enemy dead and drops a normal pile of gold. ";
                    }
                
                }
                if(en->get_race() != 'D') {
                    g.floor[xy[1]][xy[0]] = 'G'; // change the char the enemy stored in floor
                } else{
                    g.floor[xy[1]][xy[0]] = '.'; // remove dragon from map
                }
                g.e.erase(g.e.begin()+pos); // remove the enemy * stored in e
                en = nullptr;
            }
        }
    } else{
        throw cmd;
    }
    
}

string Shade:: get_pc_name() {
    return string("Shade");
}

Shade:: ~Shade() {}
