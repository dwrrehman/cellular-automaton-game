//
//  gameloops.cpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#include <vector>

#include "gameloops.hpp"
#include "globals.hpp"
#include "parameters.hpp"
#include "structures.h"
#include "prettyprint.hpp"
#include "io.hpp"
#include "space_manipulation.hpp"
#include <unistd.h>

#include "execute.hpp"

inline static void evolve(struct block** space, std::vector<interaction_type> &interactions) {
    struct block** newspace;
    create(newspace);
    copy_space(space, newspace);
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            
            for (auto [from, to, result, direction] : interactions) {
                
                if (direction == up && i > 0 && space[i][j] == from && space[i-1][j] == to)
                    newspace[i-1][j] = result;
                
                else if (direction == down && i < height - 1 && space[i][j] == from && space[i+1][j] == to)
                    newspace[i+1][j] = result;
                
                else if (direction == left && j > 0 && space[i][j] == from && space[i][j-1] == to)
                    newspace[i][j-1] = result;
                
                else if (direction == right && j < width - 1 && space[i][j] == from && space[i][j+1] == to)
                    newspace[i][j+1] = result;
                
                else if (direction == self && space[i][j] == from)
                    newspace[i][j] = result;
            }
            
            if (space[i][j].id == player_block && !(player.x == j && player.y == i))
                newspace[i][j] = {air, 0};
            
        }
    }
    copy_space(newspace, space);
    destroy(newspace);
}

void simulate(struct block** space, std::vector<interaction_type> &interactions) {
    while (!quitting) {
        if (!paused) evolve(space, interactions);
        usleep(500000);
    }
}

void interface(struct block** space, std::vector<interaction_type>* interactions) {
    while (input != quit || !should("quit")) {
        execute_command(space, *interactions);
        draw(space);
        usleep(75000);
    }
}

void get_input() {
    while (!quitting) {
        if (input != quit && !input_paused) input = getch();
        else sleep(1);
    }
}
