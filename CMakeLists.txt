cmake_minimum_required(VERSION 3.10)
project(NesterLite)

set(CMAKE_CXX_STANDARD 17)

add_executable(NesterLite
    main.cpp
    polygon.cpp
    polygon.h
    svg_writer.cpp
    svg_writer.h
)
