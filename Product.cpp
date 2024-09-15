//
// Created by Guillermo on 14/09/24.
//

#include "Product.h"

void Product::printProduct() {
    std::cout<<"--> "<<nameProduct<<" qty: "<<qty<<std::endl;
}

const std::string &Product::getNameProduct() const {
    return nameProduct;
}

const std::string &Product::getCategory() const {
    return category;
}

unsigned int Product::getQty() const {
    return qty;
}
