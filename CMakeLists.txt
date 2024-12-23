cmake_minimum_required(VERSION 3.10)
project(PHDF5Example C CXX)


find_package(MPI REQUIRED)
find_package(HDF5 REQUIRED COMPONENTS C)


add_executable(phdf5_example main.cpp)


target_include_directories(phdf5_example PRIVATE 
    ${MPI_C_INCLUDE_DIRS}
    ${HDF5_INCLUDE_DIRS}
)


target_link_libraries(phdf5_example 
    ${MPI_C_LIBRARIES}
    ${HDF5_LIBRARIES}
    ${ADIOS2_LIBRARIES}
    mpi_cxx  
)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


target_compile_options(phdf5_example PRIVATE ${MPI_C_COMPILE_FLAGS})