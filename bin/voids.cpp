#include "voids.hpp"

#include "gui/frame.hpp"
#include "lib/services/map_maker.hpp"
#include "lib/services/tile_maker.hpp"

namespace g = sm::src::gui;
namespace sls = sm::src::lib::services;

namespace sm::bin {
void run()
{
    float offset_x = 0.0f, offset_y = 0.0f;
    auto frame = std::make_shared<g::Frame>(400, 250, "Super mario");

    auto tile_set = std::make_shared<sf::Texture>(); // texture mush be alive while program works, otherwise no image appears
    tile_set->loadFromFile("../../assets/Mario_tileset.png"); // relative for "build/bin/"

    auto map = sls::map_maker::generate_sample();
    auto tiles = sls::tile_maker::make_tiles(tile_set, map, offset_x, offset_y);
    frame->set_tiles(tiles);

    auto mario = make_player(tile_set, map, offset_x, offset_y);
    frame->set_mario(mario);

    frame->add_enemy(make_toadstool(tile_set, map, offset_x, offset_y));

    frame->run();
}

std::shared_ptr<slm::Player> make_player(const std::shared_ptr<sf::Texture> texture,
    const std::vector<std::string>& map, float offset_x, float offset_y)
{
    auto result = std::make_shared<slm::Player>(texture);
    result->set_map(map);
    result->set_offsetx(offset_x);
    result->set_offsety(offset_y);

    return result;
}

std::shared_ptr<slm::ToadStool> make_toadstool(const std::shared_ptr<sf::Texture> texture,
    const std::vector<std::string>& map, float offset_x, float offset_y)
{
    auto result = std::make_shared<slm::ToadStool>(texture, 48 * 16, 13 * 16);
    result->set_map(map);
    result->set_offsetx(offset_x);
    result->set_offsety(offset_y);

    return result;
}

}