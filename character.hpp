//
//  character.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef character_hpp
#define character_hpp
#include <string>
#include <vector>

class Game;

class Character {
protected:
    int x;
    int y;
    char race;
    int hp;
    int atk;
    int def;
    std::string output;
    int damage;
    
    

    
public:
    Character (int, int, int);
    virtual void next(Game&) = 0;  // move/attack
    virtual ~Character() = 0;
    int get_x();
    int get_y();
    void set_x(int);
    void set_y(int);
    void set_damage(int d);
    int get_atk();
    int get_hp();
    int get_def();
    int get_damage();
    std::string get_output();
    
    std::vector<int> change_xy(std::string cmd);
    
};


#endif /* character_hpp */
