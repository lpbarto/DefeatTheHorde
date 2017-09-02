//
// Created by Lapo Bartolacci on 03/07/17.
//

#ifndef VIDEOGAME_VILLAIN_H
#define VIDEOGAME_VILLAIN_H


#include "GameCharacter.h"
#include "Villain.h"
#include "Animator.h"

class Villain : public GameCharacter {

public:

    Villain(sf::Texture& texture);



    void die();

    bool isDying() const;
    bool isDead() const;


    void update(sf::Time delta);

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states)const ;
    sf::Sprite m_visual;

    bool m_isDying;
    bool m_isDead;


    Animator m_dieAnimator;
    Animator m_waitAnimator;


};


#endif //VIDEOGAME_VILLAIN_H
