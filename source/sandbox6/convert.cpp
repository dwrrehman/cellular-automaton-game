//
//  convert.cpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#include "convert.hpp"
#include "color.h"

#include <vector>

const std::vector<char> convert_block = {
    ' ',
    
    'u',
    'd',
    'l',
    'r',
    
    '^',
    'v',
    '<',
    '>',
    
    '1',
    '!',
    ']',
    '[',
    
    'x',
};

const std::vector<std::string> opening_state = {
    " ",
    GRAY "(" RESET,
    WHITE "[" RESET,
    MAGENTA "{" RESET
};

const std::vector<std::string> closing_state = {
    " ",
    GRAY ")" RESET,
    WHITE "]" RESET,
    MAGENTA "}" RESET
};


const std::vector<std::vector<std::string>> convert = {
    { // inactive:
        " ",
        
        RED "u" RESET,
        RED "d" RESET,
        RED "l" RESET,
        RED "r" RESET,
        
        GREEN "^" RESET,
        GREEN "v" RESET,
        GREEN "<" RESET,
        GREEN ">" RESET,
        
        BLUE "1" RESET,
        BLUE "!" RESET,
        BLUE "]" RESET,
        BLUE "[" RESET,
        
        WHITE "x" RESET,
    },
    
    {// residual
        " ",
        
        RED "u" RESET,
        RED "d" RESET,
        RED "l" RESET,
        RED "r" RESET,
        
        GREEN "^" RESET,
        GREEN "v" RESET,
        GREEN "<" RESET,
        GREEN ">" RESET,
        
        BLUE "1" RESET,
        BLUE "!" RESET,
        BLUE "]" RESET,
        BLUE "[" RESET,
        
        WHITE "x" RESET,
    },
    
    { // active:
         " ",
        BRIGHT_RED "u" RESET,
        BRIGHT_RED "d" RESET,
        BRIGHT_RED "l" RESET,
        BRIGHT_RED "r" RESET,
        
        BRIGHT_GREEN "^" RESET,
        BRIGHT_GREEN "v" RESET,
        BRIGHT_GREEN "<" RESET,
        BRIGHT_GREEN ">" RESET,
        
        BRIGHT_BLUE "1" RESET,
        BRIGHT_BLUE "!" RESET,
        BRIGHT_BLUE "]" RESET,
        BRIGHT_BLUE "[" RESET,
        
        WHITE "x" RESET,
    },
    
    { // primed:
        " ",
        BOLDRED "u" RESET,
        BOLDRED "d" RESET,
        BOLDRED "l" RESET,
        BOLDRED "r" RESET,
        
        BOLDGREEN "^" RESET,
        BOLDGREEN "v" RESET,
        BOLDGREEN "<" RESET,
        BOLDGREEN ">" RESET,
        
        BOLDBLUE "1" RESET,
        BOLDBLUE "!" RESET,
        BOLDBLUE "]" RESET,
        BOLDBLUE "[" RESET,
        
        BOLDWHITE "x" RESET,
    }
};




enum blocks convert_block_string(std::string s) {
    if (s == "air") return air;
    if (s == "player") return player_block;
    
    else if (s == "zero_up") return zero_up;
    else if (s == "zero_down") return zero_down;
    else if (s == "zero_left") return zero_left;
    else if (s == "zero_right") return zero_right;
    
    else if (s == "one_up") return one_up;
    else if (s == "one_down") return one_down;
    else if (s == "one_left") return one_left;
    else if (s == "one_right") return one_right;
    
    else if (s == "two_up") return two_up;
    else if (s == "two_down") return two_down;
    else if (s == "two_left") return two_left;
    else if (s == "two_right") return two_right;
    
    else return block_count;
}

enum blocks convert_abstract_block_string(std::string s) {
    if (s == "air") return air;
    if (s == "player") return player_block;
    else if (s == "zero") return zero_up;
    else if (s == "one") return one_up;
    else if (s == "two") return two_up;
    else return block_count;
}

enum direction convert_direction_string(std::string s) {
    if (s == "self") return self;
    else if (s == "up") return up;
    else if (s == "down") return down;
    else if (s == "left") return left;
    else if (s == "right") return right;
    else return direction_count;
}

