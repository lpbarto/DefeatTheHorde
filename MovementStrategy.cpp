//ii
// Created by Lapo Bartolacci on 07/09/17.
//

#include "MovementStrategy.h"


void NormalBehavior::move(Villain* villain, Hero* hero) {

    if(hero->getPosition().x < villain->getPosition().x){

        villain->setDirection(sf::Vector2i(-1,0));

    }else if (hero->getPosition().x > villain->getPosition().x){

        villain->setDirection(sf::Vector2i(1,0));

    }


}



void DefensiveBehavior::move(Villain* villain, Hero* hero) {

    villain->setM_speed(villain->getM_speed() / 2);

    if(hero->getPosition().x < villain->getPosition().x){

        villain->setDirection(sf::Vector2i(-1,0));

    }else if (hero->getPosition().x > villain->getPosition().x){

        villain->setDirection(sf::Vector2i(1,0));

    }

}



void AggressiveBehavior::move(Villain* villain, Hero* hero) {

   villain->setM_speed(villain->getM_speed() * 2);

    if(hero->getPosition().x < villain->getPosition().x){

        villain->setDirection(sf::Vector2i(-1,0));

    }else if (hero->getPosition().x > villain->getPosition().x){

        villain->setDirection(sf::Vector2i(1,0));

    }

}