#ifndef SM_SRC_LIB_SERVICES_TILEMAKER_H_
#define SM_SRC_LIB_SERVICES_TILEMAKER_H_

#include <iostream>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

namespace sm::src::lib::services::tile_maker {
std::vector<std::shared_ptr<sf::Sprite>> make_tiles(const std::shared_ptr<sf::Texture> texture,
    const std::vector<std::string>& tile_map, float offsetX = 0, float offsetY = 0);

} // namespace sm::src::lib::services::time_maker

#endif