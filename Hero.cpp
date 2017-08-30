//
// Created by Lapo Bartolacci on 03/07/17.
//

#include "Hero.h"

Hero::Hero(sf::Texture& texture, int characterNumber)
        : m_visual(texture)
        , m_isDying(false)
        , m_isDead(false)
{
  if(characterNumber == 1) {

        setOrigin(30, 60);


        m_runAnimator.addFrame(sf::IntRect(551, 321, 67, 105));
        m_runAnimator.addFrame(sf::IntRect(0, 429, 61, 110));
        m_runAnimator.addFrame(sf::IntRect(62, 429, 62, 104));
        m_runAnimator.addFrame(sf::IntRect(126, 429, 62, 103));
        m_runAnimator.addFrame(sf::IntRect(189, 429, 63, 103));
        m_runAnimator.addFrame(sf::IntRect(252, 429, 67, 104));
        m_runAnimator.addFrame(sf::IntRect(319, 429, 70, 107));
        m_runAnimator.addFrame(sf::IntRect(389, 429, 68, 104));
        m_runAnimator.addFrame(sf::IntRect(457, 429, 70, 103));
        m_runAnimator.addFrame(sf::IntRect(527, 429, 72, 105));

        m_notMovingAnimator.addFrame(sf::IntRect(527, 429, 72, 105));

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
        m_notMovingAnimator.play(sf::seconds(1), true);
    }else if(characterNumber == 2){

       setOrigin(30, 60);

        m_notMovingAnimator.addFrame(sf::IntRect(467,622,500,666));
        m_notMovingAnimator.play(sf::seconds(1), true);

    }


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
    if(!m_isDead && !m_isDying && getDirection() == sf::Vector2i(0,0))
    {
        m_notMovingAnimator.play(sf::seconds(1),true);
        m_notMovingAnimator.update(delta);
        m_notMovingAnimator.animate(m_visual);
    }

    else if (!m_isDead && !m_isDying && getDirection() != sf::Vector2i(0,0))
    {
        m_runAnimator.play(sf::seconds(1.1),true);
        m_runAnimator.update(delta);
        m_runAnimator.animate(m_visual);
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
