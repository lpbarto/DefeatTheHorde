//ii
// Created by Lapo Bartolacci on 07/09/17.
//

#include "MovementStrategy.h"
#include <math.h>


void NormalBehavior::move(Villain* villain, Hero* hero) {

    villain->setM_attackSpeed(1);

    if(fabs(villain->getPosition().x - hero->getPosition().x) <= 40 ){

        villain->setDirection(sf::Vector2i(0,0));
        int attackProbability = rand() % 100;
        villain->setAttacking(attackProbability == 0);

    }else{

        if(hero->getPosition().x < villain->getPosition().x){

            villain->setDirection(sf::Vector2i(-1,0));

        }else if (hero->getPosition().x > villain->getPosition().x){

            villain->setDirection(sf::Vector2i(1,0));

        }

    }

}



void DefensiveBehavior::move(Villain* villain, Hero* hero) {

    villain->setM_speed(40.f);
    villain->setM_attackSpeed(0.8);


    if(fabs(villain->getPosition().x - hero->getPosition().x) <= 40 ){

        villain->setDirection(sf::Vector2i(0,0));
        int attackProbability = rand() % 100;
        villain->setAttacking(attackProbability == 0);

    }else{

        if(hero->getPosition().x < villain->getPosition().x){

            villain->setDirection(sf::Vector2i(-1,0));

        }else if (hero->getPosition().x > villain->getPosition().x){

            villain->setDirection(sf::Vector2i(1,0));

        }

    }

}



void AggressiveBehavior::move(Villain* villain, Hero* hero) {

    villain->setM_speed(120.f);
    villain->setM_attackSpeed(2.3);


    if(fabs(villain->getPosition().x - hero->getPosition().x) <= 40 ){

        villain->setDirection(sf::Vector2i(0,0));
        int attackProbability = rand() % 100;
        villain->setAttacking(attackProbability == 0);

    }else{

        if(hero->getPosition().x < villain->getPosition().x){

            villain->setDirection(sf::Vector2i(-1,0));

        }else if (hero->getPosition().x > villain->getPosition().x){

            villain->setDirection(sf::Vector2i(1,0));

        }

    }

}