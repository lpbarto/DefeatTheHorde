//
// Created by Lapo Bartolacci on 23/08/17.
//

#include "gtest/gtest.h"

#include "../Hero.h"


TEST(Hero, DefaultConstructor){
sf::Texture texture;


    Hero *h = new Hero(texture,2);

    ASSERT_EQ(0,h->getDirection().x);
    ASSERT_EQ(0,h->getDirection().y);


    ASSERT_FALSE(h->isDying());
    ASSERT_FALSE(h->isDead());


}

TEST(Hero, Death){

    sf::Texture texture;


    Hero *h = new Hero(texture,2);

    h->die();
    ASSERT_FALSE(!h->isDying());

}