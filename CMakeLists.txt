cmake_minimum_required(VERSION 3.30)
project(ShoppingList_App)

set(CMAKE_CXX_STANDARD 11)

add_executable(ShoppingList_App main.cpp
        Account.cpp
        Account.h
        Product.cpp
        Product.h
        ShoppingList.cpp
        ShoppingList.h
        Subject.h
        Observer.h
        DisplayShowQty.cpp
        DisplayShowQty.h)
