//
// Created by Lapo Bartolacci on 23/08/17.
//

#include "gtest/gtest.h"

#include "../Hero.h"

TEST(Hero, DefaultConstructor){
    Hero *h;
    ASSERT_EQ( 0 ,h->getDirection().x);
    ASSERT_EQ( 0 ,h->getDirection().y);


}