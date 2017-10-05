//
// Created by Lapo Bartolacci on 03/10/17.
//

#include "Observer.h"
#include <math.h>

Achievements::Achievements():heroKills(0),pixelTraveled(0) {}

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
                    unlock(Runner);
                }
                break;

            case Terminator:
                setHeroKills(getHeroKills() + 1);
                if(getHeroKills() == 3)
                {
                    unlock(Terminator);
                }
                break;

        }
    }
}

void Achievements::unlock(Event event) {
    {
        // Unlock if not already unlocked...
    }

}


int Achievements::getHeroKills() {
    return heroKills;
}

void Achievements::setHeroKills(int k) {
    heroKills = k;
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