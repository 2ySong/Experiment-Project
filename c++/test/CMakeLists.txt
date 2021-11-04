cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp)
include_directories("/E:\\Love me\\c++\\test\\max.h") #换成头文件所在目录

add_executable(max max.cpp)