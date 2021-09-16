cmake_minimum_required(VERSION 3.20)
project(FoglioDiCalcolo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(FoglioDiCalcolo
        Fogliodicalcolo.cpp
        Fogliodicalcolo.h
        main.cpp
        TestFoglioCalcolo.cpp)
