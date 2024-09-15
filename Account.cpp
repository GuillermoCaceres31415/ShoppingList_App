//
// Created by Guillermo on 14/09/24.
//

#include "Account.h"

Account::Account(std::string &n, std::string& p) :name(n),password(p),list(){}



const std::string &Account::getName() const {
    return name;
}

 std::string Account::getPassword() const {
    return password;
}

 ShoppingList &Account::getList()  {
    return list;
}


