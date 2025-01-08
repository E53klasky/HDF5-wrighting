cmake_minimum_required(VERSION 3.19)
project(PHDF5Example)


find_package(MPI REQUIRED)
find_package(HDF5 REQUIRED COMPONENTS C)
#find_package(ADIOS2 REQUIRED PATHS /opt/adios2/ NO_DEFAULT_PATH)

#set(ADIOS2_ROOT /opt/adios2/)
find_package(ADIOS2 REQUIRED)

add_definitions(-DOMPI_SKIP_MPICXX -DMPICH_SKIP_MPICXX)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -Wfatal-errors -Wall -Wextra")


add_executable(phdf5_example main.cpp)

target_link_libraries(phdf5_example 
    adios2::adios2 MPI::MPI_CXX hdf5::hdf5
)


