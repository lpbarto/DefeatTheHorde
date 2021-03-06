//
// Created by Lapo Bartolacci on 06/07/17.
//

#include "Map.h"
#include <iostream>
#include <cmath>

Map::Map(sf::Texture& texture)
:m_mapSize(0,0)
,m_texture(texture)
{

}

void Map::loadLevel(std::string name) {

    m_mapSize = sf::Vector2i(0,0);
    m_mapData.clear();
    m_heroPosition = sf::Vector2i(0,0);
    m_villainPositions.clear();

    sf::Image levelData;
    if (!levelData.loadFromFile("assets/levels/" + name + ".png"))
        throw std::runtime_error("Failed to load " + name + ".png");

    m_mapSize = sf::Vector2i(levelData.getSize());

    if (m_mapSize.x < 20 || m_mapSize.y < 15)
        throw std::runtime_error("the loaded level is too small");


    for (unsigned int y = 0; y < m_mapSize.y; y++) {
        for (unsigned int x = 0; x < m_mapSize.x; x++) {

            sf::Color cellData = levelData.getPixel(x, y);


            if (cellData == sf::Color::White) {
                m_mapData.push_back(Empty);

            } else if(cellData == sf::Color(908973311)) {
                m_mapData.push_back(Empty);

            }else if (cellData == sf::Color(0,0,0)) {
                m_mapData.push_back(Ground);

            } else if (cellData == sf::Color(0,255,0)) {
                m_mapData.push_back(Grass);

            } else if (cellData == sf::Color::Red) {
                //the hero start the level here
                m_heroPosition = sf::Vector2i(x, y);
                m_mapData.push_back(Empty);
            }else if(cellData == sf::Color(50,50,50)){
                //villain positions
                m_villainPositions.emplace_back(x,y);
                m_mapData.push_back(Empty);
            } else{
                m_mapData.push_back(Empty);
            }


        }
    }

    m_renderTexture.create(64 * m_mapSize.x, 64 * m_mapSize.y);

   // m_renderTexture.clear(sf::Color(71,161,193));


    sf::Sprite grass(m_texture);
    grass.setTextureRect(sf::IntRect(0,603,64,64));

    sf::Sprite ground(m_texture);
    ground.setTextureRect(sf::IntRect(64,539,64,64));

    sf::Sprite ice(m_texture);
    ice.setTextureRect(sf::IntRect(256,922,64,64));

    sf::Sprite snow(m_texture);
    snow.setTextureRect(sf::IntRect(192,987,64,64));

    sf::Sprite sand(m_texture);
    sand.setTextureRect(sf::IntRect(320,1051,64,64));

    sf::Sprite drysand(m_texture);
    drysand.setTextureRect(sf::IntRect(256,1115,64,64));

    sf::Sprite sky(m_texture);
    sky.setTextureRect(sf::IntRect(475,1336,64,64));




    m_renderTexture.display();


    if(name == "large-level-villain-3"){
        grass=snow;
        ground=ice;
    }else if(name == "large-level-villain-6"){
        grass=drysand;
        ground=sand;
    }

    for (unsigned int i = 0; i < m_mapData.size(); i++) {
        sf::Vector2i position = indexToPosition(i);

        if (m_mapData[i] == Ground) {

            ground.setPosition(64 * position.x, 64 * position.y);
            m_renderTexture.draw(ground);

        }
        else if (m_mapData[i] == Grass) {

            grass.setPosition(64 * position.x, 64 * position.y);
            m_renderTexture.draw(grass);

        }
        else if (m_mapData[i] == Sand) {

            sand.setPosition(64 * position.x, 64 * position.y);
            m_renderTexture.draw(sand);

        }
        else if (m_mapData[i] == DrySand) {

            drysand.setPosition(64 * position.x, 64 * position.y);
            m_renderTexture.draw(drysand);

        }
        else if (m_mapData[i] == Snow) {

            snow.setPosition(64 * position.x, 64 * position.y);
            m_renderTexture.draw(snow);

        }
        else if (m_mapData[i] == Ice) {

            ice.setPosition(64 * position.x, 64 * position.y);
            m_renderTexture.draw(ice);

        }
        else if(m_mapData[i] == Empty){
            sky.setPosition(64 * position.x, 64 * position.y);
            m_renderTexture.draw(sky);

        }
    }
}


void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(sf::Sprite(m_renderTexture.getTexture()),states);
}

sf::Vector2i Map::getSize() const {
    return m_mapSize;
}

sf::Vector2i Map::getHeroPosition() const {
    return m_heroPosition;
}

std::vector<sf::Vector2i> Map::getVillainPositions() const
{
    return m_villainPositions;
}


std::size_t Map::positionToIndex(sf::Vector2i position) const {
    return position.y * m_mapSize.x + position.x;
}

sf::Vector2i Map::indexToPosition(std::size_t index) const {

    sf::Vector2i position;

    position.x = index % m_mapSize.x;
    position.y = index / m_mapSize.x;

    return position;

}

sf::Vector2i Map::mapPixelToCell(sf::Vector2f pixel) const {

    sf::Vector2i cell;
    cell.x = std::floor(pixel.x / 64.f);
    cell.y = std::floor(pixel.y / 64.f);

    return cell;

}

sf::Vector2f Map::mapCellToPixel(sf::Vector2i cell) const {

    sf::Vector2f pixel;
    pixel.x = cell.x * 64 + 32;
    pixel.y = cell.y * 64 + 32;

    return pixel;

}

bool Map::isGrass(sf::Vector2i position) const {

    if(position.y < 0 || position.y >= m_mapSize.y)
        return false;
    if(position.x < 0 || position.x >= m_mapSize.x)
        return true;

    return m_mapData[positionToIndex(position)] == Grass || m_mapData[positionToIndex(position)] == Snow || m_mapData[positionToIndex(position)] == DrySand;

}


