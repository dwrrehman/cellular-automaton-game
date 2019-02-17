//
//  space_manipulation.hpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#ifndef space_manipulation_hpp
#define space_manipulation_hpp

#include "structures.h"

void create(struct block** &space);
void destroy(struct block** &space);
void fill_with_air(struct block** space);
void copy_space(struct block** oldspace, struct block** newspace);
void place_player_in(struct block** space);

#endif /* space_manipulation_hpp */
