//
// Created by Lapo Bartolacci on 06/07/17.
//

#ifndef VIDEOGAME_MAP_H
#define VIDEOGAME_MAP_H

#include <vector>
#include <SFML/Graphics.hpp>


class Map : public sf::Drawable{

public:

    Map(sf::Texture& texture);

    void loadLevel(std::string name);

    sf::Vector2i getHeroPosition()const;
    std::vector<sf::Vector2i> getVillainPositions() const;

    inline std::size_t positionToIndex(sf::Vector2i position) const;
    inline sf::Vector2i indexToPosition(std::size_t index) const;



    sf::Vector2i mapPixelToCell(sf::Vector2f pixel) const;
    sf::Vector2f mapCellToPixel(sf::Vector2i cell) const;

    bool isGrass(sf::Vector2i position) const;

    sf::Vector2i getSize() const;



private:

    enum CellData{

        Empty,
        Grass,
        Ground,
        Ice,
        Snow,
        Sand,
        DrySand

    };

    void draw(sf::RenderTarget& target, sf::RenderStates states)const;

    sf::Vector2i m_mapSize;
    std::vector<CellData> m_mapData;

    sf::Vector2i m_heroPosition;

    std::vector<sf::Vector2i> m_villainPositions;

    sf::RenderTexture m_renderTexture;
    sf::Texture& m_texture;


};


#endif //VIDEOGAME_MAP_H
