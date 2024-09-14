//
// Created by Guillermo on 14/09/24.
//

#ifndef SHOPPINGLIST_APP_PRODUCT_H
#define SHOPPINGLIST_APP_PRODUCT_H
#include <iostream>


class Product {
private:
    std::string nameProduct;
    std::string category;
    unsigned int qty;
public:
    Product(std::string& name,std::string &cat,unsigned int qty):nameProduct(name),category(cat),qty(qty){}

    void printProduct();

    ~Product()=default;



};


#endif //SHOPPINGLIST_APP_PRODUCT_H
