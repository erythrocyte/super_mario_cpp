#ifndef SM_SRC_LIB_MODELS_PLAYER_HPP
#define SM_SRC_LIB_MODELS_PLAYER_HPP

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

namespace sm::src::lib::models {
class Player {
public:
    Player(const std::shared_ptr<sf::Texture> image);

    float dx;
    float dy;
    std::shared_ptr<sf::FloatRect> rect;
    bool onGround;
    std::shared_ptr<sf::Sprite> sprite;
    float currentFrame;

    void update(float time);
    void collision(int num);

    void set_map(const std::vector<std::string>& map, float offset_x = 0, float offset_y = 0);

private:
    std::vector<std::string> m_map;
    float m_offset_x;
    float m_offset_y;
};
} // namespace sm::src::lib::modesl

#endif