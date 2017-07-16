//
// Created by Lapo Bartolacci on 03/07/17.
//

#ifndef VIDEOGAME_GAMECHARACTER_H
#define VIDEOGAME_GAMECHARACTER_H

#include <SFML/Graphics.hpp>
#include "Map.h"


class GameCharacter : public sf::Drawable, public sf::Transformable{

public:

    GameCharacter();

    virtual void update(sf::Time delta);
    void setDirection(sf::Vector2i direction);
    sf::Vector2i getDirection() const;
    void setMap(Map* map);

    int getM_hp() const;

    void setM_hp(int m_hp);

    float getM_attackSpeed() const;

    void setM_attackSpeed(float m_attackSpeed);

    float getM_speed() const;

    void setM_speed(float m_speed);
    

private:

    float m_speed;
    int m_hp;
    float m_attackSpeed;
    Map* m_map;

    sf::Vector2i m_currentDirection;
    sf::Vector2i m_nextDirection;


};


#endif //VIDEOGAME_GAMECHARACTER_H
