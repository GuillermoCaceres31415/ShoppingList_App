cmake_minimum_required(VERSION 3.5)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES runAllTests.cpp ShoppingListTest.cpp ShoppingListFixture.cpp)
add_executable(runShoppingListTests ${SOURCE_FILES})
target_link_libraries(runShoppingListTests ${GTEST_BOTH_LIBRARIES} core)