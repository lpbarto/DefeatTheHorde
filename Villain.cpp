//
// Created by Lapo Bartolacci on 03/07/17.
//

#include "Villain.h"

Villain::Villain(sf::Texture &texture, Hero *hero, std::string type)
        : m_visual(texture), m_isDying(false), m_isDead(false), m_hero(hero), m_isAttacking(false) {

    if(type == "zombie"){

        setOrigin(30, 50);

        setM_hp(10);

        setM_speed(80.f);

        /*   m_waitAnimator.addFrame(sf::IntRect(14,1823,52,85));
           m_waitAnimator.addFrame(sf::IntRect(66,1823,53,85));
           m_waitAnimator.addFrame(sf::IntRect(120,1823,53,84));
           m_waitAnimator.addFrame(sf::IntRect(178,1824,54,84));
           m_waitAnimator.addFrame(sf::IntRect(233,1824,54,84));
           m_waitAnimator.addFrame(sf::IntRect(289,1824,54,84));
           m_waitAnimator.addFrame(sf::IntRect(350,1824,54,84));
           m_waitAnimator.addFrame(sf::IntRect(408,1824,55,84));
           m_waitAnimator.addFrame(sf::IntRect(465,1824,55,84));
           m_waitAnimator.addFrame(sf::IntRect(525,1824,56,83));
           m_waitAnimator.addFrame(sf::IntRect(13,1918,56,85));
           m_waitAnimator.addFrame(sf::IntRect(71,1919,55,84));
           m_waitAnimator.addFrame(sf::IntRect(135,1918,54,84));
           */
        m_waitAnimator.addFrame(sf::IntRect(192, 1918, 54, 85));
        m_waitAnimator.addFrame(sf::IntRect(249, 1918, 54, 85));


        m_vattackAnimator.addFrame(sf::IntRect(196,1579,64,79));
        m_vattackAnimator.addFrame(sf::IntRect(274,1578,62,79));


    }else if(type == "robot"){

        setOrigin(30, 50);

        setM_hp(10);

        setM_speed(80.f);

        /*   m_waitAnimator.addFrame(sf::IntRect(14,1823,52,85));
           m_waitAnimator.addFrame(sf::IntRect(66,1823,53,85));
           m_waitAnimator.addFrame(sf::IntRect(120,1823,53,84));
           m_waitAnimator.addFrame(sf::IntRect(178,1824,54,84));
           m_waitAnimator.addFrame(sf::IntRect(233,1824,54,84));
           m_waitAnimator.addFrame(sf::IntRect(289,1824,54,84));
           m_waitAnimator.addFrame(sf::IntRect(350,1824,54,84));
           m_waitAnimator.addFrame(sf::IntRect(408,1824,55,84));
           m_waitAnimator.addFrame(sf::IntRect(465,1824,55,84));
           m_waitAnimator.addFrame(sf::IntRect(525,1824,56,83));
           m_waitAnimator.addFrame(sf::IntRect(13,1918,56,85));
           m_waitAnimator.addFrame(sf::IntRect(71,1919,55,84));
           m_waitAnimator.addFrame(sf::IntRect(135,1918,54,84));
           */
        m_waitAnimator.addFrame(sf::IntRect(387, 2700, 50, 85));
        m_waitAnimator.addFrame(sf::IntRect(441, 2701, 50, 84));
       // m_waitAnimator.addFrame(sf::IntRect(192, 1918, 54, 85));
        //m_waitAnimator.addFrame(sf::IntRect(249, 1918, 54, 85));

        m_vattackAnimator.addFrame(sf::IntRect(387, 2700, 50, 85));
        m_vattackAnimator.addFrame(sf::IntRect(441, 2701, 50, 84));


    }

    m_waitAnimator.play(sf::seconds(0.2), true);


}


void Villain::die() {

    if (!m_isDying) {
        m_vdieAnimator.play(sf::seconds(1), false);
        m_isDying = true;
    }

}

bool Villain::isDying() const {
    return m_isDying;
}

bool Villain::isDead() const {
    return m_isDead;
}


void Villain::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();

    if (!m_isDead)
        target.draw(m_visual, states);
}


void Villain::update(sf::Time delta) {

    this->move();


   this->villainAttack();
    m_isAttacking=false;

    if (!m_isDead && !m_isDying) {
        m_waitAnimator.play(sf::seconds(1), true);
        m_waitAnimator.update(delta);
        m_waitAnimator.animate(m_visual);

    }
    GameCharacter::update(delta);
}

void Villain::setBehavior(MovementStrategy *behavior) {
    this->m_behavior = behavior;
}

void Villain::move() {
    if (this->m_behavior)
        this->m_behavior->move(this, m_hero);
}

void Villain::villainAttack() {
    float damage = this->getM_attackSpeed() * 5;
    if(m_isAttacking){
       m_hero->setM_hp(m_hero->getM_hp() - static_cast<int>(damage));
    }


}

bool Villain::getAttacking() {
    return m_isAttacking;
}

void Villain::setAttacking(bool attacking) {
    m_isAttacking = attacking;
}