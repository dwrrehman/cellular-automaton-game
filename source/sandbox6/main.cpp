//
//  main.cpp
//  sandbox6
//
//  Created by Daniel Rehman on 1901222.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

/// This is a game / cellular automata experiment. (CA draft 1)





/**     ------------------------- TODOS: -------------------------------------
 
 - we should make [SPACEBAR] the "player toggle activate/deactive" action,
 
 - and then we should make [i][j][k][l] the player can activate/deactive a space next to him/her.
 
 
 - we need to add color to this!!!!
 
 
 - we should have a debug more, which you get into by pressing "b", or something like that.
 
 
 in that mode we need to be able to print out the file, (config and interact) and also print out the internal datastructures, such as player position, interactins array, sparse game board as numeric list, etc.
 
 
 -------------------------------------------------------------------------
 
 */


#include <iostream>
#include <fstream>
#include <stdint.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <thread>
#include <vector>
#include <string>


#include "structures.h"
#include "parameters.hpp"
#include "globals.hpp"
#include "space_manipulation.hpp"
#include "configuration.hpp"
#include "convert.hpp"
#include "prettyprint.hpp"
#include "io.hpp"
#include "interactions.hpp"
#include "gameloops.hpp"
#include "execute.hpp"
#include "color.h"

int main() {
    srand((unsigned) time(nullptr));
    
    std::vector<interaction_type> interactions = {};
    struct block** space = nullptr;
    
    create(space);
    fill_with_air(space);
    
    if (should("load from a config file")) {
        load_configuration();
        configure(space);
    } else place_player_in(space);
    if (should("load interactions")) load_interactions(interactions);

    std::thread get_input_thread = std::thread(get_input);
    std::thread display_thread = std::thread(interface, space, &interactions);
    simulate(space, interactions);
    display_thread.join();
    get_input_thread.join();
    
    if (should("save to a file")) save_configuration(space);
    if (should("save interactions")) save_interactions(interactions);
    destroy(space);
    
    clear_screen();
    std::cout << exit_message << std::endl;
    return 0;
}
