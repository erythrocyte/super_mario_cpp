#ifndef SM_SRC_GUI_FRAME_HPP
#define SM_SRC_GUI_FRAME_HPP

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "lib/models/player.hpp"
#include "lib/models/tile.hpp"

namespace slm = sm::src::lib::models;

namespace sm::src::gui {
class Frame {
public:
    Frame(int width, int height, const std::string& caption);

    void run();
    void set_mario(std::shared_ptr<slm::Player> mario);
    void set_tiles(const std::vector<std::shared_ptr<slm::Tile>>& tiles);

private:
    std::shared_ptr<sf::RenderWindow> m_window;
    std::shared_ptr<slm::Player> m_mario;
    std::vector<std::shared_ptr<slm::Tile>> m_tiles;
    std::shared_ptr<sf::Clock> m_clock;
    std::shared_ptr<sf::Color> m_def_bg_color;

    void update_offset_x(float value);
};
}

#endif