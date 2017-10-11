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
    Achievements();
    virtual void onNotify(Hero* hero, Event event);


    float getPixelTraveled();
    void setPixelTraveled(float px);
    float getCurrentPxPosition();
    void setCurrentPxPosition(float pos);


private:
    void unlock(Event event);

    float pixelTraveled;
    float currentPxPosition;
    float pxTraveled;
};

#endif //DEFEATTHEHORDE_OBSERVER_H
