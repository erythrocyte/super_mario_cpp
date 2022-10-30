#include "frame.hpp"

namespace sm::src::gui {

Frame::Frame(int width, int height, const std::string& caption)
{
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), caption);
    m_clock = std::make_shared<sf::Clock>();
}

void Frame::set_plater(std::shared_ptr<lm::Player> player)
{
    m_player = player;
}

void Frame::set_tiles(const std::vector<std::shared_ptr<sf::Sprite>>& tiles)
{
    m_tiles = tiles;
}

void Frame::run()
{
    // sf::Texture tileSet;
    // tileSet.loadFromFile("/home/erythrocyte/Documents/progs/cpp/super_mario_cpp/assets/Mario_tileset.png");

    // sf::Sprite tile(tileSet);
    // tile.setTextureRect(sf::IntRect(143 - 16 * 3, 112, 16, 16));
    // tile.setPosition(16, 16);

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
        
        m_window->clear(sf::Color(107, 140, 255));
        // m_window->draw(tile);
        for (auto const& tile : m_tiles) {
            m_window->draw(*tile);
        }
        m_window->display();
    }
}

}