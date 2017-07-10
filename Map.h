//
// Created by Lapo Bartolacci on 06/07/17.
//

#ifndef VIDEOGAME_MAP_H
#define VIDEOGAME_MAP_H

#include <vector>
#include <SFML/Graphics.hpp>


class Map : public sf::Drawable{

public:

    Map();

    void loadLevel(std::string name);

    sf::Vector2i getHeroPosition()const;

    inline std::size_t positionToIndex(sf::Vector2i position) const;
    inline sf::Vector2i indexToPosition(std::size_t index) const;

    sf::Vector2i mapPixelToCell(sf::Vector2f pixel) const;
    sf::Vector2f mapCellToPixel(sf::Vector2i cell) const;

    bool isGrass(sf::Vector2i position) const;



private:

    enum CellData{

        Empty,
        Grass,
        Ground,

    };

    void draw(sf::RenderTarget& target, sf::RenderStates states)const;

    sf::Vector2i m_mapSize;
    std::vector<CellData> m_mapData;

    sf::Vector2i m_heroPosition;

    sf::RenderTexture m_renderTexture;


};


#endif //VIDEOGAME_MAP_H
