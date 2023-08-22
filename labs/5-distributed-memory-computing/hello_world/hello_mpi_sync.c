#include <stdio.h>
#include <mpi.h>

int main (int argc, char *argv[])
{
  int myrank, size;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  for (int i = 0; i < size; i++) {
    if (i == myrank) {
      printf("Processor %d of %d: Hello World!\n", myrank, size);
      fflush(stdout);
    }
    MPI_Barrier(MPI_COMM_WORLD); 
  }
  
  MPI_Finalize();

  return 0;
}
