//
//  globals.cpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#include "globals.hpp"
#include "parameters.hpp"

bool paused = false;
bool quitting = false;
bool input_paused = false;

size_t current_selected_block = 0;
unsigned char input = null_command;

enum control_mode mode = hand_control;
struct point hand = {height/3, width/2};

struct point player = {0, 0};
size_t player_energy = 0;

std::string message = "game started. type ? for help.";
std::vector<std::pair<struct block, struct point>> configuration = {};

