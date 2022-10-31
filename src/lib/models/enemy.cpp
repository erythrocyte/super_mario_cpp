#include "enemy.hpp"

namespace sm::src::lib::models {

Enemy::Enemy(std::shared_ptr<sf::Texture> image, int x, int y)
{
    sprite = std::make_shared<sf::Sprite>(*image);
    rect = std::make_shared<sf::FloatRect>(x, y, 16, 16);

    vx = 0.05;
    currentFrame = 0;
    alife = true;
};

void Enemy::set_map(const std::vector<std::string>& value)
{
    m_map = value;
}

void Enemy::set_offsetx(float value)
{
    m_offset_x = value;
}

void Enemy::set_offsety(float value)
{
    m_offset_y = value;
}

}