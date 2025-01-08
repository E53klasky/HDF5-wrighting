import h5py
import adios2
import numpy as np
import argparse

# Function to read a variable from an HDF5 file
def read_hdf5(file_path, variable):
    with h5py.File(file_path, 'r') as f:
        if variable in f:
            return f[variable][...]
        else:
            raise ValueError(f"Variable '{variable}' not found in HDF5 file: {file_path}")

# Function to read a variable from an ADIOS BP file
def read_adios_bp(file_path, variable):
    with adios2.open(file_path, "r") as f:
        for step in f:
            if variable in step:
                return step.read(variable)
        raise ValueError(f"Variable '{variable}' not found in ADIOS BP file: {file_path}")

# Main function
def main():
    parser = argparse.ArgumentParser(description="Compare a variable between HDF5 and ADIOS BP files.")
    parser.add_argument("--hdf5", required=True, help="Path to the HDF5 file.")
    parser.add_argument("--adios", required=True, help="Path to the ADIOS BP file.")
    parser.add_argument("--variable", required=True, help="Variable to compare.")

    args = parser.parse_args()

    try:
        # Read the variable from both files
        hdf5_data = read_hdf5(args.hdf5, args.variable)
        adios_data = read_adios_bp(args.adios, args.variable)

        # Compare the data
        if hdf5_data.shape != adios_data.shape:
            print("The shapes of the data do not match:")
            print(f"HDF5 shape: {hdf5_data.shape}")
            print(f"ADIOS BP shape: {adios_data.shape}")
        else:
            diff = np.isclose(hdf5_data, adios_data, atol=1e-6)
            if np.all(diff):
                print("The data are identical within the tolerance.")
            else:
                print("The data differ:")
                print("Differences:", np.where(~diff))
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
