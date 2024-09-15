//
// Created by Guillermo on 14/09/24.
//



#include "ShoppingList.h"


void ShoppingList::AddProduct(std::string &name,std::string &category,unsigned int Product_qty) {
    auto *product=new Product (name,category,Product_qty);
    list.push_back(product);
    qty=qty+Product_qty; //
}

void ShoppingList::RemoveProduct(std::string &name) {
    for (auto itr :list) {
        if ((*itr).getNameProduct() == name) {
            list.remove(itr);
            qty=qty-(*itr).getQty();
            return;
        }
    }
    std::cout << "prodotto non trovato" << std::endl;
}


void ShoppingList::PrintList() {
    if (list.empty())
        std::cout<<"la lista è vuota"<<std::endl;
    else {
        for (auto itr: list)
            itr->printProduct();
    }
}

