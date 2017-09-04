//
// Created by Lapo Bartolacci on 04/09/17.
//

#include "gtest/gtest.h"
#include "../Villain.h"

TEST(Villain, Constructor){
    Villain *villain;
    villain->setOrigin(30,50);
    ASSERT_EQ(villain->getOrigin(), sf::Vector2f(30,50));

    ASSERT_EQ(villain->getDirection(), sf::Vector2i(0,0));




}
