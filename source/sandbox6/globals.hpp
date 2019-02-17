//
//  globals.hpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#ifndef globals_hpp
#define globals_hpp

#include <stdlib.h>
#include <vector>
#include <string>
#include <stdint.h>

#include "structures.h"

extern bool paused;
extern bool quitting;
extern bool input_paused;

extern size_t current_selected_block;
extern unsigned char input;

extern enum control_mode mode;
extern struct point hand;

extern struct point player;
extern size_t player_energy;

extern std::string message;
extern std::vector<std::pair<struct block, struct point>> configuration;



#endif /* globals_hpp */
