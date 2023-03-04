cmake_minimum_required(VERSION 3.20)
project(t1_Timoficiuc_Daniel_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t1_Timoficiuc_Daniel_1
        domain.cpp
        domain.h
        main.cpp
        repo.cpp
        repo.h
        service.cpp
        service.h
        ui.cpp
        ui.h)
