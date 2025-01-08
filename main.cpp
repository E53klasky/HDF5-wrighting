#include <mpi.h>
#include <hdf5.h>
#include <H5FDmpio.h>
#include <cstdlib>
#include <iostream>
#include <adios2.h>
#include <vector>

#define H5FILE_NAME "SDS_row.h5"
#define DATASETNAME "IntArray"
#define NX          8 /* dataset dimensions */
#define NY          5
#define RANK        2

// ASSUMING THIS CODE ONLY RUNS WITH MPI 

int main(int argc , char** argv)
{
    /*
     * HDF5 APIs definitions
     */
    hid_t   file_id , dset_id;    /* file and dataset identifiers */
    hid_t   filespace , memspace; /* file and memory dataspace identifiers */
    hsize_t dimsf[2];            /* dataset dimensions */
    int* data;                /* pointer to data buffer to write */
    hsize_t count[2];            /* hyperslab selection parameters */
    hsize_t offset[2];
    hid_t   plist_id; /* property list identifier */
    int     i;
    herr_t  status;

    dimsf[0] = NX;
    dimsf[1] = NY;
    std::vector<int> myVector;


   /*
    * MPI variables
    */
    int provided;
    MPI_Init_thread(&argc , &argv , MPI_THREAD_MULTIPLE , &provided);

    // Move these after initialization
    int mpi_size , mpi_rank;
    MPI_Comm comm = MPI_COMM_WORLD;
    MPI_Info info = MPI_INFO_NULL;

    MPI_Comm_size(comm , &mpi_size);
    MPI_Comm_rank(comm , &mpi_rank);
    if (provided < MPI_THREAD_MULTIPLE) {
        std::cerr << "Warning: Insufficient MPI threading support" << std::endl;
    }
    /*
     * Initialize MPI
     */

    // #if ADIOS2_USE_MPI
    // std::cout << "Number of processes: " << mpi_size << std::endl;
    // // maybe it works now???
    // adios2::ADIOS adios("adios2.xml" , comm);
    // #else
    adios2::ADIOS adios;
   // #endif
    adios2::IO bpIO = adios.DeclareIO("WriteIO");
    adios2::Engine bpWriter = bpIO.Open("output" , adios2::Mode::Write);
    // adios2::Operator op = adios.DefineOperator("mgard" , "mgard");


   /*
    * Set up file access property list with parallel I/O access
    */
    plist_id = H5Pcreate(H5P_FILE_ACCESS);
    H5Pset_fapl_mpio(plist_id , comm , info);

    /*
     * Create a new file collectively and release property list identifier.
     */
    file_id = H5Fcreate(H5FILE_NAME , H5F_ACC_TRUNC , H5P_DEFAULT , plist_id);
    H5Pclose(plist_id);

        /*
         * Create the dataspace for the dataset.
         */
    dimsf[0] = NX;
    dimsf[1] = NY;
    filespace = H5Screate_simple(RANK , dimsf , NULL);

    /*
     * Create the dataset with default properties and close filespace.
     */
    dset_id =
        H5Dcreate(file_id , DATASETNAME , H5T_NATIVE_INT , filespace , H5P_DEFAULT , H5P_DEFAULT , H5P_DEFAULT);
    H5Sclose(filespace);

    /*
     * Each process defines dataset in memory and writes it to the hyperslab
     * in the file.
     */
    count[0] = dimsf[0] / mpi_size;
    count[1] = dimsf[1];
    offset[0] = mpi_rank * count[0];
    offset[1] = 0;
    memspace = H5Screate_simple(RANK , count , NULL);

    if (mpi_rank == 0)
        std::cout << "Count 0 is: " << count[0] << " offest for 0 is: " << offset[0] << "\n" << "Count 1 is: " << count[1] << " offest for 1 is: " << offset[1] << std::endl;


    /*
     * Select hyperslab in the file.
     */
    filespace = H5Dget_space(dset_id);
    H5Sselect_hyperslab(filespace , H5S_SELECT_SET , offset , NULL , count , NULL);

    /*
     * Initialize data buffer
     */
    data = (int*)malloc(sizeof(int) * count[0] * count[1]);
    for (i = 0; i < count[0] * count[1]; i++) {
        data[i] = mpi_rank + 10;
        myVector.push_back(mpi_rank + 10);
    }

    /*
     * Create property list for collective dataset write.
     */
    plist_id = H5Pcreate(H5P_DATASET_XFER);
    H5Pset_dxpl_mpio(plist_id , H5FD_MPIO_COLLECTIVE);

    status = H5Dwrite(dset_id , H5T_NATIVE_INT , memspace , filespace , plist_id , data);
    free(data);


    adios2::Variable<int> adiosVar = bpIO.DefineVariable<int>(
        "data" , { dimsf[0], dimsf[1] } , { offset[0], offset[1] } , { count[0], count[1] });


           // adios2::Variable<double> yOut = bpIO.DefineVariable<double>(
          //  name  globla size     offset     local size     
          //   "y",   {leny},    {start_y},   {local_len_y}, adios2::ConstantDims);
          /*
           * Close/release resources.
           */

    bpWriter.Put(adiosVar , myVector.data() , adios2::Mode::Sync);
    H5Dclose(dset_id);
    H5Sclose(filespace);
    H5Sclose(memspace);
    H5Pclose(plist_id);
    H5Fclose(file_id);

    bpWriter.Close();

    if (mpi_rank == 0)
        std::cout << "PHDF5 example finished with no errors" << std::endl;


    MPI_Finalize();

    return 0;
}