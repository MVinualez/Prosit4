cmake_minimum_required(VERSION 3.26)
project(workshop4_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(workshop4_1 main.cpp
        lib/Recepteur.cpp
        lib/Recepteur.h
        lib/Emetteur.h
        lib/Emetteur.cpp)
