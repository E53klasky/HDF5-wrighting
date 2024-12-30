cmake_minimum_required(VERSION 3.19)
project(PHDF5Example)


find_package(MPI REQUIRED)
find_package(HDF5 REQUIRED COMPONENTS C)
find_package(ADIOS2 REQUIRED PATHS /opt/adios2/ NO_DEFAULT_PATH)



add_definitions(-DOMPI_SKIP_MPICXX -DMPICH_SKIP_MPICXX)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -Wfatal-errors -Wall -Wextra")


add_executable(phdf5_example main.cpp)
link_directories(/opt/adios2/lib)
target_link_libraries(phdf5_example 
    adios2_cxx11_mpi    
    adios2_cxx11        
    adios2_c_mpi        
    adios2_c           
    MPI::MPI_C         
    ${HDF5_LIBRARIES}   
)
