//
// Created by Lapo Bartolacci on 03/10/17.
//

#ifndef DEFEATTHEHORDE_OBSERVER_H
#define DEFEATTHEHORDE_OBSERVER_H

#include "Event.h"
#include "Hero.h"

class Hero;

class Observer {

public:

    virtual ~Observer() {}
    virtual void onNotify(Hero* hero, Event event) = 0;

};



class Achievements : public Observer
{
public:
    virtual void onNotify(Hero* hero, Event event);

    int getHeroKills();
    void setHeroKills(int k);
    float getPixelTraveled();
    void setPixelTraveled(float px);


private:
    void unlock(Event event);
    int heroKills;
    float pixelTraveled;
};

#endif //DEFEATTHEHORDE_OBSERVER_H
