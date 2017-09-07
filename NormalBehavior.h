//
// Created by Lapo Bartolacci on 07/09/17.
//

#ifndef DEFEATTHEHORDE_NORMALBEHAVIOR_H
#define DEFEATTHEHORDE_NORMALBEHAVIOR_H


#include "MovementStrategy.h"

class NormalBehavior : public MovementStrategy {

public:
    virtual void move() const;

};


#endif //DEFEATTHEHORDE_NORMALBEHAVIOR_H
