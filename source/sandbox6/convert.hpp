//
//  convert.hpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#ifndef convert_hpp
#define convert_hpp

#include "structures.h"
#include <string>


extern const std::vector<char> convert_block;
extern const std::vector<std::vector<std::string>> convert;
extern const std::vector<std::string> opening_state;
extern const std::vector<std::string> closing_state;

enum blocks convert_block_string(std::string s);
enum blocks convert_abstract_block_string(std::string s);
enum direction convert_direction_string(std::string s);

#endif /* convert_hpp */
