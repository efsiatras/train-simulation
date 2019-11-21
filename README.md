# Train Simulation
Simulation of a subway train.

### Compilation
`$ make clean`

`$ make`

### Usage
Command line arguments are optional.

`$ ./train_simulation <Total Stations> <Total Waggons> <Max Capacity of Each Waggon> <Full Fine> <Reduced Fine>`

### Design Decisions
There are three classes: **Passenger**, **Waggon** and **Train**.
-  **Waggon**:
  Seats are represented as an array of pointers to Passengers.  This choice was made, because the size of the array is fixed, so a vector was not needed.

- **Train**:
  Waggons are represented as an array of pointers to Waggons.  This choice was made, because the size of the array is fixed, so a vector was not needed.
