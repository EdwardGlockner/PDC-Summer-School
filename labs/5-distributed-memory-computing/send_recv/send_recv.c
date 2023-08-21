#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[] )
{
  int rank, value, size;
  int value2;
  MPI_Status status;
  int numtasks;

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&numtasks); 
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  if (rank == 0) {
    value = 5;
    printf( "Process %d sending %d\n", rank, value );
    MPI_Send(&value, 4, MPI_INT, 0, 17, MPI_COMM_WORLD);
  } 
  else {
    printf( "Process %d got %d\n", rank, value );
    if (rank < size - 1) {
      MPI_Recv(&value2, 4, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    }
  }
  MPI_Finalize( );
  return 0;
}
