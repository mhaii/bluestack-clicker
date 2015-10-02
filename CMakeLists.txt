cmake_minimum_required(VERSION 3.3)
project(bluestack_clicker)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

set(SOURCE_FILES main.cpp keylist.h)
add_executable(bluestack_clicker ${SOURCE_FILES} keylist.h)