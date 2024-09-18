//
// Created by Guillermo314 on 02/05/16.
//

#include "gtest/gtest.h"

#include "../ShoppingList.h"



class ShoppingListSuite : public ::testing::Test {

protected:
     void SetUp() override{
        std::string name1="mela";
        std::string category1="Frutta";
        s.AddProduct(name1,category1,5);

        std::string name2="Latte";
        std::string category2="Latticini";
        s.AddProduct(name2,category2,2);

    }

    ShoppingList s;
};


TEST_F(ShoppingListSuite, TestMove) {
    ASSERT_EQ(7,s.getQty());
}
