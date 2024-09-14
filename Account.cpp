//
// Created by Guillermo on 14/09/24.
//

#include "Account.h"

Account::Account(std::string &n, std::string& p) :name(n),password(p),list(nullptr){}

const std::string &Account::getName() const {
    return name;
}

const std::string &Account::getPassword() const {
    return password;
}

