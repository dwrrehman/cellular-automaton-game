//
//  configuration.cpp
//  sandbox6
//
//  Created by Daniel Rehman on 1902074.
//  Copyright © 2019 Daniel Rehman. All rights reserved.
//

#include "configuration.hpp"
#include "parameters.hpp"
#include "structures.h"
#include <iostream>
#include <fstream>
#include "globals.hpp"

void load_configuration() {
    std::ifstream file {savefile};
    while (file.good()) {
        
        size_t id = 0, energy = 0, y = 0, x = 0;
        file >> id;
        file >> energy;
        file >> x;
        file >> y;
        
        if ((enum blocks) id == player_block) {
            player.x = x;
            player.y = y;
            player_energy = energy;
        }
        
        if (id) configuration.push_back({{(enum blocks) id, energy}, {x, y}});
    }
}

void load_interactions(std::vector<interaction_type> &interactions) {
    std::ifstream file {interactionsfile};
    while (file.good()) {
        
        size_t from_id = 0, from_energy = 0, to_id = 0, to_energy = 0, result_id = 0, result_energy = 0, direction = 0;
        file >> from_id;
        file >> from_energy;
        file >> to_id;
        file >> to_energy;
        file >> result_id;
        file >> result_energy;
        file >> direction;
        
        if (from_id || from_energy || to_id ||to_energy || result_id || result_energy)
            interactions.push_back({
                {(enum blocks) from_id, from_energy},
                {(enum blocks) to_id, to_energy},
                {(enum blocks) result_id, result_energy},
                (enum direction) direction
            });
    }
}

void save_configuration(struct block **space) {
    std::ofstream file {savefile, std::ofstream::trunc};
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (space[i][j].id != air) {
                file << (uint) space[i][j].id << " " << space[i][j].energy << "   "
                << j << " " << i << "\n";
            }
        }
    }
    file.close();
}

void save_interactions(std::vector<interaction_type> &interactions) {
    std::ofstream file {interactionsfile, std::ofstream::trunc};
    
    for (const auto& [from, to, result, direction] : interactions) {
        
        file << (uint) from.id << " " << from.energy
        << "    "
        << (uint) to.id << " " << to.energy
        << "    "
        << (uint) result.id << " " << result.energy
        << "    "
        << (uint) direction
        << std::endl;
    }
    
    file.close();
}

void configure(struct block** space) {
    for (auto [block, point] : configuration)
        if (point.y >= 0 && point.y < height
            && point.x >= 0 && point.x < width)
            space[point.y][point.x] = block;
}
