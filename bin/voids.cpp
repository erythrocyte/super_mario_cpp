#include "voids.hpp"

#include <string>

#include <SFML/Graphics.hpp>

#include "gui/frame.hpp"
#include "lib/services/tile_maker.hpp"
#include "lib/services/tile_map_maker.hpp"

namespace g = sm::src::gui;
namespace ss = sm::src::lib::services;

namespace sm::bin {
void run()
{
    auto frame = std::make_shared<g::Frame>(400, 250, "Super mario");

    auto tile_map = ss::tile_map_maker::generate_sample();
    auto tiles = ss::time_maker::make_tile("/home/erythrocyte/Documents/progs/cpp/super_mario_cpp/assets/Mario_tileset.png", tile_map);
    frame->set_tiles(tiles);
    frame->run();
}
}