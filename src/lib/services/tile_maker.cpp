#include "tile_maker.hpp"

#include "lib/models/tile_map_objects.hpp"

namespace sm::src::lib::services::tile_maker {

std::vector<std::shared_ptr<slm::Tile>> make_tiles(const std::shared_ptr<sf::Texture> texture,
    const std::vector<std::string>& tile_map, float offsetX, float offsetY)
{
    std::vector<std::shared_ptr<slm::Tile>> result;

    int ih = static_cast<int>(tile_map.size());
    int jw = static_cast<int>(tile_map[0].size());
    for (int i = 0; i < ih; i++) {
        for (int j = 0; j < jw; j++) {
            auto tile = std::make_shared<slm::Tile>(*texture);
            tile->set_i(i);
            tile->set_j(j);
            tile->set_offset_x(offsetX);
            tile->set_offset_y(offsetY);

            if (tile_map[i][j] == models::TileMapObjectEnum::Bp)
                tile->setTextureRect(sf::IntRect(143 - 16 * 3, 112, 16, 16));

            if (tile_map[i][j] == models::TileMapObjectEnum::Lk)
                tile->setTextureRect(sf::IntRect(143, 112, 16, 16));

            if (tile_map[i][j] == models::TileMapObjectEnum::Coin)
                tile->setTextureRect(sf::IntRect(143 - 16, 112, 16, 16));

            if (tile_map[i][j] == models::TileMapObjectEnum::Lt)
                tile->setTextureRect(sf::IntRect(0, 47, 32, 95 - 47));

            if (tile_map[i][j] == models::TileMapObjectEnum::Lg)
                tile->setTextureRect(sf::IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));

            if (tile_map[i][j] == models::TileMapObjectEnum::Bg)
                tile->setTextureRect(sf::IntRect(145, 222, 222 - 145, 255 - 222));

            if (tile_map[i][j] == models::TileMapObjectEnum::Ld)
                tile->setTextureRect(sf::IntRect(0, 106, 74, 127 - 106));

            if (tile_map[i][j] == models::TileMapObjectEnum::Lw)
                tile->setTextureRect(sf::IntRect(99, 224, 140 - 99, 255 - 224));

            if (tile_map[i][j] == models::TileMapObjectEnum::Lr)
                tile->setTextureRect(sf::IntRect(143 - 32, 112, 16, 16));

            if ((tile_map[i][j] == models::TileMapObjectEnum::Empty) || (tile_map[i][j] == models::TileMapObjectEnum::Zero))
                continue;

            tile->setPosition(j * 16 - offsetX, i * 16 - offsetY);
            result.push_back(tile);
        }
    }

    return result;
}

} // namespace sm::src::lib::services::time_maker
