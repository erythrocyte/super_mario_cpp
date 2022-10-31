#ifndef SM_SRC_LIB_MODELS_ENEMY_HPP_
#define SM_SRC_LIB_MODELS_ENEMY_HPP_

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

namespace sm::src::lib::models {

class Enemy {

public:
    Enemy(std::shared_ptr<sf::Texture> image, int x, int y);

    float vx;
    float vy;
    std::shared_ptr<sf::FloatRect> rect;
    std::shared_ptr<sf::Sprite> sprite;
    float currentFrame;
    bool alife;

    void set_map(const std::vector<std::string>& value);
    void set_offsetx(float value);
    void set_offsety(float value);

    virtual void update(float time) = 0;

protected:
    std::vector<std::string> m_map;
    float m_offset_x;
    float m_offset_y;

    virtual void collision() = 0;
};

}

#endif