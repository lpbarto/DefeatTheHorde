//
// Created by Lapo Bartolacci on 06/10/17.
//

#ifndef DEFEATTHEHORDE_VILLAINFACTORY_H
#define DEFEATTHEHORDE_VILLAINFACTORY_H

#include "Villain.h"

class VillainFactory {

public:
    Villain* createVillain(sf::Texture& texture, Hero* hero,std::string type) const ;





};


#endif //DEFEATTHEHORDE_VILLAINFACTORY_H
