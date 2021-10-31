cmake_minimum_required (VERSION 3.10)
project(parallel)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP)

find_package(MPI REQUIRED)

find_package(benchmark REQUIRED)

#add_executable(main main.cc)
#target_compile_definitions(main PUBLIC TEST)

add_executable(test_mpi_nonblocking test_mpi_nonblocking.cc)
target_link_libraries(test_mpi_nonblocking PRIVATE MPI::MPI_CXX)

add_executable(block_cyclic_scatter block_cyclic_scatter.cc)
target_link_libraries(block_cyclic_scatter PRIVATE MPI::MPI_CXX)

add_executable(sum_factor sum_factor.cc)
target_link_libraries(sum_factor benchmark::benchmark pthread)