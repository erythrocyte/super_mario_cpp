#ifndef SM_SRC_LIB_MODELS_ENEMY_HPP_
#define SM_SRC_LIB_MODELS_ENEMY_HPP_

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

namespace sm::src::lib::models {

class Enemy {

public:
    Enemy(std::shared_ptr<sf::Texture> image, int x, int y)
    {
        sprite = std::make_shared<sf::Sprite>(image);
        rect = std::make_shared<sf::FloatRect>(x, y, 16, 16);

        vx = 0.05;
        currentFrame = 0;
        alife = true;
    }

    float vx;
    float vy;
    std::shared_ptr<sf::FloatRect> rect;
    std::shared_ptr<sf::Sprite> sprite;
    float currentFrame;
    bool alife;

    virtual void update(float time);
    // {
    //     rect.left += dx * time;

    //     Collision();

    //     currentFrame += time * 0.005;
    //     if (currentFrame > 2)
    //         currentFrame -= 2;

    //     sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, 16, 16));
    //     if (!life)
    //         sprite.setTextureRect(IntRect(58, 0, 16, 16));

    //     sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
    // }

    virtual void collision();
    // {

    //     for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
    //         for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
    //             if ((TileMap[i][j] == 'P') || (TileMap[i][j] == '0')) {
    //                 if (dx > 0) {
    //                     rect.left = j * 16 - rect.width;
    //                     dx *= -1;
    //                 } else if (dx < 0) {
    //                     rect.left = j * 16 + 16;
    //                     dx *= -1;
    //                 }
    //             }
    // }
};

}

#endif