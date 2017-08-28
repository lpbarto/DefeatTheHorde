//
// Created by Lapo Bartolacci on 23/08/17.
//

#include "gtest/gtest.h"

#include "../Hero.h"

TEST(Hero, DefaultConstructor){
    Hero *h;

    ASSERT_EQ(0,h->getDirection().x);
    ASSERT_EQ(0,h->getDirection().y);


    ASSERT_FALSE(h->isDying());
    ASSERT_FALSE(h->isDead());


}

TEST(Hero, Death){
    Hero *h;

    h->die();
    ASSERT_FALSE(!h->isDying());

}