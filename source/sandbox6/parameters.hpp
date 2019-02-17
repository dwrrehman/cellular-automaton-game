//
//  parameters.hpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#ifndef parameters_hpp
#define parameters_hpp

#include <string>
#include <stdlib.h>

#include "structures.h"

extern const size_t width; 
extern const size_t height;
extern const std::string savefile;
extern const std::string interactionsfile;
extern const size_t energy_count;
extern const std::string help_message;
extern const std::string exit_message;
using interaction_type = std::tuple<struct block, struct block, struct block, enum direction>;


#endif /* parameters_hpp */
