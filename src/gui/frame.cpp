#include "frame.hpp"

namespace sm::src::gui {

Frame::Frame(int width, int height, const std::string& caption)
{
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), caption);
    m_clock = std::make_shared<sf::Clock>();
    m_def_bg_color = std::make_shared<sf::Color>(107, 140, 255);
}

void Frame::set_mario(std::shared_ptr<slm::Player> mario)
{
    m_mario = mario;
}

void Frame::set_tiles(const std::vector<std::shared_ptr<slm::Tile>>& tiles)
{
    m_tiles = tiles;
}

void Frame::run()
{
    while (m_window->isOpen()) {

        float time = m_clock->getElapsedTime().asMicroseconds();
        m_clock->restart();

        time = time / 500; // здесь регулируем скорость игры

        if (time > 20) // this time only for smooth move of mario;
            time = 20;

        sf::Event event;
        while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            m_mario->vx = -0.1; // set velocity x
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            m_mario->vx = 0.1; // set velocity x
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (m_mario->onGround) { // jump only if we on ground;
                m_mario->vy = -0.27;
                m_mario->onGround = false;
            }
        }

        m_mario->update(time);

        if (m_mario->rect->left > 200) {
            this->update_offset_x(m_mario->rect->left - 200); // смещение
        }

        m_window->clear(*m_def_bg_color);
        for (auto const& tile : m_tiles) {
            if (tile == nullptr)
                continue;
            m_window->draw(*tile);
        }

        m_window->draw(*m_mario->sprite);
        m_window->display();
    }
}

void Frame::update_offset_x(float value)
{
    m_mario->set_offsetx(value);
    for (auto const& tile : m_tiles) {
        tile->set_offset_x(value);
        tile->update_position();
    }
}

}