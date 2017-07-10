//
// Created by Lapo Bartolacci on 03/07/17.
//

#include "Hero.h"

Hero::Hero(sf::Texture& texture)
        : m_visual(texture)
        , m_isDying(false)
        , m_isDead(false)
{
    setOrigin(20,20);

    /*
    m_runAnimator.addFrame(sf::IntRect(3308,1924,400,666));
    m_runAnimator.addFrame(sf::IntRect(0,2573,400,666));
    m_runAnimator.addFrame(sf::IntRect(372,2573,400,666));
    m_runAnimator.addFrame(sf::IntRect(750,2573,400,666));
    m_runAnimator.addFrame(sf::IntRect(1133,2573,400,666));
    m_runAnimator.addFrame(sf::IntRect(1515,2573,400,666));
    m_runAnimator.addFrame(sf::IntRect(1917,2573,400,666));
    m_runAnimator.addFrame(sf::IntRect(2336,2573,400,666));
    m_runAnimator.addFrame(sf::IntRect(2747,2573,400,666));*/
    m_runAnimator.addFrame(sf::IntRect(527,429,72,105));

/*
    m_dieAnimator.addFrame(sf::IntRect(467,622,500,666));
    m_dieAnimator.addFrame(sf::IntRect(911,622,500,666));
    m_dieAnimator.addFrame(sf::IntRect(1347,622,500,666));
    m_dieAnimator.addFrame(sf::IntRect(1788,622,500,666));
    m_dieAnimator.addFrame(sf::IntRect(2280,622,500,666));
    m_dieAnimator.addFrame(sf::IntRect(2785,622,500,666));
    m_dieAnimator.addFrame(sf::IntRect(0,1260,500,666));
    m_dieAnimator.addFrame(sf::IntRect(575,1260,500,666));
    m_dieAnimator.addFrame(sf::IntRect(1242,1260,500,666));
    m_dieAnimator.addFrame(sf::IntRect(1933,1260,500,666));
*/
    m_runAnimator.play(sf::seconds(1.1), true);
}

void Hero::die() {

    if(!m_isDying){
        m_dieAnimator.play(sf::seconds(1), false);
        m_isDying = true;
    }

}

bool Hero::isDying() const {
    return m_isDying;
}

bool Hero::isDead() const {
    return m_isDead;
}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    states.transform *= getTransform();

    if(!m_isDead)
        target.draw(m_visual,states);


}

void Hero::update(sf::Time delta)
{
    if (!m_isDead && !m_isDying)
    {
        m_runAnimator.update(delta);
        m_runAnimator.animate(m_visual);
    }
    else
    {
       //m_dieAnimator.update(delta);
        m_dieAnimator.animate(m_visual);

        if (!m_dieAnimator.isPlaying())
        {
            m_isDying = false;
            m_isDead = true;
        }
    }
}
