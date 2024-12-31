#include <mpi.h>
#include <iostream>

int main(int argc , char** argv) {
    int provided;
    int init_result = MPI_Init_thread(&argc , &argv , MPI_THREAD_MULTIPLE , &provided);
    if (init_result != MPI_SUCCESS) {
        std::cerr << "MPI Initialization failed with error code " << init_result << std::endl;
        MPI_Abort(MPI_COMM_WORLD , init_result);
        return init_result;
    }

    std::cout << "MPI_Init_thread provided: " << provided << std::endl;

    MPI_Comm comm = MPI_COMM_WORLD;
    MPI_Info info = MPI_INFO_NULL;

    int mpi_size;
    int mpi_rank;

    int comm_size_result = MPI_Comm_size(comm , &mpi_size);
    if (comm_size_result != MPI_SUCCESS) {
        std::cerr << "MPI_Comm_size failed with error code " << comm_size_result << std::endl;
        MPI_Abort(comm , comm_size_result);
        return comm_size_result;
    }
    std::cout << "MPI_Comm_size: " << mpi_size << std::endl;

    int comm_rank_result = MPI_Comm_rank(comm , &mpi_rank);
    if (comm_rank_result != MPI_SUCCESS) {
        std::cerr << "MPI_Comm_rank failed with error code " << comm_rank_result << std::endl;
        MPI_Abort(comm , comm_rank_result);
        return comm_rank_result;
    }
    std::cout << "MPI_Comm_rank: " << mpi_rank << std::endl;

    std::cout << "Hello world from rank " << mpi_rank << " out of " << mpi_size << " processors" << std::endl;

    MPI_Finalize();
    return 0;
}
