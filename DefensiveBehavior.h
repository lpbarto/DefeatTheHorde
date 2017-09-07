//
// Created by Lapo Bartolacci on 07/09/17.
//

#ifndef DEFEATTHEHORDE_DEFENSIVEBEHAVIOR_H
#define DEFEATTHEHORDE_DEFENSIVEBEHAVIOR_H


#include "MovementStrategy.h"

class DefensiveBehavior : public MovementStrategy {

public:
    virtual void move() const;

};


#endif //DEFEATTHEHORDE_DEFENSIVEBEHAVIOR_H
