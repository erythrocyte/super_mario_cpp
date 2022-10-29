#include "frame.hpp"

namespace sm::src::gui {

Frame::Frame(int width, int height, const std::string& caption)
{
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), caption);
}

void Frame::run()
{
    while (m_window->isOpen()) {
        sf::Event event;
        while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }

        m_window->clear();
        for (auto const& item : m_shapes) {
            std::shared_ptr<sf::RenderStates> state;
            std::shared_ptr<sf::Drawable> drawable;
            std::tie(state, drawable) = item;
            m_window->draw(*drawable, *state);
        }
        m_window->display();
    }
}

void Frame::add_drawable(std::shared_ptr<sf::Drawable> shape, std::shared_ptr<sf::RenderStates> state)
{
    m_shapes.push_back(std::make_tuple(state, shape));
}

}