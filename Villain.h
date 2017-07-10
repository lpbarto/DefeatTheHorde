//
// Created by Lapo Bartolacci on 03/07/17.
//

#ifndef VIDEOGAME_VILLAIN_H
#define VIDEOGAME_VILLAIN_H


#include "GameCharacter.h"

class Villain : public GameCharacter {

public:

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states)const ;
    sf::Sprite m_visual;


};


#endif //VIDEOGAME_VILLAIN_H
