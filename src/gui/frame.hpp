#ifndef SM_SRC_GUI_FRAME_HPP
#define SM_SRC_GUI_FRAME_HPP

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "lib/models/enemy.hpp"
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
    void add_enemy(std::shared_ptr<slm::Enemy> enemy);

private:
    std::shared_ptr<sf::RenderWindow> m_window;
    std::shared_ptr<slm::Player> m_mario;
    std::vector<std::shared_ptr<slm::Tile>> m_tiles;
    std::shared_ptr<sf::Clock> m_clock;
    std::shared_ptr<sf::Color> m_def_bg_color;
    std::vector<std::shared_ptr<slm::Enemy>> m_enemies;
    float m_time;

    void update_offset_x(float value);
    void draw_tiles();
    void draw_enemies();
    void update_enemies_time();
    void update_time();
    void check_enemies_intersect();
    void check_keyboard_press();
    void check_events();
    void update_object_time();
    void update_offsets();

    void update_window();
};
}

#endif