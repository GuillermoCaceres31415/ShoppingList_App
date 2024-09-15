//
// Created by Guillermo on 14/09/24.
//

#ifndef SHOPPINGLIST_APP_SHOPPINGLIST_H
#define SHOPPINGLIST_APP_SHOPPINGLIST_H
#include "Product.h"
#include <list>


class ShoppingList {
private:
    std::list<Product*> list;
    unsigned int qty;
public:
    ShoppingList():qty(0){}

    void AddProduct(std::string &name,std::string &category,unsigned int qty);

    void RemoveProduct(std::string &name);

    void PrintList();

    ~ShoppingList()=default;



};


#endif //SHOPPINGLIST_APP_SHOPPINGLIST_H
