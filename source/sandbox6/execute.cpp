//
//  execute.cpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#include <vector>
#include <iostream>
#include <unistd.h>

#include "execute.hpp"
#include "io.hpp"
#include "parameters.hpp"
#include "globals.hpp"
#include "structures.h"
#include "prettyprint.hpp"
#include "configuration.hpp"
#include "interactions.hpp"



inline static void increment_state(struct block **space) {
    auto& new_block = space[hand.y][hand.x].id;
    
    if (current_selected_block == air) {
        new_block = (enum blocks) (current_selected_block = block_count - 1);
    } else new_block = (enum blocks)(--current_selected_block);
}

inline static void decrement_state(struct block **space) {
    auto& new_block = space[hand.y][hand.x].id;
    
    if (current_selected_block == block_count - 1) {
        current_selected_block = new_block = air;
    } else new_block = (enum blocks) (++current_selected_block);
}

inline static void toggle_player_mode() {
    if (mode == hand_control) {
        message = "[entering player mode]";
        mode = player_control;
    } else if (mode == player_control) {
        message = "[entering hand mode]";
        mode = hand_control;
    }
}

void execute_command(struct block** space, std::vector<interaction_type> &interactions) {
    
    if (!input) return;
    
    // Move Hand:
    else if (input == 'w' && hand.y && mode == hand_control) hand.y -= 1;
    else if (input == 's' && hand.y < height - 1 && mode == hand_control) hand.y += 1;
    else if (input == 'a' && hand.x && mode == hand_control) hand.x -= 1;
    else if (input == 'd' && hand.x < width - 1 && mode == hand_control) hand.x += 1;
    
    
    // Move Player:
    else if (input == 'w'
             && player.y
             && mode == player_control
             && space[player.y-1][player.x].id == air)
    {
        space[player.y][player.x] = {air, 0};
        player.y -= 1;
        space[player.y][player.x] = {player_block, player_energy};
    }
    
    else if (input == 's'
             && player.y < height - 1
             && mode == player_control
             && space[player.y+1][player.x].id == air)
    {
        space[player.y][player.x] = {air, 0};
        player.y += 1;
        space[player.y][player.x] = {player_block, player_energy};
    }
    
    else if (input == 'a'
             && player.x
             && mode == player_control
             && space[player.y][player.x-1].id == air)
    {
        space[player.y][player.x] = {air, 0};
        player.x -= 1;
        space[player.y][player.x] = {player_block, player_energy};
    }
    
    else if (input == 'd'
             && player.x < width - 1
             && mode == player_control
             && space[player.y][player.x+1].id == air)
    {
        space[player.y][player.x] = {air, 0};
        player.x += 1;
        space[player.y][player.x] = {player_block, player_energy};
    }
    
    // Do other commands:
    else if (input == clear_state && mode == hand_control) {
        space[hand.y][hand.x] = {air, 0};
    } else if (input == change_state_down && mode == hand_control) {
        decrement_state(space);
    } else if (input == change_state_up && mode == hand_control) {
        increment_state(space);
        
    } else if (input == decrease_activation && mode == hand_control) {
        space[hand.y][hand.x].energy += energy_count - 1;
        space[hand.y][hand.x].energy %= energy_count;
        
    } else if (input == increase_activation && mode == hand_control) {
        space[hand.y][hand.x].energy += 1;
        space[hand.y][hand.x].energy %= energy_count;
        
        
    } else if (input == pause_command) {
        message = "paused";
        paused = true;
    } else if (input == unpause_command) {
        message = "running";
        paused = false;
        
    } else if (input == toggle_player) {
        toggle_player_mode();
        
    } else if (input == save_game_state_command) {
        input_paused = true;
        if (should("save the game")) save_configuration(space);
        message = "saved game.";
        input_paused = false;
        
    } else if (input == save_interactions_command) {
        input_paused = true;
        if (should("save all interactions")) save_interactions(interactions);
        message = "saved interations.";
        input_paused = false;
        
    } else if (input == modify_interactions_command) {
        message = "entering interaction shell... ";
        draw(space);
        usleep(500000);
        modify_interactions(interactions);
        
    } else if (input == help_command) {
        input_paused = true;
        clear_screen();
        std::cout << help_message << std::endl;
        getch();
        message = "done.";
        input_paused = false;
        
    } else if (input != 'w' && input != 'a' && input != 's' && input != 'd'){
        message = "received unmapped: ";
        message.push_back(input);
        message += " (" + std::to_string((size_t) input) + ")";
    }
    input = null_command;
}
