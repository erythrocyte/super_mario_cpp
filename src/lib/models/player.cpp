#include "player.hpp"

#include "tile_map_objects.hpp"

namespace sm::src::lib::models {

Player::Player(const std::shared_ptr<sf::Texture> image)
{
    sprite = std::make_shared<sf::Sprite>(*image);
    rect = std::make_shared<sf::FloatRect>(100, 180, 16, 16);

    vx = vy = 0.1;
    currentFrame = 0;
}

void Player::update(float time)
{
    rect->left += vx * time;
    collision(false);

    if (!onGround)
        vy = vy + 0.0005 * time; // gravitation;
    rect->top += vy * time;
    onGround = false;
    collision(true);

    currentFrame += time * 0.005;
    if (currentFrame > 3)
        currentFrame -= 3;

    if (vx > 0)
        sprite->setTextureRect(sf::IntRect(112 + 31 * int(currentFrame), 144, 16, 16));
    if (vx < 0)
        sprite->setTextureRect(sf::IntRect(112 + 31 * int(currentFrame) + 16, 144, -16, 16));

    sprite->setPosition(rect->left - m_offset_x, rect->top - m_offset_y);

    vx = 0;
}

void Player::collision(bool is_y)
{
    for (int i = rect->top / 16; i < (rect->top + rect->height) / 16; i++)
        for (int j = rect->left / 16; j < (rect->left + rect->width) / 16; j++) {
            if ((m_map[i][j] == TileMapObjectEnum::BrownStone)
                || (m_map[i][j] == TileMapObjectEnum::BrownBrick)
                || (m_map[i][j] == TileMapObjectEnum::Zero)
                || (m_map[i][j] == TileMapObjectEnum::BrownConcrete)
                || (m_map[i][j] == TileMapObjectEnum::Tube)) {
                if (vy > 0 && is_y) {
                    rect->top = i * 16 - rect->height;
                    vy = 0;
                    onGround = true;
                }
                if (vy < 0 && is_y) {
                    rect->top = i * 16 + 16;
                    vy = 0;
                }
                if (vx > 0 && !is_y) {
                    rect->left = j * 16 - rect->width;
                }
                if (vx < 0 && !is_y) {
                    rect->left = j * 16 + 16;
                }
            }

            if (m_map[i][j] == TileMapObjectEnum::Coin) {
                // TileMap[i][j]=' ';
            }
        }
}

void Player::set_map(const std::vector<std::string>& value)
{
    m_map = value;
}

void Player::set_offsetx(float value)
{
    m_offset_x = value;
}

void Player::set_offsety(float value)
{
    m_offset_y = value;
}

} // namespace sm::src::lib::modesl