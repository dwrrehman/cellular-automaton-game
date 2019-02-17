//
//  interactions.cpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#include "interactions.hpp"

#include "structures.h"
#include <vector>
#include <iostream>
#include "prettyprint.hpp"
#include "convert.hpp"
#include "globals.hpp"
#include "parameters.hpp"
#include "io.hpp"

void add_raw_interaction(std::vector<interaction_type> &interactions) {
    
    std::string from_block = "", to_block = "", result_block = "", direction_string = "";
    size_t from_energy = 0, to_energy = 0, result_energy = 0;
    std::cin >> from_block;
    std::cin >> from_energy;
    std::cin >> to_block;
    std::cin >> to_energy;
    std::cin >> result_block;
    std::cin >> result_energy;
    std::cin >> direction_string;
    
    if (convert_block_string(from_block) != block_count &&
        convert_block_string(to_block) != block_count &&
        convert_block_string(result_block) != block_count &&
        convert_direction_string(direction_string) != direction_count) {
        struct block from, to, result;
        enum direction direction = convert_direction_string(direction_string);
        from.id = convert_block_string(from_block);
        from.energy = from_energy;
        to.id = convert_block_string(to_block);
        to.energy = to_energy;
        result.id = convert_block_string(result_block);
        result.energy = result_energy;
        
        interaction_type i = {from, to, result, direction};
        interactions.push_back(i);
        std::cout << "added:\n\t";
        print_interaction(i);
        std::cout << std::endl;
        
    } else {
        std::cout << "couldnt create interaction with: " << std::endl;
        std::cout << "\t from : " << from_block << std::endl;
        std::cout << "\t to : " << to_block << std::endl;
        std::cout << "\t result : " << result_block << std::endl;
        std::cout << "\t direction : " << direction_string << std::endl;
        std::cout << std::endl;
    }
}

void find_and_remove_interaction(std::vector<interaction_type> &interactions) {
    
    std::string from_block = "", to_block = "", result_block = "", direction_string = "";
    size_t from_energy = 0, to_energy = 0, result_energy = 0;
    std::cin >> from_block;
    std::cin >> from_energy;
    std::cin >> to_block;
    std::cin >> to_energy;
    std::cin >> result_block;
    std::cin >> result_energy;
    std::cin >> direction_string;
    
    if (convert_block_string(from_block) != block_count &&
        convert_block_string(to_block) != block_count &&
        convert_block_string(result_block) != block_count &&
        convert_direction_string(direction_string) != direction_count) {
        struct block from, to, result;
        enum direction direction = convert_direction_string(direction_string);
        from.id = convert_block_string(from_block);
        from.energy = from_energy;
        to.id = convert_block_string(to_block);
        to.energy = to_energy;
        result.id = convert_block_string(result_block);
        result.energy = result_energy;
        
        interactions.erase(std::remove_if(interactions.begin(), interactions.end(), [=](const std::tuple<struct block, struct block, struct block, enum direction> interaction){
            auto [this_from, this_to, this_result, this_direction] = interaction;
            return this_from == from && this_to == to && this_result == result && this_direction == direction;
        }));
        std::cout << "removed interaction." << std::endl;
        
    } else {
        std::cout << "couldnt remove interaction: " << std::endl;
        std::cout << "\t from : " << from_block << std::endl;
        std::cout << "\t to : " << to_block << std::endl;
        std::cout << "\t result : " << result_block << std::endl;
        std::cout << "\t direction : " << direction_string << std::endl;
        std::cout << std::endl;
    }
}

