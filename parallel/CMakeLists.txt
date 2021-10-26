cmake_minimum_required (VERSION 3.10)
project(parallel)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP)

find_package(MPI REQUIRED)

add_executable(main main.cc)
target_compile_definitions(main PUBLIC TEST)

add_executable(test_mpi_nonblocking test_mpi_nonblocking.cc)
target_link_libraries(test_mpi_nonblocking PRIVATE MPI::MPI_CXX)