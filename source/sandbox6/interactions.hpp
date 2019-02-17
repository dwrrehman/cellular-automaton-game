//
//  interactions.hpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#ifndef interactions_hpp
#define interactions_hpp

#include "structures.h"
#include <vector>

void add_raw_interaction(std::vector<interaction_type> &interactions);
void find_and_remove_interaction(std::vector<interaction_type> &interactions);
void add_omnidirectional_interaction(std::vector<interaction_type> &interactions);
void find_interaction(std::vector<interaction_type> &interactions);
void list_interaction(std::vector<interaction_type> &interactions);
void modify_interactions(std::vector<interaction_type> &interactions);

#endif /* interactions_hpp */
