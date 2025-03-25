cmake_minimum_required(VERSION 3.30)
project(Hunt_The_Wumpus)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hunt_The_Wumpus main.cpp
        Map.cpp
        Map.h
        Room.cpp
        Room.h)
