//
// Created by Lapo Bartolacci on 03/07/17.
//

#ifndef VIDEOGAME_HERO_H
#define VIDEOGAME_HERO_H


#include "GameCharacter.h"
#include "Animator.h"
#include "Hero.h"
#include "Observer.h"
#include "Event.h"
#include <vector>

class Observer;


class Hero : public GameCharacter {

public:
    Hero(sf::Texture& texture, int characterNumber);

    int attack();

    void die();

    bool runnerBadgeVisible;
    bool killerBadgeVisible;


    bool isDying() const;
    bool isDead() const;

    int getCharNum();
    void setCharNum(int);


    void update(sf::Time delta);



    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);

    void notify(Event event);




private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    int CharNum;

    bool m_isAttacking;


    bool m_isDying;
    bool m_isDead;
    sf::Sprite m_visual;

    Animator m_runAnimator;
    Animator m_dieAnimator;
    Animator m_idleAnimator;
    Animator m_jumpAnimator;
    Animator m_attackAnimator;

    //Observer

    //Observer* observers_[MAX_OBSERVERS];
    std::vector<class Observer*> observerList;







};


#endif //VIDEOGAME_HERO_H
