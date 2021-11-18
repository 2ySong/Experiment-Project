cmake_minimum_required(VERSION 3.20)
project(pta_4)

include_directories("D:\\Program Files (x86)\\Microsoft SDKs\\MPI\\Include")
link_directories("D:\\Program Files (x86)\\Microsoft SDKs\\MPI\\Lib\\x64")
link_libraries(msmpi)

set(CMAKE_CXX_STANDARD 14)

add_executable(pta_4 main.cpp)

add_executable(4.1 4.1.cpp)
add_executable(Test test/Test.cpp)
add_executable(4.2 4.2.cpp)
add_executable(test2 test/test2.cpp)
add_executable(test3 test/test3.cpp)
add_executable(test4 test/test4.cpp)