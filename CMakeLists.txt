cmake_minimum_required(VERSION 4.1)
project(MetroSim)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MetroSim
        main.cpp
        Tren.cpp
        Tren.h
        TrenLent.cpp
        TrenLent.h
        TrenNormal.cpp
        TrenNormal.h
        TrenRapid.cpp
        TrenRapid.h
        Statie.cpp
        Statie.h
        Linie.cpp
        Linie.h
        Joc.cpp
        Joc.h)
