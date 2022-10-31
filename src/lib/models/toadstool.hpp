#ifndef SM_SRC_LIB_MODELS_TOADSTOOL_HPP_
#define SM_SRC_LIB_MODELS_TOADSTOOL_HPP_

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "enemy.hpp"

namespace sm::src::lib::models {

class ToadStool : public Enemy {

public:
    ToadStool(std::shared_ptr<sf::Texture> image, int x, int y);

    virtual void update(float time);
    virtual void collision();
};

}

#endif