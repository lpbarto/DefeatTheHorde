//
// Created by Lapo Bartolacci on 07/09/17.
//

#ifndef DEFEATTHEHORDE_AGGRESSIVEBEHAVIOR_H
#define DEFEATTHEHORDE_AGGRESSIVEBEHAVIOR_H


#include "MovementStrategy.h"

class AggressiveBehavior : public MovementStrategy {

public:
    virtual void move() const;

};


#endif //DEFEATTHEHORDE_AGGRESSIVEBEHAVIOR_H
