cmake_minimum_required(VERSION 3.10)
project(PHDF5Example C CXX)

# Find required packages
find_package(MPI REQUIRED)
find_package(HDF5 REQUIRED COMPONENTS C)

# Add executable
add_executable(phdf5_example main.cpp)

# Include directories
target_include_directories(phdf5_example PRIVATE 
    ${MPI_C_INCLUDE_DIRS}
    ${HDF5_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(phdf5_example 
    ${MPI_C_LIBRARIES}
    ${HDF5_LIBRARIES}
    mpi_cxx  # Link against MPI C++ library
)

# Specify C++ standard (optional, but recommended)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add MPI compile flags
target_compile_options(phdf5_example PRIVATE ${MPI_C_COMPILE_FLAGS})