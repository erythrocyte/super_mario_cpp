#ifndef SM_SRC_GUI_FRAME_HPP
#define SM_SRC_GUI_FRAME_HPP

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>


namespace sm::src::gui {
class Frame {
public:
    Frame(int width, int height, const std::string& caption);

    void run();
    void add_drawable(std::shared_ptr<sf::Drawable> shape,
        std::shared_ptr<sf::RenderStates> state = std::make_shared<sf::RenderStates>(sf::RenderStates::Default));

private:
    std::shared_ptr<sf::RenderWindow> m_window;
    std::vector<std::tuple<std::shared_ptr<sf::RenderStates>, std::shared_ptr<sf::Drawable>>> m_shapes;
};
}

#endif