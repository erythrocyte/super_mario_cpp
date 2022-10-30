#include "tile.hpp"

namespace sm::src::lib::models {

void Tile::update_position()
{
    setPosition(m_i * 16 - m_offset_x, m_j * 16 - m_offset_y);
}

void Tile::set_i(int value)
{
    m_i = value;
}

void Tile::set_j(int value)
{
    m_j = value;
}

void Tile::set_offset_x(float value)
{
    m_offset_x = value;
}

void Tile::set_offset_y(float value)
{
    m_offset_y = value;
}

}
