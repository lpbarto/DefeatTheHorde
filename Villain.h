//
// Created by Lapo Bartolacci on 03/07/17.
//

#ifndef VIDEOGAME_VILLAIN_H
#define VIDEOGAME_VILLAIN_H


#include "GameCharacter.h"
#include "Villain.h"
#include "Animator.h"
#include "MovementStrategy.h"
#include "Hero.h"

class MovementStrategy;

class Villain : public GameCharacter {

public:

    Villain(sf::Texture& texture, Hero* hero, std::string type);

    void setBehavior(MovementStrategy* behavior);
    void move();




    void die();

    bool isDying() const;
    bool isDead() const;



    void update(sf::Time delta);

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states)const ;
    sf::Sprite m_visual;
    Hero* m_hero;

    bool m_isDying;
    bool m_isDead;


    Animator m_vdieAnimator;
    Animator m_waitAnimator;

    MovementStrategy* m_behavior;



};


#endif //VIDEOGAME_VILLAIN_H
