cmake_minimum_required(VERSION 3.15)
project(Coffee-Shop)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp CoffeeItem.cpp CoffeeItem.h EspressoItem.cpp EspressoItem.h)
add_executable(testing testing.cpp CoffeeItem.cpp CoffeeItem.h EspressoItem.cpp EspressoItem.h)
