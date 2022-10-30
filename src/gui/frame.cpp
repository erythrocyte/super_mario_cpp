#include "frame.hpp"

namespace sm::src::gui {

Frame::Frame(int width, int height, const std::string& caption)
{
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), caption);
    m_clock = std::make_shared<sf::Clock>();
    m_def_bg_color = std::make_shared<sf::Color>(107, 140, 255);
}

void Frame::set_mario(std::shared_ptr<lm::Player> mario)
{
    m_mario = mario;
}

void Frame::set_tiles(const std::vector<std::shared_ptr<sf::Sprite>>& tiles)
{
    m_tiles = tiles;
}

void Frame::run()
{
    float time = m_clock->getElapsedTime().asMicroseconds();
    m_clock->restart();

    time = time / 500; // здесь регулируем скорость игры

    if (time > 20)
        time = 20;

    while (m_window->isOpen()) {
        sf::Event event;
        while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }

        m_window->clear(*m_def_bg_color);
        for (auto const& tile : m_tiles) {
            if (tile == nullptr)
                continue;
            m_window->draw(*tile);
        }
        m_window->display();
    }
}

}