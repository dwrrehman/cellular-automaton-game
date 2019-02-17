//
//  io.cpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#include "io.hpp"

#include <iostream>
#include "structures.h"
#include <termios.h>
#include "globals.hpp"
#include "parameters.hpp"
#include "convert.hpp"
#include <unistd.h>

void clear_screen() {printf("\033[2J\033c");}

char getch() {
    struct termios t = {0}; if (tcgetattr(0, &t) < 0) perror("tcsetattr()");
    t.c_lflag &= ~ICANON; t.c_lflag &= ~ECHO; t.c_cc[VMIN] = 1; t.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &t) < 0) perror("tcsetattr ICANON");
    char c = 0; if (read(0, &c, 1) < 0) perror("read()"); t.c_lflag |= ICANON; t.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &t) < 0) perror("tcsetattr ~ICANON");
    return c;
}



bool should(std::string action) {
    std::cout << "do you want to " << action << "? (y/n) " << std::flush;
    char i = '\0';
    while (i != 'n' && i != 'y') i = getch();
    std::cout << std::endl;
    
    if (action == "quit") {
        if (i == 'y') quitting = true;
        else input = '\0';
    }
    return i == 'y';
}


inline static std::string state_under_hand(struct block** space) {
    if (space[hand.y][hand.x].id == air) return "";
    if (space[hand.y][hand.x].energy == 0) return "inactive";
    else if (space[hand.y][hand.x].energy == 1) return "(residual)";
    else if (space[hand.y][hand.x].energy == 2) return "[active]";
    else if (space[hand.y][hand.x].energy == 3) return "{primed}";
    else return "null state";
}

void draw(struct block** space) {
    clear_screen();
    std::cout << "\n\n\t+";
    for (int i = 0; i < width; i++) std::cout << "---";
    std::cout << "+" <<  std::endl;
    for (int i = 0; i < height; i++) {
        std::cout << "\t|";
        for (int j = 0; j < width; j++) {
            
            if (i == hand.y && j == hand.x && mode == hand_control) std::cout << "\\" << convert_block[space[i][j].id][] << "/";
            
            else std::cout << " " << convert[space[i][j].id] << " ";
            
        } std::cout << "|" << std::endl;
    }
    std::cout << "\t+";
    for (int i = 0; i < width; i++) std::cout << "---";
    std::cout << "+" << std::endl;
    std::cout << "\t :: " << message;
    int i = 0;
    while (message.size() + 4 + i++ < width * 3 - 8 && width * 3 - 8 > 0) std::cout << " ";
    std::cout << state_under_hand(space) << std::endl;
}
