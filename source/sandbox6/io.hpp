//
//  io.hpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#ifndef io_hpp
#define io_hpp

#include <string>
#include "structures.h"

void clear_screen();
char getch();
bool should(std::string action);
void draw(struct block** space);

#endif /* io_hpp */
