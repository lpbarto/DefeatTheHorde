//
// Created by Lapo Bartolacci on 03/10/17.
//

#include "Observer.h"

void Achievements::onNotify(Hero* hero, Event event) {

    {
        switch (event)
        {
            case Runner:
                setPixelTraveled(getPixelTraveled() + hero->getPixelTraveled());
                if (getPixelTraveled() >= 1000)
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