//
// Created by Lapo Bartolacci on 03/07/17.
//

#include "GameCharacter.h"
#include <cmath>


GameCharacter::GameCharacter()
:m_map(nullptr)
,m_speed(100.f)
,m_currentDirection(0,0)
,m_nextDirection(0,0)
,m_pixelTraveled(0.f)


{

}

sf::FloatRect GameCharacter::getCollisionBox() const {

    sf::FloatRect bounds(6, 6, 72, 72);
    return getTransform().transformRect(bounds);
}

void GameCharacter::setMap(Map* map) {
    m_map = map;
}

float GameCharacter::getM_speed() const {
    return m_speed;
}

void GameCharacter::setM_speed(float m_speed) {
    GameCharacter::m_speed = m_speed;
}

int GameCharacter::getM_hp() const {
    return m_hp;
}

void GameCharacter::setM_hp(int m_hp) {
    GameCharacter::m_hp = m_hp;
}

float GameCharacter::getM_attackSpeed() const {
    return m_attackSpeed;
}

void GameCharacter::setM_attackSpeed(float m_attackSpeed) {
    GameCharacter::m_attackSpeed = m_attackSpeed;
}


void GameCharacter::setDirection(sf::Vector2i direction) {
    m_nextDirection = direction;
}

sf::Vector2i GameCharacter::getDirection() const {
    return m_currentDirection;
}

float GameCharacter::getPixelTraveled() {
    return m_pixelTraveled;
}

void GameCharacter::update(sf::Time delta) {

    sf::Vector2f pixelPosition = getPosition();

    float pixelTraveled = getM_speed() * delta.asSeconds();
    m_pixelTraveled = pixelTraveled;

    sf::Vector2f nextPixelPosition = pixelPosition + sf::Vector2f(m_currentDirection) * pixelTraveled;
    setPosition(nextPixelPosition);


    sf::Vector2i cellPosition = m_map->mapPixelToCell(pixelPosition);

    sf::Vector2f offset;

    offset.x = std::fmod(pixelPosition.x, 64) - 32;
    offset.y = std::fmod(pixelPosition.y, 64) - 32;

    if (m_map->isGrass(cellPosition + m_currentDirection)) {
        if ((m_currentDirection.x == 1 && offset.x > 0) ||
            (m_currentDirection.x == -1 && offset.x < 0) ||
            (m_currentDirection.y == 1 && offset.y > 0) ||
            (m_currentDirection.y == -1 && offset.y < 0)) {

            setPosition(m_map->mapCellToPixel(cellPosition));
        }

    }

    if (!m_map->isGrass(cellPosition + m_nextDirection) && m_currentDirection != m_nextDirection) {
        if ((!m_currentDirection.y && (offset.x > -2 && offset.x < 2)) ||
            (!m_currentDirection.x && (offset.y > -2 && offset.y < 2))) {

            setPosition(m_map->mapCellToPixel(cellPosition));
            m_currentDirection = m_nextDirection;

            if (m_currentDirection == sf::Vector2i(1, 0)) {
                setRotation(0);
                setScale(1, 1);
            } else if (m_currentDirection == sf::Vector2i(-1, 0)) {
                setRotation(0);
                setScale(-1, 1);

                }

            }

        }
    }

