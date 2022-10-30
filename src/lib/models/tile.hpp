#ifndef SM_SRC_LIB_MODELS_TILE_HPP
#define SM_SRC_LIB_MODELS_TILE_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

namespace sm::src::lib::models {
class Tile : public sf::Sprite {
public:
    using sf::Sprite::Sprite;

    void update_position();
    void set_i(int value);
    void set_j(int value);
    void set_offset_x(float value);
    void set_offset_y(float value);

private:
    int m_i;
    int m_j;
    float m_offset_x;
    float m_offset_y;
};
}

#endif