#ifndef SM_SRC_GUI_FRAME_HPP
#define SM_SRC_GUI_FRAME_HPP

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "lib/models/player.hpp"

namespace lm = sm::src::lib::models;

namespace sm::src::gui {
class Frame {
public:
    Frame(int width, int height, const std::string& caption);

    void run();
    void set_plater(std::shared_ptr<lm::Player> player);
    void set_tiles(const std::vector<std::shared_ptr<sf::Sprite>>& tiles);

private:
    std::shared_ptr<sf::RenderWindow> m_window;
    std::shared_ptr<lm::Player> m_player;
    std::vector<std::shared_ptr<sf::Sprite>> m_tiles;
    std::shared_ptr<sf::Clock> m_clock;
    std::shared_ptr<sf::Color> m_def_bg_color;
};
}

#endif