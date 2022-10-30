#ifndef SM_SRC_LIB_SERVICES_TILE_MAP_MAKER_HPP
#define SM_SRC_LIB_SERVICES_TILE_MAP_MAKER_HPP

#include <iostream>
#include <string>
#include <vector>

namespace sm::src::lib::services::tile_map_maker {

std::vector<std::string> generate_random(int row_count, int col_count, int m_roof_count = 1, int m_flour_count = 3);
std::vector<std::string> generate_sample();
}

#endif