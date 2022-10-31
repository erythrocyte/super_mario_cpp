#ifndef SM_BIN_VOIDS_HPP
#define SM_BIN_VOIDS_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "lib/models/toadstool.hpp"
#include "lib/models/player.hpp"

namespace slm = sm::src::lib::models;

namespace sm::bin {

void run();
std::shared_ptr<slm::Player> make_player(const std::shared_ptr<sf::Texture> texture,
    const std::vector<std::string>& map, float offset_x, float offset_y);

std::shared_ptr<slm::ToadStool> make_toadstool(const std::shared_ptr<sf::Texture> texture,
    const std::vector<std::string>& map, float offset_x, float offset_y);
}

#endif