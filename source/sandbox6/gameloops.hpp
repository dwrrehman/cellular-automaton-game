//
//  gameloops.hpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#ifndef gameloops_hpp
#define gameloops_hpp

#include <vector>
#include "structures.h"

void simulate(struct block** space, std::vector<interaction_type> &interactions);
void interface(struct block** space, std::vector<interaction_type>* interactions);
void get_input();

#endif /* gameloops_hpp */
