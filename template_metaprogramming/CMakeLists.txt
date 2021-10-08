cmake_minimum_required(VERSION 3.10)

project(template_metaprogramming)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(benchmark REQUIRED
	HINTS /export/home/cucui/Documents/UniHeidelberg/benchmark/build/src)

add_compile_options(
        -std=c++2a -O0
)

add_executable(cppcon2014_p1 cppcon2014_p1.cpp OOP.cc)
target_link_libraries(cppcon2014_p1 benchmark::benchmark)
