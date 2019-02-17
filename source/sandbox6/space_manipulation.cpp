//
//  space_manipulation.cpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#include "space_manipulation.hpp"

#include "globals.hpp"
#include "parameters.hpp"
#include <stdlib.h>

void create(struct block** &space) {
    space = (struct block**) malloc(sizeof(struct block*) * height);
    for (int i = 0; i < height; i++)
        space[i] = (struct block*) calloc(width, sizeof(struct block));
}

void destroy(struct block** &space) {
    for (int i = 0; i < height; i++) free(space[i]);
    free(space);
}

void place_player_in(struct block** space) {
    struct point place = {rand() % width, rand() % height};
    player = place;
    player_energy = 2;
    space[place.y][place.x].id = player_block;
    space[place.y][place.x].energy = player_energy;
}

void fill_with_air(struct block** space) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            space[i][j].id = blocks::air;
        }
    }
}

void copy_space(struct block** oldspace, struct block** newspace) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            newspace[i][j] = oldspace[i][j];
        }
    }
}
