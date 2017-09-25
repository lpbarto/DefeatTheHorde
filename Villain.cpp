//
// Created by Lapo Bartolacci on 03/07/17.
//

#include "Villain.h"

Villain::Villain(sf::Texture &texture)
        : m_visual(texture)
        , m_isDying(false)
        , m_isDead(false)
{
    setOrigin(30,50);

    setM_hp(10);

    m_waitAnimator.addFrame(sf::IntRect(14,1823,52,85));
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
    m_waitAnimator.addFrame(sf::IntRect(192,1918,54,85));
    m_waitAnimator.addFrame(sf::IntRect(249,1918,54,85));

    m_waitAnimator.play(sf::seconds(1.2), true);

}


void Villain::die() {

    if(!m_isDying){
        m_dieAnimator.play(sf::seconds(1), false);
        m_isDying = true;
    }

}

bool Villain::isDying() const {
    return m_isDying;
}

bool Villain::isDead() const {
    return m_isDead;
}


void Villain::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    states.transform *= getTransform();

    if (!m_isDead)
        target.draw(m_visual, states);
}


void Villain::update(sf::Time delta)
{


    if(!m_isDead && !m_isDying)
    {
        m_waitAnimator.play(sf::seconds(1),true);
        m_waitAnimator.update(delta);
        m_waitAnimator.animate(m_visual);
    }
    else
    {
        m_dieAnimator.update(delta);
        m_dieAnimator.animate(m_visual);

        if (!m_dieAnimator.isPlaying())
        {
            m_isDying = false;
            m_isDead = true;
        }
    }
    GameCharacter::update(delta);
}

void Villain::setBehavior(MovementStrategy *behavior) {
    m_behavior = behavior;
}