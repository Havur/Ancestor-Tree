cmake_minimum_required(VERSION 3.21)
project(Ancestor_Tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ancestor_Tree
        main.cpp
        make_person.hpp)
