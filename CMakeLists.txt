cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)



add_executable(SDL2Test main.cpp)
target_link_libraries(SDL2Test sfml-graphics)