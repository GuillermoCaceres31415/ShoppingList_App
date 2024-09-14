//
// Created by Guillermo on 14/09/24.
//



#include "ShoppingList.h"


void ShoppingList::AddProduct(Product *product) {
    list.push_back(product);
}

void ShoppingList::RemoveProduct(Product *product) {
    list.remove(product);
}

void ShoppingList::PrintList() {
    for (auto itr:list){
        itr->printProduct();
    }
}

