//
// Created by Lapo Bartolacci on 03/07/17.
//

#include "Hero.h"

Hero::Hero(sf::Texture& texture, int characterNumber)
        : m_visual(texture)
        , m_isDying(false)
        , m_isDead(false)
        , m_isAttacking(false)
        ,heroKills(0)
{
    setCharNum(characterNumber);

  if(characterNumber == 1) {  //hero

      setM_hp(100);


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

      m_idleAnimator.addFrame(sf::IntRect(458,544,69,99));
      m_idleAnimator.addFrame(sf::IntRect(534,544,69,98));
      m_idleAnimator.addFrame(sf::IntRect(455,649,69,98));
      m_idleAnimator.addFrame(sf::IntRect(532,648,68,97));
      m_idleAnimator.addFrame(sf::IntRect(455,755,69,97));
      m_idleAnimator.addFrame(sf::IntRect(532,755,67,97));
      m_idleAnimator.addFrame(sf::IntRect(453,860,66,97));
      m_idleAnimator.addFrame(sf::IntRect(529,859,68,98));
      m_idleAnimator.addFrame(sf::IntRect(453,964,68,98));
      m_idleAnimator.addFrame(sf::IntRect(527,962,71,99));


      m_dieAnimator.addFrame(sf::IntRect(78,104,74,105));
      m_dieAnimator.addFrame(sf::IntRect(152,104,72,105));
      m_dieAnimator.addFrame(sf::IntRect(224,104,74,103));
      m_dieAnimator.addFrame(sf::IntRect(298,104,81,93));
      m_dieAnimator.addFrame(sf::IntRect(379,104,85,90));
      m_dieAnimator.addFrame(sf::IntRect(464,104,88,84));
      m_dieAnimator.addFrame(sf::IntRect(0,209,96,75));
      m_dieAnimator.addFrame(sf::IntRect(95,210,111,61));
      m_dieAnimator.addFrame(sf::IntRect(207,210,115,54));
      m_dieAnimator.addFrame(sf::IntRect(321,210,117,53));

      m_jumpAnimator.addFrame(sf::IntRect(437,210,68,105));
      m_jumpAnimator.addFrame(sf::IntRect(505,210,70,110));
      m_jumpAnimator.addFrame(sf::IntRect(0,319,67,109));
      m_jumpAnimator.addFrame(sf::IntRect(67,320,67,105));
      m_jumpAnimator.addFrame(sf::IntRect(134,320,70,103));
      m_jumpAnimator.addFrame(sf::IntRect(204,320,69,102));
      m_jumpAnimator.addFrame(sf::IntRect(273,320,71,103));
      m_jumpAnimator.addFrame(sf::IntRect(344,320,71,105));
      m_jumpAnimator.addFrame(sf::IntRect(415,320,68,108));
      m_jumpAnimator.addFrame(sf::IntRect(483,320,68,108));

      m_attackAnimator.addFrame(sf::IntRect(0,0,65,102));
      m_attackAnimator.addFrame(sf::IntRect(65,0,61,102));
      m_attackAnimator.addFrame(sf::IntRect(126,0,58,102));
      m_attackAnimator.addFrame(sf::IntRect(185,0,60,102));
      m_attackAnimator.addFrame(sf::IntRect(245,0,69,102));
      m_attackAnimator.addFrame(sf::IntRect(314,0,78,100));
      m_attackAnimator.addFrame(sf::IntRect(391,0,79,100));
      m_attackAnimator.addFrame(sf::IntRect(471,0,79,100));
      m_attackAnimator.addFrame(sf::IntRect(550,0,83,102));
      m_attackAnimator.addFrame(sf::IntRect(0,104,78,102));



      m_idleAnimator.play(sf::seconds(1), true);

    }else if(characterNumber == 2){ //ninja


      setOrigin(30,40);

      setM_speed(200.f);
      setM_hp(50);

      m_runAnimator.addFrame(sf::IntRect(205,2446,60,80));
      m_runAnimator.addFrame(sf::IntRect(270,2452,60,83));
      m_runAnimator.addFrame(sf::IntRect(335,2452,60,83));
      m_runAnimator.addFrame(sf::IntRect(401,2453,66,78));
      m_runAnimator.addFrame(sf::IntRect(467,2454,66,79));
      m_runAnimator.addFrame(sf::IntRect(538,2453,60,79));
      m_runAnimator.addFrame(sf::IntRect(7,2538,59,83));
      m_runAnimator.addFrame(sf::IntRect(69,2537,59,80));
      m_runAnimator.addFrame(sf::IntRect(134,2538,59,75));
      m_runAnimator.addFrame(sf::IntRect(195,2541,61,79));

      m_idleAnimator.addFrame(sf::IntRect(368,2274,44,83));
      m_idleAnimator.addFrame(sf::IntRect(429,2275,44,82));
      m_idleAnimator.addFrame(sf::IntRect(486,2275,44,82));
      m_idleAnimator.addFrame(sf::IntRect(535,2275,44,82));
      m_idleAnimator.addFrame(sf::IntRect(586,2275,43,82));
      m_idleAnimator.addFrame(sf::IntRect(1,2358,44,81));
      m_idleAnimator.addFrame(sf::IntRect(45,2358,43,81));
      m_idleAnimator.addFrame(sf::IntRect(89,2358,43,82));
      m_idleAnimator.addFrame(sf::IntRect(133,2358,43,82));
      m_idleAnimator.addFrame(sf::IntRect(180,2358,44,82));


      m_dieAnimator.addFrame(sf::IntRect(184,2185,43,84));
      m_dieAnimator.addFrame(sf::IntRect(246,2189,50,80));
      m_dieAnimator.addFrame(sf::IntRect(302,2193,62,80));
      m_dieAnimator.addFrame(sf::IntRect(364,2204,70,69));
      m_dieAnimator.addFrame(sf::IntRect(438,2213,79,56));
      m_dieAnimator.addFrame(sf::IntRect(519,2215,81,52));
      m_dieAnimator.addFrame(sf::IntRect(6,2305,83,48));
      m_dieAnimator.addFrame(sf::IntRect(94,2309,83,48));
      m_dieAnimator.addFrame(sf::IntRect(182,2305,82,47));
      m_dieAnimator.addFrame(sf::IntRect(272,2304,84,48));

      m_jumpAnimator.addFrame(sf::IntRect(234,2364,53,82));
      m_jumpAnimator.addFrame(sf::IntRect(294,2364,49,86));
      m_jumpAnimator.addFrame(sf::IntRect(349,2364,47,81));
      m_jumpAnimator.addFrame(sf::IntRect(402,2364,47,82));
      m_jumpAnimator.addFrame(sf::IntRect(457,2363,47,81));
      m_jumpAnimator.addFrame(sf::IntRect(513,2365,47,81));
      m_jumpAnimator.addFrame(sf::IntRect(568,2369,51,79));
      m_jumpAnimator.addFrame(sf::IntRect(4,2442,56,79));
      m_jumpAnimator.addFrame(sf::IntRect(66,2446,62,77));
      m_jumpAnimator.addFrame(sf::IntRect(130,2444,61,77));

      m_attackAnimator.addFrame(sf::IntRect(9,2100,53,81));
      m_attackAnimator.addFrame(sf::IntRect(71,2099,52,82));
      m_attackAnimator.addFrame(sf::IntRect(129,2099,56,82));
      m_attackAnimator.addFrame(sf::IntRect(194,2098,50,82));
      m_attackAnimator.addFrame(sf::IntRect(247,2100,65,81));
      m_attackAnimator.addFrame(sf::IntRect(317,2102,100,79));
      m_attackAnimator.addFrame(sf::IntRect(420,2102,100,80));
      m_attackAnimator.addFrame(sf::IntRect(534,2103,73,79));
      m_attackAnimator.addFrame(sf::IntRect(3,2188,78,79));
      m_attackAnimator.addFrame(sf::IntRect(96,2187,73,80));

      /*
         m_slideAnimator.addFrame(sf::IntRect(272,2552,68,64));
         m_slideAnimator.addFrame(sf::IntRect(346,2548,68,64));
         m_slideAnimator.addFrame(sf::IntRect(420,2542,68,64));
         m_slideAnimator.addFrame(sf::IntRect(492,2543,67,64));
         m_slideAnimator.addFrame(sf::IntRect(562,2542,67,64));
         m_slideAnimator.addFrame(sf::IntRect(4,2621,66,65));
         m_slideAnimator.addFrame(sf::IntRect(72,2621,66,65));
         m_slideAnimator.addFrame(sf::IntRect(142,2621,67,64));
         m_slideAnimator.addFrame(sf::IntRect(213,2621,68,64));
         m_slideAnimator.addFrame(sf::IntRect(287,2620,67,64));

         m_throwAnimator.addFrame(sf::IntRect(360,2616,48,78));
         m_throwAnimator.addFrame(sf::IntRect(415,2616,45,81));
         m_throwAnimator.addFrame(sf::IntRect(473,2613,58,82));
         m_throwAnimator.addFrame(sf::IntRect(535,2615,56,82));
         m_throwAnimator.addFrame(sf::IntRect(3,2700,56,81));
         m_throwAnimator.addFrame(sf::IntRect(63,2700,56,83));
         m_throwAnimator.addFrame(sf::IntRect(123,2700,55,83));
         m_throwAnimator.addFrame(sf::IntRect(187,2700,60,83));
         m_throwAnimator.addFrame(sf::IntRect(252,2700,54,83));
         m_throwAnimator.addFrame(sf::IntRect(314,2701,45,81));


       */



      m_idleAnimator.play(sf::seconds(1), true);

    }


}

