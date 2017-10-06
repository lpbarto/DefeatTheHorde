//
// Created by Lapo Bartolacci on 06/10/17.
//

#include "VillainFactory.h"

Villain* VillainFactory::createVillain(sf::Texture &texture, Hero *hero, std::string type) const {
    Villain* villain = 0;

    if(type == "zombie")
        villain = new Villain(texture, hero, type);
    if(type == "robot")
        villain = new Villain(texture, hero, type);

    return villain;
}