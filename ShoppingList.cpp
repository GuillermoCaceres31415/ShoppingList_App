//
// Created by Guillermo on 14/09/24.
//



#include "ShoppingList.h"


void ShoppingList::AddProduct(std::string &name,std::string &category,unsigned int Product_qty) {
    auto *product=new Product (name,category,Product_qty);
    list.push_back(product);
    qty=qty+Product_qty;
    notify();
}

void ShoppingList::RemoveProduct(std::string &name) {
    for (auto itr :list) {
        if ((*itr).getNameProduct() == name) {
            list.remove(itr);
            qty=qty-(*itr).getQty();
            notify();
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

void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
}

void ShoppingList::unsubscribe(Observer *o) {
    observers.push_back(o);
}

void ShoppingList::notify() {
    for (auto itr=std::begin(observers);itr!=std::end(observers);itr++){
        (*itr)->update();
    }
}

unsigned int ShoppingList::getQty() const {
    return qty;
}

