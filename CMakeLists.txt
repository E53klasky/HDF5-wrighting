cmake_minimum_required(VERSION 3.19)
project(PHDF5Example)

# Enable C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add ADIOS2 path to CMAKE_PREFIX_PATH
set(CMAKE_PREFIX_PATH "/home/adios/local/adios-install")

# Find required packages
find_package(MPI REQUIRED)
find_package(HDF5 REQUIRED COMPONENTS C CXX)
find_package(ADIOS2 REQUIRED)

# Skip MPI C++ bindings
add_definitions(-DOMPI_SKIP_MPICXX -DMPICH_SKIP_MPICXX)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -Wfatal-errors -Wall -Wextra")

# Add executable
add_executable(phdf5_example main.cpp)

# Link libraries
target_link_libraries(phdf5_example 
    adios2::adios2 
    MPI::MPI_CXX 
    hdf5::hdf5
)

# Print information for debugging
message(STATUS "MPI include dirs: ${MPI_INCLUDE_PATH}")
message(STATUS "HDF5 include dirs: ${HDF5_INCLUDE_DIRS}")
message(STATUS "ADIOS2 include dirs: ${ADIOS2_INCLUDE_DIRS}")