int Hero::attack() {

    if (!m_isAttacking) {
        m_attackAnimator.play(sf::seconds(1), false);
        m_isAttacking = true;

        if (getCharNum() == 1) { //hero
            return 3;
        } else if (getCharNum() == 2) {
            return 5;
        }
    } else{
        return 0;
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
    if(getM_hp() <= 0) {
        this->die();
    }

    if(m_isAttacking && !m_isDead && !m_isDying) {
        m_attackAnimator.update(delta);
        m_attackAnimator.animate(m_visual);

        if(!m_attackAnimator.isPlaying()){
            m_isAttacking = false;
        }
    }
    else if(!m_isDead && !m_isDying && getDirection() == sf::Vector2i(0,0))
    {
        m_idleAnimator.play(sf::seconds(1),true);
        m_idleAnimator.update(delta);
        m_idleAnimator.animate(m_visual);
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
    this->notify(Runner);
}


void Hero::setCharNum(int num) {
    CharNum = num;
}

int Hero::getCharNum() {
    return CharNum;
}


void Hero::addObserver(Observer *observer) {

        observerList.push_back(observer);

}

void Hero::removeObserver(Observer *observer) {

    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());

}

void Hero::notify(Event event) {

   // for (int i = 0; observerList.size(); i++)
   // {
        observerList[0]->onNotify(this, event);
   // }

}

int Hero::getHeroKills() {
    return heroKills;
}

void Hero::setHeroKills(int k) {
    heroKills = k;
}