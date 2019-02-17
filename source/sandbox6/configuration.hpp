//
//  configuration.hpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#ifndef configuration_hpp
#define configuration_hpp

#include <vector>
#include "structures.h"

void load_configuration(void);
void load_interactions(std::vector<interaction_type> &interactions);

void save_configuration(struct block **space);
void save_interactions(std::vector<interaction_type> &interactions);

void configure(struct block** space);

#endif /* configuration_hpp */
