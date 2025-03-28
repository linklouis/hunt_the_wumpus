cmake_minimum_required(VERSION 3.30)
project(Hunt_The_Wumpus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Hunt_The_Wumpus main.cpp
        Map.cpp
        Map.h
        Room.cpp
        Room.h
        Entity.cpp
        Entity.h
        ActiveEntity.cpp
        ActiveEntity.h
        ActiveEntity.cpp
        ActiveEntity.h
        Player.cpp
        Player.h
        Wumpus.cpp
        Wumpus.h
        Treent.cpp
        Treent.h
        Nightmare.cpp
        Nightmare.h
        Vector.cpp
        Vector.h
        Remains.cpp
        Remains.h)
