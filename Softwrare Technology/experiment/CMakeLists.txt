cmake_minimum_required(VERSION 3.20)
project(experiment)

set(CMAKE_CXX_STANDARD 14)

include_directories("D:\\Program Files (x86)\\Microsoft SDKs\\MPI\\Include")
link_directories("D:\\Program Files (x86)\\Microsoft SDKs\\MPI\\Lib\\x64")
link_libraries(msmpi)

add_executable(experiment main.cpp)

add_executable(3.1 3.1.cpp)
add_executable(4.1 4.1.cpp)
add_executable(mpi_test mpi_test.cpp)
add_executable(4.1.2 4.1.2.cpp)