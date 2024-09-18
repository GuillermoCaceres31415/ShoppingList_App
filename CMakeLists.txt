cmake_minimum_required(VERSION 3.5)
project(ShoppingList_App)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILE
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

add_executable(ShoppingList_App main.cpp)
add_library(core ${SOURCE_FILE})
target_link_libraries(ShoppingList_App core)