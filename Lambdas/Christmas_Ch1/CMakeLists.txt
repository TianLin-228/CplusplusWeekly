if (APPLE)
    cmake_minimum_required(VERSION 3.20)
    set(CMAKE_CXX_STANDARD 20)
elseif (LINUX)
    cmake_minimum_required(VERSION 3.10)
endif ()

project(Christmas_Class)

add_executable(ep133 ep133.cpp)
add_executable(ep37 ep37.cpp)
add_executable(ep51 ep51.cpp)
add_executable(ep40 ep40.cpp)
add_executable(ep97 ep97.cpp)
add_executable(exercise exercise.cpp)