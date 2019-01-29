//
//  game.hpp
//  cc3k_final_project
//
//  Created by group on 23/11/2016.
//  Copyright © 2016 group. All rights reserved.
//

#ifndef game_hpp
#define game_hpp
#include <vector>
#include "player.hpp"
#include "enemy.hpp"
#include <string>

class Game{
    int current_floor;
    //std::vector<std::string>floor;
    std::vector<std::string>empty_floor;
    
    struct Coordinate {
        int x;
        int y;
    };
    
    struct Chamber{
        std::vector<Coordinate> coords;
    };
    
    struct Item{
        int x,y;
        bool used;
        std::string type;
        std::string gold_name;
        int value;
        std::string potion_name;
        int effect;
    }; // Gold and Potion.
    
    Chamber chambers[5];
    std::vector <Item> golds;
    std::vector <Item> potions;
    std::vector <Enemy*> e;
    Player *p;
    //void print();
    
public:
    std::vector<std::string>floor;
    Game();
    //void Play();
    void new_floor();  // generate new floor without arg
    void new_floor(std::string); // generate new floor with arg
    void new_game(); // generate a new empty_floor without arg
    void new_game(std::string); // generate new floor with arg
    void drop_gold(int x, int y, std::string gold_name, int gold_value);
    void set_pc(Player *); // set pointer p
    Player * get_pc(); // return pointer p
    std::vector<Enemy *> get_e(); // return vector of enemies s
    int get_floor(); // return current floor number
    void upstairs(); // current_floor add 1
    ~Game();
    friend class Character;
    friend class Player;
    friend class Enemy;
    friend class Shade;
    friend class Drow;
    friend class Vampire;
    friend class Troll;
    friend class Goblin;
    friend class Halfling;
    friend class Human;
    friend class Dwarf;
    friend class Elf;
    friend class Orc;
    friend class Merchant;
    friend class Dragon;
    friend std::ostream & operator<< (std::ostream &, Game &);
    
};

std::ostream & operator<< (std::ostream &, Game &);

#endif /* game_hpp */
