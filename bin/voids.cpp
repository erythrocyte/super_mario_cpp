#include "voids.hpp"

#include <string>

#include <SFML/Graphics.hpp>

#include "gui/frame.hpp"
#include "lib/services/tile_maker.hpp"
#include "lib/services/map_maker.hpp"

namespace g = sm::src::gui;
namespace ss = sm::src::lib::services;

namespace sm::bin {
void run()
{
    auto frame = std::make_shared<g::Frame>(400, 250, "Super mario");

    auto tile_set = std::make_shared<sf::Texture>(); // texture mush be alive while program works, otherwise no image appears
    tile_set->loadFromFile("../../assets/Mario_tileset.png"); // relative for "build/bin/"

    auto map = ss::map_maker::generate_sample();
    auto tiles = ss::tile_maker::make_tiles(tile_set, map);
    frame->set_tiles(tiles);

    frame->run();
}
}