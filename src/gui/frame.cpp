#include "frame.hpp"

namespace sm::src::gui {

Frame::Frame(int width, int height, const std::string& caption)
{
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), caption);
    m_clock = std::make_shared<sf::Clock>();
    m_def_bg_color = std::make_shared<sf::Color>(107, 140, 255);
    m_on_focus = true;
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
        update_time();

        check_events();

        if (m_on_focus) {
            check_keyboard_press();
        }

        update_object_time();

        check_enemies_intersect();

        update_offsets();

        update_window();
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

void Frame::draw_tiles()
{
    for (auto const& tile : m_tiles) {
        if (tile == nullptr)
            continue;
        m_window->draw(*tile);
    }
}

void Frame::draw_enemies()
{
    for (auto const& enemy : m_enemies) {
        if (enemy == nullptr || !enemy->alife)
            continue;
        m_window->draw(*enemy->sprite);
    }
}

void Frame::add_enemy(std::shared_ptr<slm::Enemy> enemy)
{
    m_enemies.push_back(enemy);
}

void Frame::update_enemies_time()
{
    for (auto const& enemy : m_enemies) {
        if (enemy == nullptr)
            continue;
        enemy->update(m_time);
    }
}

void Frame::update_time()
{
    m_time = m_clock->getElapsedTime().asMicroseconds();
    m_clock->restart();

    m_time = m_time / 500; // здесь регулируем скорость игры

    if (m_time > 20) // this time only for smooth move of mario;
        m_time = 20;
}

void Frame::check_enemies_intersect()
{
    for (auto const& enemy : m_enemies) {
        if (m_mario->rect->intersects(*enemy->rect)) {
            if (enemy->alife) {
                if (m_mario->vy > 0) {
                    enemy->vx = 0;
                    m_mario->vy = -0.2;
                    enemy->alife = false;
                } else {
                    m_mario->sprite->setColor(sf::Color::Red);
                    break;
                }
            }
        }
    }
}

void Frame::check_keyboard_press()
{
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
}

void Frame::check_events()
{
    sf::Event event;
    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window->close();
        else if (event.type == sf::Event::GainedFocus) {
            m_on_focus = true;

        } else if (event.type == sf::Event::LostFocus) {
            m_on_focus = false;
        }
    }
}

void Frame::update_object_time()
{
    m_mario->update(m_time);
    update_enemies_time();
}

void Frame::update_offsets()
{
    if (m_mario->rect->left > 200) {
        this->update_offset_x(m_mario->rect->left - 200); // смещение
    }
}

void Frame::update_window()
{
    m_window->clear(*m_def_bg_color);
    draw_tiles();
    draw_enemies();
    m_window->draw(*m_mario->sprite);
    m_window->display();
}

}