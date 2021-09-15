if (APPLE)
    cmake_minimum_required(VERSION 3.20)
    set(CMAKE_CXX_STANDARD 20)
elseif (LINUX)
    cmake_minimum_required(VERSION 3.10)
endif ()

project(Lambdas)

add_executable(Lambdas main.cpp)
add_executable(for_each_loop for_each_loop.cpp)
add_executable(lambda lambda.cpp)
add_executable(variadic_function variadic_function.cpp)
add_executable(custom_iterator custom_iterator.cpp)

add_subdirectory(Christmas_Ch1)
add_subdirectory(Christmas_Ch2)
