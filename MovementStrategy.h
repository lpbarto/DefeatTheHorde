//
// Created by Lapo Bartolacci on 07/09/17.
//

#ifndef DEFEATTHEHORDE_MOVEMENTSTRATEGY_H
#define DEFEATTHEHORDE_MOVEMENTSTRATEGY_H

#include "Villain.h"
#include "Hero.h"


class Villain;

class MovementStrategy {

public:

    virtual void move(Villain* villain, Hero* hero) = 0;

};


class NormalBehavior : public MovementStrategy {

public:
    virtual void move(Villain* villain, Hero* hero);

};


class DefensiveBehavior : public MovementStrategy {

public:
    virtual void move(Villain* villain, Hero* hero);

};


class AggressiveBehavior : public MovementStrategy {

public:
    virtual void move(Villain* villain, Hero* hero);

};


#endif //DEFEATTHEHORDE_MOVEMENTSTRATEGY_H
