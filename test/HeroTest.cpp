//
// Created by Lapo Bartolacci on 23/08/17.
//

#include "gtest/gtest.h"

#include "../Hero.h"

TEST(Hero, DefaultConstructor){
    Hero *h;

    ASSERT_FALSE(h->isDying());
    ASSERT_FALSE(h->isDead());


}

TEST(Hero, Death){
    Hero *h;

    h->die();
    ASSERT_FALSE(!h->isDying());

}