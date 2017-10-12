//
// Created by Lapo Bartolacci on 03/10/17.
//

#include "Observer.h"
#include <math.h>

Achievements::Achievements():pixelTraveled(0) {}

void Achievements::onNotify(Hero* hero, Event event) {

    {
        switch (event)
        {
            case Runner:
                pxTraveled = abs(getCurrentPxPosition() - hero->getNextPixelPosition());
                setPixelTraveled(getPixelTraveled() + pxTraveled);
                setCurrentPxPosition(hero->getNextPixelPosition());
                if (getPixelTraveled() >= 10000)
                {
                  hero->runnerBadgeVisible = true;
                }
                break;

            case Killer:
                hero->setHeroKills(hero->getHeroKills() + 1);
                if(hero->getHeroKills() == 3)
                {
                    hero->killerBadgeVisible = true;
                }
                break;

        }
    }
}


float Achievements::getPixelTraveled() {
    return pixelTraveled;
}

void Achievements::setPixelTraveled(float px) {
    pixelTraveled = px;
}

float Achievements::getCurrentPxPosition() {
    return currentPxPosition;
}

void Achievements::setCurrentPxPosition(float pos) {
    currentPxPosition = pos;
}