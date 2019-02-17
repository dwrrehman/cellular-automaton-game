//
//  structures.h
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#ifndef structures_h
#define structures_h


#include <stdlib.h>

#include <utility>

enum commands {
    null_command = '\0',
    help_command = '?',
    quit = 'x',
    toggle_player = 'e',
    change_state_up = ']',
    change_state_down = '[',
    increase_activation = '\'',
    decrease_activation = ';',
    pause_command = 'p',
    unpause_command = 'o',
    modify_interactions_command = 'u',
    clear_state = '\\',
    save_game_state_command = '.',
    save_interactions_command = ',',
};

enum blocks {
    air,
    
    zero_up,
    zero_down,
    zero_left,
    zero_right,
    
    one_up,
    one_down,
    one_left,
    one_right,
    
    two_up,
    two_down,
    two_left,
    two_right,
    
    player_block,
    
    block_count,
};

enum direction {
    up, down, left, right, self, direction_count
};

enum control_mode {
    hand_control, player_control
};

struct point {
    size_t x;
    size_t y;
};

struct block {
    enum blocks id;
    size_t energy;
    bool operator==(struct block x) {return this->id == x.id && this->energy == x.energy;}
};


using interaction_type = std::tuple<struct block, struct block, struct block, enum direction>;


#endif /* structures_h */
