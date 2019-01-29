//
//  main.cpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#include <iostream>
#include "game.hpp"
#include "character.hpp"
#include "shade.hpp"
#include "drow.hpp"
#include "vampire.hpp"
#include "troll.hpp"
#include "goblin.hpp"

using namespace std;



int main(int argc, const char * argv[]) {
    bool has_file = false;
    string filename;
    if(argc == 1) { // if no in line argument
        has_file = false;
    } else if(argc == 2) { // if file name is provided
        has_file = true;
        filename = argv[1]; // read in file name
    } else {
        cout << "Expect at most one in line argument." << endl;
        return 0;
    }
    
    srand(unsigned (time(0)));
    
    while(true) {
        Game g;
        try {
            bool stop_e = false;
            
            // generate a player character
            cout << "Please choose a Player Character: " << endl;
            cout << "s for Shade" << endl;
            cout << "d for Drow" << endl;
            cout << "v for Vamire" << endl;
            cout << "t for Troll" << endl;
            cout << "g for Goblin" << endl;
            string cmd_pc;
            while(true) {
                cin >> cmd_pc;
                if(cmd_pc == "s") { // generate a Shade as player
                    g.set_pc(new Shade());
                    break;
                } else if(cmd_pc == "d") { // generate a Drow as player
                    g.set_pc(new Drow());
                    break;
                } else if(cmd_pc == "v") { // generate a Vampire as player
                    g.set_pc(new Vampire());
                    break;
                } else if(cmd_pc == "t") { // generate a Troll as player
                    g.set_pc(new Troll());
                    break;
                } else if(cmd_pc == "g") { // generate a Goblin as player
                    g.set_pc(new Goblin());
                    break;
                } else{ // unexpected command type in
                    cout << "Please type in s, d, v, t, or g to chose player character. " << endl;
                }
            }
            
            if(has_file) {
                g.new_game(filename); // generate a new game
                g.new_floor(filename); // generate a new floor
            } else {
                g.new_game(); // generate a new game
                g.new_floor(); // generate a new floor
            }
            
            cout << g;
            cout << "Player Character has generate successfully, which denotes as @ on map" << endl;
            
            while(true) {
                // do player next
                Player *pc = g.get_pc();
                try{
                    pc->next(g);
                }
                catch(string cmd) {
                    if(cmd == "PC dead") {
                        cout << g;
                        cout << pc->get_output() << endl;
                        cout << "PC dead, and you have collected ";
                        if(pc->get_pc_name() == "Shade") {
                                cout << 1.5*pc->return_gold();
                            } else {
                                cout << pc->return_gold();
                            }

                        cout << " value of gold. " << endl;
                        break;
                    }
                    if(cmd == "upstair") {
                        if(g.get_floor() < 4) {
                            
                            g.upstairs();
                            if(has_file) {
                                g.new_floor(filename);
                            } else {
                                g.new_floor();
                            }
                            g.set_pc(pc->new_player());
                            cout << g;
                            if(g.get_floor() == 0) {
                                cout << "This is the 1st floor. " << endl;
                            } else if(g.get_floor() == 1) {
                                cout << "This is the 2nd floor. " << endl;
                            } else if(g.get_floor() == 2) {
                                cout << "This is the 3rd floor. " << endl;
                            } else if(g.get_floor() == 3) {
                                cout << "This is the 4th floor. " << endl;
                            } else if(g.get_floor() == 4) {
                                cout << "This is the 5th floor. " << endl;
                            } else {
                                cout << "This is the " << g.get_floor()+1 << "th floor. " << endl;
                            }
                            continue;
                        }
                        else{
                            cout << g;
                            cout << pc->get_output() << endl;
                            cout << "PC wins, and you have collected ";
                            if(pc->get_pc_name() == "Shade") {
                                cout << 1.5*pc->return_gold();
                            } else {
                                cout << pc->return_gold();
                            }
                            cout << " value of gold. " << endl;
                            break;
                        }
                    }
                    if(cmd == "r") {
                        cout << "Restart the game? Type in y to quit, type in anything else to continue the game. " << endl;
                        string restart;
                        cin >> restart;
                        if(restart == "y") {
                            cout << g;
                            cout << "Restart game successfully, you have collected ";
                            if(pc->get_pc_name() == "Shade") {
                                cout << 1.5*pc->return_gold();
                            } else {
                                cout << pc->return_gold();
                            }

                            cout << " value of gold. " << endl;
                            throw 'r';
                        } else {
                            continue;
                        }
                    }
                    if(cmd == "q") {
                        cout << "Quit the game? Type in y to quit, type in anything else to continue the game. " << endl;
                        string quit;
                        cin >> quit;
                        if(quit == "y") {
                            cout << g;
                            cout << "Quit game successfully, you have collected ";
                            if(pc->get_pc_name() == "Shade") {
                                cout << 1.5*pc->return_gold();
                            } else {
                                cout << pc->return_gold();
                            }

                            cout << " value of gold. " << endl;
                            break;
                        } else {
                            continue;
                        }
                    }
                    if(cmd == "f") {
                        stop_e = !stop_e;
                        if(stop_e) {
                            cout << "Enemies will not move until type in command f. " << endl;
                        } else {
                            cout << "Enemies start to move now. ";
                            cout << "Type in command f to stop enemies. " << endl;
                        }
                        continue;
                    }
                }
                
                vector<Enemy*> enemy = g.get_e();
                
                // do enemy next
                if(!stop_e) { // if enemy are not stoped
                    try {
                        int s = enemy.size();
                        for(int i = 0; i < s; ++i) {
                            try{
                                enemy[i]->next(g);
                            } catch(string s){
                                if(s == "PC dead") {
                                    cout << g;
                                    cout << pc->get_output() << endl;
                                    cout << "PC dead, and you have collected ";
                                    if(pc->get_pc_name() == "Shade") {
                                cout << 1.5*pc->return_gold();
                            } else {
                                cout << pc->return_gold();
                            }

                                    cout << " value of gold. " << endl;
                                    throw string("PC dead");
                                }
                            }
                        }
                    } catch(string s) {
                        if(s == "PC dead") {
                            break;
                        }
                    }
                }
                pc->regain_hp(); // add_hp if pc is Troll
                cout << g;
            }
        } catch(char &c) {
            if(c == 'r') {
                continue;
            }
        }
        
        break;
    }
    

}
