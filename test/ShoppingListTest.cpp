//
// Created by Marco Bertini on 02/05/16.
//

#include "gtest/gtest.h"

#include "../ShoppingList.h"

TEST(ShoppingList, DefaultConstructor) {
    ShoppingList s;
    ASSERT_EQ(0, s.getQty());

}


