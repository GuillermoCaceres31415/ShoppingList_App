//
// Created by Guillermo on 14/09/24.
//



#include "ShoppingList.h"


void ShoppingList::AddProduct(std::string &name,std::string &category,unsigned int qty) {
    Product *product=new Product (name,category,qty);
    list.push_back(product);
    qty=qty+product->getQty();
}

void ShoppingList::RemoveProduct(std::string &name) {
    for (auto itr = list.begin(); itr != list.end(); ++itr) {
        if ((*itr)->getNameProduct() == name) {
            delete *itr; // Dealloca l'oggetto
            list.erase(itr); // Rimuovi il puntatore dalla lista
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

