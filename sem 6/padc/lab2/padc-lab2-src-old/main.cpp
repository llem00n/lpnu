#include <mpi.h>
#include "ranks/mpi_rank_0.hpp"

int main(int argc, char **argv) {
  int rank, size;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0) {
    mpi_rank_0 rank_0(argc, argv);
    rank_0.run();
  }

  MPI_Finalize();
}