void add_omnidirectional_interaction(std::vector<interaction_type> &interactions) {
    
    std::string from_block = "", to_block = "", result_block = "";
    size_t from_energy = 0, to_energy = 0, result_energy = 0;
    std::cin >> from_block;
    std::cin >> from_energy;
    std::cin >> to_block;
    std::cin >> to_energy;
    std::cin >> result_block;
    std::cin >> result_energy;
    
    if (convert_abstract_block_string(from_block) != block_count &&
        convert_abstract_block_string(to_block) != block_count &&
        convert_abstract_block_string(result_block) != block_count) {
        struct block from, to, result;
        from.id = convert_abstract_block_string(from_block);
        from.energy = from_energy;
        to.id = convert_abstract_block_string(to_block);
        to.energy = to_energy;
        result.id = convert_abstract_block_string(result_block);
        result.energy = result_energy;
        
        std::vector block_shifts = {0,1,2,3};                       // turns a state like one_up, into:      one_up, one_down, one_left, one_right,      for example.
        std::vector directions = {up, down, left, right};
        
        for (auto dir : directions) {
            
            for (auto fromshift : block_shifts) {
                const enum blocks f = (enum blocks) (from.id + fromshift);
                
                for (auto toshift : block_shifts) {
                    const enum blocks t = (enum blocks) (to.id + toshift);
                    
                    if (fromshift == dir) {
                        interaction_type i = {{f, from.energy}, {t, to.energy}, {t, result.energy}, dir};
                        interactions.push_back(i);
                        std::cout << "added omni:\n\t";
                        print_interaction(i);
                        std::cout << std::endl;
                    }
                }
            }
        }
        
        std::cout << "added all omni." << std::endl;
        
    } else {
        std::cout << "couldnt add abstract interaction: " << std::endl;
        std::cout << "\t from : " << from_block << std::endl;
        std::cout << "\t to : " << to_block << std::endl;
        std::cout << "\t result : " << result_block << std::endl;
        std::cout << std::endl;
    }
}


void find_interaction(std::vector<interaction_type> &interactions) {
    std::cout << "unimplemented!" << std::endl;
}

void list_interaction(std::vector<interaction_type> &interactions) {
    std::cout << "all interactions currently defined:\n" << std::endl;
    for (auto interaction : interactions) print_interaction(interaction);
    std::cout << "\ndone." << std::endl;
}

void print_help_message() {
    std::cout << "available commands:\n\n\t . \
    addraw  <fb> <fe>  <tb> <te>  <rb> <re> <dir>\n\t . \
    removeraw <fb> <fe>  <tb> <te>  <rb> <re> <dir>\n\t . \
    add_omni <afb> <fe>  <atb> <te>  <arb> <re> \n\t . \
    add_omni_rotational <afb> <fe>  <tb> <te>  <rb> <re> \n\t . \
    list : lists the current interactions.\n\t . \
    undefined <fb> <fe>  <tb> <te>  <rb> <re> <dir> : does something.\n\t . \
    find from [<fb> <fe>]/[null] to [<tb> <te>]/[null] result [<rb> <re>]/[null] direction [<dir>]/[null]\n\t . \
    clear : clears the screen. \n\t . \
    delete_all_interactions: deletes all current interactions.\n\t . \
    quit : quits the interaction terminal .\n\t . \
    help : this help menu.\n" << std::endl;
}

void modify_interactions(std::vector<interaction_type> &interactions) {
    input_paused = true;
    
    clear_screen();
    std::cout << "a interaction manipulator terminal. \ntype help for more info." << std::endl;
    
    std::string interaction_input;
    do {
        std::cout << ">>> ";
        
        interaction_input = "";
        std::cin >> interaction_input;
        
        if (interaction_input == "help") {
            print_help_message();
            
        } else if (interaction_input == "addraw") {
            add_raw_interaction(interactions);
            
        } else if (interaction_input == "add_omni") {
            add_omnidirectional_interaction(interactions);
            
        } else if (interaction_input == "removeraw") {
            find_and_remove_interaction(interactions);
            
        } else if (interaction_input == "list") {
            list_interaction(interactions);
            
        } else if (interaction_input == "clear") {
            clear_screen();
            
        } else if (interaction_input == "delete_all_interactions") {
            interactions.clear();
            
        } else if (interaction_input == "find") {
            find_interaction(interactions);
            
        } else {
            std::cout << "unknown command: " << interaction_input << std::endl;
        }
        
    } while(interaction_input != "quit");
    
    input_paused = false;
}
