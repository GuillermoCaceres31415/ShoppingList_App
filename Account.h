//
// Created by Guillermo on 14/09/24.
//

#ifndef SHOPPINGLIST_APP_ACCOUNT_H
#define SHOPPINGLIST_APP_ACCOUNT_H
#include <iostream>
#include "ShoppingList.h"

class Account {
private:
    std::string name;
    std::string password;
    ShoppingList list;
public:
    Account(std::string& n,std::string& p);


    const std::string &getName() const;

     std::string getPassword() const;

     ShoppingList getList() const;

    void setList(const ShoppingList &list);
};


#endif //SHOPPINGLIST_APP_ACCOUNT_H
