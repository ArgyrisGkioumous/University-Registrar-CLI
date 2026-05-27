cmake_minimum_required(VERSION 4.2)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        Professor.cpp
        Professor.h
        Member.cpp
        Member.h
        Course.cpp
        Course.h
        Student.cpp
        Student.h
        Registrar.cpp
        Registrar.h)
