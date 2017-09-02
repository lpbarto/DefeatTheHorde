//
// Created by Lapo Bartolacci on 03/07/17.
//

#ifndef VIDEOGAME_HERO_H
#define VIDEOGAME_HERO_H


#include "GameCharacter.h"
#include "Animator.h"
#include "Hero.h"



class Hero : public GameCharacter {

public:
    Hero(sf::Texture& texture, int characterNumber);



    void die();

    bool isDying() const;
    bool isDead() const;


    void update(sf::Time delta);



private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;


    bool m_isDying;
    bool m_isDead;
    sf::Sprite m_visual;

    Animator m_runAnimator;
    Animator m_dieAnimator;
    Animator m_idleAnimator;
    Animator m_jumpAnimator;
    Animator m_attackAnimator;



};


#endif //VIDEOGAME_HERO_H
