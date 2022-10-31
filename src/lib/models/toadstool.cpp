#include "toadstool.hpp"

#include "tile_map_objects.hpp"

namespace sm::src::lib::models {

ToadStool::ToadStool(std::shared_ptr<sf::Texture> image, int x, int y)
    : Enemy(image, x, y)
{
}

void ToadStool::update(float time)
{
    rect->left += vx * time;

    collision();

    currentFrame += time * 0.005;
    if (currentFrame > 2)
        currentFrame -= 2;

    sprite->setTextureRect(sf::IntRect(18 * int(currentFrame), 0, 16, 16));
    if (!alife)
        sprite->setTextureRect(sf::IntRect(58, 0, 16, 16));

    sprite->setPosition(rect->left - m_offset_x, rect->top - m_offset_y);
}
// {

// }

void ToadStool::collision()
{
    for (int i = rect->top / 16; i < (rect->top + rect->height) / 16; i++) {
        for (int j = rect->left / 16; j < (rect->left + rect->width) / 16; j++) {
            if ((m_map[i][j] == TileMapObjectEnum::Bp) || (m_map[i][j] == TileMapObjectEnum::Zero)) {
                if (vx > 0) {
                    rect->left = j * 16 - rect->width;
                    vx *= -1;
                } else if (vx < 0) {
                    rect->left = j * 16 + 16;
                    vx *= -1;
                }
            }
        }
    }
}

}