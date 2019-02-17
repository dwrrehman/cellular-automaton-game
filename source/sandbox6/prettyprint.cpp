//
//  prettyprint.cpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#include "prettyprint.hpp"
#include "structures.h"
#include "convert.hpp"
#include <iostream>
#include "color.h"

#include "parameters.hpp"

void print_block(struct block b) {
    if (b.energy < energy_count) printf("%s", convert[b.energy][b.id]);
    else printf("???");
}

void print_direction(enum direction d) {
    printf(GRAY);
    if (d == self) printf("| . |");
    else if (d == up) printf("| ^ |");
    else if (d == down) printf("| V |");
    else if (d == left) printf("| < |");
    else if (d == right) printf("| > |");
    else printf("| unknown direction |");
    printf(RESET);
}

void print_interaction(interaction_type interaction) {
    auto [from, to, result, direction] = interaction;
    std::cout << "\t";
    print_direction(direction);
    std::cout << "\t";
    print_block(from);
    std::cout << GRAY " --> " RESET;
    if (direction != self) {
        print_block(to);
        std::cout << GRAY " : " RESET;
    }
    print_block(result);
    std::cout << std::endl;
}
